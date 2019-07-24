
#include "Sphere.h"

Sphere::Sphere( Vector3* _center, float32 _radius ) {

    center = _center->clone();
    radius = _radius;
}

Sphere::~Sphere( ) {

    delete center;
} 

bool Sphere::hit( Ray* r ) {
    
    Vector3* oc = r->origin->clone();
    oc->sub(center);

    const float32 a = (r->dir)->dot(r->dir);
    const float32 b = 2.0 * (oc->dot(r->dir));
    const float32 c = oc->dot(oc) - (radius * radius);
    const float32 discriminant = b*b - 4*a*c;

    delete oc; 

    if (discriminant > 0) {
        return true;
    }
    return false;
}
