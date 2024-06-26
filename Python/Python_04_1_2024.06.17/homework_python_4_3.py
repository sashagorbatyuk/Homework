# Завдання 3
# Користувач вводить із клавіатури два числа (початок і кінець діапазону). 
# Потрібно проаналізувати всі числа в цьому діапазоні. 
# Виведення на екран має відбуватися за правилами, зазначеними нижче.

# Якщо число кратне 3 (ділиться на 3 без залишку), потрібно вивести слово "Fizz". 
# Якщо число кратне 5, потрібно вивести слово "Buzz". Якщо число кратне 3 і 5, потрібно вивести "Fizz Buzz". 
# Якщо число не кратне ні 3, ні 5, потрібно вивести саме число.

startNumber = int(input("Enter start number of range: "))
endNumber = int(input("Enter end number of range: "))

for i in range(startNumber, endNumber + 1):
    if i % 3 == 0 and i % 5 == 0:
        print("Fizz Buzz")
    elif i % 3 == 0:
        print("Fizz")
    elif i % 5 == 0:
        print("Buzz")
    else:
        print(i)