# Злиття множин:
# Створіть список списків, перетворіть кожен список на множину, і вручну знайдіть об'єднання всіх цих множин.
# Створюємо список списків
list_of_lists = [
    [1, 2, 3],
    [3, 4, 5],
    [5, 6, 7],
    [7, 8, 9]
]

# Перетворюємо кожен список на множину
set1 = set(list_of_lists[0])
set2 = set(list_of_lists[1])
set3 = set(list_of_lists[2])
set4 = set(list_of_lists[3])

# Вручну знаходимо об'єднання всіх цих множин
union_set = set1.union(set2).union(set3).union(set4)

# Виводимо результати для перевірки
print(f"Список списків: {list_of_lists}")
print(f"Множина 1: {set1}")
print(f"Множина 2: {set2}")
print(f"Множина 3: {set3}")
print(f"Множина 4: {set4}")
print(f"Об'єднання всіх множин: {union_set}")