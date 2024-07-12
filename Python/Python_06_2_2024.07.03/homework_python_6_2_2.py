# Завдання 2
# Напишіть функцію для знаходження мінімуму в списку цілих.
# Список передається як параметр. Отриманий результат повертається з функції.

def find_minimum(lst):
    if not lst:
        return None
    return min(lst)

numbers = [3, 1, -4, 1, 5, 9, -2]
print(find_minimum(numbers))
