# Завдання 3
# Напишіть програму, яка дозволяє користувачеві ввести з клавіатури набір додатних (число більше нуля) чисел.
# Числа необхідно накопичувати у списку. Після отримання всіх значень програма повинна проаналізувати дані.
# У разі виявлення від'ємного значення програма має згенерувати виняток. Якщо всі значення у списку позитивні, програма має повернути на екран суму всіх чисел списку.
# Згенерований виняток має бути оброблений кодом програми.

def collect_numbers():
    numbers = []

    while True:
        user_input = input("Введіть додатне число (або 'стоп' для завершення): ")

        if user_input.lower() == 'стоп':
            break

        try:
            number = float(user_input)
            numbers.append(number)
        except ValueError as e:
            print(f"Помилка: {e}")

    return numbers

def analyze_numbers(numbers):
    try:
        print(f"Аналіз даних ...")
        for number in numbers:
            if number < 0:
                raise ValueError("Знайдено від'ємне значення або нуль у списку.")
        return sum(numbers)
    except ValueError as e:
        print(f"Помилка: {e}")
        return None

def main():
    numbers = collect_numbers()
    result = analyze_numbers(numbers)
    
    if result is not None:
        print(f"Сума всіх додатних чисел у списку: {result}")
    else:
        print("Суму додатних чисел не рахуєм, оскільки при аналізі виявлено числа менше нуля у списку.")

main()