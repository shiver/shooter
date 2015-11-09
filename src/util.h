#pragma once

#include <ios>
#include <memory>
#include <string>
#include <istream>
#include <sstream>

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>{new T{std::forward<Args>(args)... }};
}

// Implementation based on Explicit C++ blog post:
// http://cpp.indi.frih.net/blog/2014/09/how-to-read-an-entire-file-into-memory-in-cpp/
template <typename Char, typename Traits,
          typename Allocator = std::allocator<Char>>
auto read_stream_into_string(std::basic_istream<Char, Traits>& in,
                             Allocator alloc = {}) {
  std::basic_ostringstream<Char, Traits, Allocator> ss(
    std::basic_string<Char, Traits, Allocator>(std::move(alloc)));

  if (!(ss << in.rdbuf()))
    throw std::ios_base::failure{"error"};

  return ss.str();
}

// vim: ts=2:sw=2:et:
