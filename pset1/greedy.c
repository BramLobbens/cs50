#include <stdio.h>
#include <cs50.h> // GetFloat(), GetInt() link with '-lcs50'
#include <math.h> // link with '-lm'

// Assume only coins are quarters(25¢), dimes(10¢), 
// nickels(5¢), and pennies(1¢).

int main(void)
{
	// user input
	float f;
	int s;
	do {
		printf("How much change is owed?\n");
		f = GetFloat();
		if (f == 0) {
			printf("Are you sure?\n");
			printf("('1' for yes / '2' for no): "); // buggy on non-int input
			s = GetInt();
			if (s == 1) {
				printf("Goodbye...\n");
				return 0; // end main early if selected
			}
		}
	}
	while (f <= 0);
	printf("You are owed $%.2f\n\n", f);
	printf("You receive...\n");

	// calculation of change
	// return dollar notes
	int dollar = roundf(f); // round f to nearest int
	if (dollar > f) {
		dollar -= 1; // if rounded up, detract by 1
	}
	if (dollar == 1) {
		printf("  %d dollar\n", dollar);
	} else {
		printf("  %d dollars\n", dollar);
	}

	float remainder = f - dollar; // remainder after the dollar

	// return coins
	float quarter = 0.25;
	float dime = 0.10;
	float nickel = 0.05;
	float cent = 0.01;
	float zero = 0.0;

	// quarters
	float qrtRemain = (remainder*100) / (quarter*100);
	int newQrtRemain = roundf(qrtRemain);
	if (newQrtRemain > qrtRemain) {
		newQrtRemain -= 1; // if rounded up, detract by 1
	}
	if (newQrtRemain != zero) {
		if (newQrtRemain == 1) {
			printf("  %d quarter\n", newQrtRemain);
		} else {
			printf("  %d quarters\n", newQrtRemain);
		}	
	}
	float newRemainder = remainder - (newQrtRemain * quarter);

	// dimes
	float dimeRemain = (newRemainder*100) / (dime*100);
	int newDimeRemain = roundf(dimeRemain);
	if (newDimeRemain > dimeRemain) {
		newDimeRemain -= 1; // if rounded up, detract by 1
	}
	if (newDimeRemain != zero) {
		if (newDimeRemain == 1) {
			printf("  %d dime\n", newDimeRemain);
		} else {
			printf("  %d dimes\n", newDimeRemain);
		}
	}
	float newNewRemainder = newRemainder - (newDimeRemain * dime);

	// nickels
	float nickelRemain = (newNewRemainder*100) / (nickel*100);
	int newNickelRemain = roundf(nickelRemain);
	if (newNickelRemain > nickelRemain) {
		newNickelRemain -= 1; // if rounded up, detract by 1
	}
	if (newNickelRemain != zero) {
		if (newNickelRemain == 1) {
			printf("  %d nickel\n", newNickelRemain);
		} else {
			printf("  %d nickels\n", newNickelRemain);
		}
	}
	float newNewNewRemainder = newNewRemainder - (newNickelRemain * nickel);

	// cents
	float centRemain = (newNewNewRemainder*100) / (cent*100);
	int newCentRemain = roundf(centRemain);
	if (newCentRemain != zero) {
		if (newCentRemain == 1) {
			printf("  %d cent\n", newCentRemain);
		} else {
			printf("  %d cents\n", newCentRemain);
		}
	}
	printf("\n");
	printf("Goodbye...\n");

	return 0; // end main
}