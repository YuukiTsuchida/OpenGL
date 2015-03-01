cmake_minimum_required(VERSION 2.8)

#SET( CMAKE_CXX_COMPILER /usr/bin/clang++ )
#add_definitions( -std=c++11 -Wall )
SET( CMAKE_CXX_COMPILER $ENV{HOME}/clang3.5/bin/clang++ )
add_definitions( -std=c++14 -Wall )

SET( GLEW ${PROJECT_SOURCE_DIR}/external/glew )
SET( GLFW ${PROJECT_SOURCE_DIR}/external/glfw )
SET( FREETYPE ${PROJECT_SOURCE_DIR}/external/freetype )
SET( BOOST ${PROJECT_SOURCE_DIR}/external/boost )

include_directories( ${GLEW}/include ${GLFW}/include ${BOOST}/include ${FREETYPE}/include )

link_directories( ${GLEW}/lib ${GLFW}/lib ${FREETYPE}/lib )

file( GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/opengl/*" )
add_executable(myapp ${SOURCES} )

IF(APPLE)
    #    include_directories( /System/Library/Frameworks )
    find_library( COCOA_LIBRARY Cocoa )
    find_library( OpenGL_LIBRARY OpenGL )
    find_library( IOKIT_LIBRARY IOKit )
    find_library( COREVIDEO_LIBRARY CoreVideo )
    SET( EXTRA_LIBS ${COCOA_LIBRARY} ${OpenGL_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY} )
ENDIF(APPLE)

message( ${EXTRA_LIBS} )
target_link_libraries( myapp glew glfw3 ${EXTRA_LIBS} )
