
def readdatas():
    words = []
    with open('dic.data') as f:
        for line in f:
            word = line[:-1].split('<out>')
            while len(word) < 3:
                word.append('') 
            words.append(word)

    return words
