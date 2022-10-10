/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Application.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 08/10/2022 21:39:56													 
//==============================================================================//

#ifndef _OpenGL_Application_CPP_
#define _OpenGL_Application_CPP_

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <glew.h>
#include <glfw3.h>
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Display.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"



static void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (" << error << "): " << function << " " << file << ": " << line << std::endl;
        return false;
    }
    return true;
}

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};
static ShaderProgramSource ParseShader(const std::string& filePath)
{
    std::ifstream stream(filePath);

  

    enum class ShaderType
    {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };
    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
  
  
    while (getline(stream, line))
    {
        
        if (line.find("#shader") != std::string::npos)
        {

            if (line.find("vertex") != std::string::npos)
            {
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                type = ShaderType::FRAGMENT;
            }  
        }
        else
        {
            ss[static_cast<int>(type)] << line << '\n';
        }

            
        
    }

    return ShaderProgramSource{ ss[0].str(), ss[1].str() };
}
static unsigned int CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    GLCall(glShaderSource(id, 1, &src, nullptr));
    GLCall(glCompileShader(id));

    int result;
    GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

    //error handlind 
    if (!result)
    {
        int length;
        GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
        char* message = static_cast<char*>(_malloca(length * sizeof(char)));
        GLCall(glGetShaderInfoLog(id, length, &length, message));
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
        std::cout << message << std::endl;

        GLCall(glDeleteShader(id));
        return 0;
    }

    return id;
}
static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));
    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));

    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));

    return program;
}

int main(void)
{


    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_COMPAT_PROFILE);
    

    /* Create a windowed mode window and its OpenGL context */
    Display display(1280, 720, std::string("Hello World"));
    if (!display.SpawnWindow(NULL, NULL))
    {
        std::cout << "Error creating display" << std::endl;
        return 0;
    }

    display.CreateContext();
    display.SetSwapInterval(1);
    
   



    if (glewInit() != GLEW_OK)
    {
        std::cout << "Error!" << std::endl;
    }

    
    std::cout << glGetString(GL_VERSION) << std::endl;

    float positions[] = {

           -0.5f, -0.5f, //0
            0.5f, -0.5f, //1
            0.5f,  0.5f, //2
           -0.5f,  0.5f, //3
           
    };

    unsigned int indices[] =
    {
        0, 1, 2,
        2, 3, 0
    };
    unsigned int vao;
 
    


    VertexArray va;
    VertexBuffer vb(positions, 4 * 2 * sizeof(float));
    IndexBuffer ib(indices, 6);
    VertexBufferLayout layout;
    layout.Push<float>(2);
    va.AddBuffer(vb, ib, layout);
    va.Bind();
   
    //create the layout for the buffer. Rembember that the buffer is binded

    
    
    //create index buffer
    
    
    

    //ShaderProgramSource source = ParseShader("../../../OpenGL/res/shaders/Basic.shader");
    ShaderProgramSource source = ParseShader("res/shaders/Basic.shader");


    unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
    GLCall(glUseProgram(shader));


    int location = glGetUniformLocation(shader, "u_Color");
    GLCall(glUniform4f(location, 0.3f, 0.1f, 0.3f, 1.0f));



    float r{ 0.0f };
    float increment{ 0.05f };

    /* Loop until the user closes the window */
    while (!display.ShouldCloseWindow())
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        GLCall(glUseProgram(shader));
        
        GLCall(glUniform4f(location, r, 0.1f, 0.3f, 1.0f));
        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

        r += increment;

        if (r > 1.0f)
            increment = -0.05f;
        else if (r < 0.0f)
            increment = 0.05f;

        /* Swap front and back buffers */
        display.SwapBuffers();

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shader);
    return 0;
}




#endif // !_OpenGL_Application_CPP_

