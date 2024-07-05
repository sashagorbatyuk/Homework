# Кортежі з вкладеними кортежами:
# Створіть кортеж, що містить вкладені кортежі. Вручну отримайте елементи з цих вкладених кортежів.
# Створимо кортеж з вкладеними кортежами
nested_tuple = ((1, 2, 3), (4, 5, 6), (7, 8, 9))

# Отримаємо елементи з вкладених кортежів
first_element_first_tuple = nested_tuple[0][0]
second_element_second_tuple = nested_tuple[1][1]
third_element_third_tuple = nested_tuple[2][2]

# Виведемо результати
print("Перший елемент першого кортежу:", first_element_first_tuple)
print("Другий елемент другого кортежу:", second_element_second_tuple)
print("Третій елемент третього кортежу:", third_element_third_tuple)