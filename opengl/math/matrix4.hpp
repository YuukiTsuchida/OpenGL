#pragma once


#include <array>

namespace math
{
    class matrix4
    {
    public:
        matrix4( float m11, float m12, float m13, float m14,
                 float m21, float m22, float m23, float m24,
                 float m31, float m32, float m33, float m34,
                 float m41, float m42, float m43, float m44 ) 
        {
        }

    private:
        std::array< std::array< float, 4 >, 4 > mat;
    };

}
