#include <stdio.h>
#include <cs50.h> // GetInt()

int main(void)
{
	// get user input
	int n; // pyramid height
	do {
		printf("Input half-pyramid height between 1 and 23:\n");
		n = GetInt();
	}
	while (n <= 0 || n >= 24); // number ranging from 1 to 23, loop until get

	// draw half-pyramid
	printf("Height: %d\n", n);
	char block = '@'; // pyramid building block, char in single quotes
	int i, j, spaces = n-1, spaceCount;
	for(i = 1; i <= n; i++) { // starts at second row with 2 blocks
		for(spaceCount = spaces; spaceCount >= 1; spaceCount--) {
			printf("  "); // double space
		}
		for(j = 0; j <= i; j++) {
			printf("%2c", block); // %2c because double space
		}
		printf("\n");
		spaces--; // decrease number of spaces by 1 for next line
	}
	return 0; // end main
}