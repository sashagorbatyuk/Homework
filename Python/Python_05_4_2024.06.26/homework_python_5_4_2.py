# Фільтрація елементів кортежу:
# Створіть кортеж чисел і вручну створіть новий кортеж що містить тільки парні числа
my_tuple = (1, 2, 3, 4, 5)
even_tuple = (2, 4)

# Створіть кортеж з п'яти елементів і вручну отримайте два перших і два останніх елементи як окремі змінні, а середній елемент як список.
my_tuple = (1, 2, 3, 4, 5)

first_element = my_tuple[0]
second_element = my_tuple[1]

fourth_element = my_tuple[3]
fifth_element = my_tuple[4]

middle_element = [my_tuple[2]]

print(f"Перший елемент: {first_element}")
print(f"Другий елемент: {second_element}")
print(f"Четвертий елемент: {fourth_element}")
print(f"П'ятий елемент: {fifth_element}")
print(f"Середній елемент (як список): {middle_element}")
