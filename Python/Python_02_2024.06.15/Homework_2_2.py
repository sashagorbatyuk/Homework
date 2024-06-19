# Завдання 2
# Користувач вводить із клавіатури три числа. 
# Залежно від вибору користувача програма виводить на екран максимум із трьох, мінімум із трьох або середньоарифметичне трьох чисел.

# функція перевірки числа на float
def isFloat(num):
    try:
        float(num)
        return True
    except ValueError:
        return False

# введення та валідація трьох чисел
while(True):
    num1String = input("Введіть перше число: ")
    if(isFloat(num1String)): 
        num1 = float(num1String)
        break
    else:
        print(f"Введено невірне число. Повторіть введення")
        continue

while(True): 
    num2String = input("Введіть друге число: ")
    if(isFloat(num2String)): 
        num2 = float(num2String)
        break
    else:
        print(f"Введено невірне число. Повторіть введення")
        continue

while(True): 
    num3String = input("Введіть третє число: ")
    if(isFloat(num3String)):
        num3 = float(num3String)
        break
    else:
        print(f"Введено невірне число. Повторіть введення")
        continue

# введення та валідація операції з введеними числами
while(True): 
    operation = input("Введіть min, max або avg: ")
    if(operation in ["min", "max", "avg"]):
        break
    else:
        print("Введено невірне значення. Введіть min, max або avg")
        continue

# обчислення та виведення результату
if operation == 'min':
    result = min(num1, num2, num3)
    print("Мінімальне число:", result)

elif operation == 'max':
    result = max(num1, num2, num3)
    print("Максимальне число:", result)

elif operation == 'avg':
    result = (num1+num2+num3) / 3
    print("Середнє арифметичне чисел дорівнює:", result)

else:
    print(f"Вибачте, щось пішло не так!")