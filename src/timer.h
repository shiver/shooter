#pragma once

#include <cstdint>

class Timer {
public:
    void start();
    void stop();
    void reset();
    std::uint32_t get_ticks();

    bool is_stopped();

private:
    bool _started;
    std::uint32_t _start_ticks;
    std::uint32_t _ticks;
};

// vim: ts=2:sw=2:et:
