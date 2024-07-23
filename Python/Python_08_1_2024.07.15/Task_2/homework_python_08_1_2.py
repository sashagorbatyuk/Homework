# Завдання 2
# Маємо текстовий файл. Створіть новий файл і запишіть до нього наступну статистику за вихідним файлом:
# кількість символів;
# кількість рядків;
# кількість голосних літер;
# кількість приголосних літер;
# кількість цифр. 

import string

def count_vowels_and_consonants(text):
    vowels = "AEIOUaeiou"
    consonants = ''.join(set(string.ascii_letters) - set(vowels))
    vowel_count = sum(1 for char in text if char in vowels)
    consonant_count = sum(1 for char in text if char in consonants)
    return vowel_count, consonant_count

def generate_file_statistics(input_file_path, output_file_path):
    with open(input_file_path, "r", encoding="utf-8") as file:
        content = file.read()
    
    num_characters = len(content)
    num_lines = content.count('\n') + 1
    vowel_count, consonant_count = count_vowels_and_consonants(content)
    num_digits = sum(1 for char in content if char.isdigit())

    statistics = (
        f"Кількість символів: {num_characters}\n"
        f"Кількість рядків: {num_lines}\n"
        f"Кількість голосних літер: {vowel_count}\n"
        f"Кількість приголосних літер: {consonant_count}\n"
        f"Кількість цифр: {num_digits}\n"
    )

    with open(output_file_path, "w", encoding="utf-8") as file:
        file.write(statistics)

input_file_path = "input_file.txt"
output_file_path = "output_statistics.txt"
generate_file_statistics(input_file_path, output_file_path)

print(f"Statistics have been written to {output_file_path}")