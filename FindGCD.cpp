//
//  main.cpp
//  Test
//
//  Created by Ashwin V Prabhu on 8/25/17.
//  Copyright © 2017 Ashwin V Prabhu. All rights reserved.
//

//
// Question: Write a program to find GCD of two numbers A and B
//

#include <iostream>
using namespace std;

// Time complexity will be log(A + B)
// Euclidean algorithm by division: https://codility.com/media/train/10-Gcd.pdf

int FindGCD(int x, int y) {
    int A = (x > y) ? x : y;
    int B = (x < y) ? x : y;
    
    if (B == 0 && A != 0) return A;
    
    int R = A % B;
    A = B;
    B = R;
    
    return FindGCD(A, B);
    
}

int main() {
    
    cout << FindGCD(77, 91) << endl;
    
    return 0;
}
