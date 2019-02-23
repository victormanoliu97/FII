import requests
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

def getCityBasedOnCoordinates():
    apiKey = returnAPIKey("google_geo")
    latitude = str(getLocation()["latitude"])
    longitude = str(getLocation()["longitude"])

    googleMapsEndPoint = "https://maps.googleapis.com/maps/api/geocode/json?latlng=" + latitude + "," + longitude + \
                         "&key=" + str(apiKey)

    response = json.loads(urllib.request.urlopen(googleMapsEndPoint).read().decode("utf-8"))

    return response

def logGetWeatherBasedOnCity():
    apiKey = returnAPIKey("open_weather")
    plusCode = str(getCityBasedOnCoordinates()["plus_code"])
    city = plusCode.split().__getitem__(2).replace(",", "")

    openWeatherEndPoint = "https://samples.openweathermap.org/data/2.5/weather?q=" + str(city) + "&appid=" + str(apiKey)
    openWeatherEndPointToLog = "https://samples.openweathermap.org/data/2.5/weather?q=" + str(city)

    detailedResponse = requests.get(openWeatherEndPoint)

    request = Request("OpenWeather", openWeatherEndPointToLog, detailedResponse.encoding, detailedResponse.status_code,
                      detailedResponse.elapsed.total_seconds())

    writeJsonToFile(request)

def getWeatherBasedOnCity():
    apiKey = returnAPIKey("open_weather")
    plusCode = str(getCityBasedOnCoordinates()["plus_code"])
    city = plusCode.split().__getitem__(2).replace(",", "")

    openWeatherEndPoint = "https://samples.openweathermap.org/data/2.5/weather?q=" + str(city) + "&appid=" + str(apiKey)

    response = requests.get(openWeatherEndPoint)

    parallelExecuteRequest(functionName=logGetWeatherBasedOnCity)

    return response.json()["weather"]


print(getWeatherBasedOnCity())
