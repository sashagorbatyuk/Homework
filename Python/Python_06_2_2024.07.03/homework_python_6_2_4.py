# Завдання 4
# Напишіть функцію, що видаляє зі списку цілих деяке задане число.
# З функції потрібно повернути кількість видалених елементів.
def remove_element(lst, value):
    initial_length = len(lst)
    lst[:] = [num for num in lst if num != value]
    return initial_length - len(lst)

numbers = [1, 2, 3, 2, 4, 2, 5]
print(numbers)

removed_count = remove_element(numbers, 2)

print("removed_count: ", removed_count) 
print(numbers)
