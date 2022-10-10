/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: VertexArray.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 10/10/2022 22:03:26													 
//==============================================================================//

#ifndef _OpenGL_VertexArray_H_
#define _OpenGL_VertexArray_H_

#pragma once



class VertexBuffer;
class VertexBufferLayout;
class IndexBuffer;

class VertexArray
{
private:
	unsigned int m_RendererID;
protected:

public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const IndexBuffer& ib, const VertexBufferLayout& layout);
	void Bind() const;
	void Unbind() const;
};
#endif // !_OpenGL_VertexArray_H_

