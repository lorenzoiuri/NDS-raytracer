
#include "nds/ndstypes.h"
#include "math.h"

#ifndef _VECTOR3
#define _VECTOR3
#endif

class Vector3 {

    private:

    public:
        float32 x;
        float32 y;
        float32 z;

        Vector3( );
        Vector3( float32 _x, float32 _y, float32 _z );

        // returns a pointer to a Vector3 allocated by new
        Vector3* clone();

        // modifies the current Vector3 multipliyng each component by f
        void multiplyScalar( float32 f );

        // modifies the current Vector3 adding it to n
        void add( Vector3* n );

        // modifies the current Vector3 subtracting it n
        void sub( Vector3* n );

        // modifies the current Vector3 normalizing it
        void normalize( );

        // does not modify the vectors
        float32 dot( Vector3* b );


};
