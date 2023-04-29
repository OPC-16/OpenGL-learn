#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/* uniforms are used to get data from CPU to GPU ie in shader to use it like variables 
 * uniforms are set per draw call*/

int main() {
   //specify uniform after the shader is binded using glUseProgram function

   int location_of_uniform = glGetUniformLocation(shader_program_id, "u_Color"); //returns location of uniform variable
   /* 1st arg -> which shader program to query
    * 2nd arg -> name of uniform variable in a string*/
   //if location_of_uniform is -1 then it could not retrive location of that uniform or that uniform may be unused

   glUniform4f(location_of_uniform, 0.2f, 0.3f, 0.8f, 1.0f);
   //4f in function name represents that we are taking 4 floats
   /* 1st arg -> location of uniform variable
    * then accordingly we input 4 floats or 3 ints or 1 unsigned int etc*/

   /* fragment shader will look like this after introducing u_Color uniform variable -> 

      #shader fragment
      #version 330 core

      layout(location = 0) out vec4 color;

      uniform vec4 u_Color;

      void main()
      {
        color = u_Color;
      };
*/
} //function-main
