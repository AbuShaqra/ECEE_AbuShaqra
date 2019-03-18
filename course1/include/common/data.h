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
 * @file data.h
 * @brief  provides functions that does some basic data manipulation
 *
 * @author Albara Abu Shaqra 
 * @date March 18 2019
 *
 */

#ifndef __DATA_H__ 
#define __DATA_H__

#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

/**
 * @brief  function will convert data from standard integer to ASCII string
 *
 * Note: the passed pointer ptr has to be previouly defined
 *
 * @param data signed 32-bit integer that will be converted
 * @param ptr char pointer that the converted data will be allocated to
 * @param base is the base i will convert to (2 to 16)
 * 
 * @return the length of the converted data including NULL reminator
 *
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief  function will convert data from  ASCII string to standard integer
 *
 * 
 * If you are using base more than 10, letters must be UPPER CASE
 *
 * @param digits number of digits in my string
 * @param ptr char pointer that has the number to be converted
 * @param base is the base i will convert from (2 to 16)
 * 
 * @return the length of the converted data including NULL terminator
 *
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


#endif /* __DATA_H__ */
