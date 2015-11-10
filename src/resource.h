#pragma once

#include <easylogging++.h>
#include <GL/glew.h>

#include <unordered_map>

class Resource {
public:
  Resource() {}
  Resource(std::uint64_t id) : _id(id) {}

private:
  std::uint64_t _id;
};

class ShaderResource : Resource {
public:
  ShaderResource(const char* filename, GLuint shader_type);
  void load();
  void get_error(GLuint shader_id);

  ~ShaderResource() {}
private:
  const char* _filename;
  GLuint _shader_type;
  std::string _shader_src;
};

class ResourceManager {
public:
    ResourceManager() : _resources() {}
    ResourceManager(ResourceManager&&) = default;

    template<typename T>
    T add(const T&) {
    }

    template<typename T>
    T add(const T&&) {
    }

private:
    std::unordered_map<std::string, Resource> _resources;
    std::uint64_t _lastId = 0;
};

// vim: ts=2:sw=2:et:
