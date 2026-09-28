#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
    srand(time(0));

    int targetNum = rand() % 100 + 1;
    int guess;

    cout << "====Number Guessing Game====" << endl;
    cout << "I have selected a number between 1 and 100" << endl;
    cout << "Try guesing it!" << endl;

    while (true) {
        cout << "\nEnter your guess: ";
        cin >> guess;

        if (guess > targetNum)
        cout << "Too high! Try again." << endl;
        
        else if (guess < targetNum)
        cout << "Too low! Try again" << endl;

        else{
            cout << "Congrats the number you guessed is right!!" << endl;
            break;
        } 
        
    }
    return 0;
}
