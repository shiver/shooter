#include <vector>

#include "shader.h"
#include "resource.h"

ShaderProgram::ShaderProgram(ResourceList shaders) {
    auto program = glCreateProgram();
    for (auto shader_ptr : shaders) {
      auto shader = std::static_pointer_cast<ShaderResource>(shader_ptr);
      shader->load();

      glAttachShader(program, shader->get());

      shader->cleanup();
    }

    GLint success;
    GLchar infoLog[512];
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        LOG(ERROR) << "Shader PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
}

// vim: ts=2:sw=2:et:
