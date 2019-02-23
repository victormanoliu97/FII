class Request:
    def __init__(self, requestName, requestUrl, requestEncoding, requestResponse, requestTime):
        self.requestName = requestName
        self.requestUrl = requestUrl
        self.requestEncoding = requestEncoding
        self.requestResponse = requestResponse
        self.requestTime = requestTime

    def __str__(self):
        result = {"name": str(self.requestName), "url": str(self.requestUrl), "encoding": str(self.requestEncoding),
                  "response": self.requestResponse, "time": self.requestTime}
        return result
