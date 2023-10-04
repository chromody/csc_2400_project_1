
#ifndef MIDDLE_SCHOOL
#define MIDDLE_SCHOOL

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
    Jesus Villanueva-Segovia
    Due on 9/8/23
    middle-school.h
    this is where the prime gcd method is defined
*/


// --- Primes
/*
    This method is possibly the simplest to do by hand. It is commonly taught in middle school. We effectively find the prime
    factorization of both numbers, and multiply the common primes togethor.

    Middle School Procedure to find gcd(a, b)
    1. find prime factorization of a
    2. find prime factorization of b
    3. identify the common factors in the two prime expansions and collect them
    4. compute the product of those factors and return it as the gcd
*/

/*
    Name: MatchValues
    Purpose:
        We find the common values in two given vectors

        here we simply compare each value in the smaller list against each value in the larger list. if we find the value,
        we add that value to a commonValues vector, and then we remove that element from the larger array. 
*/
vector<int> MatchValues(vector<int> a, vector <int> b) {
    //vector containing those common elements
    vector<int> commonValues;

    //we want to find the smaller vector and larger vector
    //this helps simplify checking for common values
    vector<int> smallerVector = a;
    vector<int> largerVector = b;

    if (a.size() > b.size()) {
        vector<int> smallerVector = b;
        vector<int> largerVector = a;
    }

    //a for loop iterating through the smaller vector and checking for the same elements in the other vector
    for (auto i = smallerVector.begin(); i < smallerVector.end(); ++i) {
        //iterator for the while loop going through the larger vector
        auto j = largerVector.begin(); 
        //bool to tell us when to stop
        bool found = false;
        while ( (j != largerVector.end()) & (!found)) { //while we havent reached the end and havent found the value
            if (*i == *j) { // checking if the current element in the smaller array is equal to the current element in the other array
                commonValues.push_back(*j); // add that value to the vector containing common values
                largerVector.erase(j); // erase that found value in the other array to prevent recounting values
                found = true; // declaring that we want to exit the loop
            }
            else {
                ++j; // else we go forward in the larger array
            }
        }
    }

    return commonValues; // return that array
}

/*
    Name: PrimeFactors
    Purpose:
        this finds the primes of a passed number, and returns a vector containing each one
*/
vector<int> PrimeFactors(int n) {
    // vector that will contain those prime numbers
    vector<int> primeFactors;

    // checking how many times we can divide n by 2, and adding it to the vector
    while (n%2 == 0){
        primeFactors.push_back(2);
        n = n/2; // dividing n by 2 to ensure we do not unnecessarily add a 2 
    }

    // checking what other prime numbers n is divisible by, starting at 3. we skip even numbers by incrementing by 2.
    for (int i = 3; i <= sqrt(n); i = i+2){ // we stop before the square root of n
        while (n%i == 0){ // checking if n is divisible by the current iteration
            primeFactors.push_back(i); // if so, we add it to the vector
            n = n/i; // remove that number from the list once by assigning n = n / i
        }
   }
   // after all of that, if n is still greater than 2, then that itself is a prime number
    if (n > 2) {
    primeFactors.push_back(n);
   }

    //return that vector of collected prime numbers
    return primeFactors;
}

/*
    Name: gcd_primes(int a, int b)
    Purpose:
        This is the prime factorization method for gcd.
*/
int gcd_primes(int a, int b) {
    //checking if both are 0 to return 0. this indicates an error
    if ( (a == 0) & (b == 0) ) {
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

    //finding the prime factorization of a and b. we store this as a vector.
    vector<int> a_primes = PrimeFactors(a);
    vector<int> b_primes = PrimeFactors(b);

    //finding the common prime values between those prime factorizations
    vector<int> commonPrimes = MatchValues(a_primes, b_primes);

    //multiplying out each prime in commonPrimes
    int gcd = 1;
    for (auto i = commonPrimes.begin(); i < commonPrimes.end(); ++i) {
        gcd = gcd * *i;
    }

    return gcd;
}

/*
    Name: print_prime_gcd(int a, int b)
    Purpose:
        this just prints out the gcd result
*/
void print_prime_gcd(int a, int b) {
    // finding the gcd
    int result = gcd_primes(a, b);
    //checking if gcd == 0, to output an error
    if (result == 0) {
        cout << "prime method: " << " gcd(" << a << ", " << b << ") =  UNDEFINED\n";
    }
    else {
        cout << "prime method: " << " gcd(" << a << ", " << b << ") = " << result << "\n";
    }
}

// ---------------------------------------

#endif