# Знаходження найчастіших елементів:
# Створіть список з повторюваними елементами, перетворіть його в множину і знайдіть елементи, що зустрічаються найчастіше.
from collections import Counter

elements_list = [1, 2, 4, 3, 5, 8, 7 ,3 ,9 ,5 ,6, 3, 5 , 1, 2]

# Перетворимо список у множину, щоб позбутися повторів
unique_elements_set = set(elements_list)

# Використаємо Counter для підрахунку частоти кожного елемента у списку
elements_count = Counter(elements_list)

# Знайдемо найчастіші елементи
most_common_elements = elements_count.most_common()

print("Список всіх елементів:", elements_list)
print("Унікальні елементи:", unique_elements_set)
print("Найчастіші елементи:", most_common_elements)
