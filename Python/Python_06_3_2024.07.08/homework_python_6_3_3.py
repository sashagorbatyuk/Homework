# Завдання 3
# Є шахівниця розміром 8×8 і шаховий кінь.
# Програма має запитати в користувача координати клітинки поля і поставити туди коня.
# Завдання програми знайти і вивести шлях коня, за якого він обійде всі клітини дошки, стаючи в кожну клітинку тільки один раз.
# (Оскільки процес пошуку шляху для різних початкових клітин може затягнутися, рекомендується спочатку випробувати задачу на полі розміром 6×6).
# У програмі необхідно використовувати рекурсію.
def is_safe(x, y, board, N):
    # Перевіряє, чи можливо перемістити коня на позицію (x, y)
    return 0 <= x < N and 0 <= y < N and board[x][y] == -1

def print_board(board, N):
    # Виводить дошку на екран
    for row in board:
        print(' '.join(f'{cell:2}' for cell in row))

def solve_knights_tour(N):
    #Ініціалізує дошку і починає рішення задачі
    board = [[-1 for _ in range(N)] for _ in range(N)]
    
    # Всі можливі рухи коня
    move_x = [2, 1, -1, -2, -2, -1, 1, 2]
    move_y = [1, 2, 2, 1, -1, -2, -2, -1]
    0
    # Початкові координати коня
    x, y = map(int, input(f"Введіть координати для стартової позиції коня (дві цифри від 0 до {N-1} через пробіл): ").split())
    board[x][y] = 0  # Початковий хід

    # Виклик рекурсивної функції для пошуку рішення
    if not solve_knights_tour_util(x, y, 1, board, move_x, move_y, N):
        print("Рішення не існує")
    else:
        print_board(board, N)

def solve_knights_tour_util(x, y, move_i, board, move_x, move_y, N):
    #Рекурсивна функція для пошуку рішення задачі
    if move_i == N * N:
        return True

    for k in range(8):
        next_x = x + move_x[k]
        next_y = y + move_y[k]
        if is_safe(next_x, next_y, board, N):
            board[next_x][next_y] = move_i
            if solve_knights_tour_util(next_x, next_y, move_i + 1, board, move_x, move_y, N):
                return True
            board[next_x][next_y] = -1  # Відміна ходу (backtracking)
    return False

# Виклик функції для дошки 6x6
solve_knights_tour(6)
