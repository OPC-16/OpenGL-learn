#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/*glGetError is used to tell us errors occured during exec of gl functions,
 * but it only tells 1 error at a time so call glGetError in a loop
 *
 * glGetError returns a GLenum i.e. unsigned int which represents the error information */

/* there is another function 'glDebugMessageCallback' which is better than glGetError, and is latest*/

static void GLClearError() {
   while (glGetError() != GL_NO_ERROR);  //value of GL_NO_ERROR enum is zero
} //function-GLClearError

static void GLPrintError() {
   while (GLenum error = glGetError()){
      std::cout << "[OpenGL Error] (" << error << ")\n";
   }
} //function-GLPrintError

#define GLCheckError(x) GLClearError();\
   x;\
   GLPrintError2(#x, __FILE__, __LINE__) //#x converts x into string, __FILE__ gives file name, __LINE__ gives line number

static void GLPrintError2(const char* function,const char* file, int line) {
   while (GLenum error = glGetError()){
      std::cout << "[OpenGL Error] (" << error << "): " << function <<
         " " << file << ":" << line << std::endl;
   }
} //function-GLPrintError2

int main() {
   GLClearError();   //this clears all the previous errors
   glDrawElements(GL_TRIANGLES, 6, GL_INT, nullptr);
   GLPrintError();   //this checks for errors in just above gl func call
   /* we have introduced an enum error in the draw call, GL_INT is not valid, GL_UNSIGNED_INT is valid*/

   /* after running above we get 1280 number printing in our terminal, after converting 1280 in hexdecimal (coz GLAD and GLEW define 
    * errors codes in hex) we conclude to GL_INVALID_ENUM*/

   /* fault in above implementation is that we don't actually understand which error has occured on which line in which file*/
   /* to rectify this, we have declared 'GLCheckError' macro which first exec GLClearError func then excutes the actual
    * gl function inside it and then calls GLPrintError2 with file and line number*/
      GLCheckError(glDrawElements(GL_TRIANGLES, 6, GL_INT, nullptr));
} //function-main
