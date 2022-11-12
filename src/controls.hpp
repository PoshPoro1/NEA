#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// This class is mainly here for the sake of limiting access to variables and abstraction
class Camera{
	private:
		glm::vec3 camTarget;
		glm::vec3 camDirection;
		glm::vec3 camRight;

		glm::vec3 worldUp;
		glm::mat4 view;
		float Yaw;
		float Pitch;
		float MoveSpeed;
		float Sens;
		float fov;
	public:
		// Public as need them for input handling
		glm::vec3 camPos;
		glm::vec3 camFront;
		glm::vec3 camUp;
		Camera(glm::vec3 camPos_ = glm::vec3(0.0f,0.0f,0.0f), glm::vec3 up = glm::vec3(0.0f,1.0f,0.0f) ,float yaw = -90.0f, float pitch = 0.0f) : camFront(glm::vec3(0.0f,0.0f,-1.0f)), Sens(0.1f), MoveSpeed(2.5f), fov(45.0f){
			camPos = camPos_;
			worldUp = up;
			Yaw = yaw;
			Pitch = pitch;
			UpdCamVec();
		}
		void processInput(GLFWwindow* window);
		void UpdCamVec();
		void CamProcessMouse(float xOffset, float yOffset);
};
