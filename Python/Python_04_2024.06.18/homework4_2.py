# Завдання 2
# Користувач вводить із клавіатури довжину лінії та символ для заповнення лінії. Потрібно відобразити на екрані вертикальну лінію з уведеного символу, вказаної довжини.

#  Зчитуємо довжину лінії та символ з клавіатури

length = int(input("Введіть довжину лінії: "))
symbol = input("Введіть символ для заповнення лінії: ")

# Виводимо лінію із заданими параметрами 

for i in range(length): 
    print(symbol)