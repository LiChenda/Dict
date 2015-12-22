
def readdatas():
    words = []
    with open('dic.data') as f:
        for line in f:
            words.append([])
            c = line[:-1].split('<out>')
            words[-1].append(c[0])
            try:
                words[-1].append(c[1].split('<in>'))
            except:
                pass
            try:
                words[-1].append(c[2].split('<in>'))
            except:
                pass
            
    return words
