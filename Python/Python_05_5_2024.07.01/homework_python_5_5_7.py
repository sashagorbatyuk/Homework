# 7 Напиши код, який приймає список кортежів (де кожен кортеж складається з двох елементів) 
# і створює словник, де ключами є перші елементи кортежів, а значеннями — списки других елементів кортежів, згрупованих за першим елементом.
# Наприклад, [(1, 'a'), (2, 'b'), (1, 'c')] -> {1: ['a', 'c'], 2: ['b']}.
def group_tuples(tuples_list):
    grouped_dict = {}
    for key, value in tuples_list:
        if key in grouped_dict:
            grouped_dict[key].append(value)
        else:
            grouped_dict[key] = [value]
    return grouped_dict

tuples_list = [(1, 'a'), (2, 'b'), (1, 'c')]
result = group_tuples(tuples_list)
print(result)