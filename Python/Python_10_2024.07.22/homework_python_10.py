#Завантажити клікер, який зберігає кращий результат у файл та на головному вікні відображає найкращий результат з файлу
import tkinter as tk

class ClickerApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Клікер")

        self.best_score = 0
        self.current_score = 0

        self.load_best_score()

        self.best_score_label = tk.Label(root, text=f"Найкращий результат: {self.best_score}")
        self.best_score_label.pack()

        self.current_score_label = tk.Label(root, text=f"Поточний результат: {self.current_score}")
        self.current_score_label.pack()

        self.button = tk.Button(root, text="Клік", command=self.increment_score)
        self.button.pack()

        self.reset_button = tk.Button(root, text="Скинути", command=self.reset_score)
        self.reset_button.pack()

    def load_best_score(self):
        try:
            with open("best_score.txt", "r") as file:
                self.best_score = int(file.read())
        except FileNotFoundError:
            self.best_score = 0

    def save_best_score(self):
        with open("best_score.txt", "w") as file:
            file.write(str(self.best_score))

    def increment_score(self):
        self.current_score += 1
        if self.current_score > self.best_score:
            self.best_score = self.current_score
            self.save_best_score()

        self.best_score_label.config(text=f"Найкращий результат: {self.best_score}")
        self.current_score_label.config(text=f"Поточний результат: {self.current_score}")

    def reset_score(self):
        self.current_score = 0
        self.current_score_label.config(text=f"Поточний результат: {self.current_score}")

if __name__ == "__main__":
    root = tk.Tk()
    app = ClickerApp(root)
    root.mainloop()
