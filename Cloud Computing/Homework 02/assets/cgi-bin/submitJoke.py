import sys
from server import *
from server import databaseManager
import cgi
import json
from utils import apiUtil
import os
import pymysql
import cgitb

print("Content-Type: text/html\n")


def returnErrorMessage(text, code):
    response = {'type': 'error', "code": code, 'message': text}
    print(json.dumps(response))
    exit(0)


def returnSuccesMessage():
    response = {'type': 'success', "code": 200, 'message': "Joke inserted successfully"}
    print(json.dumps(response))
    exit(0)


arguments = cgi.FieldStorage()

if 'json' not in arguments.keys():
    returnErrorMessage("No JSON found.", 422)  # unprocessable entity

jsonObj = json.loads(arguments['json'].value)

if 'joke_text' not in jsonObj.keys():
    returnErrorMessage("No id specified", 400)  # bad request

if os.environ['REQUEST_METHOD'] == 'POST':
    try:
        jsonObj = json.loads(arguments['json'].value.encode('utf-8'))
        databaseManager.insertJoke(apiUtil.generateRandomId(), jsonObj["joke_text"])
        returnSuccesMessage()
    except pymysql.DatabaseError:
        returnErrorMessage("Internal server error", 500)
    except pymysql.InterfaceError:
        returnErrorMessage("Internal server error", 500)
else:
    returnErrorMessage("Method not allowed", 405)  # method not allowed
