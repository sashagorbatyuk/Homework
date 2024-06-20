# Завдання 4
# Користувач вводить із клавіатури числа. Програма повинна підраховувати суму, максимум і мінімум введених чисел. 
# Коли користувач вводить число 7, програма припиняє свою роботу і виводить на екран напис "Good bye!".

sum = 0
isFirstNumber = True

while True:
    number = int(input("Enter number: "))
    
    if number == 7:
        print("Good bye!")
        break

    if isFirstNumber:
        minNumber = number
        maxNumber = number
        isFirstNumber = False
    else:
        minNumber = min(number, minNumber)
        maxNumber = max(number, maxNumber)

    sum += number

    print(f"Sum: ", sum)
    print("Min number is: ", minNumber)
    print("Max number is: ", maxNumber)
    print("================================")
