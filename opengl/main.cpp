#include "application.hpp"
#include <iostream>


int main(int argc, const char * argv[]) 
{
    application application( 640, 480, "OpenGL" );
    
    if( !application.init() )
    {
        return -1;
    }

    application.run();

    return 0;
}
