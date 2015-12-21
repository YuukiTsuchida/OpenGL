#include "test_scene.hpp"
#include "math/vector3.hpp"

#include <GL/glew.h>

#include <iostream>

#include "math/matrix4.hpp"


static GLuint vertex_buffer;
static GLuint index_buffer;

test_scene::~test_scene()
{
    std::cout << "~test_scene" << std::endl;
}

void test_scene::init()
{
    constexpr math::vector3 test( 1.0f, 1.0f, 1.0f );
    constexpr math::vector3 test2( -1.0f, -1.0f, -1.0f );
//     std::cout << test.to_string() << std::endl;
//     test.zero();
//     std::cout << test.to_string() << std::endl;
    std::cout << test.dot( test2 ) << std::endl;   
    std::cout << ( test2 != test ) << std::endl;

    std::cout << "init" << std::endl;

    static const float vertices[][3] = {
        {  0.0f, 1.0f, 0.0f },
        { -0.5f, 0.0f, 0.0f },
        {  0.5f, 0.0f, 0.0f }
    };

    glGenBuffers( 1, &vertex_buffer );
    glBindBuffer( GL_ARRAY_BUFFER, vertex_buffer );
    glBufferData( GL_ARRAY_BUFFER, sizeof( vertices ), vertices, GL_STATIC_DRAW );
    glBindBuffer( GL_ARRAY_BUFFER, 0 );


    static const unsigned short indices[] = {
        0, 1, 2
    };

    glGenBuffers( 1, &index_buffer );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, index_buffer );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices, GL_STATIC_DRAW );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}

void test_scene::destroy()
{
    std::cout << "destroy" << std::endl;

    glDeleteBuffers( 1, &vertex_buffer );
    glDeleteBuffers( 1, &index_buffer );
}


void test_scene::update()
{
    
}


void test_scene::draw()
{
    glBindBuffer( GL_ARRAY_BUFFER, vertex_buffer );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, index_buffer );
    glEnableClientState( GL_VERTEX_ARRAY );
    glVertexPointer( 3, GL_FLOAT, 0, 0 );
    glDrawElements( GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, nullptr );
}
