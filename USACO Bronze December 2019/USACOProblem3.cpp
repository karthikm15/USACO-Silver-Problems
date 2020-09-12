#include <fstream>
#include <iostream>
#include <string>
using namespace std;
ifstream fin("lineup.in");
ofstream fout("lineup.out");

int main() {
  int n1;
  fin >> n1;
  
  string k;
  string arr[10000];
  int counter = 0;
  while (fin >> k) {
      arr[counter] = k;
      counter++;
  }

  string arr1[10000];
  int counter2 = 0;
  for (int i = 0; i < counter; i++) {
    if ((arr[i] != "must") && (arr[i] != "be") && (arr[i] != "milked") && (arr[i] != "beside")) {
      arr1[counter2] = arr[i];
      counter2++;
    }
  }

  string names[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
  string arr2[8] = {"", "", "", "", "", "", "", ""};
  bool works;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i != j) {
        for (int k = 0; k < 8; k++) {
          if ((j != k) && (i != k)) {
            for (int l = 0; l < 8; l++) {
              if ((i != l) && (j != l) && (k != l)) {
                for (int m = 0; m < 8; m++) {
                  if ((i != m) && (j != m) && (k != m) && (l != m)) {
                    for (int n = 0; n < 8; n++) {
                      if ((i != n) && (j != n) && (k != n) && (l != n) && (m != n)) {
                        for (int o = 0; o < 8; o++) {
                          if ((i != o) && (j != o) && (k != o) && (l != o) && (m != o) && (n != o)) {
                            for (int p = 0; p < 8; p++) {
                              if ((i != p) && (j != p) && (k != p) && (l != p) && (m != p) && (n != p) && (o != p)) {
                                arr2[0] = names[i];
                                arr2[1] = names[j];
                                arr2[2] = names[k];
                                arr2[3] = names[l];
                                arr2[4] = names[m];
                                arr2[5] = names[n];
                                arr2[6] = names[o];
                                arr2[7] = names[p];
                                
                                works = true;
                                for (int q = 0; q < counter2; q=q+2) {
                                  string cow1 = arr1[q];
                                  string cow2 = arr1[q+1];
                                  int index1, index2;
                                  for (int r = 0; r < 8; r++) {
                                    if (cow1 == arr2[r]) {
                                      index1 = r;
                                    }
                                    if (cow2 == arr2[r]) {
                                      index2 = r;
                                    }
                                  }

                                  if (!((index1 == index2) || (index1 == (index2+1)) || (index1 == (index2-1)))) {
                                    works = false;
                                    break;
                                  }
                                }
                                if (works) {
                                  break;
                                }
                              }
                            }
                          }
                          if (works) {
                            break;
                          }
                        }
                      }
                      if (works) {
                        break;
                      }
                    }
                  }
                  if (works) {
                    break;
                  }
                }
              }
              if (works) {
                break;
              }
            }
          }
          if (works) {
            break;
          }
        }
      }
      if (works) {
        break;
      }
    }
    if (works) {
      break;
    }
  }

  for (int i = 0; i < 8; i++) {
    fout << arr2[i] << endl;
  }
}
