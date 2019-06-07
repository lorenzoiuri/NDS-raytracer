
#ifndef _VECTOR3
#define _VECTOR3
#include "Vector3.h"
#endif

#ifndef _HITRECORD
#define _HITRECORD
#endif

class HitRecord {

    private:

    public:
        float32 t; // distance of hit point
        Vector3* p; // coordinates of the hit point
        Vector3* n; // normal of the hit point

        // creates an ampty undefined HitRecord
        HitRecord( );

        // creates a new hit record from the arguments
        // copies the arguments, does not modify arguments
        HitRecord( float32 _t, Vector3* _p, Vector3* _n );

        ~HitRecord( );
};
