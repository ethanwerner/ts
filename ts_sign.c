// Sign
//
// sign - sgn
//
//          ⎧ -1 if x < 0
// f( x ) = ⎨  0 if x = 0
//          ⎩  1 if x > 0
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include "ts.h"


ts_parameter( sign, 1, 1, 0 );


ts_function_define( sign, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = ( x[0][i] > 0 ) - ( x[0][i] < 0 );
	}
}
