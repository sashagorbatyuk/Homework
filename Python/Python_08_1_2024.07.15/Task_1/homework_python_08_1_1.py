# Завдання 1
#  Маємо два текстові файли. З'ясуйте, чи співпадають їхні рядки. Якщо ні, то виведіть із кожного файлу рядок, який не співпадає. 

def compare_files(file_path_1, file_path_2):

    with open(file_path_1, "r") as file1:
        lines_file1 = file1.readlines()

    with open(file_path_2, "r") as file2:
        lines_file2 = file2.readlines()

    # Перевіряє чи є така саама кількість ліній в обох файлах
    if len(lines_file1) != len(lines_file2):
        print("Files have different number of lines.")
        return

    # Шукає лінії які не такі самі
    non_matching_lines = []

    for line1, line2 in zip(lines_file1, lines_file2):
        if line1.strip() != line2.strip():
            non_matching_lines.append((line1.strip(), line2.strip()))

    # Виводить не схожі лінії
    if non_matching_lines:
        print("Non-matching lines:")
        for line1, line2 in non_matching_lines:
            print(f"File 1: {line1}")
            print(f"File 2: {line2}")
            print()
    else:
        print("All lines match.")

file_path_1 = "file_path_1.txt"
file_path_2 = "file_path_2.txt"
compare_files(file_path_1, file_path_2)