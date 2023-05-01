#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/* other rendering APIs like DirectX does not have such vertex arrays */

/* when we declare our data buffer and index buffers we bind them and then specify their layout with vertexAttribPoint 
 * (for data buffer),   if we unbind these buffers and again bind them we still have to specify their layout again,
 * so to avoid this we use vertex array objects to store the buffer's layout i.e. it's state
 * it is very helpful if we have muliple buffers i.e. geometric objects to draw
 *
 * before -
 *    bind-shader -> bind-vertex-buffer -> setup-vertex-layout -> bind-index-buffer -> draw-call
 * after -
 *    bind-shader -> bind-vertex-array -> bind-index-buffer -> draw-call*/

/* it actually is mandatory to use vertex array objects -
 * it is imp to know that in compatibility mode of opengl a default vertex array is automatically produced 
 *       glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

 * and in core mode we manually have to create the vertex array objects & then use vertexAttribPointer etc
 *       glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); */

int main() {
   unsigned int vao;    //vertex array object
   glGenVertexArrays(1, &vao);   //generating the vertex arr obj
   /* 1st arg -> Specifies the number of vertex array object names to generate. 
    * 2nd arg -> Specifies an array in which the generated vertex array object names are stored*/

   glBindVertexArray(vao); //binds the vao
   /* it doesn't take any target like GL_ARRAY_BUFFER etc
    * 1st arg -> name of the vertex array to bind*/

   /* and the    GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0)); 
    * actually links the buffer and the vao*/
} //function-main
