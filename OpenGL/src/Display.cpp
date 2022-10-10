/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Display.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 10/10/2022 19:07:39													 
//==============================================================================//

#ifndef _OpenGL_Display_CPP_
#define _OpenGL_Display_CPP_

#pragma once
#include "Display.h"
#include <glfw3.h>

Display::Display():
	Display(0, 0, "")
{
	
}


Display::Display(const uint32_t& width, const uint32_t& height, const std::string& windowName):
	m_Width(width),
	m_Height(height),
	m_WindowName(windowName)
{
	m_noptr_Window = nullptr;
	m_TargetMonitor = nullptr;
	m_SharedWindow = nullptr;
}

Display::~Display()
{
	glfwTerminate();
}

bool Display::SpawnWindow(GLFWmonitor* targetMonitor, GLFWwindow* sharedWindow)
{
	m_noptr_Window = glfwCreateWindow(m_Width, m_Height, m_WindowName.c_str(), targetMonitor, sharedWindow);
	if (!m_noptr_Window)
		return false;

	return true;
}

bool Display::ShouldCloseWindow()
{
	return glfwWindowShouldClose(m_noptr_Window);
}

void Display::SwapBuffers()
{
	glfwSwapBuffers(m_noptr_Window);
}

void Display::SetSwapInterval(const uint32_t& interval)
{
	glfwSwapInterval(interval);
}

void Display::CreateContext()
{
	glfwMakeContextCurrent(m_noptr_Window);
}




#endif // !_OpenGL_Display_CPP_

