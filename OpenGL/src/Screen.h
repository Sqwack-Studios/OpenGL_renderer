/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Screen.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 10/10/2022 20:48:50													 
//==============================================================================//

#ifndef _OpenGL_Screen_H_
#define _OpenGL_Screen_H_

#pragma once
#include <glfw3.h>
#include <string>
#include <stdint.h>

class Screen
{
public:

	Screen();
	Screen(const uint32_t& width, const uint32_t& height, const std::string& windowName);
	~Screen();

	bool SpawnWindow(GLFWmonitor* targetMonitor, GLFWwindow* sharedWindow);
	bool ShouldCloseWindow();



private:
	GLFWwindow*					m_noptr_Window;
	uint32_t					m_Width;
	uint32_t					m_Height;
	std::string					m_WindowName;
	GLFWmonitor*				m_TargetMonitor;
	GLFWwindow*					m_SharedWindow;
};
#endif // !_OpenGL_Screen_H_

