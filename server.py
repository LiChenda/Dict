from flask import * 
import dict

app = Flask(__name__)

@app.route('/search/<word>')
def search(word):
    item = dict.searchWord(word)
    if(item):
        mean = item['meanings']  
        sen = item['examples']
        return render_template('wordinfo.html', w = word,\
                meaning = mean, examples = sen)
    return '' 

@app.route('/edit')
def edit():
    word = request.args.get('word')
    num = request.args.get('num')
    item = dict.searchWord(word)
    if(item):
        sen = item['examples'][int(num)-1]
        return render_template('edit.html', en = sen['sentence'],\
                ch = sen['translation'], i = int(num))
    return '' 
@app.route('/addsen_t')
def addsen_t():
    return render_template('add.html')
    
@app.route('/delsen', methods=['POST'])
def delsen():
    word = request.form['word']
    num = request.form['num']
    n = int(num) - 1
    item = dict.searchWord(word)
    del item['examples'][n]
    return dict.modifyWord(item)
    

@app.route('/addsen', methods=['POST'])
def addsen():
    word = request.form['word']
    en = request.form['en']
    ch = request.form['ch']
    item = dict.searchWord(word)
    item['examples'].append({'sentence':en, 'translation': ch})
    return dict.modifyWord(item)

@app.route('/modifysen', methods=['POST'])
def modifysen():
    word = request.form['word']
    num = request.form['num']
    en = request.form['en']
    ch = request.form['ch']
    item = dict.searchWord(word)
    item['examples'][int(num) - 1]['sentence'] = en
    item['examples'][int(num) - 1]['translation'] = ch
    return dict.modifyWord(item)
    


@app.route('/typeahead')
def typeahead():
    s = request.args.get('query') 
    return dict.suggestWord(s) 

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/you')
def you():
    return 'you'

if __name__ == '__main__':
    app.debug = True
    app.run(host='0.0.0.0')

