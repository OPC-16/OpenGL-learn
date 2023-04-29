#shader vertex
#version 330 core

layout(location = 0) in vec4 pos;

void main()
{
  gl_Position = pos;
};

#shader fragment
#version 330 core

out vec4 color;

void main()
{
  color = vec4(0.6f, 0.8f, 0.3f, 1.0f);
};
