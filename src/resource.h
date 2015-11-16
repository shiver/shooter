#pragma once

#include <easylogging++.h>
#include <GL/glew.h>

#include <unordered_map>

class Resource {
public:
  Resource() {}
  Resource(std::uint64_t id) : _id(id) {}

  virtual ~Resource() = default;

private:
  std::uint64_t _id;
};

class ShaderResource : Resource {
public:
  ShaderResource() {}
  ShaderResource(const char* filename, GLuint shader_type);

  ~ShaderResource() = default;

  void load();
  void get_error(GLuint shader_id);

private:
  const char* _filename;
  GLuint _shader_type;
  std::string _shader_src;
};

class ResourceManager {
public:
    ResourceManager() : _resources() {}
    ResourceManager(ResourceManager&&) = default;

    template<typename T, typename... Args>
    std::uint64_t create(Args&&... args) {
      // TODO: Is last_id handling here thread safe?
      _resources.insert({
          ++_last_id,
          std::make_shared<T>(std::forward<Args>(args)...)
      });
      return _last_id;
    }

private:
    std::unordered_map<std::uint64_t, std::shared_ptr<ShaderResource>> _resources;
    std::uint64_t _last_id = 0;
};

// vim: ts=2:sw=2:et:
