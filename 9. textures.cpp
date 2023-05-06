#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/* taking an image and putting it in our GPU and then it goes in our shader, 
 * so how do we do this -> 
 * we first load an image in our CPU memory with help of a library known as STBimage. And 'loading an image in cpu' means
 * that this library takes file path of image and then returns a pointer to a buffer of RGBA pixels,
 * then we take this pixel array and load it in GPU as texture with help of OpenGL,
 * after that we modify our shader to read that texture and the fragment shader read from that texture memory and works out
 * which pixel should be of which color as per the texture*/

/* in OpenGL we have 'slots' where we can bind our textures to, and we can bind many textures as there are many slots,
 * roughly on pc we have 32 slots and on mobile 8 (but these numbers depend on the GPU and their implementation of OpenGL)
 * */

int main() {
   unsigned int someID, num;

   stbi_set_flip_vertically_on_load(1);   //a stb_image function
   /* we vertically flip the texture pixels of image as OpenGL's texture pixels start from bottom left and png's texture 
    * pixel start from top left */
   char* m_localBuffer = stbi_load(path.c_str(), &m_width, &m_height, &m_bitsPerPixel, 4);   //all our texture data put in m_localBuffer
   /* this function helps to get all the texture data in our local variable */


   glGenTextures(1, &someID); //generates texture names
   /* 1st arg -> number of texture names to be generated
    * 2nd arg -> where to store the generated texture names*/

   glBindTexture(GL_TEXTURE_2D, someID);  //bind a named texture to a texturing target
   /* 1st arg -> specifies target to which texture should be bound
    * 2nd arg -> name of texture*/

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //sets parameter for texture, and i is for integer
   /* 1st arg -> target
    * 2nd arg -> specifies symbolic names for single-valued texture parameter
    * 3rd arg -> specifies scalar commands*/

   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer);
   //specifies 2D texture image
   /* 1st arg ->target
    * 2nd arg -> specifies level-of-detail number, level 0 is base image level
    * 3rd arg -> internal format, this is how OpenGL will see our format
    * 4th arg -> width
    * 5th arg -> height
    * 6th arg -> format which we are suppling to OpenGL
    * 7th arg -> specifies type of pixel data
    * 8th arg -> specifies pointer to image data in memory*/

   glDeleteTextures(1, &someID); //delete named textures
   /* 1st arg -> number of textures to be deleted
    * 2nd arg -> which textures to delete*/

   glActiveTexture(GL_TEXTURE0 + num);
   // this make specified slot active, so that the next texture we bind will be binded to that slot
   /* arg -> specifies which texture slot or unit to make active, GL_TEXTURE0 means zeroth slot, and these enums are 
    *        just unsigned ints*/

   /* we also have to specify the texture coordinates, coz fragment shader needs to know color of the pixel of image it is 
    * drawing currently
    * and these coordinates are supplied to the fragment shader as an uniform, but those coords are in vertex shader.
    * We send data between vertex and fragment shaders by the in-out system*/

   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   /* Finally we have to enable the blending, to render the transparency correctly*/
} //function-main
