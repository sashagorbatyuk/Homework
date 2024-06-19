# Завдання 3
# Користувач вводить із клавіатури кількість метрів.
# Залежно від вибору користувача програма конвертує метри в милі, дюйми або ярди.

# функція перевірки числа (string) на float
def isFloat(num):
    try:
        float(num)
        return True
    except ValueError:
        return False 

# введення та валідація кількості метрів
while(True): 
    metersString = input("Введіть кількість метрів: ")
    if(isFloat(metersString)):  
        meters = float(metersString)
        break
    else:
        print(f"Введено невірне число. Повторіть введення")
        continue
 
# введення та валідація одиниця вимірювання
print("Оберіть одиницю вимірювання для конвертації:")
print("1. Милі")
print("2. Дюйми")
print("3. Ярди")

while(True):
    selectedItem = input("Ваш вибір:")
    if(selectedItem in ["1", "2", "3"]):
        break
    else:
        print(f"Введено невірне число з меню. Повторіть введення")
        continue

# конвертація метрів в інші одиниці вимірювання
if selectedItem == "1":
    miles = meters * 0.000621371
    print(f"{meters} метрів дорівнює {miles} миль")
elif selectedItem == "2":
    inches = meters * 39.3701
    print(f"{meters} метрів дорівнює {inches} дюймів")
elif selectedItem == "3":
    yards = meters * 1.09361
    print(f"{meters} метрів дорівнює {yards} ярдів")
else:
    print("Ви ввели неправильний вибір.")