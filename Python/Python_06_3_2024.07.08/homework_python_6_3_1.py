# Завдання 1
# Написати рекурсивну функцію знаходження найбільшого спільного дільника двох цілих чисел.
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

num1 = 8
num2 = 18
print(f"Найбільший спільний дільник чисел ({num1}, {num2}) = {gcd(num1, num2)}")