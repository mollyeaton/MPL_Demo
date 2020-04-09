
hiddenWordFile = open("hiddenWord.txt", "w")

wordFile = open("Word.txt", "r")
word = wordFile.read()
word = list(word)

    
guessesFile = open("guesses.txt", "r")
guesses = guessesFile.read()


hiddenWord = '' #initialize as an empty string

#replace all letters in the word with an asterick
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