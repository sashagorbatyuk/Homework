# Завдання 3
# Напишіть функцію, що визначає кількість простих чисел у списку цілих.
# Список передається як параметр. Отриманий результат повертається з функції.

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def count_primes(lst):
    return sum(1 for num in lst if is_prime(num))

numbers = [3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
print(count_primes(numbers))
