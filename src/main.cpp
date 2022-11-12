#include <iostream>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_internal.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
GLFWwindow* window;
#include <fstream> 
#include <cerrno> 
#include <locale>
#include <string>
#include <sstream>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
float yaw = -90.0f;
float pitch;
float sensitivity = 0.1f;
bool firstMouseInput = true;

#include "shader.hpp"
#include "controls.hpp"

static const GLfloat g_vertex_buffer_data[] = {
    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f, // triangle 1 : end
    1.0f, 1.0f,-1.0f, // triangle 2 : begin
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f, // triangle 2 : end
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
};

static const GLfloat g_color_buffer_data[] = {
    0.583f,  0.771f,  0.014f,
    0.609f,  0.115f,  0.436f,
    0.327f,  0.483f,  0.844f,
    0.822f,  0.569f,  0.201f,
    0.435f,  0.602f,  0.223f,
    0.310f,  0.747f,  0.185f,
    0.597f,  0.770f,  0.761f,
    0.559f,  0.436f,  0.730f,
    0.359f,  0.583f,  0.152f,
    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,
    0.014f,  0.184f,  0.576f,
    0.771f,  0.328f,  0.970f,
    0.406f,  0.615f,  0.116f,
    0.676f,  0.977f,  0.133f,
    0.971f,  0.572f,  0.833f,
    0.140f,  0.616f,  0.489f,
    0.997f,  0.513f,  0.064f,
    0.945f,  0.719f,  0.592f,
    0.543f,  0.021f,  0.978f,
    0.279f,  0.317f,  0.505f,
    0.167f,  0.620f,  0.077f,
    0.347f,  0.857f,  0.137f,
    0.055f,  0.953f,  0.042f,
    0.714f,  0.505f,  0.345f,
    0.783f,  0.290f,  0.734f,
    0.722f,  0.645f,  0.174f,
    0.302f,  0.455f,  0.848f,
    0.225f,  0.587f,  0.040f,
    0.517f,  0.713f,  0.338f,
    0.053f,  0.959f,  0.120f,
    0.393f,  0.621f,  0.362f,
    0.673f,  0.211f,  0.457f,
    0.820f,  0.883f,  0.371f,
    0.982f,  0.099f,  0.879f
};
void framebufferSizeCallback(GLFWwindow* window, int width, int height){
	glViewport(0,0,width,height);
}

int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1024,768,"NEA", NULL,NULL);
    if(window == NULL){
	    std::cout << "Failed to make window using GLFW" << std::endl;
	    glfwTerminate();
	    return 1;
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to start glad" << std::endl;
        return 1;
    }
    glViewport(0,0,1024,768);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetCursorPos(window,1024.0f/2,768.0f/2.0f);
    



    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);



    const char* vertexPath = "Shaders/vertex.vs";
    const char* fragmentPath = "Shaders/fragment.fs";
    Shader myshader(vertexPath, fragmentPath);
    std::vector<unsigned int> indicies;
    GLuint VAO, VBO, EBO, CAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    GLuint matID = glGetUniformLocation(myshader.ID, "mvp");
    glGenBuffers(1, &CAO);
    glBindBuffer(GL_ARRAY_BUFFER, CAO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
    glm::vec3 model = glm::vec3(0.0f,0.0f,0.0f);
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0.0f,0.0f,3.0f),
		    glm::vec3(0.0f,0.0f,0.0f),
		    glm::vec3(0.0f,1.0f,0.0f));
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f,1.0f,0.0f);

    Camera myCam(model,cameraPos ,view, cameraFront, cameraUp );
    glfwSetCursorPosCallback(window, mouse_callback);
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    ImGui::SetMouseCursor(ImGuiMouseCursor_None);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    bool wireframe = false;
    bool currentDraw = 1; // 1 is fill 0 is wireframe
    bool vsync = true;
    bool currentsync = 1;




    while (!(glfwWindowShouldClose(window))){
	    if(wireframe == true && currentDraw ==1 ){
		    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		    currentDraw = 0;
	    }
	    else if(wireframe == false && currentDraw == 0){
		    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		    currentDraw = 1;
	    }
	    if(vsync == true && currentsync == 0){
		    glfwSwapInterval(1);
		    currentsync = 1;
	    }
	    else if(vsync == false && currentsync == 1){
		    glfwSwapInterval(0);
		    currentsync = 0;
	    }


	    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	    /*
	    ImGui_ImplOpenGL3_NewFrame();
	    ImGui_ImplGlfw_NewFrame();
	    ImGui::NewFrame();
	    */
	    myshader.use();
	    processInput(window, myCam);
	    /*	    if(imguishow == false){
		    computeMatricesFromInputs();
		    glm::mat4 Projection = getProjectionMatrix();
		    glm::mat4 View = getViewMatrix();
		    glm::mat4 Model = glm::mat4(1.0f);
		    glm::mat4 mvp = Projection*View*Model;
		    glUniformMatrix4fv(matID, 1, GL_FALSE, &mvp[0][0]);
		    }
		    */

	    glEnableVertexAttribArray(0);
	    glBindBuffer(GL_ARRAY_BUFFER, VBO);
	    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
	    glDrawArrays(GL_TRIANGLES,0,12*3);
	    glDisableVertexAttribArray(0);

	    glEnableVertexAttribArray(1);
	    glBindBuffer(GL_ARRAY_BUFFER, CAO);
	   /* glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,(void*)0);
	    if(imguishow == true){
		    ImGui::Begin("Window");
		    ImGui::Text("Gamering");
		    ImGui::Checkbox("Wireframe mode", &wireframe);
		    ImGui::Checkbox("Vsync", &vsync);
		    ImGui::Text("Current fps: %f", ImGui::GetIO().Framerate);
		    if(ImGui::Button("Exit")){
			    glfwSetWindowShouldClose(window, 1);
		    }

		    ImGui::End();

	    }
	    ImGui::Render();
	    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
*/




	    glfwSwapBuffers(window);
	    glfwPollEvents();
    }

    

    // Making and binding VBO
    glfwTerminate();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    return 0;
    
}
