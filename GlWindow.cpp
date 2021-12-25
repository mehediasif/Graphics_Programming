#include "GlWindow.h"

GlWindow::GlWindow()
{
	width = 800;
	height = 600;
}

GlWindow::GlWindow(GLfloat windowWidth, GLfloat windowheight)
{
	width = windowWidth;
	height = windowheight;
}

int GlWindow::initialise()
{
	//Initialize GLFW
	if (!glfwInit())
	{
		printf("GLFW Initialization failed!");
		glfwTerminate();
		return 1;
	}
	//Setup GLFW Window properties
	//OpenGl Version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//core profile = no backwards compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Forward Compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	mainWindow = glfwCreateWindow(width, height, "Test Window", NULL, NULL);
	if (!mainWindow) {
		printf("GLFW window creation failed");
		glfwTerminate();
		return 1;
	}

	//Buffer Size Information
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	//allow modern extension
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Glew initialization failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST);

	//Setup Viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);
}

GlWindow::~GlWindow()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
}
