# Завдання 1
# Користувач вводить із клавіатури три числа. 
# Залежно від вибору користувача програма виводить на екран суму трьох чисел або добуток трьох чисел

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

# введення та валідація наступної дії
while(True): 
    operator = input("Введіть дію + або * : ")
    if(operator in ["*", "+"]):
        break
    else:
        print("Введено невірну дію. Введіть + або *")
        continue

# виконуєм обрахунок
if operator == "*":
    result = (num1*num2*num3)
    print(f"Добуток чисел {num1}, {num2} та {num3} дорівнює = ", result)
elif operator == "+":
    result = (num1+num2+num3)
    print(f"Сума чисел {num1}, {num2} та {num3} дорівнює = ", result)
else:
    print(f"Вибачте, щось пішло не так!")