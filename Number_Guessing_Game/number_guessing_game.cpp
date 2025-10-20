#include<iostream>

#include<cstdlib>

#include<ctime>

using namespace std;

int main()
{

   srand(time(0));
  
  int secretNumber = rand() % 100 + 1;
  int guess;
  int tries = 0;
  
  	cout << "?? Welcome to the Number Guessing Game!\n";
    cout << "Guess a number between 1 and 100:\n";
    
     do {
        cout << "Enter your guess: ";
        cin >> guess;
        tries++;

        if (guess > secretNumber)
            cout << "Too high! Try again.\n";
        else if (guess < secretNumber)
            cout << "Too low! Try again.\n";
        else
            cout << "?? Congrats! You guessed it in " << tries << " tries.\n";

    } while (guess != secretNumber);

    return 0;
    
    
  	
}
