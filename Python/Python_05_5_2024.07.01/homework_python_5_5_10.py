# 10 Напиши код, який приймає словник, значеннями якого є інші словники з числовими значеннями, і підраховує суму всіх числових значень. 
# Наприклад, {'a': {'x': 1, 'y': 2}, 'b': {'x': 3, 'y': 4}} -> 10.
def sum_nested_dict_values(nested_dict):
    total_sum = 0
    for key, inner_dict in nested_dict.items():
        for inner_key, value in inner_dict.items():
            total_sum += value
    return total_sum

nested_dict = {'a': {'x': 1, 'y': 2}, 'b': {'x': 3, 'y': 4}}
dict_total_sum = sum_nested_dict_values(nested_dict)
print(dict_total_sum)