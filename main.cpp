#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>



int main()
{

	glfwInit();

	// We are instructing glfw what version of OpenGl we are using. The file we used was from version 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // core allows us to use the modern functions of openGl. Compatibility profile allows use of modern and outdated objects

	

	GLFWwindow* window = glfwCreateWindow(400, 225, "I made this!", NULL, NULL); // making a GLFW object window, called window. The creation window function takes 5 parameters. This window is 400 pixels by 225 pixels, named I made this!. Exercise #3

	// error checking if the window fails to create
	if (window == NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//Introdue the windo into the current context
	glfwMakeContextCurrent(window); 


	//Loads GLAD to configure OpenGL;
	gladLoadGL();

	// This is specifing the viewport of OpenGL in the window. The viewport goes from x = 0, y = 0 to x = 400, y = 225 //EXERCISE #1 easy
	glViewport(0, 0, 400, 225);

	
	// Specifying the color of the background, this is color orange. //EXERCISE #2 easy
	glClearColor(0.80f, 0.33f, 0.07f, 1.0f);
	
	
	// this cleans the back buffer and assigns the new color to it.
	glClear(GL_COLOR_BUFFER_BIT);

	// swaps back buffer with front buffer
	glfwSwapBuffers(window);


	// main while loop
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window); //EXERCISE #1 medium
		// function to check all fo the GLFW events
		glfwPollEvents();
	}

	// Deletes window before ending program
	glfwDestroyWindow(window);
	// Terminates GLFW before ending program.
	glfwTerminate();
	return 0;
}
