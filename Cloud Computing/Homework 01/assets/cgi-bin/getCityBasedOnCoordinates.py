import json
import urllib.request
import cgi
from server import *
from utils.apiUtils import returnAPIKey, writeJsonToFile, parallelExecuteRequest
import requests
from utils.request import Request

print("Content-Type: text/html\n")

arguments = cgi.FieldStorage()

def getLocation():
    apiKey = returnAPIKey("ip_stack")
    ipStackEndpoint = "http://api.ipstack.com/81.180.208.125?access_key=" + str(apiKey)
    response = json.loads(urllib.request.urlopen(ipStackEndpoint).read().decode("utf-8"))
    return response


def logGetCityBasedOnCoordinates():
    apiKey = returnAPIKey("google_geo")
    latitude = str(getLocation()["latitude"])
    longitude = str(getLocation()["longitude"])
    googleMapsEndPoint = "https://maps.googleapis.com/maps/api/geocode/json?latlng=" + latitude + "," + longitude + \
                         "&key=" + str(apiKey)

    googleMapsEndPointToLog = "https://maps.googleapis.com/maps/api/geocode/json?latlng=" + latitude + "," + longitude + \
                              "&key="

    detailedResponse = requests.get(googleMapsEndPoint)
    request = Request("Google_GEO", googleMapsEndPointToLog, detailedResponse.encoding, detailedResponse.status_code,
                      detailedResponse.elapsed.total_seconds())

    writeJsonToFile(request)


def getCityBasedOnCoordinates():
    apiKey = returnAPIKey("google_geo")
    latitude = str(getLocation()["latitude"])
    longitude = str(getLocation()["longitude"])

    googleMapsEndPoint = "https://maps.googleapis.com/maps/api/geocode/json?latlng=" + latitude + "," + longitude + \
                         "&key=" + str(apiKey)

    response = json.loads(urllib.request.urlopen(googleMapsEndPoint).read().decode("utf-8"))

    parallelExecuteRequest(functionName=logGetCityBasedOnCoordinates)

    return response


print(getCityBasedOnCoordinates())