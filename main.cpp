#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

void pickWord(string inFile, string outFile);
bool validateGuess(string guess);

int main(){
    //seed the random number generator
    srand((unsigned) time(0));

    //declare variables
    const int MAX_GUESSES = 8;
    int guessCounter = 0; //keeps running count of how manny guesses have been made
    string guess;

    //pick the word that will be used and store into the word file
    pickWord("1-521.txt", "word.txt");

    fstream fOut;
    //open the file and clear the current contents
    fOut.open(string("../") + "guesses.txt", ios::out | ios::trunc);



    //display intro message
    cout << "Welcome to HANGMAN!" << endl;
    cout << "The goal of the game is to guess the hidden word." << endl;
    cout << "You will have " << MAX_GUESSES << " guesses, good luck!" << endl;

    //continue the loop for the game while the player still has guesses
    while (guessCounter < 8) {
        cout << "Make a guess: ";
        getline(cin, guess);
        //make the guess al lowercase
        for (int i = 0; i < guess.length(); ++i) {
            tolower(guess[i]);
        }
        //continue prompting for a guess until it meets the requirements
        while (!validateGuess(guess)){
            cout << "Enter your new guess: " ;
            getline(cin, guess);

            for (int i = 0; i < guess.length(); ++i) {
                tolower(guess[i]);
            }
            validateGuess(guess);
        }
        system("python3 hangman.py");
        ++ guessCounter;

    }
    return 0;
}

void pickWord(string inFile, string outFile) {
    //seed the random number generator
    srand((unsigned) time(0));

    //create vector to hold all of the words pulled in
    vector <string> wordVec;
    string readWord; //create variable to hold each word read in

    //create the input stream for the file
    ifstream fIn;
    //find the text file and open it
    fIn.open(string("../") + inFile);
    //while the file still has information and is good
    while (fIn && fIn.peek() != EOF)
    {
        //read in each line and store in the temp variable
        getline(fIn, readWord);
        wordVec.push_back(readWord); //add the word to the vector
    }
    //use the random number generator to pick a number between 0-521
    int wordChoice = (rand() % 521);

    fIn.close(); //close the file

    fstream fOut;
    //open the file and clear the current contents
    fOut.open(string("../") + outFile, ios::out | ios::trunc);

    if (fOut) {
        fOut << wordVec[wordChoice];
        fOut.close();
    }

    fOut.close(); //close the file

}

bool validateGuess(string guess){
    bool passed = true;

    string letter;
    vector<string> guessVec;

    //create the input stream for the file
    ifstream fIn;
    //find the text file and open it
    fIn.open(string("../") + "guesses.txt");
    //while the file still has information and is good
    while (fIn && fIn.peek() != EOF){
        //read in each line and store in the temp variable
        getline(fIn, letter);
        guessVec.push_back(letter); //add the word to the vector
    }
    fIn.close();

    //loop through the vector to see if the letter has been guessed
    for (int i = 0; i < guessVec.size(); ++i){
        if (guess ==  guessVec[i]){
            cout << "You have already guessed that letter/word" << endl;
            passed = false;
        }
    }

    for (int i = 0; i < guess.length(); ++i) {
        if (isdigit(guess[i]) || !isalnum(guess[i])){
            cout << "That is an invalid guess. No digits or special characters allowed" << endl;
            passed = false;
        }
    }

    return passed;

}