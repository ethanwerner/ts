// Sigmoid
//
// sigmoid - sig
//
// f(x) = ( L / ( 1 + e^( -( 4m * ( x - x_0 ) / L ) ) ) ) + b - ( L / 2 )
//
// m = f'(0)
// b = f(0)
// ( b - ( L / 2 ) ) < y < ( b + ( L / 2 ) )
//
// X_n - 1
// Y_n - 1
// C_n - 3
//
// c[0] = m
// c[1] = L
// c[2] = b


#include <tgmath.h>
#include "ts.h"


ts_parameter( sigmoid, 1, 1, 3 );


ts_function_define( sigmoid, 0 )
{
	fp_t L = ts_cast_byte( c, 0, fp_t );
	fp_t m = ts_cast_byte( c, sizeof( fp_t ), fp_t );
	fp_t b = ts_cast_byte( c, 2 * sizeof( fp_t ), fp_t );

	m = -( 4.0 * m ) / L;
    b = b - ( 0.5 * L );

	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = ( L / exp( m * x[0][i] ) ) + b;
	}
}
