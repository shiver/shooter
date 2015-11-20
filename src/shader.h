#pragma once

#include <vector>

#include "resource.h"

class ShaderProgram : public Resource {
public:
    ShaderProgram(ResourceList);
    GLuint get() { return _program_id; }

private:
    GLuint _program_id;
};


// vim: ts=2:sw=2:et:
