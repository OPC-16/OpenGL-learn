/* ---- shaders info ----
        Author >_ OPC
*/
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
   /* shaders are programs which run on the GPU, there are popular 2 types of shaders -
    * 1. vertex shaders
    * 2. fragment shaders (also known as pixel shaders)
    * there are many shaders but for 90% of time we only use these 
    * 
    * There is a graphics pipeline which starts with a draw call and many other stages later in it
    * So, our code goes from draw call to vertex shader to fragment shader to final picture
    * there are many things in between them (just remember it)
    *
    * vertex shader -
    *    is called for each vertex we defined, so for a triangle it will be called 3 times,
    *    primary purpose of this shader is to tell opengl where we want that vertex to be on out screen,
    *    it is also used to pass data ie attributes to the next stage coz vertex shader will take in all the attributes 
    *    that we have specified in out buffer
    *
    * fragment shader -
    *    it basically draws the pixels in the specified position and also colorize them if needed, but remember fragments 
    *    and pixels are different things, pixel drawing is also known as rasterization, this shader gets called once 
    *    for each pixel
    *
    * also remember - in big game engines shaders are generated on the fly based on whats going on in our game and graphic 
    * settings */

} //function-main
