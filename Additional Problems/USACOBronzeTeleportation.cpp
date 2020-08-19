#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
int main() {
	2
	int Start, End, TeleStart, TeleEnd, Way1, Way2, Way3, minimum;
	inFile >> Start >> End;
	inFile >> TeleStart >> TeleEnd;

	Way1 = 0;
	Way2 = 0;
	Way3 = 0;

	Way1 = (abs(Start - TeleStart) + abs(End - TeleEnd));
	Way2 = abs(Start - End);
	Way3 = (abs(Start - TeleEnd) + abs(TeleStart - End));

	int Ways[3] = {Way1, Way2, Way3};
	minimum = Ways[0];
	for (int i = 0; i < 3; i++) {
		if (minimum > Ways[i]) {
			minimum = Ways[i];
		}
	}
	ofstream output;
	output.open("teleport.out");
	output << minimum << endl;

	output.close();
}
