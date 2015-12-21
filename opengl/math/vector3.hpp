#pragma once

#include <string>

namespace math 
{
   class vector3
   {
   public:
        constexpr vector3( float x = 0.0f, float y = 0.0f, float z = 0.0f ) :
            x_( x ), y_( y ), z_( z ) {}

        constexpr vector3( const vector3& other ) :
            x_( other.x_ ),
            y_( other.y_ ),
            z_( other.z_ )
       {}

        void zero();
        std::string&& to_string() const;

        void normalize();
        float length() const;
        float dot( const vector3& other ) const;
        vector3&& cross( const vector3& other ) const;

        vector3&& operator - () const;

        vector3& operator = ( const vector3& other );
        bool operator == ( const vector3& other ) const;
        bool operator != ( const vector3& other ) const;

        vector3&& operator + ( const vector3& other ) const;
        vector3&& operator - ( const vector3& other ) const;
        vector3&& operator * ( float scala ) const;
        vector3&& operator / ( float scala ) const;

        vector3& operator += ( const vector3& other );
        vector3& operator -= ( const vector3& other );
        vector3& operator *= ( float scala );
        vector3& operator /= ( float scala );

   public:
        float x_;
        float y_;
        float z_;
   };

   float distance( const vector3& vec1, const vector3& vec2 );

} // namespace math
