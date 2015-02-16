cmake_minimum_required(VERSION 2.8)

SET( CMAKE_CXX_COMPILER /usr/bin/clang++ )
add_definitions( -std=c++11 -Wall )

include_directories( ${PROJECT_SOURCE_DIR}/external/glew/include ${PROJECT_SOURCE_DIR}/external/glfw/include )

link_directories( ${PROJECT_SOURCE_DIR}/external/glew/lib ${PROJECT_SOURCE_DIR}/external/glfw/lib )
add_executable(myapp ${PROJECT_SOURCE_DIR}/opengl/main.cpp)

IF(APPLE)
    INCLUDE_DIRECTORIES( /System/Library/Frameworks )
    FIND_LIBRARY( COCOA_LIBRARY Cocoa )
    FIND_LIBRARY( OpenGL_LIBRARY OpenGL )
    FIND_LIBRARY( IOKIT_LIBRARY IOKit )
    FIND_LIBRARY( COREVIDEO_LIBRARY CoreVideo )
    MARK_AS_ADVANCED( COCOA_LIBRARY OpenGL_LIBRARY IOKIT_LIBRARY COREVIDEO_LIBRARY )
    SET( EXTRA_LIBS ${COCOA_LIBRARY} ${OpenGL_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY} )
ENDIF(APPLE)

MESSAGE( ${EXTRA_LIBS} )
target_link_libraries( myapp glew glfw3 ${EXTRA_LIBS} )
