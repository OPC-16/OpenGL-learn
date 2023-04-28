#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/* to draw a rectangle we need 2 triangles, so we have to store same vertices twice this is waste of GPU memory
 * to help us with this we use index buffers
 * */

int main() {
   float positions_old[] = {
      -0.5f, -0.5f,
      0.5f, -0.5f,
      0.5f, 0.5f,

      0.5f, 0.5f,
      -0.5f, 0.5f,
      -0.5f, -0.5f
   };
/*       3         2
    *    +---------+
    *    |       / |
    *    |     /   |
    *    |   /     |
    *    |  /      |
    *    | /       |
    *    +---------+
    *    0         1
    * numbers are vertices
    *    */
   float positions_new[] = {
      -0.5f, -0.5f,  //will draw vertex 0
      0.5f, -0.5f,  //will draw vertex 1
      0.5f, 0.5f,  //will draw vertex 2
      -0.5f, 0.5f,  //will draw vertex 3
   };
   /* we need to draw 0, 1 and 2 vertices and then 2, 3, 0*/
   unsigned int indices[] {   //we can also use unsigned chars or shorts to save memory
      0, 1, 2,
      2, 3, 0
   }; //these indices are now in cpu we need to send them in gpu, so we do following after the vertex attrib pointer stuff

   unsigned int ibo;    //ibo stands for 'index buffer object'
   glGenBuffers(1, &ibo);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

   //indices array has to be unsigned

   glDrawArrays(GL_TRIANGLES, 0, 6);
   //instead of above draw arrays call, we use draw elements call
   glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
   /* 1st arg -> what kind of primitives to render
    * 2nd arg -> no. of elements or indices to be rendered
    * 3rd arg -> type of values of indices
    * 4th arg -> addr of 1st element in indices array*/
   // as we have binded the ibo buffer we dont need to spicifi 4th arg in above call, so it is 'nullptr' in there
} //function-main
