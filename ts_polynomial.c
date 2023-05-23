// Polynominal
//
// polynomial - poly
//
// f(x) = ( a_k * x^n_k ) + ( a_k-1 * x^n_k-1 ) + ... + ( a_1 * x^n_1 )
//
// X_n - 1
// Y_n - 1
// C_n - 2k + 1
//
// c[0] = k
// c[1] = a_1
// c[2] = n_1
// c[3] = a_2
// c[4] = n_2
// ---
// c[2k-1] = a_k
// c[2k] = n_k


#include <assert.h>
#include <stddef.h>
#include <string.h>
#include <tgmath.h>
#include "ts.h"


ts_parameter( polynomial, 1, 1, -1 );


ts_function_define( polynomial, 0 )
{
	assert( c != NULL );

    uint_t k = ts_cast_byte( c, 0, uint_t );
    assert( k != 0 );

    fp_t an[k][2];

    memcpy( an, ( uint8_t * ) c + sizeof( uint_t ), k * 2 );

    for( uint_t i = 0; i < n; ++i )
    {
        y[0][i] = 0;

        for( uint_t j = 0; j < k; ++j )
        {
            y[0][i] += an[j][0] * pow( x[0][i], an[j][1] );
        }
    }
}
