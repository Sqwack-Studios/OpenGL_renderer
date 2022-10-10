/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Display.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 10/10/2022 19:07:32													 
//==============================================================================//

#ifndef _OpenGL_Display_H_
#define _OpenGL_Display_H_

#pragma once
#include <glfw3.h>
#include <stdint.h>
#include <string>


class Display
{
public:

	Display();
	Display(const uint32_t& width, const uint32_t& height, const std::string& windowName);
	~Display();

	bool SpawnWindow(GLFWmonitor* targetMonitor, GLFWwindow* sharedWindow);
	bool ShouldCloseWindow();
	void CreateContext();
	void SwapBuffers();
	void SetSwapInterval(const uint32_t& interval);



private:
	GLFWwindow*					m_noptr_Window;
	uint32_t					m_Width;
	uint32_t					m_Height;
	std::string					m_WindowName;
	GLFWmonitor*				m_TargetMonitor;
	GLFWwindow*					m_SharedWindow;

protected:



};


#endif // !_OpenGL_Display_H_

