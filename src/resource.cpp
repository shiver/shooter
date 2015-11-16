#include <iostream>
#include <fstream>

#include <easylogging++.h>
#include <GL/glew.h>

#include "util.h"
#include "resource.h"

ShaderResource::ShaderResource(const char* filename, GLuint shader_type) {
  _filename = filename;
  _shader_type = shader_type;
}

void ShaderResource::load() {
  std::ifstream ifs(_filename);
  auto shader_src = read_stream_into_string(ifs);

  const char* shader_bytes = _shader_src.c_str();
  GLuint shader_id = glCreateShader(_shader_type);
  glShaderSource(shader_id, 1, &shader_bytes, NULL);
  glCompileShader(shader_id);

  GLint success;
  glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
  if (!success) {
    get_error(shader_id);
  }
}

void ShaderResource::get_error(GLuint shader_id) {
  GLchar infoLog[512];
  glGetShaderInfoLog(shader_id, 512, NULL, infoLog);
  LOG(ERROR) << "Shader compile failed for " <<  _filename << ": " << infoLog << "\n";
}

// vim: ts=2:sw=2:et: