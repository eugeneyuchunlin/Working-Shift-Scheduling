from os import system
from flask import Flask,request,jsonify,render_template,request

app = Flask(__name__)

@app.route('/',methods = ['GET'])
def index():
    return render_template('index.html',title='index.html')

@app.route('/test/', methods = ['GET'])
def test():
    system("../../objects/main -m 4 5 6 -p ../../files/")
    return "Ok"

if __name__ == "__main__":
    app.run()
