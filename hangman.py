#open the hidden word file in write mode
hiddenWordFile = open("hiddenWord.txt", "w")

#open the word file in read mode
wordFile = open("Word.txt", "r")
#store the data into the word variable
word = wordFile.read()
#make the word a list so that it can be iterated through
word = list(word)

#open the guesses file in read mode
guessesFile = open("guesses.txt", "r")
#store the data into the guesses variable and strip all new line characters
guesses = guessesFile.read().strip('\n')

hiddenWord = '' #initialize as an empty string

#replace all letters in the word with an asterisk
for i in word:
    hiddenWord += '*'

#convert into a list so it can be manipulated
hiddenWord = list(hiddenWord)

#loop through all of the guesses and replace the astericks with letters if they are correct guesses
for i in range(len(word)):
    for j in guesses:
        
        if (j.lower() == word[i]):
            #if the guess is the same as a letter show the letter
            hiddenWord[i] = j.lower()

#join the list back together into a string
hiddenWord = "".join(hiddenWord)
#print the new hidden word
print(hiddenWord)
#add the hidden word to the file so the main program can check if it is done or not
hiddenWordFile.write(hiddenWord)

#close all the files
hiddenWordFile.close()
wordFile.close()
guessesFile.close()