#pragma once

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class GlWindow
{
public:
	GlWindow();
	GlWindow(GLfloat windowWidth, GLfloat windowheight);

	int initialise();

	GLfloat getBufferWidth() { return bufferWidth; }
	GLfloat getBufferHeight() { return bufferHeight; }

	bool getShouldClose() {
		return glfwWindowShouldClose(mainWindow);
	}

	void swapBuffers(){ glfwSwapBuffers(mainWindow); }

	~GlWindow();

private:
	GLFWwindow* mainWindow;

	GLfloat width, height;
	GLint bufferWidth, bufferHeight;
};

