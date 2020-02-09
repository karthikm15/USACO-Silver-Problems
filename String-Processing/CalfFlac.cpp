/*
It is said that if you give an infinite number of cows an infinite 
number of heavy-duty laptops (with very large keys), that they will 
ultimately produce all the world's great palindromes. Your job will 
be to detect these bovine beauties.

Ignore punctuation, whitespace, numbers, and case when testing for 
palindromes, but keep these extra characters around so that you can 
print them out as the answer; just consider the letters 'A-Z' and 
'a-z'.

Find any largest palindrome in a string no more than 20,000 
characters long. The largest palindrome is guaranteed to be at most 
2,000 characters long before whitespace and punctuation are removed.

PROGRAM NAME: calfflac

INPUT FORMAT:

A file with no more than 20,000 characters. The file has one or 
more lines. No line is longer than 80 characters (not counting the 
newline at the end).

SAMPLE INPUT:

Confucius say: Madam, I'm Adam.

OUTPUT FORMAT:

The first line of the output should be the length of the longest 
palindrome found. The next line or lines should be the actual text 
of the palindrome (without any surrounding white space or 
punctuation but with all other characters) printed on a line (or 
more than one line if newlines are included in the palindromic 
text). If there are multiple palindromes of longest length, output 
the one that appears first.

SAMPLE OUTPUT:

11
Madam, I'm Adam
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string name;
    string c;
    while (getline(cin, c)) {
        name += c + "~";
    }
    string str = "";
    string placeholder = "";
    int maximum = 0;
    string maxstr = "";
    for (int i = 0; i < name.length(); i++) {
        str = name[i];
        for (int j = (i+1); j < name.length(); j++) {
            str += name[j];
            placeholder = str;
            string newstr = "";
            
            for_each(placeholder.begin(), placeholder.end(), [](char & c) {
		        c = ::tolower(c);
	        });
	        
	        for (int k = 0; k < str.length(); k++) {
	            if ((!((int(placeholder[k]) >= 32) && (int(placeholder[k]) <= 47))) && 
	               (!((int(placeholder[k]) >= 58) && (int(placeholder[k]) <= 64))) &&
	               (!((int(placeholder[k]) >= 91) && (int(placeholder[k]) <= 96))) &&
	               (!((int(placeholder[k]) >= 123) && (int(placeholder[k]) <= 126)))) {
	                   newstr += placeholder[k];
	               }
	        }
	        //cout << newstr << endl;
	        int length = newstr.length();
	        bool palindrome = false;
	        for (int i=0; i < length; i++) {
	            if (newstr[i] != newstr[length-i-1]) {
	                palindrome = true;
	                break;
	            }
	        }
	        if (((!palindrome) && (maximum < newstr.length())) &&
	           ((!((int(str[0]) >= 32) && (int(str[0]) <= 47))) && 
	               (!((int(str[0]) >= 58) && (int(str[0]) <= 64))) &&
	               (!((int(str[0]) >= 91) && (int(str[0]) <= 96))) &&
	               (!((int(str[0]) >= 123) && (int(str[0]) <= 126)))))  {
	            maximum = newstr.length();
	            maxstr = str;
	        }
	        
        }
    }
    cout << maximum << endl;
    for (int i = 0; i < maxstr.length(); i++) {
        if (maxstr[i] == '~') {
            cout << endl;
        }
        else {
            cout << maxstr[i];
        }
    }
} 