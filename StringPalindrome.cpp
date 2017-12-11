//
//  main.cpp
//  Test
//
//  Created by Ashwin V Prabhu on 8/25/17.
//  Copyright © 2017 Ashwin V Prabhu. All rights reserved.
//

//
// Question: Check if two strings are Palindrome or not
//

#include <iostream>
using namespace std;

bool IsPalindrome(const string s1, const string s2) {
    if (s1.length() != s2.length()) return false;
    size_t n = s1.length();
    for (size_t i = 0; i < n / 2; i++) {
        if (s1[i] != s2[n - i - 1])
            return false;
    }
    
    return true;
}

int main() {
    
    cout << IsPalindrome("malayalam", "malayalam");
    cout << endl;
    cout << IsPalindrome("abc", "ced");
    cout << endl;
    
    return 0;
}
