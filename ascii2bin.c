/************************************/
/* Program Name: ascii2bin.c        */
/* Author: Ryan Larson              */
/* Date: 2/28/21                    */
/************************************/
/* Description:                     */
/* Validation Checks: input = 1 or 0*/
/* Enhancements:                    */
/************************************/

#include <stdio.h>
#include <unistd.h>

const unsigned long long max_num = (1ULL << 32);

int main (int argc, char * argv[], char ** envp)
{
	unsigned char offset = 0x30;
	unsigned long long number = 0;
	unsigned char ascii_value;
	unsigned char digit;

	unsigned int retval = read(0, &ascii_value, 1);
	while (retval == 1 && ascii_value != '\n' && ascii_value != '\r')
	{
		digit = ascii_value - offset;
		
		if(digit > 1 || number > max_num) // note that digit is unsigned
			return 1;
			
		number = (number << 1) + digit;  
		retval = read(0, &ascii_value, 1);
	}
		
	printf("%llu\n", number);
	return 0;
}