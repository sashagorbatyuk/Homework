# Завдання 3
# Напишіть програму, яка дає змогу користувачеві заповнити список із клавіатури числами. Після отримання даних відобразіть на екран меню, яке дозволяє виконати такі операції:

# Відображення списку;
# Отримання максимального значення у списку;
# Отримання мінімального значення у списку;
# Відображення значення елемента за індексом, введеним користувачем;
# Видалення елемента за індексом, введеним користувачем.
# Обробіть виняток, що виникає під час виходу за межі списку (користувач ввів неправильне значення для індексу елемента в списку), і виведіть повідомлення про помилку.

def display_menu():
    print("\nМеню:")
    print("1. Відображення списку")
    print("2. Отримання максимального значення у списку")
    print("3. Отримання мінімального значення у списку")
    print("4. Відображення значення елемента за індексом")
    print("5. Видалення елемента за індексом")
    print("6. Вихід")

def display_list(numbers):
    print("Список чисел:", numbers)

def get_max(numbers):
    if numbers:
        print("Максимальне значення у списку:", max(numbers))
    else:
        print("Список порожній.")

def get_min(numbers):
    if numbers:
        print("Мінімальне значення у списку:", min(numbers))
    else:
        print("Список порожній.")

def display_element_by_index(numbers):
    try:
        index = int(input("Введіть індекс елемента: "))
        print(f"Елемент на індексі {index}: {numbers[index]}")
    except IndexError:
        print("Помилка: індекс поза межами списку.")
    except ValueError:
        print("Помилка: індекс повинен бути цілим числом.")

def delete_element_by_index(numbers):
    try:
        index = int(input("Введіть індекс елемента для видалення: "))
        element = numbers.pop(index)
        print(f"Елемент {element} видалено з індексу {index}.")
    except IndexError:
        print("Помилка: індекс поза межами списку.")
    except ValueError:
        print("Помилка: індекс повинен бути цілим числом.")

def main():
    numbers = []
    
    # Заповнення списку числами
    while True:
        user_input = input("Введіть число (або 'стоп' для завершення введення): ")
        if user_input.lower() == 'стоп':
            break
        try:
            number = float(user_input)
            numbers.append(number)
        except ValueError:
            print("Помилка: введене значення повинно бути числом.")

    # Меню
    while True:
        display_menu()
        choice = input("Виберіть опцію: ")

        if choice == '1':
            display_list(numbers)
        elif choice == '2':
            get_max(numbers)
        elif choice == '3':
            get_min(numbers)
        elif choice == '4':
            display_element_by_index(numbers)
        elif choice == '5':
            delete_element_by_index(numbers)
        elif choice == '6':
            print("Вихід з програми...")
            break
        else:
            print("Помилка: некоректний вибір. Спробуйте ще раз.")

if __name__ == "__main__":
    main()
