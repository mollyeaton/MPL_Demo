# ME-Final-Project-MPL
##Hangman Game using C++ and Python

This project is a rendition of the classic Hangman Game. The object of the game is to guess a hidden word letter by 
letter. There is a maximum number of guesses allowed (10 for this project) and the player must guess the word within 
that number of rounds or else they lose the game. All input is validated based on these parameters: no numbers or 
special characters can be guessed and letters cannot be repeatedly guessed. 

The program will randomly choose a word from a dictionary of choices. The original dictionary contained the 1000 most 
common words in the english language (found here: https://gist.github.com/deekayen/4148741). I then altered the file so 
it only contains words with 5 or more letters making the total number of options 521. The chosen word is stored into a 
file so that it can be shared across programs. The program will loop to allow user choices until the user is either out 
of guesses or has correctly guessed the word. All input is case insensitive. 

The program begins in C++. The main.cpp file will choose the word, get user input, validate input, and keep track of 
guesses. The main.cpp file will call the hangman.py file within a loop to check the user's guess with the word. The word
will be hidden with asterisks until correct letters or the word has been guessed. The user can guess the full word at 
any point, but all incorrect guesses are counted as a turn and full words will be counted as many times as they are 
guessed. 

To run this program you will need:
>- Python 3 installed on your computer
> - These files:
>   * "1-521.txt" - dictionary containing all word choices
>   * "word.txt" - text file that will hold the chosen word
>   * "guesses.txt" - text file that will hold the ongoing list of guesses
>   * "hiddenWord.txt" - text file that holds the continually changing hidden version of the word
>   * "main.cpp" - main C++ program
>   * "hangman.py" - peripheral python program to check guesses against word

For the program to run you will need to compile and execute via command line prompts. Here are the basic commands you 
will need to run with C++14:

> g++ -std=c++1y main.cpp
>
> ./a.out

The first command will compile the file and create the executable. By running the executable the program will then run 
with output on the console. 

Once the program is running all you have to do is enjoy the game!