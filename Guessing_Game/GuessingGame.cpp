#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <string>
#include <limits>
#include <locale>
#include<bits/stdc++.h>

using namespace std;

//variables
bool exiting = false;

bool playAgain() {
	bool valid = false;
	cout << "Play Again(y/n)?" << endl;
	string input;
	while (!valid) {
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "sdfsdf" << endl;
		}
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (input == "Y" || input == "YES") {
			valid = true;
			return false;
		}
		else if (input == "N" || input == "NO") {
			valid = true;
			return true;
		}
		else {
			cout << "Invalid Input! Play Again(y/n)?" << endl;
			valid = false;
		}
	}
}

int game() {
	srand(time(0));
	int random = rand() % 101;
	cout << random << endl;

	int guesses = 0;
	int guess = -1;
	while (guess != random) {
		cin >> guess;
		guesses++;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please Enter Only Numbers!" << endl;
			guesses--;
		}
		else if (guess == random) {
			cout << "Guessed Correctly!" << endl;
			cout << "Guesses Taken: " << guesses << endl;
			break;
		}
		else if (guess < random) {
			cout << "Guess Higher!" << endl;
		}
		else if (guess > random) {
			cout << "Guess Lower!" << endl;
		}
	}

	return playAgain();
}

int main() {
	while (!exiting) {
		exiting = game();
	}

	return 0;
}