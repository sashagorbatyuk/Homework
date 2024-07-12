# Завдання 6
# Напишіть функцію, що обчислює ступінь кожного елемента списку цілих. 
# Значення для ступеня передається як параметр, список теж передається як параметр.
# Функція повертає новий список, що містить отримані результати.

def power_of_elements(lst, degree):
    return [num ** degree for num in lst]

numbers = [1, 2, 3, 4, 5]
degree = 3
result = power_of_elements(numbers, degree)

print("numbers", numbers)
print("degree", degree)
print("result", result)
