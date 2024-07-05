# Згортання кортежа:
# Створіть кортеж чисел і вручну обчисліть їх суму, добуток та середнє значення.
numbers_tuple = (1, 2, 3, 4, 5)

# Обчислюємо суму чисел у кортежі
sum_of_numbers = sum(numbers_tuple)

# Обчислюємо добуток чисел у кортежі
product_of_numbers = 1
for number in numbers_tuple:
    product_of_numbers *= number

# Обчислюємо середнє значення чисел у кортежі
average_of_numbers = sum_of_numbers / len(numbers_tuple)

# Виводимо результати для перевірки
print(f"Кортеж чисел: {numbers_tuple}")
print(f"Сума чисел: {sum_of_numbers}")
print(f"Добуток чисел: {product_of_numbers}")
print(f"Середнє значення чисел: {average_of_numbers:.2f}")
