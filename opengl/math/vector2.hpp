#pragma once

#include <boost/format.hpp>

#include <string>

namespace math {

    class vector2
    {
    public:
        constexpr vector2( float x = 0.0f, float y = 0.0f ) :
            x_( x ),
            y_( y )
        {}

        constexpr vector2( const vector2& other ) :
            x_( other.x_ ),
            y_( other.y_ )
        {}

        void zero();
        std::string&& to_string() const;

        void normalize();
        float length() const;
        float dot( const vector2& other ) const;
        float cross( const vector2& other ) const;

        vector2&& operator - () const;
        
        vector2& operator = ( const vector2& other );
        bool operator == ( const vector2& other ) const;
        bool operator != ( const vector2& other ) const;

        vector2&& operator + ( const vector2& other ) const;
        vector2&& operator - ( const vector2& other ) const;
        vector2&& operator * ( float scala ) const;
        vector2&& operator / ( float scala ) const;

        vector2& operator += ( const vector2& other );
        vector2& operator -= ( const vector2& other );
        vector2& operator *= ( float scala );
        vector2& operator /= ( float scala );

    public:
        float x_;
        float y_;
    };

} // namespace math
