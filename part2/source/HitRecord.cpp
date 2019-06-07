
#include "HitRecord.h"

HitRecord::HitRecord( ) {

    t = 0;
    p = new Vector3();
    n = new Vector3();
}

HitRecord::HitRecord( float32 _t, Vector3* _p, Vector3* _n ) {

    t = _t;
    p = _p->clone();
    n = _n->clone();
}

HitRecord::~HitRecord() {

    delete p;
    delete n; 
} 
