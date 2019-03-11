import sys
from server import *
from server import databaseManager
import cgi
import json
import os

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

response = {}

if os.environ['REQUEST_METHOD'] == 'GET':
    if not databaseManager.getAllJokes():
        response["type"] = "fail"
        response["code"] = 500
    else:
        result = databaseManager.getAllJokes()
        returnSuccesMessage(result)
else:
    returnErrorMessage("Method not allowed", 405) # method not allowed
