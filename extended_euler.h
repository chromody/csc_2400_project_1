
#ifndef EXTENDED_EULER
#define EXTENDED_EULER

#include <iostream>
using namespace std;
/*
    Jesus Villanueva-Segovia
    Due on 9/8/23
    extended_euler.h
    this is where the euler gcd method is defined


*/


// --- Euler Section
/*
    General Algorithm:
    
    gcd(a, b)
    1. if b = 0, then return a. Else proceed to step 2.
    2. find a % b. assign this to r.
    3. assign b to a, and r to b. move to 1

    For the extended version, we need to find x and y that satisfy ax + by = gcd(a, b)
    we can find x and y by simulating the recursion of the basic euler's algorithm:
        a*x + b*y = gcd(a, b)
        b*x1 + (a%b)*y1 = a*x + b*y                 -> a%b = a - floor(a/b)*b, this is the definition of the modulo function
        b*x1 + (a - floor(a/b)*b)*y1 = a*x + b*y
        b*x1 + a*y1 - floor(a/b)*b*y1 = a*x + b*y
        a*y1 + b*x1 - floor(a/b)*b*y1 = a*x + b*y
        a*y1 + b*(x1 - floor(a/b)*y1) = a*x + b*y

            a*x = a*y1
                -> x = y1
            b*y = b*(x1 - floor(a/b)*y1)
                -> y = x1 - floor(a/b)*y1
    so x = y1, and y = x1 - floor(a/b)*y1
*/

/*
    Name: gcd_euler(int a, int b)
    Purpose:
        this is the basic euler's algorithm. I added it just to think through the basic process
*/
int gcd_euler(int a, int b) {
    // base case, we stop whenever b = 0, as 0 mod anything is undefined
    if (b == 0) {
        // return a as this is the gcd
        return a;
    }
    // we find the remainder of a/b
    int r = a%b;
    a = b; // we swap a and b
    b = r; // we assign the remainder of a/b to b
    int gcd = gcd_euler(a, b); // we make a recursive call to find the gcd
    if (gcd < 0) { // if the gcd is negative, we take the absolute value of it
        gcd = -1*gcd;
    }
    return gcd; //returning the gcd
}

/*
    Name: gcd_euler_extended(int a, int b, int *x, int *y)
    Purpose:
        this is the extended euler's algorithm. We essentially do the process above but find x and y for ax+by = gcd. We do this using
        the equation explained before for x and y.
        
        we change x and y using association. this is why we require the user to pass x and y variables.
*/
int gcd_euler_extended(int a, int b, int *x, int *y) {
    // Base Case
    if (b == 0) { //gcd * 1 + 0 * 0 = gcd.
        *x = 1; // since this is the base case, then x is the gcd. so we multiply it by 1 to satisfy ax + by = gcd
        *y = 0; // if b = 0, then y might as well be 0
        return a;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcd_euler_extended(b, a%b, &x1, &y1);
    if (gcd < 0) { // absolute value of the gcd
        gcd = -1*gcd;
    }
    // Update x and y using results of recursion.
    *x = y1;
    *y = x1 - (a/b)*y1;
 
    return gcd;
}

/*
    Name: print_e_euler_gcd(int a, int b)
    Purpose:
        this just prints out the gcd result
*/
void print_e_euler_gcd(int a, int b) {
    // finding the gcd
    
    int x, y, result;
    result = gcd_euler_extended(a, b, &x, &y);

    //checking if gcd == 0, to output an error
    if (result == 0) {
        cout << "extended euler: " << " gcd(" << a << ", " << b << ") =  UNDEFINED\n";
    }
    else {
        cout << "extended euler: " << " gcd(" << a << ", " << b << ") = " 
        << result << " ---- " << "x = " << x << ", y = " << y << ": " 
        << a << "*" << x << " + " << b << "*" << y << " = " << result << "\n";
    }
}

// ---------------------------------------

#endif