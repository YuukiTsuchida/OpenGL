#include "vector2.hpp"

#include <boost/format.hpp>

#include <cmath>


namespace math
{

void vector2::zero()
{
    x_ = 0.0f;
    y_ = 0.0f;
}

std::string&& vector2::to_string() const
{
    return std::move( ( boost::format( "x( %1% ) y( %2% )" ) % x_ % y_ ).str() );
}

void vector2::normalize()
{
    float len = length();
    if( len != 0 )
    {
        *this /= len;
    }
}

float vector2::length() const
{
    return std::sqrt( dot( *this ) );
}

float vector2::dot( const vector2& other ) const
{
    return ( x_ * other.x_ + y_ * other.y_ );
}

float vector2::cross( const vector2& other ) const
{
    return ( x_ * other.y_ - y_ * other.x_ );
}

vector2&& vector2::operator - () const
{
    return std::move( vector2( -x_, -y_ ) );
}

vector2& vector2::operator = ( const vector2& other )
{
    x_ = other.x_;
    y_ = other.y_;

    return *this;
}

bool vector2::operator == ( const vector2& other ) const
{
    return ( x_ == other.x_ && y_ == other.y_ );
}

bool vector2::operator != ( const vector2& other ) const
{
    return !( *this == other );
}

vector2&& vector2::operator + ( const vector2& other ) const
{
    return std::move( vector2( x_ + other.x_, y_ + other.y_ ) );
}

vector2&& vector2::operator - ( const vector2& other ) const
{
    return std::move( vector2( x_ - other.x_, y_ - other.y_ ) );
}

vector2&& vector2::operator * ( float scala ) const
{
    return std::move( vector2( x_ * scala, y_ * scala ) );
}

vector2&& vector2::operator / ( float scala ) const
{
    return std::move( vector2( x_ / scala, y_ / scala ) );
}

vector2& vector2::operator += ( const vector2& other )
{
    x_ += other.x_;
    y_ += other.y_;

    return *this;
}

vector2& vector2::operator -= ( const vector2& other )
{
    x_ -= other.x_;
    y_ -= other.y_;

    return *this;
}

vector2& vector2::operator *= ( float scala )
{
    x_ *= scala;
    y_ *= scala;

    return *this;
}

vector2& vector2::operator /= ( float scala )
{
    x_ /= scala;
    y_ /= scala;

    return *this;
}

}
