#include <stdio.h>
#include <stdlib.h>

double distance(double x, double y) {
    
    double  distance = 0;
    double     X = x;
    double     Y = y;

    asm(
        
        "fldl       %[Xin]      \n"
        "fld        %%st        \n"
        "fmulp                  \n"
        "fldl       %[Yin]      \n"
        "fld        %%st        \n"
        "fmulp                  \n"
        "faddp                  \n"
        "fsqrt                  \n"
        "fstpl  %[distanceOut]  \n"

        : [distanceOut] "=m" (distance),
          [Xout]        "=m" (X)
        : [Xin]     "m" (X),
          [Yin]     "m" (Y)
        );
    return distance;
}

double monteCarlo(int numberOfThrows) {
    int     dartsIn = 0;
    double  pi = 0;
    for ( int i = 0; i < numberOfThrows; i++ ){
        if ( distance( drand48(),drand48() ) < 1)
            dartsIn++;
    }
    pi = 4.0*dartsIn/numberOfThrows;
    return pi;
}

int main(int argc, char** argv)
{   
    if (argc < 2)
        return 0;
    int numberOfThrows = atoi(argv[1]);
	printf("CS 201 - Final Exam - David Hartman\n");
    srand48(0);
    printf("%d darts : pi = %.10f\n", numberOfThrows,
    monteCarlo(numberOfThrows));

	return 0;
}
