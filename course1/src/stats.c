/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief a program to calculate min, max, mean, median of a set of numbers
 *
 * <Add Extended Description Here>
 *
 * @author Albara Abu Shaqra
 * @date 2/24/2019
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90, };
                                


  /* Other Variable Declarations Go Here */
  
  int max, min, mean, median;
  
  
  print_array(test);
  sort_array(test);
  max=find_maximum(test);
  min=find_minimum(test);
  mean=find_mean(test);
  median=find_median(test);
  print_statistics(max, min, mean, median);

}


  /* Statistics and Printing Functions Go Here */

int find_maximum(unsigned char *test){
    
   // a Loop to scan the array elements and store largest number to test[0]
    for(int i = 0; i < SIZE; ++i)
    {

       if(test[0] < test[i])
           test[0] = test[i];
    }
    return test[0];
 
}

int find_minimum(unsigned char *test){
    
   // a Loop to scan the array elements and store smallest number to test[0]
    for(int i = 0; i < SIZE; ++i)
    {
       if(test[0] > test[i])
           test[0] = test[i];
    }
    return test[0];

}


// function to find the mean value by summing all the numbers in the array and dividing by the number of elements
int find_mean(unsigned char *test){
int s=0;
for(int i=0; i<SIZE; ++i){
s=s+test[i];
}
int mean= s/SIZE;
return mean;
}

/* function to sort the array in ascending order by selecting
*  an element and place it to its correct position by comparing with subsequent elements.
*/

unsigned char sort_array(unsigned char *test){

  for (int i=0; i<SIZE; ++i){
         for (int j=0; j<SIZE-1; ++j){
             
             if(test[j]>test[j+1])
            {
                int temp   = test[j];
                test[j]    = test[j+1];
                test[j+1]  = temp;
            }
             
         }
     }
     return test;
}


find_median(unsigned char *test){
    
    int median=0;
    // if number of elements are even
    if(SIZE%2 == 0)
        median = (test[(SIZE-1)/2] + test[SIZE/2])/2.0;
    // if number of elements are odd
    else
        median = test[SIZE/2];
    
    return median;
}

print_statistics(int max, int min, int mean, int median){

  
    printf("\nLargest element = %d", max);
    printf("\nsmallest element = %d", min);
    printf("\nmean= %d", mean);
    printf("\nmedian= %d", median);
}

print_array(unsigned char *test){
    printf("The array is: \n");
    for(int i=0;i<SIZE;++i){
    printf("%5d",(int)test[i]);
    if((i+1)%8==0 || i+1==SIZE)
        printf("\n");
  }
    }



