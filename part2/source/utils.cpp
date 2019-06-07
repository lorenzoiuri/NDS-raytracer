
#include "utils.h"

float map(float value, float istart, float istop, float ostart, float ostop) {
    return ostart + (ostop - ostart) * (((value - istart)*1.0) / ((istop - istart)-1.0));
}