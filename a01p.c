// do not change this code except in the following ways:
//   * write code for the following functions:
//      * bigOrSmallEndian()
//      * getNextHexInt()
//      * printNumberData()
//   * change studentName by changing "I. Forgot" to your actual name

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static char *studentName = "David Hartman";

// report whether machine is big or small endian
void bigOrSmallEndian()
{
    unsigned short *p = (unsigned short)0xaabb;
    printf("%x\n",p[0]);
    printf("%x\n",p[1]);
    if (p[0]>p[1])
        printf("Your system is little-endian");
    else
        printf("your system is big-endian");
}

// get next int (entered in hex) using scanf()
// returns true (success) or false (failure)
// if call succeeded, return int value via iPtr
bool getNextHexInt(unsigned int *iPtr)
{
	// replace this code with the call to scanf()
	*iPtr = 0;
	return true;
}

// print requested data for the given number
void printNumberData(int i)
{
}

// do not change this function in any way
int main(int argc, char **argv)
{
	unsigned int	i;					// number currently being analyzed
	bool			validInput;			// was user input valid?

	printf("CS201 - A01p - %s\n\n", studentName);
	bigOrSmallEndian();
	for (;;) {
		if (argc == 1)						// allow grading script to control ...
			printf("> ");					// ... whether prompt character is printed
		validInput = getNextHexInt(&i);
		printf("0x%08X\n", i);
		if (! validInput) {					// encountered bad input
			printf("bad input\n");
			while (getchar() != '\n') ;		// flush bad line from input buffer
			continue;
			}
		printNumberData(i);
		if (i == 0) {
			printf("bye...\n");
			break;
			}
		}
	printf("\n");
	return 0;
}
