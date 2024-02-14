#include <iostream>
#include <vector>
#include <ctime>
//#include <stdlib.h>

using namespace std;

void play(string secret_word);
//string add_wrd();

string hangman_art[7] = {
"         +---++\n"
"         |   ||\n"
"             ||\n"
"      _______||_______\n"
"     /       ||      /|\n"
"    /        ||     / /\n"
"   /               / /\n"
"  /               / /\n"
" /_______________/ /\n"
" |_______________|/\n"
"                   \n",
"         +---++\n"
"         |   ||\n"
"         O   ||\n"
"      _______||_______\n"
"     /       ||      /|\n"
"    /        ||     / /\n"
"   /               / /\n"
"  /               / /\n"
" /_______________/ /\n"
" |_______________|/\n"
"                   \n",
"         +---++\n"
"         |   ||\n"
"         O   ||\n"
"      ___|___||_______\n"
"     /       ||      /|\n"
"    /        ||     / /\n"
"   /               / /\n"
"  /               / /\n"
" /_______________/ /\n"
" |_______________|/\n"
"                   \n",
"         +---++\n"
"         |   ||\n"
"         O   ||\n"
"      __/|___||_______\n"
"     /       ||      /|\n"
"    /        ||     / /\n"
"   /               / /\n"
"  /               / /\n"
" /_______________/ /\n"
" |_______________|/ \n"
"                   \n",
"         +---++\n"
"         |   ||\n"
"         O   ||\n"
"      __/|\\__||_______\n"
"     /       ||      /|\n"
"    /        ||     / /\n"
"   /               / /\n"
"  /               / /\n"
" /_______________/ /\n"
" |_______________|/\n"
"                   \n",
"         +---++\n"
"         |   ||\n"
"         O   ||\n"
"      __/|\\__||_______\n"
"     /  /    ||      /|\n"
"    /        ||     / /\n"
"   /               / /\n"
"  /               / /\n"
" /_______________/ /\n"
" |_______________|/\n"
"                   \n",
"         +---++\n"
"         |   ||\n"
"         O   ||\n"
"      _ /|\\__||_______\n"
"     /  / \\  ||      /|\n"
"    /        ||     / /\n"
"   /               / /\n"
"  /               / /\n"
" /_______________/ /\n"
" |_______________|/\n"
"                   \n"
};

int main(){
    char choice;
    int sec_nm,up_range,guess, n(0);
    string secret_word;
    srand(time(0));

    home:
        char choice2;
        cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Guessing Game %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n" << "\n>>>> HOME <<<<" << "\nPick a game:" << "\n\t A.Word Guessing Game(Hangman)\n" << "\t B.Number Guessing Game\n" << "\t C.Exit\n" << "_"; 
        cin >> choice;

        if(choice == 'A')
            play(secret_word);
        else if(choice == 'B'){
            game1:
                int in_count(0); //cr_count(0);

                cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Number Guessing Game %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n" << "\nEnter an upper range for the numbers(starts from 0): \n" << "_";
                cin >> up_range;

                sec_nm = rand() % up_range + 1;

                cout << "Enter your guess(0-" << up_range << "): ";

                while(n==0){
                            cout << '\n' << hangman_art[in_count] << "\n" << "\n_";
                            cin >> guess;
        
                            if(guess == sec_nm){
                                cout << "\nCorrect!" << endl << "No# of incorrect guesses: " << in_count << endl;
                                //n += 1;
                                //return 1;
                                cout << "\nA.Back" << "\nB.Home" << "\nC.Exit\n" << "_";
                                cin >> choice2;
                                if(choice2 == 'A') goto game1;
                                else if (choice2 == 'B') goto home;
                                else if(choice2 == 'C') {cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Exit %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"; exit(0);}
                                else cout << "Invalid Input!"; exit(0);
                            }
                            else if(in_count == 6){ //no# of guesses can be adjusted
                                cout << hangman_art[in_count] << "\n";
                                cout << "\nIncorrect! You lost! The number was: " << sec_nm <<  endl << "No# of incorrect guesses: " << in_count << endl;
                                //n += 1; //alternative exit function
                                //return 1;
                                cout << "\nA.Back" << "\nB.Home" << "\nC.Exit\n" << "_";
                                cin >> choice2;
                                if(choice2 == 'A') goto game1;
                                else if (choice2 == 'B') goto home;
                                else if(choice2 == 'C') {cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Exit %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"; exit(0);}
                                else cout << "Invalid Input!"; exit(0);
                            }
                            else if(guess < 0 || guess > up_range){cout << "Out of range! Try again..."; in_count++;}
                            else if(guess > sec_nm){cout << "Incorrect! Too high,try again..."; in_count++;}
                            else if(guess < sec_nm){cout << "Incorrect! Too low,try again..."; in_count++;}
                            else{
                                cout << "Invalid input! Try again...\n"; in_count++;
                            }
                        }
        }
        else if(choice == 'C') {cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Exit %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"; exit(0);}
        else cout << "Invalid Input!"; exit(0);
        //return 0;     
}



void play(string secret_word)
{
    game2:

        char choice2,genre,guess;
        int try_no(0),correct_try(0);
        string guess_word;

        vector<string> words = {"HiLCoE", "ICT", "input", "words", "censor"};
        vector<string> anim_word = {"lion", "hippo", "mice", "tiger", "rhino", "giraffe"};
        vector<string> country_nm = {"portugal", "thailand", "senegal", "spain", "ethiopia", "egypt", "germany", "russia"};

        cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Welcome to Hangman!(Word) %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n" << "\nPick a genre:" << endl << "\t A. Random Words\n" << "\t B. Animals\n" << "\t C. Countries\n" << "_";
        //cout << "\nOptions:\n" << "\tD.Add New Word";
        cin >> genre;

        if(genre == 'A')
            secret_word = words[rand() % words.size()];
        else if(genre == 'B')
            secret_word = anim_word[rand() % anim_word.size()];
        else if(genre == 'C')
            secret_word = country_nm[rand() % country_nm.size()];
        //else if(genre == 'D') add_wrd();
        else {cout << "Invalid Input!"; exit(0);} // can't break out of conditional st. without loops!

        // start game
        guess_word = secret_word;
        for(int i = 0; i < secret_word.length(); i++)
        {
            guess_word[i] = '_'; //switches all characters into uderscores
        }

        while (true)
        {
            cout << "\n" << hangman_art[try_no] << "\n";
            cout << '\n' << guess_word << "\n";
            cout << "Enter your guess:\n";
            cin >> guess;

            if(secret_word.find(guess) != string::npos) //npos -- "Until the end of the string" func. npos -- virtual location when char position is not found
            {   
                for(int i = 0; i < guess_word.length(); i++)
                {
                    if(secret_word[i] == guess)
                    {
                        guess_word[i] = guess;
                    }
                }
                ++correct_try;
                if(secret_word == guess_word)
                {
                    cout << hangman_art[try_no] << "\n";
                    cout << guess_word << "\n";
                    cout << "\nYou win! The word was: " << secret_word << "\n No# of inccorect guesses: " << try_no << "\n No# of correct guesses: " << correct_try << "\n";
                    cout << " ";
                    cout << "\nA.Back" << "\nB.Home" << "\nC.Exit\n" << "_";
                    cin >> choice2;
                    if(choice2 == 'A') play(secret_word);
                    else if (choice2 == 'B') main();
                    else if(choice2 == 'C') {cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Exit %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"; exit(0);}
                    else {cout << "Invalid Input"; exit(0);}
                }
            } 
            else{
                ++try_no;
            }
            if(try_no >= 6)
            {
                cout << hangman_art[try_no] << "\n";
                cout << guess_word << "\n";
                cout << "\nYou lost! The word was: " << secret_word << "\nNo# of incorrect guesses: " << try_no << "\nNo# of correct guesses: " << correct_try << "\n";
                cout << "\nA.Back" << "\nB.Home" << "\nC.Exit\n" << "_";
                cin >> choice2;
                if(choice2 == 'A') play(secret_word);
                else if (choice2 == 'B') main();
                else if(choice2 == 'C') {cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Exit %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"; exit(0);}
                else cout << "Invalid Input!"; exit(0);
            }
        }        
} //end of void play() func.

// string add_wrd(){
//     string nw_wrd;
//     string nw_lst;

//     cout << "\nEnter new word:"; 
//     cin >> nw_wrd;

//     cout << "Enter custome library(list): ";
//     cin >> nw_lst;

//     return nw_wrd,nw_lst;
// }