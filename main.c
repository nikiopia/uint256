#include "uint.h"

int main(int argc, char** argv) {
	uint256 data1;
	uint256 data2;
	
	data1[0] = 0;
	data1[1] = 0;
	data1[2] = 0;
	data1[3] = 0;
	data1[4] = 0;
	data1[5] = 0;
	data1[6] = 0x80000000;
	data1[7] = 0x8000001F;
	
	data2[0] = 0;
	data2[1] = 0;
	data2[2] = 0;
	data2[3] = 0;
	data2[4] = 0;
	data2[5] = 0;
	data2[6] = 0x80000000;
	data2[7] = 0x800000F0;
	
	printBits(data1);
	printBits(data2);
	
	uint256_add(data1, data1, data2); // data1 = data1 + data2
	printBits(data1);
	
	return 0;
}