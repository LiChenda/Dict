from flask import * 
import dict

app = Flask(__name__)

@app.route('/search/<word>')
def search(word):
    item = dict.searchWord(word)
    if(item):
        mean = item['meanings']  
        print(mean)
        sen = item['examples']
        return render_template('wordinfo.html', w = word,\
                meaning = mean, examples = sen)
    return '' 

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
