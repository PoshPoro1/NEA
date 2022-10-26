#include "shader.hpp"

Shader::Shader(const char* vertpath, const char* fragpath){
	std::string vertCode;
	std::string fragCode;
	std::ifstream vertFile;
	std::ifstream fragFile;
	vertFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
	fragFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

	// Reading out of the file
	try{
		vertFile.open(vertpath);
		fragFile.open(fragpath);
		std::stringstream vertStream, fragStream;
		vertStream << vertFile.rdbuf();
		fragStream << fragFile.rdbuf();
		vertFile.close();
		fragFile.close();
		vertCode = vertStream.str();
		fragCode = fragStream.str();
	}


	catch(std::ifstream::failure e){
		std::cout << "It borked Skull emoji" << std::endl;
	}
	const char* vertexSource = vertCode.c_str();
	const char* fragmentSource = fragCode.c_str();

	//Compiling
	unsigned int vertex,fragment;
	int success;
	char log[512];
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertexSource, NULL);
	glCompileShader(vertex);
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment,1,&fragmentSource,NULL);
	glCompileShader(fragment);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if(!success){
		glGetShaderInfoLog(vertex, 512, NULL, log);
		std::cout << "Error occured when loading vertex shader\n" << log << std::endl;
	}
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if(!success){
		glGetShaderInfoLog(fragment, 512, NULL, log);
		std::cout << "Error occured when loading fragment shader\n" << log << std::endl;
	}
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if(!success){
		glGetProgramInfoLog(ID, 512, NULL, log);
		std::cout << "Error when linking the shader program\n" << log << std::endl;
	}
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}
void Shader::use(){
	glUseProgram(ID);
}
void Shader::setBool(const std::string &name, bool value) const{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void Shader::setInt(const std::string &name, int value) const{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setFloat(const std::string &name, float value) const{
	glUniform1f(glGetUniformLocation(ID,name.c_str()),value);
}

