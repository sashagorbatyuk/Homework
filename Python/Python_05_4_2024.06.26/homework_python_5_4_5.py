# Сортування унікальних елементів:
# Створіть список чисел, знайдіть унікальні елементи, сортуйте їх і вручну перетворіть на кортеж.
numbers_list = [4, 6, 2, 8, 4, 2, 9, 1, 6]
print(f"Список чисел: {numbers_list}")

unique_numbers_set = set(numbers_list)
print(f"Унікальні числа: {unique_numbers_set}")

unique_numbers_list = list(unique_numbers_set)
unique_numbers_list.sort()
print(f"Відсортовані унікальні числа: {unique_numbers_list}")

sorted_unique_numbers_tuple = tuple(unique_numbers_list)
print(f"Кортеж унікальних відсортованих чисел: {sorted_unique_numbers_tuple}")
