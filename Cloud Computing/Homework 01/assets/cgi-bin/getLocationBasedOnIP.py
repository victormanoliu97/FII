import json
import urllib.request
import cgi
from server import *
from utils.apiUtils import returnAPIKey, writeJsonToFile, parallelExecuteRequest
import requests
from utils.request import Request


print("Content-Type: text/html\n")

arguments = cgi.FieldStorage()


def logLocationRequest():
    apiKey = returnAPIKey("ip_stack")
    ipStackEndpoint = "http://api.ipstack.com/81.180.208.125?access_key=" + str(apiKey)
    ipStackEndPointToLog = "http://api.ipstack.com/81.180.208.125?access_key="

    detailedResponse = requests.get(ipStackEndpoint)
    request = Request("IP_Stack", ipStackEndPointToLog, detailedResponse.encoding, detailedResponse.status_code,
                      detailedResponse.elapsed.total_seconds())

    writeJsonToFile(request)


def getLocation():
    apiKey = returnAPIKey("ip_stack")
    ipStackEndpoint = "http://api.ipstack.com/81.180.208.125?access_key=" + str(apiKey)
    response = json.loads(urllib.request.urlopen(ipStackEndpoint).read().decode("utf-8"))

    parallelExecuteRequest(functionName=logLocationRequest)

    return response


print(getLocation())
