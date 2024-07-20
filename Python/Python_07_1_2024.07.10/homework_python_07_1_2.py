# Завдання 2
# Реалізуйте перше завдання через функцію. Функція повинна приймати ім'я і вік як параметри і повертати відформатований рядок.
# Перевірка коректності отриманих даних повинна бути всередині функції. Створіть дві версії реалізації функції:
# Перша версія не обробляє виняток всередині функції. Уся обробка знаходиться зовні;
# Друга версія обробляє виняток усередині функції.

def greeting(name, age):
    if age < 0 or age > 130:
        raise ValueError("Некоректний вік. Вік повинен бути в межах від 0 до 130 років.")
    return f"Привіт, {name}! Твій вік — {age}."

def main():
    try:
        name = input("Введіть ваше ім'я: ")
        age = int(input("Введіть ваш вік: "))
        message = greeting(name, age)
        print(message)
    except ValueError as e:
        print(f"Помилка: {e}")


main()

print("************************************************************************************")

def greeting(name, age):
    try:
        if age < 0 or age > 130:
            raise ValueError("Некоректний вік. Вік повинен бути в межах від 0 до 130 років.")
        return f"Привіт, {name}! Твій вік — {age}."
    except ValueError as e:
        return f"Помилка: {e}"

def main():
    name = input("Введіть ваше ім'я: ")
    try:
        age = int(input("Введіть ваш вік: "))
    except ValueError:
        print("Помилка: Вік повинен бути числом.")
        return
    
    message = greeting(name, age)
    print(message)

main()
