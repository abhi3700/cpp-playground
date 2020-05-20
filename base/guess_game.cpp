#include <iostream>

using std::cin;
using std::string;




int main() {
	int secretNum = 7;
	int guess;
	int guessCount = 0;
	int guessLimit = 3;
	bool outOfGuesses =false;

	while(secretNum != guess && !outOfGuesses) {
		if (guessCount < guessLimit)
		{
		    std::cout << "Enter guess: " << std::endl;
		    cin >> guess;
		    guessCount++;
		} else {
			outOfGuesses = true;
		}

	}

	if(outOfGuesses) {
		std::cout << "You lose!" << std::endl;
	}
	else {
		std::cout << "You win!" << std::endl;
	}



	return 0;
}

