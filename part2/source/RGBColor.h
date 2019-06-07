
#include "nds/ndstypes.h"

#ifndef _RGBCOLOR
#define _RGBCOLOR
#endif

class RGBColor {

    private:

    public:
        uint8 r;
        uint8 g;
        uint8 b;

        RGBColor( uint8 _r, uint8 _g, uint8 _b );

        ~RGBColor( );
};
