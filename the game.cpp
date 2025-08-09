#include <bits/stdc++.h>

using namespace std;

int main() {

    // the intro of the game
    cout << "Welcome to the Number Guessing Game!\n" <<
        "I'm thinking of a number between 1 and 100.\n" <<
        "You have 5 chances to guess the correct number.\n\n" <<
        "Please select the difficulty level:\n1. " <<
        "Easy (10 chances)\n2. Medium (5 chances)\n3. Hard (3 chances)\n\nEnter your choice: ";

    /*
    the user will choose the number of chances
        1- play_num contains the input that player will choose it, between (1 to 100)
        2- role contains the numbers of choices, if it 0 ? the game will be end
        3- tying is the integar that counting the number of the guesses
    */

    int play_num, trying = 1, role = 0;

    // after that, we should make sure the user will write play_num between (1 to 3)
    // else that ? the program will send to user that he write the invalid number

    while (true) {
        cin >> play_num;
        if (play_num >= 1 && play_num <= 3) {
            break;
        } else {
            cout << "invalid number, try to write between (1 to 3).\n" <<
                "Enter your guess: ";
        }
    }

    switch (play_num) {
        case 1:
            role = 10;
            break;
        case 2:
            role = 5;
            break;
        case 3:
            role = 3;
            break;
    }

    cout << "\nGreat! You have selected the Medium difficulty level." <<
        "\nLet's start the game!\n\n";

    srand(time(0));
    int true_num = 1 + (rand() % (100 - 1 + 1));
    int guess_num;

    while (role--) {
        cout << "Enter your guess: ";
        cin >> guess_num;
        if (guess_num == true_num) {
            cout << "Congratulations! You guessed the correct number in " << trying << " attempts.\n";
            return 0;
        } else if (guess_num > true_num) {
            cout << "Incorrect! The number is less than " << guess_num << " .\n\n";
            trying++;
        } else if (guess_num < true_num) {
            cout << "Incorrect! The number is greater than " << guess_num << " .\n\n";
            trying++;
        }
    }
    cout << "You lose all your chances, better luck next time.";
}
