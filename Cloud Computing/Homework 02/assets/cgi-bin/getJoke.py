import ast
import sys
from server import *
from server import databaseManager
import cgi
import json
import os
import pymysql

print("Content-Type: text/html\n")


def returnErrorMessage(text, code):
    response = {'type': 'error', "code": code, 'message': text}
    print(json.dumps(response))
    exit(0)


def returnSuccesMessage(data):
    response = {'type': 'success', "code": 200, 'data': data}
    print(json.dumps(response))
    exit(0)


arguments = cgi.FieldStorage()

if 'json' not in arguments.keys():
    returnErrorMessage("No JSON found.", 422)  # unprocessable entity

jsonObj = json.loads(arguments['json'].value)

if 'joke_id' not in jsonObj.keys():
    returnErrorMessage("No id specified", 400)  # bad request

if os.environ['REQUEST_METHOD'] == 'GET':
    try:
        jsonObj = json.loads(arguments['json'].value.encode('utf-8'))
        if databaseManager.getJoke(jsonObj["joke_id"]) == "":
            returnErrorMessage("Joke not found", 204)  # no content
        else:
            returnSuccesMessage(databaseManager.getJoke(jsonObj["joke_id"]))
    except pymysql.DatabaseError:
        returnErrorMessage("Internal server error", 500)
    except pymysql.InterfaceError:
        returnErrorMessage("Internal server error", 500)
else:
    returnErrorMessage("Method not allowed", 405)  # method not allowed
