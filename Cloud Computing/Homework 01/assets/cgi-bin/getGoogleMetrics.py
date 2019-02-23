from assets.metric_util import metricsUtil
import cgi
from server import *
import json

print("Content-Type: text/html\n")
arguments = cgi.FieldStorage()

def getGoogleMetrics():
    return json.dumps(metricsUtil.computeGoogleMetrics(apiName="Google_GEO"))

print(getGoogleMetrics())