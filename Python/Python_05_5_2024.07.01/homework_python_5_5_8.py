# 8 Напиши код, який приймає два словники, де значеннями є списки, і створює новий словник, де значеннями є об'єднані списки зі спільними ключами. 
# Наприклад, {'a': [1, 2], 'b': [3, 4]} і {'a': [5], 'b': [6, 7]} -> {'a': [1, 2, 5], 'b': [3, 4, 6, 7]}.
def merge_dicts(dict1, dict2):
    merged_dict = {}
    
    # Об'єднанeуємо ключів обох словників
    all_unique_keys = set(dict1.keys()).union(set(dict2.keys()))
    
    for key in all_unique_keys:
        merged_dict[key] = []
        if key in dict1:
            merged_dict[key].extend(dict1[key])
        if key in dict2:
            merged_dict[key].extend(dict2[key])
    
    return merged_dict

dict1 = {'a': [1, 2], 'b': [3, 4]}
dict2 = {'a': [5], 'b': [6, 7]}
result = merge_dicts(dict1, dict2)
print(result)
