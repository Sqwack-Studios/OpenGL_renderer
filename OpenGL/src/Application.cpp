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

#include <glew.h>
#include <glfw3.h>

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(GL_VERTEX_SHADER);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    //error handlind 
    if (!result)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = static_cast<char*>(_malloca(length * sizeof(char)));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
        std::cout << message << std::endl;

        glDeleteShader(id);
        return 0;
    }

    return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    /* Make the window's context current */
    glfwMakeContextCurrent(window);


    if (glewInit() != GLEW_OK)
    {
        std::cout << "Error!" << std::endl;
    }

    
    std::cout << glGetString(GL_VERSION) << std::endl;

    float positions[6] = {

           -0.5f, -0.5f,
            0.0f,  0.5f,
            0.5f, -0.5f
    };

    unsigned int buffer;
    //create the buffer
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), &positions, GL_STATIC_DRAW);

    //create the layout for the buffer. Rembember that the buffer is binded
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
   

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}




#endif // !_OpenGL_Application_CPP_

