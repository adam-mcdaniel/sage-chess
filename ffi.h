/*
* This file contains the implementations of the FFI functions that are called from the Sage code.
* The functions are defined with the __ prefix to avoid name collisions with the user-defined functions.
*/

#include <sys/time.h>

void __count_bits() {
    // Use the builtin function to count the number of set bits in the integer
    ffi_ptr[0].i = __builtin_popcountll(ffi_ptr[0].i);
}

// Get the current time since epoch in microseconds
void __get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    ffi_ptr++;
    // Store the time in microseconds in the cell in the FFI memory
    ffi_ptr[0].i = tv.tv_sec * 1000000 + tv.tv_usec;
}