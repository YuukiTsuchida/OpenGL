#pragma once


class scene
{
public:
    virtual ~scene(){}
    virtual void init() = 0;
    virtual void destroy() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
};
