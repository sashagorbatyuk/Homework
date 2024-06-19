# Завдання 3
# Напишіть програму, що обчислює площу ромба. 
# Користувач вводить із клавіатури довжину двох його діагоналей.

# введення та діагоналей ромбу
while(True):
    num1String = input("Введіть першу діагональ: ")
    if(str.isnumeric(num1String) and int(num1String) > 0): 
        num1 = int(num1String)
        break
    else:
        print(f"Введено невірне значення. Повторіть введення")
        continue

while(True): 
    num2String = input("Введіть друну діагональ: ")
    if(str.isnumeric(num2String) and int(num2String) > 0): 
        num2 = int(num2String)
        break
    else:
        print(f"Введено невірне значення. Повторіть введення")
        continue

print(f'S(ромба) = (a·b)/2 = {(num1*num2)/2}')