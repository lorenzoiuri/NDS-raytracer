
#include "Camera.h"

Camera::Camera( float32 _vfov, float32 _aspect ) {

    const float32 halfHeight = tan( _vfov / 2.0 );
    const float32 halfWidth = halfHeight * _aspect;

    lowerLeftCorner = new Vector3( -halfWidth, -halfHeight, -1 );
    horizontal = new Vector3( 2.0*halfWidth, 0, 0 );
    vertical = new Vector3 (0, 2.0*halfHeight, 0 );
    origin = new Vector3(0.0,0.0,0.0);
}

Camera::~Camera( ) {

    delete lowerLeftCorner;
    delete horizontal;
    delete vertical;
    delete origin;
}

Ray* Camera::getRay( float32 u, float32 v ) {

    Vector3* hor = horizontal->clone();
    hor->multiplyScalar( u );

    Vector3* vert = vertical->clone();
    vert->multiplyScalar( v );

    Vector3* dir = lowerLeftCorner->clone();
    Vector3* orig = origin->clone();

    dir->add( hor );
    dir->add( vert );
    dir->sub( origin );

    Ray* ret = new Ray( orig, dir );

    delete hor;
    delete vert;
    delete dir; 
    delete orig;

    return ret;
}
