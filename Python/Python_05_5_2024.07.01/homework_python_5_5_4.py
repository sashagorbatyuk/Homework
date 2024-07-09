# 4 Напиши код, який сортує словник за його ключами і створює новий словник, відсортований за зростанням або спаданням ключів.
def invert_dict(unique_dict):
    sorted_dict = dict(sorted(unique_dict.items(), reverse=True))
    return sorted_dict

unique_dict = {'a': 1, 'd': 0, 'b': 2, 'c': 3}
result = invert_dict(unique_dict)
print(result)