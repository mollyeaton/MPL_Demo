import numpy as np 
import pandas as pd
import os

word = pd.read_csv(os.getcwd() + '/word.txt')
guesses = pd.read_csv(os.getcwd() + '/guesses.txt')

#if they have guessed the word in full then 
if (guesses[-1] == word[0]):
    print("You guessed the word - " + word[0] + " - correctly! Congratulations!")
    exit()


for i in word[0]:
    for j in guesses:
        
        if (j == i):
            print(j, end = "")
        else:
            print("*", end = "")


