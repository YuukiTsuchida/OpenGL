#include <iostream>
#include <boost/format.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


static void error_callback( int error, const char* description )
{
    std::cerr << boost::format( "%1%( %2% )" ) % description % error << std::endl;
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    std::cout <<  boost::format( "width : %1% height %2%" ) % width % height << std::endl;
    glViewport(0, 0, width, height);
}

int main(int argc, const char * argv[]) 
{
    glfwSetErrorCallback( error_callback );

    if( !glfwInit() )
    {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_RED_BITS, 8);
    glfwWindowHint(GLFW_GREEN_BITS, 8);
    glfwWindowHint(GLFW_BLUE_BITS, 8);
    glfwWindowHint(GLFW_ALPHA_BITS, 8);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glfwWindowHint(GLFW_STENCIL_BITS, 0);

    GLFWwindow* window = 
         glfwCreateWindow( 640, 480, "GL Sample", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent( window );
    glfwSwapInterval( 1 );

    auto glewErr = glewInit();
    if (glewErr != GLEW_OK)
    {
        puts((const char*)glewGetErrorString(glewErr));
        return 1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while( !glfwWindowShouldClose( window ) )
    {
        glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
        glClearDepth(1.0f);
        glClearStencil(0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);

        glBeginQuery(GL_TIME_ELAPSED, 1);
        glEndQuery(GL_TIME_ELAPSED);

        glfwSwapBuffers( window );
        glfwPollEvents();
    }

    glfwDestroyWindow( window );
    glfwTerminate();
    return 0;
}
