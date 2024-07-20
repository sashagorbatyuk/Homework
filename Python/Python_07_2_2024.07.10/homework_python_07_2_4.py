# Реалізуйте третє завдання через функції. Створіть дві версії реалізації функцій:

# Перша версія не обробляє винятки всередині функцій. Уся обробка знаходиться зовні;
# Друга версія обробляє винятки всередині функцій.
def display_list(numbers):
    print("Список чисел:", numbers)

def get_max(numbers):
    return max(numbers)

def get_min(numbers):
    return min(numbers)

def display_element_by_index(numbers, index):
    return numbers[index]

def delete_element_by_index(numbers, index):
    return numbers.pop(index)

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
        print("\nМеню:")
        print("1. Відображення списку")
        print("2. Отримання максимального значення у списку")
        print("3. Отримання мінімального значення у списку")
        print("4. Відображення значення елемента за індексом")
        print("5. Видалення елемента за індексом")
        print("6. Вихід")
        
        choice = input("Виберіть опцію: ")

        if choice == '1':
            display_list(numbers)
        elif choice == '2':
            if numbers:
                try:
                    print("Максимальне значення у списку:", get_max(numbers))
                except ValueError as e:
                    print(f"Помилка: {e}")
            else:
                print("Список порожній.")
        elif choice == '3':
            if numbers:
                try:
                    print("Мінімальне значення у списку:", get_min(numbers))
                except ValueError as e:
                    print(f"Помилка: {e}")
            else:
                print("Список порожній.")
        elif choice == '4':
            try:
                index = int(input("Введіть індекс елемента: "))
                print(f"Елемент на індексі {index}: {display_element_by_index(numbers, index)}")
            except IndexError:
                print("Помилка: індекс поза межами списку.")
            except ValueError:
                print("Помилка: індекс повинен бути цілим числом.")
        elif choice == '5':
            try:
                index = int(input("Введіть індекс елемента для видалення: "))
                element = delete_element_by_index(numbers, index)
                print(f"Елемент {element} видалено з індексу {index}.")
            except IndexError:
                print("Помилка: індекс поза межами списку.")
            except ValueError:
                print("Помилка: індекс повинен бути цілим числом.")
        elif choice == '6':
            print("Вихід з програми.")
            break
        else:
            print("Помилка: некоректний вибір. Спробуйте ще раз.")

main()

print("****************************************")

def display_list(numbers):
    print("Список чисел:", numbers)

def get_max(numbers):
    try:
        if not numbers:
            raise ValueError("Список порожній.")
        return max(numbers)
    except ValueError as e:
        print(f"Помилка: {e}")
        return None

def get_min(numbers):
    try:
        if not numbers:
            raise ValueError("Список порожній.")
        return min(numbers)
    except ValueError as e:
        print(f"Помилка: {e}")
        return None

def display_element_by_index(numbers, index):
    try:
        if index < 0 or index >= len(numbers):
            raise IndexError("Індекс поза межами списку.")
        return numbers[index]
    except IndexError as e:
        print(f"Помилка: {e}")
        return None

def delete_element_by_index(numbers, index):
    try:
        if index < 0 or index >= len(numbers):
            raise IndexError("Індекс поза межами списку.")
        return numbers.pop(index)
    except IndexError as e:
        print(f"Помилка: {e}")
        return None

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
        print("\nМеню:")
        print("1. Відображення списку")
        print("2. Отримання максимального значення у списку")
        print("3. Отримання мінімального значення у списку")
        print("4. Відображення значення елемента за індексом")
        print("5. Видалення елемента за індексом")
        print("6. Вихід")
        
        choice = input("Виберіть опцію: ")

        if choice == '1':
            display_list(numbers)
        elif choice == '2':
            max_value = get_max(numbers)
            if max_value is not None:
                print("Максимальне значення у списку:", max_value)
        elif choice == '3':
            min_value = get_min(numbers)
            if min_value is not None:
                print("Мінімальне значення у списку:", min_value)
        elif choice == '4':
            try:
                index = int(input("Введіть індекс елемента: "))
                element = display_element_by_index(numbers, index)
                if element is not None:
                    print(f"Елемент на індексі {index}: {element}")
            except ValueError:
                print("Помилка: індекс повинен бути цілим числом.")
        elif choice == '5':
            try:
                index = int(input("Введіть індекс елемента для видалення: "))
                element = delete_element_by_index(numbers, index)
                if element is not None:
                    print(f"Елемент {element} видалено з індексу {index}.")
            except ValueError:
                print("Помилка: індекс повинен бути цілим числом.")
        elif choice == '6':
            print("Вихід з програми....")
            break
        else:
            print("Помилка: некоректний вибір. Спробуйте ще раз.")
main()
