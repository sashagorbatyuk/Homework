# 3 Напиши код, який приймає словник з унікальними значеннями і створює новий словник, де ключами є значення початкового словника, а значеннями — ключі початкового словника.
def invert_dict(unique_dict):
    inverted_dict = {}
    for key, value in unique_dict.items():
        inverted_dict[value] = key
    return inverted_dict

unique_dict = {'a': 1, 'b': 2, 'c': 3}
result = invert_dict(unique_dict)
print(result)