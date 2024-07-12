# Завдання 5
# Напишіть функцію, яка повертає добуток чисел у вказаному діапазоні. Межі діапазону передаються як параметри. 
# Якщо межі діапазону переплутані (наприклад, 5 — верхня межа, 25 — нижня межа), їх треба поміняти місцями.

def product_in_range(start, end):
    if start > end:
        start, end = end, start
    product = 1
    for number in range(start, end + 1):
        product *= number
    return product

# Виклик функції
print(product_in_range(5, 2))
