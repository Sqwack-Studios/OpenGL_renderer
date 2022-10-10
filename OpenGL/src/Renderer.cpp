/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Renderer.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 10/10/2022 18:38:01													 
//==============================================================================//

#ifndef _OpenGL_Renderer_CPP_
#define _OpenGL_Renderer_CPP_

#pragma once
#include "Renderer.h"
#include <iostream>


void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (" << error << "): " << function << " " << file << ": " << line << std::endl;
        return false;
    }
    return true;
}



#endif // !_OpenGL_Renderer_CPP_

