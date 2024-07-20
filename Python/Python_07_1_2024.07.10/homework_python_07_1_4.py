# Завдання 4
# Реалізуйте третє завдання через функцію. Функція повинна приймати список як аргумент і повертати суму елементів списку.
# Перевірка коректності отриманих даних повинна бути всередині функції. Створіть дві версії реалізації функції:
# Перша версія не обробляє виняток всередині функції. Уся обробка знаходиться зовні;
# Друга версія обробляє виняток усередині функції.

def sum_positive_numbers1(numbers):
    for number in numbers:
        if number < 0:
            raise ValueError("Знайдено від'ємне значення у списку.")
    return sum(numbers)

def main1():
    numbers = []
    
    while True:
        user_input = input("Введіть число (або 'стоп' для завершення): ")

        if user_input.lower() == 'стоп':
            break

        try:
            number = float(user_input)
            numbers.append(number)
        except ValueError as e:
            print(f"Помилка: {e}")

    try:
        result = sum_positive_numbers1(numbers)
        print(f"Сума всіх додатних чисел у списку: {result}")
    except ValueError as e:
        print(f"Помилка: {e}")

main1()


print("********************************************************************")

def sum_positive_numbers2(numbers):
    try:
        for number in numbers:
            if number < 0:
                raise ValueError("Знайдено від'ємне значення або нуль у списку.")
        return sum(numbers)
    except ValueError as e:
        return f"Помилка: {e}"

def main2():
    numbers = []

    while True:
        user_input = input("Введіть число (або 'стоп' для завершення): ")

        if user_input.lower() == 'стоп':
            break

        try:
            number = float(user_input)
            numbers.append(number)
        except ValueError as e:
            print(f"Помилка: {e}")

    result = sum_positive_numbers2(numbers)
    
    if isinstance(result, str):
        print(result)
    else:
        print(f"Сума всіх додатних чисел у списку: {result}")

main2()