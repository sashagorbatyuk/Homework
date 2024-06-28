# Завдання 2
# У списку цілих, заповненому випадковими числами, визначити мінімальний і максимальний елементи, 
# порахувати кількість від'ємних елементів, порахувати кількість додатних елементів, 
# порахувати кількість нулів. Результати вивести на екран.
import random

# Генеруємо список випадкових цілих чисел
random_list = [random.randint(-100,100) for _ in range(20)]
print("Згенерований список випадкових цілих чисел:", random_list)

# Знаходимо мінімальний та максимальний елементи
min_number = min(random_list)
max_number = max(random_list) 

# Рахуємо кількість від'ємних, додатніх та нульових елементів
negative_count = sum(1 for i in random_list if i < 0)
positive_count = sum(1 for i in random_list if i > 0)
zero_count = sum(1 for i in random_list if i == 0)

# Виводимо результат
print("Мінімальний елемент:", min_number)
print("Максимальний елемент:", max_number)
print("Кількість від'ємних елементів:", negative_count) 
print("Кількість додатніх елементів:", positive_count) 
print("Кількість нулів:", zero_count)