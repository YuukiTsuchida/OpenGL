#include "scene_manager.hpp"

#include "scene.hpp"
#include "test_scene.hpp"


scene_manager::~scene_manager()
{
}

void scene_manager::init()
{
    push_scene<test_scene>();
}

void scene_manager::destroy()
{
    stack_clear();
}

void scene_manager::update()
{
    scene_stack.top()->update();
}

void scene_manager::draw()
{
    scene_stack.top()->draw();
}

template<class scene_type>
void scene_manager::replace_scene()
{
    stack_clear();
    push_scene<scene_type>();
}

template<class scene_type>
void scene_manager::push_scene()
{
    scene_ptr scene_instance( new scene_type );
    scene_instance->init();
    scene_stack.push( scene_instance );
}

void scene_manager::pop_scene()
{
    scene_stack.pop();
}

void scene_manager::stack_clear()
{
    while( !scene_stack.empty() )
    {
        scene_ptr scene = scene_stack.top();
        scene->destroy();

        scene_stack.pop();
    }
}
