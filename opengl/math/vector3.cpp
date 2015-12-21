#include "vector3.hpp"

#include <boost/format.hpp>

#include <cmath>

namespace math
{

void vector3::zero()
{
    x_ = 0.0f;
    y_ = 0.0f;
    z_ = 0.0f;
}

std::string&& vector3::to_string() const
{
    return std::move( ( boost::format( "x( %1% ) y( %2% ) z( %3% )" ) % x_ % y_ % z_ ).str() );
}

void vector3::normalize()
{
    float len = length();
    if( len != 0 )
    {
        *this /= len;
    }
}

float vector3::length() const
{
    return std::sqrt( dot( *this ) );
}

float vector3::dot( const vector3& other ) const
{
    return ( x_ * other.x_ + y_ * other.y_ + z_ * other.z_ );
}

vector3&& vector3::cross( const vector3& other ) const
{
    return std::move( vector3(
            y_ * other.z_ - z_ * other.y_,
            z_ * other.x_ - x_ * other.z_,
            x_ * other.y_ - y_ * other.x_ ) );

}

vector3&& vector3::operator - () const
{
    return std::move( vector3( -x_, -y_, -z_ ) );
}

vector3& vector3::operator = ( const vector3& other )
{
    x_ = other.x_;
    y_ = other.y_;
    z_ = other.z_;

    return *this;
}

bool vector3::operator == ( const vector3& other ) const
{
    return ( x_ == other.x_ && y_ == other.y_ && z_ == other.z_ );
}

bool vector3::operator != ( const vector3& other ) const
{
    return !( *this == other );
}

vector3&& vector3::operator + ( const vector3& other ) const
{
    return std::move( vector3( x_ + other.x_, y_ + other.y_, z_ + other.z_ ) );
}

vector3&& vector3::operator - ( const vector3& other ) const
{
    return std::move( vector3( x_ - other.x_, y_ - other.y_, z_ - other.z_ ) );
}

vector3&& vector3::operator * ( float scala ) const
{
    return std::move( vector3( x_ * scala, y_ * scala, z_ * scala ) );
}

vector3&& vector3::operator / ( float scala ) const
{
    return std::move( vector3( x_ / scala, y_ / scala, z_ / scala ) );
}

vector3& vector3::operator += ( const vector3& other )
{
    x_ += other.x_;
    y_ += other.y_;
    z_ += other.z_;

    return *this;
}

vector3& vector3::operator -= ( const vector3& other )
{
    x_ -= other.x_;
    y_ -= other.y_;
    z_ -= other.z_;

    return *this;
}

vector3& vector3::operator *= ( float scala )
{
    x_ *= scala;
    y_ *= scala;
    z_ *= scala;

    return *this;
}

vector3& vector3::operator /= ( float scala )
{
    x_ /= scala;
    y_ /= scala;
    z_ /= scala;

    return *this;
}

float distance( const vector3& vec1, const vector3& vec2 )
{
    vector3 diff = vec1 - vec2;
    return diff.length();
}

}
