# Завдання 1
# Користувач вводить із клавіатури рядок. Перевірте, чи є введений рядок паліндромом. 
# Паліндром — слово або текст, яке читається однаково зліва направо і справа наліво. 
# Наприклад, кок; кіт утік; я несу гусеня; радар; зараз. Або російською — А роза упала на лапу Азора; доход; А буду я у дуба.

def is_palindrome(input_str):
    cleaned_str = ''.join(char.lower() for char in input_str if char.isalnum())
    reversed_str = cleaned_str[::-1]
    return cleaned_str == reversed_str

user_input = input("Введіть рядок: ")

if is_palindrome(user_input):
    print("Це паліндром")

else:
    print("Це не паліндром")