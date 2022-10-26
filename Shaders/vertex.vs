#version 460 core
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColor;
out vec3 FragColor;
uniform mat4 mvp;

void main(){
	gl_Position = mvp * vec4(vertexPosition_modelspace, 1);
	FragColor = vertexColor;


}

