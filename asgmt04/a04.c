#include <stdio.h>
#include <stdlib.h>

// You are only allowed to make changes to this code as specified by the comments in it.

// The code you submit must have these two values.
#define N_TIMES		600000
#define ARRAY_SIZE	 10000

int main(void)
{
	double	*array = calloc(ARRAY_SIZE, sizeof(double));
	double	sum = 0;
	int		i;

	// You can add variables between this comment ...

	// ... and this one.

	// Please change 'your name' to your actual name.
	printf("CS201 - Asgmt 4 - David Hartman\n");

	for (i = 0; i < N_TIMES; i++) {

		// You can change anything between this comment ...

		double*     j;

		for ( j = array; j != &(array[ARRAY_SIZE])-8; j +=8 ) {
            sum += *j + *(j+1) + *(j+2) + *(j+3) + *(j+4) + *(j+5) + *(j+6) +
            *(j+7);
        }

		// ... and this one. But your inner loop must do the same
		// number of additions as this one does.

		}

	// You can add some final code between this comment ...

	// ... and this one.

	return 0;
}
