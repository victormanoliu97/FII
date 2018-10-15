from itertools import combinations

#ex 1
def fibonacci_aux(n):
    if n == 0:
        return 0 
    elif n == 1:
        return 1 
    else:
        return fibonacci_aux(n-1) + fibonacci_aux(n-2)

def ex_1(n):
    fibonacciList = []
    for i in range(1, n+1):
        fibonacciList.append(fibonacci_aux(i))
    
    print("Ex 1 : Lista de ", n ,"numere fibonacci", "este", fibonacciList)

ex_1(3)

#ex 2
def checkNumberIsPrime(number):
    if number < 2:
        return False
    if number == 2:
        return True

    for i in range(2, number // 2):
        if number % i == 0:
            return False
    return True

def ex_2(numberList):
    resultList = []
    for i in numberList:
        if checkNumberIsPrime(i) == True:
            resultList.append(i)
    
    print(resultList)

ex_2([5,3,8,11])


#ex 3 
def checkLineCoefficients(point, a, b, c):
    if a * point[0] + b * point[1] + c == 0:
        return True
    else:
        return False

def ex_3(pointsList):
    resultList = []
    for point in pointsList:
        for a in range(-100, 100):
            for b in range(-100, 100):
                for c in range(-100, 100):
                    if checkLineCoefficients(point, a, b, c) and (a,b,c) not in resultList:
                        resultList.append((a,b,c))

    print(resultList)

#ex_3([1,10,20])

#ex 4
def ex_4(a,b):
    a_intersected_b = set(a).intersection(b)
    a_reunited_b = set(a).union(b)
    a_minus_b = set(a).difference(b)
    b_minus_a = set(b).difference(a)

    print("Ex 4")
    print("A intersectat cu B", a_intersected_b)
    print("A reunit cu B", a_reunited_b)
    print("A minus B", a_minus_b)
    print("B minus A", b_minus_a)

ex_4([1,2,3],[3,4,5])

#ex 5
def ex_5(x, k):
    print("Toate combinarile posibile", list(combinations(x, k)))

ex_5([1,2,3,4],3)

#ex 6
def ex_6(*args):
    x = args[-1]
    auxList = []
    resultList = []
    lists = args[:-1]
    for i in lists:
        auxList += i

    for j in auxList:
        if auxList.count(j) == x:
            resultList.append(j)

    print(set(resultList))

ex_6([1,2,3], [2,3,4], [4,5,6], [4, 1, "test"], 2)


#ex 7
def ex_7(*args, x=1, flag=True):
    resultList = []
    for i in args:
        for j in i:
            if flag == True and ord(j) % x == 0:
                resultList.append(j)
            elif flag == False and ord(j) % x != 0:
                resultList.append(j)

    print(resultList)

ex_7("test", "hello", "lab002", x=2, flag=False)

