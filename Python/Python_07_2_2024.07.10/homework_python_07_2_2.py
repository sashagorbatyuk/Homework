# Завдання 2
# Реалізуйте перше завдання через функцію. Функція повинна приймати число як параметр і повертати його факторіал.
# Перевірка коректності отриманих даних повинна бути всередині функції. Створіть дві версії реалізації функції:

# Перша версія не обробляє виняток усередині функції. Уся обробка знаходиться зовні;
# Друга версія обробляє виняток усередині функції.

def factorial(n):
    if n < 0:
        raise ValueError("Факторіал визначений тільки для невід'ємних чисел.")
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)

def main():
    try:
        number = int(input("Введіть число для обчислення факторіалу: "))
        result = factorial(number)
        print(f"Факторіал числа {number} дорівнює {result}.")
    except ValueError as e:
        print(f"Помилка: {e}")
    except (TypeError, ValueError):
        print("Помилка: введене значення повинно бути цілим числом.")

main()

print("**************************************************************************")

def factorial(n):
    try:
        if n < 0:
            raise ValueError("Факторіал визначений тільки для невід'ємних чисел.")
        if n == 0 or n == 1:
            return 1
        else:
            return n * factorial(n - 1)
    except ValueError as e:
        return f"Помилка: {e}"

def main():
    try:
        number = int(input("Введіть число для обчислення факторіалу: "))
    except ValueError:
        print("Помилка: введене значення повинно бути цілим числом.")
        return

    result = factorial(number)
    
    if isinstance(result, str):
        print(result)
    else:
        print(f"Факторіал числа {number} дорівнює {result}.")

main()