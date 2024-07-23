# Завдання 4
# Маємо текстовий файл. Знайдіть довжину найдовшого рядка. 

def find_longest_line_length(file_path):
    with open(file_path, "r", encoding="utf-8") as file:
        lines = file.readlines()
    
    longest_line_length = max(len(line) for line in lines)
    return longest_line_length

file_path = "file.txt"
longest_line_length = find_longest_line_length(file_path)

print(f"The length of the longest line is {longest_line_length}")