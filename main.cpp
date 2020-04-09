#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>


using namespace std;

/**
    * Requires: file names for the inFile (dictionary) and outFile (picked word)
    * Modifies: word.txt
    * Effects:  reads in the words from the dictionary and randomly chooses one for the game
    *       the word is stored in word.txt
    */
string pickWord(string inFile, string outFile);

/**
    * Requires: string guess
    * Modifies: guesses.txt
    * Effects:  validates the inputted guess for the requirements and passes it to guesses.txt if it passes
    */
bool validateGuess(string guess, string word);

/**
    * Requires: string filename
    * Modifies: input file
    * Effects:  clears the current contents
    */
void clearFile(string filename);

/**
    * Requires: string word
    * Modifies: nothing
    * Effects:  returns the passed word as all lowercase
    */
string makeLower(string word);

int main(){
    //seed the random number generator
    srand((unsigned) time(0));

    //declare variables
    const int MAX_GUESSES = 15;
    string guess;
    int guessCounter = 0;
    bool guessed = false;
    string hiddenWord;
    string word;

    //clear files before running game
    clearFile("word.txt");
    clearFile("guesses.txt");

    //display intro message
    cout << "Welcome to HANGMAN!" << endl;
    cout << "The goal of the game is to guess the hidden word." << endl;
    cout << "You will have " << MAX_GUESSES << " guesses, good luck!" << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;

    //pick the word that will be used and store into the word file
    word = pickWord("1-521.txt", "word.txt");

    //continue the loop for the game while the player still has guesses
    while (guessCounter < MAX_GUESSES && !guessed) {
        cout << "Make a guess: ";
        cin >> guess;
        while (cin.fail()){
            cin.clear();
            cin.ignore(256, '\n');
            cout << "That is not a valid response. Try again: " ;
            cin >> guess;
        }

        guess = makeLower(guess); //make lowercase

        //continue prompting for a guess until it meets the requirements
        while (!validateGuess(guess, word)){
            cout << "Enter your new guess: " ;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> guess;

            while (cin.fail()) {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "That is not a valid response. Try again: " ;
                cin >> guess;
            }
            guess = makeLower(guess);
        }

        string command = "python3 hangman.py";
        system(command.c_str());
        ++ guessCounter;

        ifstream fIn("hiddenWord.txt");
        fIn >> hiddenWord;
        fIn.close();

        if (hiddenWord.find('*') == string::npos ){
            cout << "You guessed the word! Congratulations!" << endl;
            guessed = true;
            return 0;
        }


        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
    }
    cout << "Sorry, you ran out of guesses. The word was " << word << endl;
    return 0;
}

string pickWord(string inFile, string outFile) {

    //create vector to hold all of the words pulled in
    vector <string> wordVec;
    string readWord; //create variable to hold each word read in

    //create the input stream for the file
    ifstream fIn(inFile);

    //while the file still has information and is good
    while (fIn){
        //read in each line and store in the temp variable
        fIn >> readWord;
        if(fIn){
            wordVec.emplace_back(readWord); //add the word to the vector
        }

    }
    fIn.close();

    //use the random number generator to pick a number between 0-521
    int wordChoice = (rand() % 521);

    //fIn.close(); //close the file

    ofstream fOut;
    //open the file and clear the current contents
    fOut.open(outFile, ios::app);

    if (fOut) {
        fOut << wordVec[wordChoice];
        fOut.close();
    }

    fOut.close(); //close the file
    cout << "The word you are trying to guess is a " << wordVec[wordChoice].length() << " letter word..." << endl;

    return wordVec[wordChoice];
}

bool validateGuess(string guess, string word){
    string filename = "guesses.txt";
    string letter;
    vector<string> guessVec;

    //if have gotten here then the guess has passed and can be put into the file
    for (int i = 0; i < guess.length(); ++i){
        guess[i] = tolower(guess[i]);
    }

    //create the input/output stream for the file
    ifstream inFile (filename);

    while (inFile){
        //read in each line and store in the temp variable
        inFile >> letter;
        if (inFile){
            guessVec.emplace_back(letter); //add the word to the vector
        }

    }

    //only check if letter or word is duplicate if the vector is not empty
    if (! guessVec.empty()) {
        //loop through the vector to see if the letter has been guessed
        for (int i = 0; i < guessVec.size(); ++i) {
            if (guess == guessVec[i]) {
                cout << "You have already guessed that letter/word" << endl;
                return false;
            }
        }
    }

    for (int i = 0; i < guess.length(); ++i) {
        if (isdigit(guess[i]) || !isalnum(guess[i])){
            cout << "That is an invalid guess. No digits or special characters allowed" << endl;
            return false;
        }
    }

    ofstream outFile(filename, ios::app);
    //only add the guess if it is a single character or is equal to the word
    if (guess.length() == 1 || guess == word)
        outFile << guess << endl;

    outFile.close();
    return true;

}

void clearFile(string filename){
    ofstream ofs;
    ofs.open(filename, ios::out|ios::trunc);
    ofs.close();
}

string makeLower(string word){
    for (int i = 0; i < word.length(); ++i){
        word[i] = tolower(word[i]);
    }
    return word;
}