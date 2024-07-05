# Генерація випадкових кортежів:
# Створіть список з 10 випадкових кортежів, кожен з яких містить по три випадкових числа від 1 до 100. Потім вручну перетворіть цей список на множину унікальних кортежів.
import random

random_tuples_list = [(random.randint(1, 10), random.randint(1, 10), random.randint(1, 10)) for _ in range(10)]

unique_tuples_set = set(random_tuples_list)

# Виводимо результати для перевірки
print(f"Початковий список кортежів: {random_tuples_list}")
print(f"Множина унікальних кортежів: {unique_tuples_set}")
