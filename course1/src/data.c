/******************************************************************************
 * Copyright (C) 2019 by Albara Abu Shaqra 
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Albara Abu Shaqra is not liable for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief provides functions that does some basic data manipulation
 * 
 *
 * @author Albara Abu Shaqra 
 * @date March 18 2019
 *
 */


#include "data.h"
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	uint8_t i = 0,rem , j , is_negative = 0 ;	
	
	if (data < 0) {is_negative = 1 ; data = data * (-1) ;}
	do{	
		rem = data % base;
		data = data / base ;

		if (rem > 9) *(ptr+i) = rem +65 - 10; // will be A,B,...
		else *(ptr+i) = rem + 48 ;
	
		i++;

	}while (data != 0);
	
	for(j=0 ; j< i/2 ; j++){
		*(ptr+i) = *(ptr+j);
		*(ptr+j) = *(ptr-j + i -1);
		*(ptr-j + i -1) = *(ptr+i) ;	
	}
	
	*(ptr+i) = '\0';
	if (is_negative){
		int k = i ;
		for (;k>= 0;k--){
			*(ptr + k +1)=*(ptr + k );
			
		}
		i++;
		*ptr = 45;
	}
	return i+1 ;
	
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){

	digits--; //dec by 1 bcz of null terminator is counted 	
	
	uint8_t is_negative = 0, i = 0  ; int32_t number = 0 ;
	uint32_t  multiplier =1 ;
	if (*ptr == 45){ // if the first character is negative sign

		is_negative = 1 ;
		i= 1 ;
		digits--; // dec by 1 bcz of -ve sign is counted
	}	
	int j;
	
	for ( j =  0 ; j < (digits -1) ; j++){
		multiplier *= base ;
	}

	ptr = ptr + i ;

	while (*ptr != '\0'){
		if (*ptr <58){ number += (*ptr - 48 ) * multiplier ; } // if digit from 0-9
		else { number += (*ptr - 55 ) * multiplier ; } // if digit is letter
	
		ptr++ ;
		multiplier = multiplier / base ;
	}
	if (is_negative){
		number *= -1 ;
	}
	
	return number ;
		
}
