
#ifndef _VECTOR3
#define _VECTOR3
#include "Vector3.h"
#endif

#ifndef _RAY
#define _RAY
#include "Ray.h"
#endif

#ifndef _CAMERA
#define _CAMERA
#endif

class Camera {

    private:
        Vector3* lowerLeftCorner;
        Vector3* horizontal;
        Vector3* vertical;
        Vector3* origin;

    public:

        // creates a camera with the selected vertocal fov and the aspect ratio
        Camera( float32 _vfov, float32 _aspect );

        ~Camera( );

        // returns a new ray from the camera to the image plane
        // does not modify the camera
        Ray* getRay( float32 u, float32 v );

};