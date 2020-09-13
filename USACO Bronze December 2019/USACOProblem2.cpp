#include <fstream>
#include <iostream>
#include <string>
using namespace std;
ifstream fin("whereami.in");
ofstream fout("whereami.out");

int main() {
  int n;
  fin >> n;
  
  string s = "";
  for (int i = 0; i < n; i++) {
    char placeholder;
    fin >> placeholder;

    s += placeholder;
  }
  //cout << s;
  string arr[10000];
  for (int k = 0; k < n; k++) {
    int counter = 0;
    for (int i = 0; i < (n-k+1); i++) {
      string str2 = s.substr(i, k);
      arr[counter] = str2;
      counter++;
    }
    //cout << endl;
    bool doesWork = true;
    for (int i = 0; i < (counter+1); i++) {
      for (int j = i+1; j < (counter+1); j++) {
        if (arr[i] == arr[j]) {
            doesWork = false;
            break;
        }
      }
    }
    if (doesWork) {
      //cout << k;
      fout << k;
      break;
    }
  }
}
