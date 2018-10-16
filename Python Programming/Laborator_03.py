#ex 1
def ex_1(a,b):
    a_intersected_b = frozenset(set(a).intersection(b))
    a_reunited_b = frozenset(set(a).union(b))
    a_minus_b = frozenset(set(a).difference(b))
    b_minus_a = frozenset(set(b).difference(a))

    result = set([a_intersected_b, a_reunited_b, a_minus_b, b_minus_a])
    print("Ex 1: ", result)

ex_1([1,2,3],[3,4,5])

#ex 2
def ex_2(string):
    resultDictionary = {}
    for i in string:
        resultDictionary[i] = string.count(i)

    print("Ex 2: ", resultDictionary)

ex_2("Ana are mere.")

#ex 3
def comp_val(a, b):
	types = [dict, set, list, tuple]
	indici = [list, tuple]
	if type(a) == type(b):
		if type(a) not in types:
			return a == b
		if len(a) != len(b):
			return False
		if type(a) in indici:
			for i in range(0, len(a)):
				if comp_val(a[i], b[i]) == False:
					print (a, b)
					return False
			return True
		else:
			a, b, c = comp_dict(a, b)
			if len(a) + len(b) + len(c) == 0:
				return False
			return True
	else:
		return False


def ex_3(dict1, dict2):
    cheile_comune_dar_cu_valori_diferite = []
    cheile_care_se_gasesc_doar_in_primul_dict = []
    cheile_care_se_gasesc_doar_in_al_doilea_dict = []

    for i in dict1:
        if i not in dict2:
            cheile_care_se_gasesc_doar_in_primul_dict.append(i)

    for i in dict2:
        if i not in dict1:
            cheile_care_se_gasesc_doar_in_al_doilea_dict.append(i)
        else:
            r = comp_val(dict1[i], dict2[i])
            if r == False:
                cheile_comune_dar_cu_valori_diferite.append(i)


    print("Ex 3",(cheile_comune_dar_cu_valori_diferite, cheile_care_se_gasesc_doar_in_primul_dict, cheile_care_se_gasesc_doar_in_al_doilea_dict))


ex_3({'a': 1, 'b': 1}, {'a': 1, 'b': [1, 2], 'c': 3})


#ex 4
def ex_4(tag, contents, **kwargs):
	attributes = ' '	
	for e in kwargs:
		attributes += e + '="' + kwargs[e] + '" '
	s = '<' + tag + attributes + '>'
	s += contents
	s += '</' + tag + '>'
	print("Ex 4", s)

ex_4("a", "Hello there", href="http://python.org", _class="my-link", id="someid")


#ex 6
global_dictionary = {
    "+": lambda a, b: a + b,     
    "*": lambda a, b: a * b,
    "/": lambda a, b: a / b,
    "%": lambda a, b: a % b
}
def ex_6(operator, a, b):
    result = global_dictionary[operator](a,b)
    print(result)

ex_6('+', 1, 2)


#ex 7
functions = {
    "print_all": lambda *a, **k: print(a, k),
    "print_args_commas": lambda *a, **k: print(a, k, sep=", "),
    "print_only_args": lambda *a, **k: print(a),
    "print_only_kwargs": lambda *a, **k: print(k)
}
def ex_7(operation, *a, **b):
    result = functions[operation](*a, **b)
    print(result)


#ex 8
def ex_8(mySet):
    count = 0;
    for i in mySet:
        count = count+1
    
    print((count,0))

ex_8(set({1,2,3,4}))

#ex 9
def ex_9(*sets):
    result = {}
    for i in range(0, len(sets)):
        for j in range(i+1, len(sets)):
            result[str(sets[i]) + '|' + str(sets[j])] = set(sets[i]).union(sets[j])
            result[str(sets[i]) + '&' + str(sets[j])] = set(sets[i]).intersection(sets[j])
            result[str(sets[i]) + '-' + str(sets[j])] = set(sets[i]).difference(sets[j])

    print(result)

ex_9({1, 2}, {2, 3})