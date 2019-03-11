import json
import random
import string
import urllib.request
import cgi
from server import *
import requests
from server import databaseManager


def getJokesIntoDatabase():
    for i in range(0, 10):
        r = requests.get('https://icanhazdadjoke.com', headers={"Accept": "application/json"})
        responseJson = json.loads(r.content)
        databaseManager.insertJoke(responseJson["id"], responseJson["joke"])


def generateRandomId():
    return ''.join(random.choices(string.ascii_uppercase + string.digits, k=11))