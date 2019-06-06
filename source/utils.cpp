
#include "utils.h"

int map(int value, int istart, int istop, int ostart, int ostop) {
    return ostart + (ostop - ostart) * (((value - istart)*1.0) / ((istop - istart)-1.0));
}