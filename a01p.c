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
    printf("byte order: ");

    unsigned short i = (short)0xAABB;
    char*          p;

    p = (char*)&i;

    if (p[0]>p[1]) 
        printf("little-endian\n");
    else
        printf("big-endian\n");
}

// get next int (entered in hex) using scanf()
// returns true (success) or false (failure)
// if call succeeded, return int value via iPtr
bool getNextHexInt(unsigned int *iPtr)
{
	// replace this code with the call to scanf()
	return scanf("%X",iPtr);
}

// print requested data for the given number
void printNumberData(int i)
{
    int signBitMask = 1 << ((sizeof(int)*8-1));
    int expBitMask  = 
    printf("signBit: %i, ",i&signBitMask ? 1 : 0);

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
