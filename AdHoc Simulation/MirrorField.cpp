/**
Mirror Field
============

Farmer John has left some old mirrors sitting outside his house, and his
cows, feeling mischievous as always, have stolen them!  

The cows have set up the mirrors in a rectangular field measuring N by M
squares (1 <= N, M <= 1,000).  In each square, they have placed a double
sided mirror between two of its opposite corners.  These two possible
configurations are represented by the '/' character (a mirror connecting
the lower-left corner to the upper-right corner) and the '\' character (a
mirror connecting the upper-left corner to the lower-right corner).

One evening, Bessie the cow brings a laser pointer out to the mirror field.
Standing outside the field, she shines the beam of light either
horizontally or vertically along either a row or column of the field,
causing it to bounce on mirrors. Since the mirrors are all diagonally
oriented, a horizontal beam of light that reflects off a mirror will end 
up traveling vertically, and vice versa. Bessie wonders what is the maximum
number of bounces on mirrors on which her beam of light can be reflected
at the same time. Given the layout of the mirror field, please help Bessie
compute this number.

PROBLEM NAME: mirror

INPUT FORMAT:

* Line 1: The integers N and M, separated by a space.

* Lines 2..1+N: Each line will contain M '/' or '\' characters,
        describing a row of the mirror field.

SAMPLE INPUT:

3 3
/\\
\\\
/\/

OUTPUT FORMAT:

* Line 1: A single integer indicating the maximum number of times a
        horizontal or vertical beam originating outside the mirror
        field could be reflected. Please output -1 if it could be
        reflected indefinitely.

SAMPLE OUTPUT:

3

OUTPUT DETAILS:

Bessie can shine the beam downwards above the middle column of her
field to have it reflected 3 times.
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