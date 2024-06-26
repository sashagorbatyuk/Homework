# Завдання 2
# Користувач вводить із клавіатури два числа (початок і кінець діапазону). 
# Необхідно проаналізувати всі числа в цьому діапазоні. Потрібно вивести на екран:
# 1 - Всі числа діапазону.
# 2 - Всі числа діапазону в спадному порядку.
# 3 - Всі числа, кратні 7.
# 4 - Кількість чисел, кратних 5.

startNumber = int(input("Введіть початок діапазону: "))
endNumber = int(input("Введіть кінець діапазону: "))

print("Усі числа діапазону:", end=" ")
for i in range(startNumber, endNumber + 1):
    print(i, end=" ")

print()

print("Усі числа діапазону за спаданням:", end=" ")
for i in range(endNumber, startNumber - 1, -1):
    print(i, end=" ")

print()

print("Усі числа, кратні 7:", end=" ")
for i in range(startNumber, endNumber + 1):
    if i % 7 == 0:
        print(i, end=" ")

print()

count = 0
for i in range(startNumber, endNumber + 1):
    if i % 5 == 0:
        count += 1

print("Кількість чисел, кратних 5: ", count)