/**
Bessie the cow is just learning how to convert numbers between different
bases, but she keeps making errors since she cannot easily hold a pen
between her two front hooves.

Whenever Bessie converts a number to a new base and writes down the result,
she always writes one of the digits wrong.  For example, if she converts
the number 14 into binary (i.e., base 2), the correct result should be
"1110", but she might instead write down "0110" or "1111".  Bessie never
accidentally adds or deletes digits, so she might write down a number with
a leading digit of "0" if this is the digit she gets wrong.

Given Bessie's output when converting a number N into base 2 and base 3,
please determine the correct original value of N (in base 10). You can
assume N is at most 1 billion, and that there is a unique solution for N.

Please feel welcome to consult any on-line reference you wish regarding
base-2 and base-3 numbers, if these concepts are new to you.

PROBLEM NAME: digits

INPUT FORMAT:

* Line 1: The base-2 representation of N, with one digit written
        incorrectly.

* Line 2: The base-3 representation of N, with one digit written
        incorrectly.

SAMPLE INPUT:

1010
212

INPUT DETAILS:

When Bessie incorrectly converts N into base 2, she writes down
"1010".  When she incorrectly converts N into base 3, she writes down "212".

OUTPUT FORMAT:

* Line 1: The correct value of N.

SAMPLE OUTPUT:

14

OUTPUT DETAILS:

The correct value of N is 14 ("1110" in base 2, "112" in base 3).
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib> 
#include <cmath>
using namespace std;

int main() {
    string base2, base3;
    cin >> base2 >> base3;
    //cout << base2 << " " << base3 << endl;
    vector<long long int> numbers;
    vector<long long int> numbers2;
    string placeholder = base2;
    string placeholder2 = base3;
    for (int i = 0; i < base2.length(); i++) {
        base2 = placeholder;
        long long int sum = 0;
        if (base2[i] == '0') {
            base2[i] = '1';
        }
        else {
            base2[i] = '0';
        }
        for (int j = 0; j < base2.length(); j++) {
            if (base2[j] == '1') {
               sum += pow(2, (base2.length()-1-j)); 
            }
        }
        numbers.push_back(sum);
    }
    for (int i = 0; i < base3.length(); i++) {
        base3 = placeholder2;
        long long int sum = 0;
        if (base3[i] == '0') {
            base3[i] = '1';
            for (int j = 0; j < base3.length(); j++) {
                if (base3[j] == '2') {
                    sum += 2 * pow(3, (base3.length()-1-j)); 
                }
                else if (base3[j] == '1') {
                    sum += pow(3, (base3.length()-1-j));
                }
            }
            numbers2.push_back(sum);
            sum = 0;
            base3[i] = '2';
            for (int j = 0; j < base3.length(); j++) {
                if (base3[j] == '2') {
                   sum += 2 * pow(3, (base3.length()-1-j)); 
                }
                else if (base3[j] == '1') {
                    sum += pow(3, (base3.length()-1-j));
                }
            }
            numbers2.push_back(sum);
        }
        else if (base3[i] == '1') {
            base3[i] = '2';
            for (int j = 0; j < base3.length(); j++) {
                if (base3[j] == '2') {
                   sum += 2 * pow(3, (base3.length()-1-j)); 
                }
                else if (base3[j] == '1') {
                    sum += pow(3, (base3.length()-1-j));
                }
            }
            numbers2.push_back(sum);
            sum = 0;
            base3[i] = '0';
            for (int j = 0; j < base3.length(); j++) {
                if (base3[j] == '2') {
                   sum += 2 * pow(3, (base3.length()-1-j)); 
                }
                else if (base3[j] == '1') {
                    sum += pow(3, (base3.length()-1-j));
                }
            }
            numbers2.push_back(sum);
        }
        else {
            base3[i] = '1';
            for (int j = 0; j < base3.length(); j++) {
                if (base3[j] == '2') {
                   sum += 2 * pow(3, (base3.length()-1-j)); 
                }
                else if (base3[j] == '1') {
                    sum += pow(3, (base3.length()-1-j));
                }
            }
            numbers2.push_back(sum);
            sum = 0;
            base3[i] = '0';
            for (int j = 0; j < base3.length(); j++) {
                if (base3[j] == '2') {
                   sum += 2 * pow(3, (base3.length()-1-j)); 
                }
                else if (base3[j] == '1') {
                    sum += pow(3, (base3.length()-1-j));
                }
            }
            numbers2.push_back(sum);
        }
    }
    for (vector<long long int>:: iterator i = numbers2.begin(); i != numbers2.end(); i++) {
        bool isTrue = false;
        for (vector<long long int>:: iterator j = numbers.begin(); j != numbers.end(); j++) {
            if ((*i) == (*j)) {
                cout << (*i) << endl;
                isTrue = true;
                break;
            }
        }
        if (isTrue) {
            break;
        }
    }
}