#pragma once

#include <boost/variant.hpp>

#include <list>
#include <stack>

class scene;

class scene_manager
{
public:
    ~scene_manager();    
    void init();
    void destroy();
    void update();
    void draw();

private:
    template<class scene_type>
    void replace_scene();

    template<class scene_type>
    void push_scene();

    void pop_scene();

    /*===========================================================================*/
    /**
     * sceneスタックをクリアする.
     */
    void stack_clear();

private:
    using scene_ptr = std::shared_ptr<scene>;
    std::stack<scene_ptr>   scene_stack;
};
