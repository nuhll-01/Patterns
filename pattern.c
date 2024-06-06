/*********************************************************************
*                                                                    *
* Author: Erick Chavez                                               *
* Created: May 31st, 2024                                            *
*                                                                    *
* The program outputs different asterisk-based design patterns       *
*                                                                    *
* References/Citations:                                              *
*   - https://www.geeksforgeeks.org/nested-loops-in-c-with-examples/ *
*   - https://stackoverflow.com/questions/35424632/                  *
*                                                                    *
**********************************************************************/   

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

static unsigned int lines = 0; // total number of lines to print

/*

Set the number of rows/lines for printing.

Output - Initializes 'lines' based on the user input.

*/
void setLines() {
    unsigned int flag = 1;
    while (flag == 1) {
        printf("%s", "Enter number of lines: ");
        scanf("%u", &lines);

        if ((int) lines == 0) {
            puts("\nDone!\n");
            exit(0);
        }

        if ((int) lines < 0) {
            puts("\nError: Number of lines should be positive.\n");
        } else {
            flag = 0;
        }
    }
}

/*

Return the number of rows/lines set by 'setLines()'.

*/ 
int getLines() {
    return lines;
}

/*

Prints a traingle to the screen. Negative numbers are NOT allowed. 
That functionality is covered by 'setLines()'.

Output - Prints a triangular pattern  using asterisk(*) symbols.

*/
void printTriangle() { 
    unsigned int end = getLines();
    unsigned int i = 0;

    // This outer loop will print new lines until its condition is false.
    while (i < end) {
        puts(" ");
        unsigned int j = 0;
        // This inner loop will print the asterisks.
        // During each iteration, 'j' reverts back to zero and prints the number of asterisks depending on where we are in the new line.
        while (j <= i) {
            printf("%c", '*');
            ++j;
        } 
        ++i;
    }
    puts("\n");
}

/*

Prints a reverse triangle to the screen. Negative numbers are NOT allowed. 
That fucntionality is covered by 'setLines()'.

Output - Prints a reversed triangular pattern using asterisk(*) symbols.

*/
void printReverseTriangle() { 
    unsigned int end = getLines();
    unsigned int temp = 0;
    unsigned int i = 0;
   
    temp = end;

    // This outer loop will print new lines until its condition is false.
    while (i < end) {
        puts(" ");
        unsigned int j = 0;
        // In this approach, a variable 'temp' was created in order to store the value of the number rows being printed.
        // We store the value as to not affect the original, which is 'end'.
        // And to determine the number of asterisks being printed. 
        // Assuming we had 5 rows for the pattern, 'temp' will contain '5' as it's value
        // And we'll continue printing until the condition has terminated.
        // Essentially, printing out the pattern in reverse order. 
        while (j < temp) {
            printf("%c", '*');
            ++j;
        }
        --temp;
        ++i;
    }
    puts("\n");
}

/*

Prints a pyramid to the screen. Negative numbers are NOT allowed.
That functionality is covered by 'setLines()'.

Output - Prints a pyramid pattern using asterisk(*) symbols.

*/
void printPyramid() {
    unsigned int rows = getLines();
    unsigned int blank_spaces = getLines();
    unsigned int limit = 1; 

    // This outer for-loop will print new lines until the condition is false.
    for (unsigned int i = 1; i <= rows; ++i) {
        puts(" ");
        for (unsigned int j = 1; j <= blank_spaces; ++j) {
            printf("%c", ' ');
            // Checks if we have reached the end of the blank spaces before starting to print out asterisks.
            if (j == blank_spaces) {
                unsigned int counter = 0;
                // If we've reached the end, we check how many asterisks will need to be printed out.
                // Counter keeps track of the number of asterisks being printed out. 
                // Once we've reached the limit, printing out all the necessesary asterisk symbols for a particular row.
                // The limit will grow by 2 and repeat the process. This will continue until the inner-for loop terminates. 
                while (counter < limit) {
                    printf("%c", '*');
                    ++counter;
                }
                limit += 2;
                --blank_spaces;
            }
        }
    }
    puts("\n");
}

int main(int argc, char *argv[]) {  // Caller

    // check if the argument count exceeds the limit of allowed arguments
    if (argc > 2) { 
        printf("%s\n%s%i\n", "You have exceeded the number of allowed arguments.", "Required 2, passed in ", argc);
        return 1;
    }

    // check if the argument count does not equal to the number of allowed arguments 
    if (argc != 2) {
        printf("%s %s %s\n", "Error: Invalid number of arguments.", "Usage: ./pattern", argv[1]);
        return 1;
    }

    while (TRUE) {
        switch(atoi(argv[1])) {
        // case 0 terminates the program
        case 0:
            puts("Done!");
            exit(0);
        // case 1 prints a triangle
        case 1:
            setLines(); // Called Function
            printTriangle();
            break;
        // case 2 prints a reverse triangle
        case 2: 
            setLines();
            printReverseTriangle();
            break;
        // case 3 prints a pyramid
        case 3: 
            setLines();
            printPyramid();
            break;
        default:
            printf("%s %s", "Error: Invalid pattern type.", "Valid types are 1 for triangle, 2 for reverse triangle, 3 for pyramid.");
            exit(1);
        }
    }    
    return 0;
}
