# Завдання 2
# Написати гру "Бики і корови". Програма "загадує" чотиризначне число і гравець має вгадати його.
# Після введення користувачем числа програма повідомляє, скільки цифр числа вгадано (бики) і скільки цифр вгадано і стоїть на потрібному місці (корови).
# Після відгадування числа на екран необхідно вивести кількість спроб зроблених користувачем . У програмі необхідно використовувати рекурсію.

import random

def generate_secret_number():
    # Генерує чотиризначне число, де всі цифри різні.
    digits = random.sample(range(10), 4)
    return ''.join(map(str, digits))

def evaluate_guess(secret, guess):
    # Оцінює здогадку гравця і повертає кількість биків і корів.
    cows = sum(s == g for s, g in zip(secret, guess))
    bulls = sum(s in guess for s in secret)
    return bulls, cows

def game_recursive(secret, attempts=0):
    # Рекурсивна функція для гри.
    guess = input("Введіть вашу здогадку (число з 4 унікальних цифр): ")
    if len(guess) != 4 or not guess.isdigit() or len(set(guess)) != 4:
        print("Невірний ввід. Будь ласка, введіть число з 4 унікальних цифр")
        return game_recursive(secret, attempts)

    attempts += 1
    bulls, cows = evaluate_guess(secret, guess)
    print(f"Бики: {bulls}, Корови: {cows}")

    if cows == 4:
        print(f"Ви відгадали число {secret} за {attempts} спроб!")
    else:
        return game_recursive(secret, attempts)

def start_game():
    # Функція для запуску гри.
    secret_number = generate_secret_number()
    print("Гра 'Бики і корови' почалася!")
    print(secret_number)
    game_recursive(secret_number)

# Запуск гри
start_game()
