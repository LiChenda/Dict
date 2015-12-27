import dic_tree
import json

def intitfromfile(filename):
    words = [] 
    with open(filename, 'r') as f:
        words = json.load(f)
    for word in words:
        dic_tree.insert_word(word['word'],json.dumps(word))

def searchWord(word_en):
    item = dic_tree.search_word(word_en) 
    result = {}
    if(len(item)):
        result = json.loads(item[1])
    return result

def modifyWord(item):
    s = json.dumps(item)
    word_en = item['word']
    return dic_tree.modify_word(word_en, s)

def insertWord(item):
    dic_tree.insert_word(item['word'], json.dumps(item))
    return

def suggestWord(word_en):
    item = dic_tree.suggest_word(word_en)
    result = []
    for i in item:
        if(i):
            result.append(i[0])
    j = {'result': result}
    return json.dumps(result)

intitfromfile("./items_comp.json")

    
     

    






