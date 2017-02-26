#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// do not change anything above this comment

double hullSpeed(double lgth)
{
	// here you will compute the hull speed for the specified boat length,
	// implementing the numerical computation in GNU Assembly Language
	// through use of FPU instructions (do NOT call sqrt() from math.h)
    double  hullLength  = lgth;
    double  hullSpeed   = 0.0;
    double  hullConst   = 1.34;
    asm (
            "fldl   %[hullLengthIn]     \n"
            "fsqrt                      \n"
            "fldl   %[hullConst]         \n"
            "fmulp                      \n"
            "fstl   %[hullSpeedOut]     \n"

            :[hullSpeedOut] "=m"    (hullSpeed)
            :[hullLengthIn] "m"     (hullLength),
             [hullConst]    "m"     (hullConst)
        );
	return hullSpeed;
}

// do not change anything below this comment, except for printing out your name

double hullSpeedC(double lgth)
{
	// this C implementation of the hull speed computation is provided
	// so you can compare its correct results with the results of your code

	return 1.34 * sqrt(lgth);
}

int main (int argc, char **argv)
{
	double	lgth;
	double	hullSpd, hullSpdC;

	printf("CS201 - Assignment 02 - David Hartman\n");
	if (argc != 2) {
		printf("need 1 argument: boat length\n");
		return -1;
		}
	lgth = atof(argv[1]);
	hullSpd = hullSpeed(lgth);
	hullSpdC = hullSpeedC(lgth);

	printf("hullSpeed(%.0f) = %.3f, %.3f\n", lgth, hullSpd, hullSpdC);

	return 0;
}
