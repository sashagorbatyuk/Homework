import tkinter as tk
from tkinter import messagebox

# Функція для додавання двох чисел
def add():
    try:
        num1 = float(entry1.get())
        num2 = float(entry2.get())
        result = num1 + num2
        # Відображення результату в мітці
        result_label.config(text=f"Результат: {result}")
    except ValueError:
        messagebox.showerror("Помилка", "Будь ласка, введіть дійсні числа.")

# Функція для віднімання другого числа від першого
def subtract():
    try:
        num1 = float(entry1.get())
        num2 = float(entry2.get())
        result = num1 - num2
        result_label.config(text=f"Результат: {result}")
    except ValueError:
        messagebox.showerror("Помилка", "Будь ласка, введіть дійсні числа.")

# Функція для множення двох чисел
def multiply():
    try:
        num1 = float(entry1.get())
        num2 = float(entry2.get())
        result = num1 * num2
        result_label.config(text=f"Результат: {result}")
    except ValueError:
        messagebox.showerror("Помилка", "Будь ласка, введіть дійсні числа.")

# Функція для ділення першого числа на друге
def divide():
    try:
        num1 = float(entry1.get())
        num2 = float(entry2.get())
        if num2 == 0:
            messagebox.showerror("Помилка", "Ділення на нуль неможливе.")
        else:
            result = num1 / num2
            result_label.config(text=f"Результат: {result}")
    except ValueError:
        messagebox.showerror("Помилка", "Будь ласка, введіть дійсні числа.")

# Створення головного вікна
root = tk.Tk()
root.title("Калькулятор")

# Поля введення для чисел
entry1 = tk.Entry(root)
entry1.grid(row=0, column=1)
entry2 = tk.Entry(root)
entry2.grid(row=1, column=1)

# Мітки для полів введення
label1 = tk.Label(root, text="Число 1:")
label1.grid(row=0, column=0)
label2 = tk.Label(root, text="Число 2:")
label2.grid(row=1, column=0)

# Кнопки для математичних операцій
add_button = tk.Button(root, text="Додавання", command=add)
add_button.grid(row=2, column=0)

subtract_button = tk.Button(root, text="Віднімання", command=subtract)
subtract_button.grid(row=2, column=1)

multiply_button = tk.Button(root, text="Множення", command=multiply)
multiply_button.grid(row=3, column=0)

divide_button = tk.Button(root, text="Ділення", command=divide)
divide_button.grid(row=3, column=1)

# Мітка для відображення результату
result_label = tk.Label(root, text="Результат: ")
result_label.grid(row=4, columnspan=2)

# Запуск головного циклу
root.mainloop()
