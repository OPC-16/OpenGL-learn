#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

static unsigned int compileShader(unsigned int type, const std::string& source) {
   unsigned int id = glCreateShader(GL_VERTEX_SHADER); //will create a shader of type vertex
   const char* src = source.c_str();   //this will return pointer to 1st char in source, we convert std::string into raw string coz OpenGL take raw str
   glShaderSource(id, 1, &src, nullptr);  //used to put code in the created shader
   /* 1st arg -> we have to specify which shader to use, it's unsigned int type
    * 2nd arg -> how many source codes we are specifying 
    * 3rd arg -> takes pointer to the pointer to the actual string
    * 4th arg -> takes length, how much string we want to use, if 'nullptr' then it will use whole string*/
   glCompileShader(id); //this actually compiles the shader specified

   int result; //just to store our compile status of shader
   //return parameter of shader obj
   glGetShaderiv(id, GL_COMPILE_STATUS, &result);     //i is for integer, v is for vertex i.e. array
   /* 1st arg -> Specifies the shader object to be queried
    * 2nd arg -> which parameter of shader to check
    * 3rd arg -> will store the returned ans in here*/
   if (result == GL_FALSE) {
      int length;    //to store the error message
      glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
      //we dynamically consrtuct a char array on the stack, yes on stack with alloca of size of length
      char* message = (char*)alloca(length * sizeof(char));

      glGetShaderInfoLog(id, length, &length, message);  //this gets our error message
      /* 1st arg -> which shader to be queried
       * 2nd arg -> buffer size 
       * 3rd arg -> pointer to the length
       * 4th arg -> pointer to that actual buffer*/
      std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " Shader!" << '\n';
      std::cout << message << std::endl;
      glDeleteShader(id);
      return 0;
   }

   return id;
}// function-compileShader

static unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader) {
   unsigned int program = glCreateProgram();    //here, program var has GLuint type which is unsigned int, try to use vanilla c++ types
   //glCreateProgram creates a program obj to which a shader obj can be attached
   unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
   unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

   //this attaches the shader obj to the program obj, so that later both shaders could be linked together
   glAttachShader(program, vs);
   glAttachShader(program, fs);
   /* 1st arg -> which program to use
    * 2nd arg -> which shader to use to attach to that program*/

   // this links the program obj, ie. attached shaders to program are used to create their specific executable that will run on that type of processor
   glLinkProgram(program);
   //this validates that given program can be executed or not, if validation successfull then program obj's state will be set to GL_TRUE or GL_FALSE
   glValidateProgram(program);

   //this deletes the shader obj, as that obj is attached the program and executable of that program is created we don't need the shader obj anymore
   glDeleteShader(vs);
   glDeleteShader(fs);

   return program;
}// function-createShader

int main() {
   //the actual shaders
   std::string vertexShader = 
      "#version 330 core\n"   //core will ensure that we don't use any deprecated methods
      "\n"
      "layout(location = 0) in vec4 position;\n"  //we access the actual data such as geometric points
      //'location = 0' means the data starts from zero index and 'vec4' means that there will 4 components in vertex
      "\n"
      "void main()\n"   //this main kind of works like c++ main function
      "{\n"
      "  gl_Position = position;\n"
      "}\n";

   std::string fragmentShader = 
      "#version 330 core\n"
      "\n"
      "layout(location = 0) out vec4 color;\n"    //we want to color our triangle
      "\n"
      "void main()\n"
      "{\n"
      "  color = vec4(1.0, 0.0, 0.0, 1.0);\n"   //red, instead of 0-255 it is 0-1 and in rbga format
      "}\n";

   unsigned int shader = createShader(vertexShader, fragmentShader);
   //Specifies the handle of the program object whose executables are to be used as part of current rendering state.
   glUseProgram(shader);

} //function-main
