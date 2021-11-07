// 313547085 Dor Levy
#include "ex1.h"

/*
 * The is_big_endian function returns 1 in case it was compiled and run
 * on machine that operates according to big endian method.
 * otherwise, the function returns 0.
 */
int is_big_endian(){
    int num = 1;
    // Creating a pointer to num that holds the address of the variable.
    char* addressOfNum = (char*)&num;
    // In case the first byte of the address contains the LSB, it's little endian.
    if (*addressOfNum){
        return 0;
    }
    return 1;
}

/*
 * The merge_bytes function returns a word in the size of long which is built
 * from half of the bytes of the second parameter, starting with the least
 * significant byte, and the rest of the bytes of the first parameter.
 */
unsigned long merge_bytes(unsigned long x, unsigned long int y){
    // Using right shift in order to cut the right half of chars of x
    x = x>>32;
    // Using left shift in order to return x to long structure
    x = x<<32;
    // Using left shift in order to cut the left half of chars of y
    y = y<<32;
    // Using right shift in order to return y to long structure
    y = y>>32;
    unsigned long newWord;
    // Merging x and y in order to create the merged word
    newWord = y + x;
    return newWord;
}

/*
 * The put_byte function returns the first parameter after replacing the
 * w / 8 - 1 - i byte of it by the value of the second parameter.
 * the char i represents the third parameter.
 * the char w represents the size of the first parameter.
 */
unsigned long put_byte(unsigned long x, unsigned char b, int i){
    // Creating a pointer to x that holds the address of the variable.
    char* addressOfX = (char*)&x;
    // In case the machine works according to little endian, replace the 7 - i byte of the address by b
    if (!is_big_endian()){
        addressOfX[7 - i] = b;
    }
    // In case the machine works according to big endian, replace the i byte of the address by b
    else{
        addressOfX[i] = b;
    }
    return x;
}