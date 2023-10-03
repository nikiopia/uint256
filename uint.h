#ifndef UINT_H
#define UINT_H

// TYPEDEF
typedef unsigned int uint256[8];

// FUNCTION PROTOTYPES
/*!
 *	Print the bits of the uint array
 *	@param	value	Pointer to the uint256 object
 *	@return	void
**/
void printBits(uint256 value);

/*!
 *	Add two uint256s
 *	@param	result	Where to store the results
 *	@param	A		The first value to add
 *	@param	B		The second value to add
 *	@return	int		Carry out value
**/
int uint256_add(uint256 result, uint256 A, uint256 B);

/*!
 *	uint256 == operator
 *	@param	A		First value to compare
 *	@param	B		Second value to compare
 *	@return	int		1 -> equal
					0 -> not equal
**/
int uint256_equ(uint256 A, uint256 B);

/*!
 *	uint256 > operator
 *	@param	A		LHS of comparison
 *	@param	B		RHS of comparison
 *	@return	int		1 -> A > B
					0 -> else
**/
int uint256_gtr(uint256 A, uint256 B);

#include <stdio.h>
#include "uint.c"

#endif