# Завдання 1
# Користувач вводить із клавіатури два числа (початок і кінець діапазону).
# Потрібно проаналізувати всі числа в цьому діапазоні за таким правилом: якщо число кратне 7, його треба виводити на екран.

startNumber = int(input("Введіть початок діапазону: "))
endNumber = int(input("Введіть кінець діапазону: "))

print("Усі числа діапазону:")
print(*range(startNumber, endNumber + 1))

print("Усі числа, кратні 7:")
for i in range(startNumber, endNumber + 1):
      if i % 7 == 0:
          print(i, end=" ")