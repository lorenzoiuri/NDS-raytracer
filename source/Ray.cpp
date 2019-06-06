
#include "Ray.h"

Ray::Ray(  Vector3* _origin, Vector3* _dir ) {

    origin = _origin->clone();
    dir = _dir->clone();
}

Vector3* Ray::pointAtParameter( float32 t ) {

    Vector3* result = dir->clone();
    result->multiplyScalar(t);
    result->add(origin);
    return result;
}

Ray::~Ray() {

    delete origin;
    delete dir; 
} 