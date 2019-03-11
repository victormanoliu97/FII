import pymysql.cursors
import pymysql
import json


def readDBConfig(keyname):
    with open('../config/db_config.json') as f:
        data = json.load(f)

    return data[keyname]


# connection = pymysql.connect(host=readDBConfig("db_host"),
#                              user=readDBConfig("db_username"),
#                              password=readDBConfig("db_password"),
#                              db = readDBConfig("db_name"),
#                              charset=readDBConfig("charset"),
#                              cursorclass=pymysql.cursors.DictCursor)

connection = pymysql.connect(host="localhost",
                             user="root",
                             password="victor",
                             db="cc_homework02",
                             charset="utf8mb4",
                             cursorclass=pymysql.cursors.DictCursor)


def insertJoke(jokeId, jokeText):
    with connection.cursor() as cursor:
        querystring = "insert into `DadJokes` VALUES(%s, %s)"
        cursor.execute(querystring, (jokeId, jokeText))
        connection.commit()


def getAllJokes():
    with connection.cursor() as cursor:
        querystring = "select * from `DadJokes`"
        cursor.execute(querystring)
        result = cursor.fetchall()
        return result


def getJoke(joke_id):
    with connection.cursor() as cursor:
        querystring = "select jokeText from `DadJokes` WHERE `jokeId` = %s"
        cursor.execute(querystring, str(joke_id))
        result = cursor.fetchone()
        return result


def updateJoke(jokeId, jokeText):
    with connection.cursor() as cursor:
        querystring = "update `DadJokes` set jokeText = %s where jokeId = %s"
        cursor.execute(querystring, (jokeText, jokeId))
        connection.commit()


def deleteJoke(jokeId):
    with connection.cursor() as cursor:
        querystring = "delete from `DadJokes` WHERE `jokeId` = %s"
        cursor.execute(querystring, str(jokeId))
        connection.commit()