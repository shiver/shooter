#include <SDL.h>

#include "timer.h"


void Timer::start() {
    if (is_stopped()) return;
    _start_ticks = SDL_GetTicks();
    _started = true;
}

bool Timer::is_stopped() {
    return !_started;
}

std::uint32_t Timer::get_ticks() {
    if (is_stopped()) {
        return _ticks - _start_ticks;
    }

    return SDL_GetTicks() - _start_ticks;
}

void Timer::reset() {
    _start_ticks = SDL_GetTicks();
    _ticks = _start_ticks;
}

void Timer::stop() {
    _started = false;
    _ticks = SDL_GetTicks();
}

// vim: ts=2:sw=2:et:
