#Розробіть простий графічний калькулятор з використанням бібліотеки Tkinter

import tkinter as tk

def click(event):
    current_text = display.get()
    button_text = event.widget.cget("text")

    if button_text == "=":
        try:
            result = str(eval(current_text))
            display.set(result)
        except Exception as e:
            display.set("Error")
    elif button_text == "C":
        display.set("")
    else:
        display.set(current_text + button_text)

root = tk.Tk()
root.title("Калькулятор")

display = tk.StringVar()
entry = tk.Entry(root, textvar=display, font="Arial 20 bold", bd=10, insertwidth=4, width=14, borderwidth=4)
entry.grid(row=0, column=0, columnspan=4)

buttons = [
    '7', '8', '9', '/',
    '4', '5', '6', '*',
    '1', '2', '3', '-',
    'C', '0', '=', '+'
]

row = 1
col = 0
for button in buttons:
    btn = tk.Button(root, text=button, padx=20, pady=20, font="Arial 15 bold")
    btn.grid(row=row, column=col)
    btn.bind("<Button-1>", click)
    col += 1
    if col > 3:
        col = 0
        row += 1

root.mainloop()