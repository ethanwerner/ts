#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define TS_IMPLEMENTATION
#include "ts.h"

#define ELEMENTS 100000000

int main(void) {
    fp_t *x = calloc(ELEMENTS, sizeof( fp_t ));
    fp_t *y = calloc(ELEMENTS, sizeof( fp_t ));

    ts_fill(x, ELEMENTS, 0, 1000);

    ts_sine((fp_t * const *) &y, (fp_t const * const *) &x, ELEMENTS, NULL);

    printf("%f\n", y[ELEMENTS - 1]);
}