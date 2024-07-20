# Завдання 1
# Напишіть програму, яка запитує у користувача число і обчислює його факторіал. 
# Обробіть виняток, що виникає при введенні від'ємного числа, і виведіть повідомлення про помилку.
def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)

def main():
    try:
        number = int(input("Введіть число для обчислення факторіалу: "))
        
        if number < 0:
            raise ValueError("Факторіал визначається тільки для невід'ємних цілих чисел.")
        
        result = factorial(number)
        print(f"Факторіал числа {number} дорівнює {result}.")
    
    except ValueError as e:
        print(f"Помилка: {e}")

main()
