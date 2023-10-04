#include <iostream>
#include "extended_euler.h"
#include "consecutive_integer.h"
#include "middle-school.h"
using namespace std;
//accept 2 arguments and only integers
//should be able to use directly from command line
//  file_name a b -> output
/*
    Jesus Villanueva-Segovia
    Due on 9/1/23
    gcd-assignment-csc-240-002.cpp
    this is just where the user interfaces with the gcd methods
*/

int main(int argc, char *argv[]) {
    if (argc == 3) {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        // printing out each one
        print_e_euler_gcd(a, b);
        print_consecutive_gcd(a, b);
        print_prime_gcd(a, b);
    }
    else {
        cout << "wrong # of inputs";
    }
    return 0;
}
