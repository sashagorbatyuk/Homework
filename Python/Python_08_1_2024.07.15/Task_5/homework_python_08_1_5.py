#Завдання 5
#Маємо текстовий файл. Підрахуйте кількість заданого користувачем слова у ньому.

def count_word_occurrences(file_path, word):
    with open(file_path, "r", encoding="utf-8") as file:
        content = file.read()
    
    words = content.split()
    word_count = words.count(word)
    
    return word_count

file_path = "file.txt"
word_to_count = "Вася" 
word_count = count_word_occurrences(file_path, word_to_count)

print(f"The word '{word_to_count}' occurs {word_count} times in the file.")