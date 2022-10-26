#include <GLFW/glfw3.h>
extern GLFWwindow* window;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "controls.hpp"
glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

glm::mat4 getViewMatrix(){
	return ViewMatrix;
}
glm::mat4 getProjectionMatrix(){
	return ProjectionMatrix;
}

glm::vec3 position = glm::vec3(0,0,5);
float hoizontalAngle = 3.14f;
float verticalAngle = 0.0f;
float initialFOV = 45.0f;
float speed = 5.0f;
float mouseSpeed = 0.020f;

void computeMatricesFromInputs(){
	static double lastTime = glfwGetTime();
	double currentTime = glfwGetTime();

	float deltaTime = float(currentTime - lastTime);

	double xpos,ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	glfwSetCursorPos(window, 1024.0f/2, 768.0f/2);
	hoizontalAngle += mouseSpeed * deltaTime * float(1024.0f/2.0f - xpos);
	verticalAngle += mouseSpeed * deltaTime * float(768.0f/2.0f-ypos);

	glm::vec3 direction = glm::vec3(
			cos(verticalAngle) * sin(hoizontalAngle),
			sin(verticalAngle),
			cos(verticalAngle) * cos(hoizontalAngle)
	);
	glm::vec3 right = glm::vec3(sin(hoizontalAngle-3.14f/2.0f), 0, cos(hoizontalAngle - 3.14f/2.0f));
	glm::vec3 up = glm::cross(right, direction);

	if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
		position += direction*deltaTime*speed;
	}
	if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
		position -= direction * deltaTime * speed;
	}
	if(glfwGetKey(window,GLFW_KEY_RIGHT) == GLFW_PRESS){
		position += right * deltaTime * speed;
	}
	if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}
	ProjectionMatrix = glm::perspective(glm::radians(60.0f), 4.0f/3.0f, 0.1f, 100.0f);
	ViewMatrix = glm::lookAt(
			position,
			position+direction,
			up
			);
	lastTime = currentTime;
}



