#include "controls.hpp"
void Camera::processInput(GLFWwindow* window){
	static double lastTime = glfwGetTime();
	double currentTime = glfwGetTime();
	float dTime = currentTime - lastTime;
	const float camSpeed=0.05f * dTime;
	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
		camPos += camSpeed * camFront;
	}
	if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
		camPos -= camSpeed * camFront;
	}
	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
		camPos -= glm::normalize(glm::cross(camFront, camUp) * MoveSpeed);
	}
	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
		camPos += glm::normalize(glm::cross(camFront, camUp) * MoveSpeed);
	}
}
void Camera::UpdCamVec(){
	glm::vec3 front;
	front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));

	camFront = glm::normalize(front);
	camRight = glm::normalize(glm::cross(camFront, worldUp));
	camUp = glm::normalize(glm::cross(camRight, camFront));

}
void Camera::CamProcessMouse(float xOffset, float yOffset){
	xOffset *= Sens;
	yOffset *= Sens;
	Yaw += xOffset;
	Pitch += yOffset;
	if(Pitch > 89.0f){
		Pitch = 89.0f;
	}
	if(Pitch < -89.0f){
		Pitch = -89.0f;
	}
	UpdCamVec();
}


