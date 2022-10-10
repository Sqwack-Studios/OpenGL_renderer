/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: IndexBuffer.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 10/10/2022 18:49:04													 
//==============================================================================//

#ifndef _OpenGL_IndexBuffer_H_
#define _OpenGL_IndexBuffer_H_

#pragma once

class IndexBuffer
{
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();


    void Bind() const;
    void Unbind() const;

    inline unsigned int GetCount() const { return m_Count; }

private:
    unsigned int m_RendererID;
    unsigned int m_Count;
protected:

    
};
#endif // !_OpenGL_IndexBuffer_H_

