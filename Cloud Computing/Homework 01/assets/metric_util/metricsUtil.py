import json
import statistics
import os
import scipy.stats

def readFromJson():
    with open('D:\\Facultate\\Anul 3\\Semestrul 2\\Cloud Computing\\Tema 01\\logs\\request-logs.json', 'r') as json_file:
        data = json.load(json_file)

    return data


def computeIpStackMetrics(apiName):
    ipStackMetrics = {}
    global i
    statsList = readFromJson()
    jsonObj = []
    responseTimeList = []
    statusCodeList = []
    encodingList = []
    name = ""
    url = ""

    for i in statsList:
        if i["name"] == apiName:
            jsonObj.append(i)

    for i in jsonObj:
        responseTimeList.append(i["time"])
        statusCodeList.append(i["response"])
        encodingList.append(i["encoding"])
        name = i["name"]
        url = i["url"]

    succesRequestsCounter = 0
    failedRequestsCounter = 0
    for i in statusCodeList:
        if i == 200:
            succesRequestsCounter += 1
        else:
            failedRequestsCounter += 1

    ipStackMetrics["name"] = name
    ipStackMetrics["link"] = url
    ipStackMetrics["average_time"] = statistics.mean(responseTimeList)
    ipStackMetrics["succes_requests_perc"] = str(succesRequestsCounter / len(statusCodeList) * 100) + "%"
    ipStackMetrics["failed_requests_perc"] = str(failedRequestsCounter / len(statusCodeList) * 100) + "%"
    ipStackMetrics["encoding"] = encodingList.__getitem__(0)

    return ipStackMetrics



def computeGoogleMetrics(apiName):
    ipStackMetrics = {}
    global i
    statsList = readFromJson()
    jsonObj = []
    responseTimeList = []
    statusCodeList = []
    encodingList = []
    name = ""
    url = ""

    for i in statsList:
        if i["name"] == apiName:
            jsonObj.append(i)

    for i in jsonObj:
        responseTimeList.append(i["time"])
        statusCodeList.append(i["response"])
        encodingList.append(i["encoding"])
        name = i["name"]
        url = i["url"]

    succesRequestsCounter = 0
    failedRequestsCounter = 0
    for i in statusCodeList:
        if i == 200:
            succesRequestsCounter += 1
        else:
            failedRequestsCounter += 1

    ipStackMetrics["name"] = name
    ipStackMetrics["link"] = url
    ipStackMetrics["average_time"] = statistics.mean(responseTimeList)
    ipStackMetrics["succes_requests_perc"] = str(succesRequestsCounter / len(statusCodeList) * 100) + "%"
    ipStackMetrics["failed_requests_perc"] = str(failedRequestsCounter / len(statusCodeList) * 100) + "%"
    ipStackMetrics["encoding"] = encodingList.__getitem__(0)

    return ipStackMetrics



def computeWeatherMetrics(apiName):
    ipStackMetrics = {}
    global i
    statsList = readFromJson()
    jsonObj = []
    responseTimeList = []
    statusCodeList = []
    encodingList = []
    name = ""
    url = ""

    for i in statsList:
        if i["name"] == apiName:
            jsonObj.append(i)

    for i in jsonObj:
        responseTimeList.append(i["time"])
        statusCodeList.append(i["response"])
        encodingList.append(i["encoding"])
        name = i["name"]
        url = i["url"]

    succesRequestsCounter = 0
    failedRequestsCounter = 0
    for i in statusCodeList:
        if i == 200:
            succesRequestsCounter += 1
        else:
            failedRequestsCounter += 1

    ipStackMetrics["name"] = name
    ipStackMetrics["link"] = url
    ipStackMetrics["average_time"] = statistics.mean(responseTimeList)
    ipStackMetrics["succes_requests_perc"] = str(succesRequestsCounter / len(statusCodeList) * 100) + "%"
    ipStackMetrics["failed_requests_perc"] = str(failedRequestsCounter / len(statusCodeList) * 100) + "%"
    ipStackMetrics["encoding"] = encodingList.__getitem__(0)

    return ipStackMetrics
