import tkinter as tk

# Функція для зчитування введених даних та відображення їх у мітці
def show_full_name():
    first_name = entry_first_name.get()
    last_name = entry_last_name.get()
    full_name = f"{first_name} {last_name}"
    label_result.config(text=full_name)

# Створення головного вікна
root = tk.Tk()
root.title("Проста форма введення даних")

# Поле для введення імені
label_first_name = tk.Label(root, text="Ім'я:")
label_first_name.pack()

entry_first_name = tk.Entry(root)
entry_first_name.pack()

# Поле для введення прізвища
label_last_name = tk.Label(root, text="Прізвище:")
label_last_name.pack()

entry_last_name = tk.Entry(root)
entry_last_name.pack()

# Кнопка "Показати"
button_show = tk.Button(root, text="Показати", command=show_full_name)
button_show.pack()

# Мітка для відображення результату
label_result = tk.Label(root, text="")
label_result.pack()

# Запуск головного циклу програми
root.mainloop()