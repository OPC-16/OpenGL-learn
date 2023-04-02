/* ---- declaration of a buffer ----
        Author >_ OPC
*/
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
   /* a buffer is just some bytes of memory in the gpu where our data to draw the figures lies*/

   float positions[6] = {
      -0.5f, -0.5f,
      0.0f, 0.5f,
      0.5f, -0.5f
   };

   unsigned int buffer; //a buffer is just an integer
   glGenBuffers(1, &buffer);  //this will generate one buffer in the addr of &buffer
   glBindBuffer(GL_ARRAY_BUFFER, buffer); //this will bind that generated buffer of type ARRAY of OPENGL to the int buffer
   glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);  //this copies the data to the buffer in gpu
   /* args of glBufferData ->
    *    1st - states type of buffer, here an opengl array
    *    2nd - how much size to copy in the buffer
    *    3rd - specifies a pointer to data that will be copied
    *    4th - specifies what to do with the data i.e. usage*/
} //function-main
