# Завдання 2
# Напишіть функцію, яка приймає два числа як параметр і відображає всі парні числа між ними.

def display_even_numbers(start, end):
    for number in range(start + 1, end):
        if number % 2 == 0:
            print(number)

display_even_numbers(1, 10)
