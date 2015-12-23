
import re

def readdatas():
    
    strs = []
    wordlist_row = []
    words = []
    wordln = ''
    with open('cetsix.txt') as f:
        for line in f:
            c = line.split('|', 1) 
            try:
                int(c[0])
                wordlist_row.append(c[1]) 
            except:
                wordlist_row[-1] += line
    
    for i in range(len(wordlist_row)):
        wordlist_row[i] = wordlist_row[i].replace('/r/n', '\n')
        wordlist_row[i] = wordlist_row[i].replace('<br>', '\n')
    
    for word_r in wordlist_row:
        word = word_r.split('|') 
        words.append([])
        strs.append('')
        words[-1].append(word[0])
        strs[-1] += word[0] + '<out>'
        words[-1].append([])
        tmp = re.split('\n|  ', word[1])
        #tmp = word[1].split('\n')
        for ele in tmp:
            if ele != '':
                words[-1][-1].append(ele)
                strs[-1] += ele
                strs[-1] += '<in>'
    
        strs[-1] = strs[-1][:-4] + '<out>'
        words[-1].append([])
        tmp = re.split('\n|  ', word[2])
        #tmp = word[2].split('\n')
        for ele in tmp:
            if ele != '':
                words[-1][-1].append(ele)
                strs[-1] += ele
                strs[-1] += '<in>'
        strs[-1] = strs[-1][:-4]

    return words, strs

def save(tosave):
    with open('dic.data','w') as f:
        for line in tosave:
            f.writelines(line+'\n')











    
    
