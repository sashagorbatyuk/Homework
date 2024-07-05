# Обробка множин:
# Створіть два списки, перетворіть їх на множини, знайдіть їх об'єднання, перетин, різницю та симетричну різницю, і виведіть результати.
list1 = [1, 2, 3, 4, 5]
list2 = [4, 5, 6, 7, 8]

set1 = set(list1)
set2 = set(list2)

union_set = set1.union(set2)

intersection_set = set1.intersection(set2)

difference_set = set1.difference(set2)

sym_dif_set = set1.symmetric_difference(set2)

print("Перший список:", list1)
print("Другий список:", list2)
print("Перша множина:", set1)
print("Друга множина:", set2)
print("Обєднання множин:",union_set) 
print("Перетин множин:", intersection_set)
print("Різниця множин:", difference_set)
print("Симетрична різниця множин:", sym_dif_set)
print("*************************************************")


# Створіть два кортежі чисел, перетворіть їх на множини, знайдіть спільні елементи, і вручну перетворіть їх на кортеж.
tuple1 = (1, 2, 3, 4, 5)
tuple2 = (4, 5, 6, 7, 8)

set_1 = set(tuple1)
set_2 = set(tuple2)

common_elements = set_1.intersection(set_2)

common_tuple = tuple(common_elements)

print("Перший кортеж:", tuple1)
print("Другий кортеж:", tuple2)
print("Спільні елементи:", common_elements)
print("Кортеж спільних елементів:", common_tuple)
