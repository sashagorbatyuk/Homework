# 6 Напиши код, який приймає список кортежів (де кожен кортеж складається з двох елементів) і перетворює його на словник.
# Наприклад, [(1, 'a'), (2, 'b'), (3, 'c')] -> {1: 'a', 2: 'b', 3: 'c'}.
def tuples_to_dict(tuples_list):
    result_dict = {key: value for key, value in tuples_list}
    return result_dict

tuples_list = [(1, 'a'), (2, 'b'), (3, 'c')]
result = tuples_to_dict(tuples_list)
print(result)