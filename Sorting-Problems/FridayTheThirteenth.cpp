/*
Is Friday the 13th really an unusual event?

That is, does the 13th of the month land on a Friday less often than on 
any other day of the week? To answer this question, write a program that 
will compute the frequency that the 13th of each month lands on 
Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, and Saturday 
over a given period of N years. The time period to test will be from 
January 1, 1900 to December 31, 1900+N-1 for a given number of years, N. 
N is non-negative and will not exceed 400.

There are few facts you need to know before you can solve this problem:

    * January 1, 1900 was on a Monday.
    * Thirty days has September, April, June, and November, all the rest 
    have 31 except for February which has 28 except in leap years when it has 29.
    * Every year evenly divisible by 4 is a leap year 
    (1992 = 4*498 so 1992 will be a leap year, but the year 1990 is not a leap year)
    * The rule above does not hold for century years. Century years divisible 
    by 400 are leap years, all other are not. Thus, the century years 
    1700, 1800, 1900 and 2100 are not leap years, but 2000 is a leap year. 

Do not use any built-in date functions in your computer language.

Don't just precompute the answers, either, please.

PROGRAM NAME: friday

INPUT FORMAT:

One line with the integer N.

SAMPLE INPUT:

20

OUTPUT FORMAT:

Seven space separated integers on one line. These integers represent the number 
of times the 13th falls on Saturday, Sunday, Monday, Tuesday, ..., Friday.

SAMPLE OUTPUT:

36 33 34 33 35 35 34
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> times;
    int count = 13;
    times.push_back(count);
    
    for (int i = 1900; i < (1900+n); i++) {
        for (int j = 1; j < 13; j++) {
            if ((j == 1) && (i != 1900)){
                count += 31;
                times.push_back(count);
            }
            if (j==2) {
                count += 31;
                times.push_back(count);
            }
            if (j==3) {
                if (((i%4) == 0) && (i != 1900)) {
                    count += 29;
                } else {
                    count += 28;
                }
                times.push_back(count);
            }
            if (j==4) {
                count += 31;
                times.push_back(count);
            }
            if (j==5) {
                count += 30;
                times.push_back(count);
            }
            if (j==6) {
                count += 31;
                times.push_back(count);
            }
            if (j==7) {
                count += 30;
                times.push_back(count);
            }
            if (j==8) {
                count += 31;
                times.push_back(count);
            }
            if (j==9) {
                count += 31;
                times.push_back(count);
            }
            if (j==10) {
                count += 30;
                times.push_back(count);
            }
            if (j==11) {
                count += 31;
                times.push_back(count);
            }
            if (j==12) {
                count += 30;
                times.push_back(count);
            }
        }
    }
    int numSun = 0;
    int numMon = 0;
    int numTues = 0;
    int numWed = 0;
    int numThurs = 0;
    int numFri = 0;
    int numSat = 0;
    for (vector<int>:: iterator i = times.begin(); i != times.end(); i++) {
        if (((*i) % 7) == 1) {
            numMon++;
        }
        if (((*i) % 7) == 2) {
            numTues++;
        }
        if (((*i) % 7) == 3) {
            numWed++;
        }
        if (((*i) % 7) == 4) {
            numThurs++;
        }
        if (((*i) % 7) == 5) {
            numFri++;
        }
        if (((*i) % 7) == 6) {
            numSat++;
        }
        if (((*i) % 7) == 0) {
            numSun++;
        }
    }
    cout << numSat << " " << numSun << " " << numMon << " " << numTues << " " << numWed << " " << numThurs << " " << numFri << endl;
}