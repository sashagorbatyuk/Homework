# Завдання 1
# Користувач вводить із клавіатури арифметичний вираз. Наприклад, 23+12.
# Необхідно вивести на екран результат виразу. Для нашого прикладу — це 35.
# Арифметичний вираз може складатися тільки з трьох частин: число, операція, число. Можливі операції: +, -, *, /.

import re

# Повертає результат обчислення арифметичного виразу
def calculate_expression(expression):
    # Розділяєм вираз на частини
    parts = re.split('(\+|-|\*|/)', expression)
    
    # Перевіряєм, чи вираз складається з трьох частин: число, операція, число
    if len(parts) != 3:
        return "Неправильний формат виразу"
    
    # Отримуєм частини виразу
    num1, operator, num2 = parts
    
    try:
        num1 = float(num1)
        num2 = float(num2)
    except ValueError:
        return "Неправильні числа у виразі"
    
    # Обчислюєм
    if operator == '+':
        result = num1 + num2
    elif operator == '-':
        result = num1 - num2
    elif operator == '*':
        result = num1 * num2
    elif operator == '/':
        if num2 == 0:
            return "Ділення на нуль неможливе"
        result = num1 / num2
    else:
        return "Неправильний оператор"
    
    return result

# Отримуєм арифметичний вираз від користувача
expression = input("Введіть арифметичний вираз (наприклад, 23+12): ")

# Обчислюєм результат і виводим результат на екран
result = calculate_expression(expression)
print("Результат:", result)
