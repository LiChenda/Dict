import myDict
import loaddata

words = loaddata.readdatas()

for word in words:
    myDict.insert_word(word[0], word[1], word[2])



print(len(words))



