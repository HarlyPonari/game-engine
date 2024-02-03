#include "shaderClass.h"
#include <filesystem>

std::string get_file_contents(const char* filename)
{

  // std::filesystem::path p = std::filesystem::current_path();
  // std::cout << "Current path is " << p << std::endl;

  std::ifstream in(filename, std::ios::binary);
  if (in)
  {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return(contents);
  }
  std::cout << "Could not read file" << std::endl;
  throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
  std::string vetexCode = get_file_contents(vertexFile);
  std::string fragmentCode = get_file_contents(fragmentFile);

  const char* vertextSource = vetexCode.c_str();
  const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertextSource, NULL);

	glCompileShader(vertexShader);
  compileErrors(vertexShader, "VERTEX");

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);

	glCompileShader(fragmentShader);
  compileErrors(vertexShader, "FRAGMENT");

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
  compileErrors(ID, "PROGRAM");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
  glUseProgram(ID);
}

void Shader::Delete()
{
  glDeleteProgram(ID);
}

void Shader::compileErrors(unsigned int shader, const char* type)
{
  GLint hasCompiled;
  char infoLog[1024];
  if( type != "PROGRAM")
  {
    glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
    if( hasCompiled == GL_FALSE )
    {
      glGetShaderInfoLog(shader, 1024, NULL, infoLog);
      std::cout << "SHADER_COMPILATION_ERROR for:" << infoLog << "\n" << std::endl;
    }
  }
  else{
    glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
    if( hasCompiled == GL_FALSE )
    {
      glGetProgramInfoLog(shader, 1024, NULL, infoLog);
      std::cout << "SHADER_LINKING_ERROR for: " << infoLog << "\n" << std::endl;
    }
  }

}