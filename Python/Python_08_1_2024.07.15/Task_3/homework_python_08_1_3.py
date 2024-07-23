# Завдання 3
# Маємо текстовий файл. Видаліть з нього останній рядок. Результат запишіть до іншого файлу.

def remove_last_line(input_file_path, output_file_path):
    
    # Прочитаємо всі рядки вхідного файлу
    with open(input_file_path, "r", encoding="utf-8") as file:
        lines = file.readlines()
    
    # Видалz'vj останній рядок
    lines = lines[:-1]
    
    # Запишtvj решту рядків у вихідний файл
    with open(output_file_path, "w", encoding="utf-8") as file:
        file.writelines(lines)

# 
input_file_path = "input_file.txt"
output_file_path = "output_file.txt"
remove_last_line(input_file_path, output_file_path)

print(f"Last line has been removed and the result is written to {output_file_path}")