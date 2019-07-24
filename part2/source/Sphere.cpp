
#include "Sphere.h"

Sphere::Sphere( Vector3* _center, float32 _radius ) {

    center = _center->clone();
    radius = _radius;
}

Sphere::~Sphere( ) {

    delete center;
} 

bool Sphere::hit( Ray* r, float32 tmin, float32 tmax, HitRecord* hr ) {
    
    Vector3* oc = r->origin->clone();
    oc->sub(center);

    const float32 a = (r->dir)->dot(r->dir);
    const float32 b = oc->dot(r->dir);
    const float32 c = oc->dot(oc) - (radius * radius);
    const float32 discriminant = b*b - a*c;

    delete oc; 

    if (discriminant > 0) {
        float32 temp = (-b - sqrt(b*b - a*c) ) /a;

        if (temp > tmin && temp < tmax) {
            hr->t = temp;
            Vector3* pt = r->pointAtParameter(temp);
            hr->p->x = pt->x;
            hr->p->y = pt->y;
            hr->p->z = pt->z;
            delete pt;
            hr->n->subVectors(hr->p, center);
            hr->n->multiplyScalar(1.0/radius);

            return true;
        }

        temp = (-b + sqrt(b*b - a*c) ) /a;

        if (temp > tmin && temp < tmax) {
            hr->t = temp;
            Vector3* pt = r->pointAtParameter(temp);
            hr->p->x = pt->x;
            hr->p->y = pt->y;
            hr->p->z = pt->z;
            delete pt;
            hr->n->subVectors(hr->p, center);
            hr->n->multiplyScalar(1.0/radius);

            return true;
        }
    }

    return false;
}
