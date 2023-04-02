/* ---- specifying the layout of buffer ----
        Author >_ OPC
*/
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
   /* a vertex not only contains positions but also many more things like normals, colors, tangents, etc these properties are known as attributes of that vertex and each attribute has an index just like array
    * We use glVertexAttribPointer to tell the layout of the buffer to opengl, only use this function after the buffer is binded with glBindBuffer*/

   float positions[6] = {
     -0.5f, -0.5f,
      0.0f, 0.5f,
      0.5f, -0.5f
   };
   glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
   /* args of glVertexAttribPointer ->
    *    1st - index of the attribute, here 0 coz the positions is out 1st attribute 
    *    2nd - the count of number of components in an attribute (must be 1,2,3,4), here 2 coz there are 2 floats per position
    *    3rd - type of data we are providing, here floats are used
    *    4th - is data normalized ie we have data from 0 to 255 so a normalized data is between 0 to 1, here for floats are already normalized so we say false
    *    5th - is stride, it is size in bytes of each component in an attribute
    *    6th - is offset, it is number in bytes to jump from beginning of the buffer ie 0 to get to start of next attribute, eg we have 2 attributes one position of 8 bytes and another of tangents of size 12 bytes, then offset of position is 0 and offset of tangents is 8*/

   /*we need to enable the vertex attribute in order to use that, no need to enable it after declaring the glVertexAttribPointer only that buffer should be binded coz opengl is a state machine*/

   glEnableVertexAttribArray(0);
   /* it takes only 1 arg of index which is to be enabled */

   // So those above 2 lines tells opengl the layout of our buffer
} //function-main
