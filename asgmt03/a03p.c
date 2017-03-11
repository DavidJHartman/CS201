// Numbers from command line arguments are sent to child process
// from parent process one at a time through pipe.
//
// Child process adds up numbers sent through pipe.
//
// Child process returns sum of numbers to parent process.
//
// Parent process prints sum of numbers.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int fd[2];

int main(int argc, char **argv)
{
	// set up pipe
    pipe(fd);
	// call fork()
	printf("CS201 - Assignment 3 Premium - David Hartman\n");
    pid_t childPid;

    if ( ( childPid = fork() ) == -1) {
        perror("fork");
        return -1;
    }

	if ( childPid == 0 ) {
		// -- running in child process --
		int     sum = 0;

		// Receive characters from parent process via pipe
		// one at a time, and count them.

        for ( int i = 0; i < argc-1; i++){
            int readInt;
            read(fd[0], &readInt, sizeof(readInt));
            sum += readInt;
        }
		// Return sum of numbers.
        write(fd[1], &sum, sizeof(sum)); 
		return sum;
		}
	else {
		// -- running in parent process --
		int sum = 0;
        int status = 0;
        int ints[argc-1];
        sleep(1);

		// Send numbers (datatype: int, 4 bytes) from command line arguments
		// starting with argv[1] one at a time through pipe to child process.
        for ( int i = 0; i < argc-1; i++) {
            ints[i] = atoi(argv[i+1]);
            write(fd[1], &ints[i], sizeof(ints[i]));
            sleep(1);
        }
		// Wait for child process to return. Reap child process.
		// Receive sum of numbers via the value returned when
		// the child process is reaped.
        
        read(fd[0], &sum, sizeof(sum));
        waitpid(childPid, &status, 0);
        
		printf("sum = %d\n", sum);
		return 0;
		}
}
