#include "glad/glad.h"
#include "GLFW/glfw3.h"

// #include <GL/gl.h>
#include <iostream>
// glad: load all OpenGL function pointers
if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
{
  std::cout << "Failed to initialize GLAD" << std::endl;
  return -1;
}
