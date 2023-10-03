#include "uint.h"

void printBits(uint256 value) {
	// Print the 3 uints
	char uint_bits[33];
	char currentBit;
	unsigned int temp;
	for (int i = 0; i < 8; ++i) {
		temp = value[i];
		for (int j = 31; j >= 0; --j) {
			// Populate from LSB to MSB
			currentBit = (temp % 2) + 48;
			uint_bits[j] = currentBit;
			temp = temp >> 1;
		}
		uint_bits[32] = '\0'; // Guarantee string ending
		printf("[%d]: %s\n",&value[i],uint_bits);
	}
	printf("\n");
}

int uint256_add(uint256 result, uint256 A, uint256 B) {
	int carryIn = 0; // No carry-in on bottom bytes
	int carryOccurs;
	for (int i = 7; i >= 0; --i) {
		// Time to determine if a carry will occur for this
		// operation and account for it here
		// carryOccurs = A + B >= 0x100000000, might overflow
		// ... = (A + B) / 2 >= 0x80000000 - (LSB(A) && LSB(B)), wont overflow
		//		  A / 2 is approx: A >> 1	  ^ account for if both LSBs are 1
		// ... = (A >> 1) + (B >> 1) >= 0x80000000 - (LSB(A) && LSB(B))
		carryOccurs = (A[i] >> 1) + (B[i] >> 1) + carryIn >= 
			0x80000000 - ((A[i] % 2) && (B[i] % 2));
		
		result[i] = A[i] + B[i] + carryIn;
		carryIn = carryOccurs;
	}
	return carryIn;
}

int uint256_equ(uint256 A, uint256 B) {
	int equal = 1;
	for (int i = 0; i < 8; ++i) {
		equal = equal && (A[i] == B[i]);
	}
	return equal;
}

int uint256_gtr(uint256 A, uint256 B) {
	int i = 0;
	while (A[i] == B[i]) { i++; }
	if (A[i] > B[i]) { return 1; }
	return 0;
}