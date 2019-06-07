
#include "Vector3.h"


Vector3::Vector3() {
    x = 0.0; y = 0.0; z = 0.0;
}

Vector3::Vector3( float32 _x, float32 _y, float32 _z ) {
    x = _x; y = _y; z = _z;
}
 
Vector3* Vector3::clone( ) {
    Vector3* n = new Vector3();
    n->x = x; n->y = y; n->z = z;
    return n;
}

void Vector3::multiplyScalar( float32 f ) {
    x *= f;
    y *= f;
    z *= f;
}

void Vector3::add( Vector3* n ) {
    x += n->x;
    y += n->y;
    z += n->z;
}

void Vector3::sub( Vector3* n ) {
    x -= n->x;
    y -= n->y;
    z -= n->z;
}

void Vector3::normalize( ) {
	float32 magnitude = sqrt( (x * x) + (y * y) + (z * z) );
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
}

float32 Vector3::dot( Vector3* b ) {
    float32 ret = (x * b->x) + (y * b->y) + (z * b->z);
    return ret;
}
