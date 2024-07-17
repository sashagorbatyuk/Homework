import random

def create_puzzle():
    # Створює та перемішує пазл 4x4
    numbers = list(range(1, 16)) + [0]
    random.shuffle(numbers)
    puzzle = [numbers[i * 4:(i + 1) * 4] for i in range(4)]
    return puzzle

def print_puzzle(puzzle):
    # Виводить пазл на екран
    for row in puzzle:
        print(' '.join(f'{num:2}' if num != 0 else '  ' for num in row))

def find_zero(puzzle):
    # Знаходить координати нульового елементу (порожньої клітинки)
    for i, row in enumerate(puzzle):
        if 0 in row:
            return i, row.index(0)

def is_solvable(puzzle):
    # Перевіряє, чи має пазл рішення
    numbers = sum(puzzle, [])
    inv_count = 0
    for i in range(15):
        for j in range(i + 1, 16):
            if numbers[j] and numbers[i] and numbers[i] > numbers[j]:
                inv_count += 1
    zero_row = find_zero(puzzle)[0]
    return (inv_count + zero_row) % 2 == 0

def move_tile(puzzle, x, y, new_x, new_y):
    # Переміщує плитку в порожню клітинку
    puzzle[x][y], puzzle[new_x][new_y] = puzzle[new_x][new_y], puzzle[x][y]

def is_solved(puzzle):
    # Перевіряє, чи вирішено пазл
    return puzzle == [list(range(i * 4 + 1, i * 4 + 5)) for i in range(3)] + [[13, 14, 15, 0]]

def play_game():
    #Основна функція для гри
    puzzle = create_puzzle()
    while not is_solvable(puzzle):
        puzzle = create_puzzle()

    while True:
        print_puzzle(puzzle)
        if is_solved(puzzle):
            print("Вітаємо! Ви розв'язали пазл!")
            break
        
        try:
            move = int(input("Введіть номер плитки, яку хочете перемістити (0 для виходу): "))
            if move == 0:
                print("Гру завершено.")
                break
        except ValueError:
            continue
        
        zero_x, zero_y = find_zero(puzzle)
        tile_x, tile_y = None, None
        
        for i in range(4):
            for j in range(4):
                if puzzle[i][j] == move:
                    tile_x, tile_y = i, j
        
        if tile_x is not None and (
            (tile_x == zero_x and abs(tile_y - zero_y) == 1) or
            (tile_y == zero_y and abs(tile_x - zero_x) == 1)
        ):
            move_tile(puzzle, tile_x, tile_y, zero_x, zero_y)

# Запуск гри
play_game()