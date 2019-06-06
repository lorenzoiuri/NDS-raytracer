
#include "Vector3.h"

class Ray {

    private:

    public:
        Vector3* origin;
        Vector3* dir;

        // creates a new ray from which direction is from _origin to _dir
        // copies the arguments
        Ray( Vector3* _origin, Vector3* _dir );

        // calculates the coordinates of a point along the ray distant t from origin
        // returns a new Vector3 which need to be deleted manually
        Vector3* pointAtParameter( float32 t );

        ~Ray();



};
