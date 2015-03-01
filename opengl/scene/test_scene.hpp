#pragma once

#include "scene.hpp"

class test_scene : public scene
{
public:
    ~test_scene();
    virtual void init() override;
    virtual void destroy() override;
    virtual void update() override;
    virtual void draw() override;

private:
};
