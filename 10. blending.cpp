#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/* blending is useful in rendering something that is partially or fully transparent
 * by default OpenGL doesn't perform blending
 *
 * blending determines how we combine out output color with what is already in out target buffer
 * output = the color we output from out fragment shader
 * target buffer = the buffer our fragment shader is drawing to*/

int main() {
   glEnable(GL_BLEND);  //enables the blending        glDisable(GL_BLEND)

   glBlendFunc(src, dest); //this specifies how the blending will be done
/* 1st arg -> this determines how the scr's RGBA factor is computed, default is GL_ONE ie scr's format multiplied by one
* 2nd arg -> this determines how the dest's RGBA factor is computed, default is GL_ZERO ie dest's format multiplied by zero*/

   glBlendEquation(mode);
   /* equation takes mode arg which determines how the colors of src and dest are combined, default is GL_FUNC_ADD ie add*/

   /* if our image's alpha channel is zero then it is completely transparent */
} //function-main
