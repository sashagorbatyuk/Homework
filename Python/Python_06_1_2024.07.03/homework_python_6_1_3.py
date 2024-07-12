# Завдання 3
# Напишіть функцію, яка відображає порожній або заповнений квадрат з певного символу. Функція приймає як параметри довжину сторони квадрата, символ і змінну логічного типу:
# якщо вона дорівнює True, квадрат заповнений;
# якщо — False, квадрат порожній.

def display_square(size, symbol, filled):
    for i in range(size):
        if filled or i == 0 or i == size - 1:
            print(symbol * size)
        else:
            print(symbol + ' ' * (size - 2) + symbol)

# Виклик функції для заповненого квадрата
display_square(5, '*', True)

# Виклик функції для порожнього квадрата
display_square(8, 'n', False)
