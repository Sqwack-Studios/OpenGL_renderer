/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: VertexBuffer.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 10/10/2022 18:41:54													 
//==============================================================================//

#ifndef _OpenGL_VertexBuffer_H_
#define _OpenGL_VertexBuffer_H_

#pragma once

class VertexBuffer
{

public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
private:
	unsigned int m_RendererID;
protected:


};
#endif // !_OpenGL_VertexBuffer_H_

