# Завдання 6
# Маємо текстовий файл. Знайдіть і замініть у ньому задане слово. Яке слово шукати і на яке замінювати – встановлюється користувачем.

def find_and_replace_word(file_name, target_word, replacement_word):
    with open(file_name, "r", encoding="utf-8") as file:
        content = file.read()
    
    # Замініюємо цільове слово словом-заміною
    updated_content = content.replace(target_word, replacement_word)
    
    with open(file_name, "w", encoding="utf-8") as file:
        file.write(updated_content)

file_name = "input_file.txt"
target_word = "Hello" 
replacement_word = "Bye"

find_and_replace_word(file_name, target_word, replacement_word)

print(f"The word '{target_word}' has been replaced with '{replacement_word}' in the file '{file_name}'.")