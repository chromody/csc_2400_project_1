#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <time.h>
#include "extended_euler.h"
#include "consecutive_integer.h"
#include "middle-school.h"
using namespace std;

void test_gcd(int (*method)(int, int), int size, int (* const array)[2]){
    srand(time(NULL));
    string pass = "PASSED";
    for (int i = 0; i < size; ++i) {
        int a = method(array[i][0], array[i][1]);
        int b = __gcd(array[i][0], array[i][1]);
        if (a!=b) {
            cout << a << ":" << b << "FAILED" << "\n";
            pass = "FAILED";
        }
    }
    cout << pass << "\n";

}

int main() {

    int g_size = 10;
    int r_size = 10000;
    const int tuple_size = 2;
    int inputs_given[g_size][tuple_size] = {{60, 24}, {24, 60}, {0, 0}, {10, 0}, {0, 10}, {13, 4}, {4, 13}, {1, 2}, {999, 132}};
    int inputs_random[r_size][tuple_size];

    for (int i = 0; i < r_size; ++i) {
        inputs_random[i][0] = rand();
        inputs_random[i][1] = rand();
    }
    

    //---               TESTING EULER
    cout << "-------------- Testing EULER\n";
    // TESTING WITH GIVEN INPUTS
    test_gcd(gcd__extended_euler, g_size, inputs_given);

    // TESTING WITH RANDOM INPUTS
    test_gcd(gcd__extended_euler, r_size, inputs_random);


    //---               TESTING CONSECUTIVE
    cout << "-------------- Testing CONSECUTIVE\n";
    // TESTING WITH GIVEN INPUTS
    test_gcd(gcd_consecutive, g_size, inputs_given);


    // TESTING WITH RANDOM INPUTS
    test_gcd(gcd_consecutive, r_size, inputs_random);

    //---               TESTING CONSECUTIVE
    cout << "-------------- Testing PRIMES\n";
    // TESTING WITH GIVEN INPUTS
    test_gcd(gcd_primes, g_size, inputs_given);


    // TESTING WITH RANDOM INPUTS
    test_gcd(gcd_primes, r_size, inputs_random);

    return 0;
}
