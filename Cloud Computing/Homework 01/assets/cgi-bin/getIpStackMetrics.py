from assets.metric_util import metricsUtil
import cgi
from server import *
import json

print("Content-Type: text/html\n")
arguments = cgi.FieldStorage()


def getIpStackMetrics():
    return json.dumps(metricsUtil.computeIpStackMetrics(apiName="IP_Stack"))

print(getIpStackMetrics())
