/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Renderer.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 10/10/2022 18:37:51													 
//==============================================================================//

#ifndef _OpenGL_Renderer_H_
#define _OpenGL_Renderer_H_

#pragma once
#include <glew.h>

#define ASSERT(x) if(!(x)) __debugbreak();

#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__,__LINE__))





void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);


#endif // !_OpenGL_Renderer_H_

