#ifndef CONTROLS_HPP
#define CONTROLS_HPP
void globalBindings();
extern bool imguishow;
void computeMatricesFromInputs();
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();

#endif
