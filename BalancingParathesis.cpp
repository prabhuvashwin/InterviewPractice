//
//  main.cpp
//  Test
//
//  Created by Ashwin V Prabhu on 8/25/17.
//  Copyright © 2017 Ashwin V Prabhu. All rights reserved.
//

//
// Question: Balancing Parathesis
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool ArePair(char opening, char closing) {
    if (opening == '{' && closing == '}') return true;
    else if (opening == '[' && closing == ']') return true;
    else if (opening == '(' && closing == ')') return true;
    return false;
}

bool BalancingParanthesis(string s) {
    vector<char> v = {};
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            v.push_back(s[i]);
        else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
            if (v.empty() || !ArePair(v.back(), s[i]))
                return false;
            else
                v.pop_back();
        }
    }
    return v.empty() ? true : false;
}

int main() {
    
    string s = "({a}-{b}+[c])";
    string s1 = "({a}-{b}+c])";
    string s2 = "({a}-{b}+[c]";
    string s3 = "{a}-{b}+[c])";
    
    cout << BalancingParanthesis(s) << endl;
    cout << BalancingParanthesis(s1) << endl;
    cout << BalancingParanthesis(s2) << endl;
    cout << BalancingParanthesis(s3) << endl;
    
    return 0;
}
