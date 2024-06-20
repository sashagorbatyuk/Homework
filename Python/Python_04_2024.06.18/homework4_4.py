# Завдання 4
# Користувач вводить із клавіатури числа. Програма повинна підраховувати суму, максимум і мінімум введених чисел. 
# Коли користувач вводить число 7, програма припиняє свою роботу і виводить на екран напис "Good bye!".

number1 = int(input("Enter first number: "))

number2 = int(input("Enter second number: "))

sumresult = (number1+number2)
minnumber = min(number1, number2)
maxnumber = max(number1, number2)

print(f"Sum of {number1} and {number2} is: ",sumresult)

print("Min number is: ",minnumber)

print("Max number is: ", maxnumber)
