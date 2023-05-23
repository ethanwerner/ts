// Multiplication
//
// multiplicaiton - mul
//
// f( x_0, x_1 ) = x_0 * x_1
//
// X_n - 2
// Y_n - 1
// C_n - 0


#include <assert.h>
#include "ts.h"


ts_parameter( multiplication, 1, 1, 0 );


ts_function_define( multiplication, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = x[0][i] * x[1][i];
	}
}
