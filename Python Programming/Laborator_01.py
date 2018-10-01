import re

#ex 1
def aux_cmmdc(x, y):
    while x != y:
        if x > y:
            x = x - y 
        else:
            y = y - x
    return x

def ex_1(*numbers):
    num1 = numbers[0]
    num2 = numbers[1]

    result = aux_cmmdc(num1, num2)

    for i in numbers:
        result = aux_cmmdc(result, i)
    print("Ex 1 CMMDC este:", result)

ex_1(6,12,9)

#ex 2
def ex_2(string):
    nr = 0
    for i in string:
        if i in "aeiouAEIOU":
            nr = nr+1
    print("Ex 2 Numarul de vocale este:", nr)

ex_2("ANA ARE MERE")

#ex 3
def ex_3(string):
    nr = len(re.findall("[a-zA-Z_]+", string))
    print("Ex 3 numarul de cuvinte este:", nr)

ex_3("ana are mere!ana...are pere")

#ex 4
def ex_4(string1, string2):
    firstCharacter = string1[0]
    nr = string2.count(firstCharacter)
    print("Ex 4 Caracterul", firstCharacter, "apare de", nr, "in string-ul", string2)

ex_4("ana", "ana are mere ana are pere")


# ex 5
def ex_5(string):
    nr = 0
    for i in string:
        if i == '\r':
            nr = nr + 1 
        elif i == '\t':
            nr = nr + 1
        elif i == '\n':
            nr = nr + 1 
        elif i == '\a':
            nr = nr + 1
        elif i == '\b':
            nr = nr + 1
        elif i == '\f':
            nr = nr + 1
        elif i == '\v':
            nr = nr + 1
    print("Ex 5", nr)

ex_5("ioana \a are mere")

#ex 6
def ex_6(string):
    print(re.sub('(?!^)([A-Z]+)', r'_\1', string).lower())

ex_6("UpperCamelCase")


#ex 7
def letter_start(string1, string2, index):
    if string2[0:index] == string1[len(string1)-index:]:
        return True 
    else:
        return False


def ex_7(char_len, *strings):
    for i in range(1, len(strings)):
        if letter_start(strings[i-1], strings[i], char_len):
            print("Cuvintele", strings[i-1], strings[i], "respecta regula")
        else:
            print("Cuvintele", strings[i-1], strings[i], "nu respecta regula")

  
ex_7(2, "bal", "alabama", "albatros", "ospiciu")


#ex 9
def checkNumberIsPrime(number):
    if number < 2:
        return False
    if number == 2:
        return True

    for i in range(2, number // 2):
        if number % i == 0:
            return False
    return True

def ex_9(string):
    numbersListAux = re.findall(r'\d+', string)
    numbersList = list(map(int, numbersListAux))
    
    maxi = numbersList[0]
    for i in numbersList:
        if maxi < i and checkNumberIsPrime(i):
            maxi = i

    print(maxi)


ex_9("ahsfaisd35biaishai23isisvdshcbsi271cidsbfsd97sidsda")