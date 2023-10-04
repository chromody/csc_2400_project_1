
#ifndef CONSECUTIVE
#define CONSECUTIVE

#include <iostream>
using namespace std;

/*
    Jesus Villanueva-Segovia
    Due on 9/8/23
    consecutive_integer.h
    this is where the subtractive gcd method is defined
*/

// --- Conesecutive

/*
    Here we:
        1. Find the minimum of the given inputs and asssign it to min
        2. Divide a by min. If the remainder == 0, then go to 3. Else go to 4.
        3. Divide b by min. If the remainder == 0, then return min.
        4. Reduce min by 1, then go to 2. 
    
    we find the smaller number between a and b and assign it to min. we check if the remainder of a/min is 0 and b/min is 0. If it is, then
    we return the #. else we subtract one from min and repeat the remainder checking.
*/

/*
    Name: gcd_consecutive(int a, int b)
    Purpose:
        this calculates the gcd using the consecutive integer method
*/
int gcd_consecutive(int a, int b) {
    // check if both are zero, to return 0. this is means undefined for the purposes for gcd.
    if ( (a == 0 && b == 0) ) {
        return 0;
    }
    
    // we check if a or b is already 0, meaning we have no work to do

    else if (a == 0) {
        return b;
    }

    else if (b == 0) {
        return a;
    }

    if (a<0) {
        a=a*(-1);
    }

    if (b<0) {
        b=b*(-1);
    }

    // finding the minimum between the inputs
    int min = a;
    if (min > b) {
        min = b;
    }

    //loop to find the largest number they both perfectly divisible by
    // bool to see if we should exit the loop
    bool passed = false;
    while ( (min >= 0) & (passed != true) ) { // while we are above 0 and we have not found the number
        if ( (a%min == 0) & (b%min == 0) ) { // checking if both are perfectly divisible by min
            passed = true; // setting passed to true to exit the while loop
        }
        else{
            --min; // else we just go down a number
        }
    }

    return min; // return that number

}

/*
    Name: print_consecutive_gcd(int a, int b)
    Purpose:
        this just prints out the gcd result
*/
void print_consecutive_gcd(int a, int b) {
    // finding the gcd
    int result = gcd_consecutive(a, b);
    //checking if gcd == 0, to output an error
    if (result == 0) {
        cout << "consecutive euler: " << " gcd(" << a << ", " << b << ") =  UNDEFINED\n";
    }
    else {
        cout << "consecutive euler: " << " gcd(" << a << ", " << b << ") = " << result << "\n";
    }
}

// ---------------------------------------

#endif