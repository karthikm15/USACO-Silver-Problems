/**
The cows are so very silly about their dinner partners. They have
organized themselves into two groups (conveniently numbered 1 and
2) that insist upon dining together in order, with group 1 at the
beginning of the line and group 2 at the end. The trouble starts
when they line up at the barn to enter the feeding area.

Each cow i carries with her a small card upon which is engraved D_i
(1 <= D_i <= 2) indicating her dining group membership. The entire
set of N (1 <= N <= 30,000) cows has lined up for dinner but it's
easy for anyone to see that they are not grouped by their dinner-partner
cards.

FJ's job is not so difficult.  He just walks down the line of cows
changing their dinner partner assignment by marking out the old
number and writing in a new one. By doing so, he creates groups of
cows like 112222 or 111122 where the cows' dining groups are sorted
in ascending order by their dinner cards. Rarely he might change
cards so that only one group of cows is left (e.g., 1111 or 222).

FJ is just as lazy as the next fellow. He's curious: what is the
absolute minimum number of cards he must change to create a proper
grouping of dining partners? He must only change card numbers and
must not rearrange the cows standing in line.

PROBLEM NAME: diningb

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 describes cow i's dining preference with a
        single integer: D_i

SAMPLE INPUT:

7
2
1
1
1
2
2
1

INPUT DETAILS:

Seven cows; all but three of which currently prefer dining group 1.

OUTPUT FORMAT:

* Line 1: A single integer that is the minimum number of cards Farmer
        John must change to assign the cows to eating groups as
        described.

SAMPLE OUTPUT:

2

OUTPUT DETAILS:

Change the first and last cow's cards.
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int numones = 0;
    int numtwos = 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) {
            numones++;
        }
        else{
            numtwos++;
        }
    }
    if (numones > numtwos) {
        int max = numones;
    }
    else {
        int max = numtwos;
    }
    int min = 1000000;
    int count = 0;
    bool isTrue = false;
    int count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) {
            count2++;
        }
    }
    if (count2 == n) {
        isTrue = true;
    }
    for (int i = 0; i < n; i++) {
        count = 0;
        for (int j = 0; j <= i; j++) {
            if (arr[j] == 2) {
                count++;
            }
        }
        for (int j = (i+1); j < n; j++) {
            if (arr[j] == 1) {
                count++;
            }
        }
        if (min > count) {
            min = count;
        }
    }
    if (isTrue) {
        cout << 0 << endl;
    }
    else {
        cout << min << endl;
    }
    /*int count2 = 0;
    for (int i = 0; i < n; i++) {
        if ((arr[i] == 2) && (i < numones)){
            for (int j = i; j < n; j++) {
                if (arr[j] == 1) {
                    int placeholder = arr[j];
                    arr[j] = arr[i];
                    arr[i] = placeholder;
                    count2 += 2;
                    for (int k = 0; k < n; k++) {
                        cout << arr[k] << " ";
                    }
                    cout << endl;
                    break;
                }
            }
        }
        if ((arr[i] == 1) && (i >= numones)) {
            for (int j = i; j < n; j++) {
                if (arr[j] == 2) {
                    int placeholder = arr[j];
                    arr[j] = arr[i];
                    arr[i] = placeholder;
                    count2 += 2;
                    for (int k = 0; k < n; k++) {
                        cout << arr[k] << " ";
                    }
                    cout << endl;
                    break;
                }
            }
        }
    } 
    int max = 0; 
    int index = 0;
    int number = 1;
    int count = 0;
    int index2 = 0;
    int index3 = 0;
    for (int i = 0; i < n; i++) {
        count = 0;
        if (arr[i] == 1) {
            for (int j = i; j < n; j++) {
                if (arr[j] == 1) {
                    count++;
                }
                else {
                    index2 = j;
                    break;
                }
            }
        }
        if (arr[i] == 2) {
            for (int j = i; j < n; j++) {
                if (arr[j] == 2) {
                    count++;
                }
                else {
                    index2 = j;
                    break;
                }
            }
        }
        if (max < count) {
            max = count;
            index = i;
            if (number == 2) {
                number = 2;
            }
            else {
                number = 1;
            }
            index3 = index2;
        }
    }
    int counter = 0;
    if (number == 1) {
        for (int i = 0; i < index; i++) {
            if (arr[i] == 2) {
                counter++;
            }
        }
        for (int i = index3; i < n; i++) {
            if (arr[i] == 1) {
                counter++;
            }
        }
    }
    cout << index << " " << number << endl;
    if (number == 2) {
        for (int i = n; i <= index3; i--) {
            if (arr[i] == 1) {
                counter++;
            }
        }
        for (int i = index; i <= 0 ; i--) {
            if (arr[i] == 2) {
                counter++;
            }
        }
    }
    if (index == 0) {
        cout << 0;
    }
    else if (count2 < counter) {
        cout << "COUNTER IS: " << counter << endl;
    }
    else {
        cout << "COUNT2 IS: " << count2;
    }*/
}