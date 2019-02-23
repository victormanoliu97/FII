from assets.metric_util import metricsUtil
import cgi
from server import *
import json

print("Content-Type: text/html\n")
arguments = cgi.FieldStorage()

def getWeatherMetrics():
    return json.dumps(metricsUtil.computeWeatherMetrics(apiName="OpenWeather"))

print(getWeatherMetrics())