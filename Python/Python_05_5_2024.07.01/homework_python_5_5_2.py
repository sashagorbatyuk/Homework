# 2 Напиши код, який об'єднує два словники. Якщо ключі збігаються, значення повинні бути об'єднані у список.
def merge_dicts(dict1, dict2):
    merged_dict = dict1.copy()
    for key, value in dict2.items():
        if key in merged_dict:
            if not isinstance(merged_dict[key], list):
                merged_dict[key] = [merged_dict[key]]
            merged_dict[key].append(value)
        else:
            merged_dict[key] = value
    return merged_dict

dict1 = {'a': 1, 'b': 2, 'c': 3}
dict2 = {'b': 4, 'c': 5, 'd': 6}
print(merge_dicts(dict1, dict2))