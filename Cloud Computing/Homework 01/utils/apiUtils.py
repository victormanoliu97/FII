import json

def returnAPIKey(keyName):
    with open('../config/api_keys.json') as f:
        data = json.load(f)

    return data[keyName]


def writeJsonToFile(response):
    with open('../logs/request-logs.json', 'a') as outfile:
        outfile.truncate()
        outfile.write(',')
        json.dump(response.__str__(), outfile, indent=6)


def parallelExecuteRequest(functionName):
    agents = 100

    # pool = Pool(processes=agents)
    # pool.apply_async(functionName, endpoint)

    for i in range(10):
        functionName()

