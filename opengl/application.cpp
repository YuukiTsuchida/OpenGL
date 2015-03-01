#include "application.hpp"

#include "scene/scene_manager.hpp"

#include <boost/format.hpp>

#include <iostream>

application::application( int width, int height, const char* title ) :
    window_param_( width, height, title ),
    window_( nullptr )
{}

bool application::init()
{
    glfwSetErrorCallback( []( int error, const char* discription ){
                std::cerr << boost::format( "%1%(%2%)" ) % error % discription << std::endl;
            } );

    if( !glfwInit() )
    {
        return false;
    }

    return true;
}


void application::run()
{
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode( monitor );

    std::cout << boost::format( "red(%1%) blue(%2%) green(%3%) refreshRate(%4%)" )  %
                                                                    mode->redBits   %
                                                                    mode->blueBits  %
                                                                    mode->greenBits %
                                                                    mode->refreshRate << std::endl;


    glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );
    glfwWindowHint( GLFW_RED_BITS, mode->redBits );
    glfwWindowHint( GLFW_GREEN_BITS, mode->greenBits );
    glfwWindowHint( GLFW_BLUE_BITS, mode->blueBits );
    glfwWindowHint( GLFW_ALPHA_BITS, 8 );
    glfwWindowHint( GLFW_DEPTH_BITS, 24 );
    glfwWindowHint( GLFW_REFRESH_RATE, mode->refreshRate );

    window_ = glfwCreateWindow( window_param_.width_, window_param_.height_, window_param_.title_.c_str(), nullptr, nullptr );
    if( !window_ )
    {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent( window_ );
    glfwSwapInterval( 1 );

    GLenum error = glewInit();
    if( glewInit() != GLEW_OK )
    {
        std::cout << glewGetErrorString( error ) << std::endl;
    }

    scene_manager scene_manager; 
    scene_manager.init();

    glViewport( 0, 0, window_param_.width_, window_param_.height_ );
    while( !glfwWindowShouldClose( window_ ) )
    {
        glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
        glClearDepth( 1.0f );
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);

        scene_manager.update();
        scene_manager.draw();
        // 速度の測定
//         glBeginQuery(GL_TIME_ELAPSED, 1);
//         glEndQuery(GL_TIME_ELAPSED);

        glFinish();
        glfwSwapBuffers( window_ );
        glfwPollEvents();
    }

    scene_manager.destroy();
    glfwDestroyWindow( window_ );
    glfwTerminate();
}



void application::display()
{

}

/*========= End of File =====================================================*/

