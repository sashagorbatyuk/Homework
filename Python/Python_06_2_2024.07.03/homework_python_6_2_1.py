# Завдання 1
# Напишіть функцію, що обчислює добуток елементів списку цілих.
# Список передається як параметр. Отриманий результат повертається з функції.

def product_of_elements(lst):
    result = 1
    for num in lst:
        result *= num
    return result

numbers = [1, 2, 3, 4, 5]
print(product_of_elements(numbers))
