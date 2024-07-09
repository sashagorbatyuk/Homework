# 9 Напиши код, який приймає словник з числовими значеннями і знаходить ключі з максимальним та мінімальним значеннями.
def find_min_max_keys(input_dict):
    if not input_dict:
        return None, None

    min_key = min(input_dict, key=input_dict.get)
    max_key = max(input_dict, key=input_dict.get)

    return min_key, max_key

input_dict = {'a': 10, 'b': 20, 'c': 5, 'd': 30, 'e': 25}
min_key, max_key = find_min_max_keys(input_dict)
print(f"Key with minimum value: {min_key}")
print(f"Key with maximum value: {max_key}")