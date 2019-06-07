
#ifndef _VECTOR3
#define _VECTOR3
#include "Vector3.h"
#endif

#ifndef _RAY
#define _RAY
#include "Ray.h"
#endif

#ifndef _SPHERE
#define _SPHERE
#endif

class Sphere {

    private:

    public: 
        Vector3* center;
        float32 radius;

        // creates a new sphere cloning the vector3 center
        Sphere( Vector3* center, float32 radius );

        ~Sphere( );

        // returns true if the argument ray hits the sphere
        // does not modify the sphere nor the ray
        bool hit( Ray* r );

};
