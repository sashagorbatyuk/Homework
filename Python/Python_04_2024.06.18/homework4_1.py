# Завдання 1
# Користувач вводить із клавіатури два числа. Потрібно порахувати окремо суму парних чисел, непарних чисел і чисел, кратних 9 у зазначеному діапазоні, а також середньоарифметичне кожної групи.

# функція перевірки числа на float
def isFloat(num):
    try:
        float(num)
        return True
    except ValueError:
        return False

while(True):
    startString = input("Введіть початкове число діапазону: ")
    if(str(startString)): 
        start = int(startString)
        break
    else:
        print(f"Введено невірне число. Повторіть введення")
        continue


while(True):
    endString = input("Введіть кінцеве число діапазону: ")
    if(str(endString)): 
        end = int(endString)
        break
    else:
        print(f"Введено невірне число. Повторіть введення")
        continue

sum_even = 0
count_even = 0
sum_odd = 0
count_odd = 0
sum_multiple_of_9 = 0
count_multiple_of_9 = 0


for num in range(start, end + 1):

   if num % 2 == 0:
       sum_even += num
       count_even += 1

   else:
       sum_odd += num
       count_odd += 1

   if num % 9 == 0:
       sum_multiple_of_9 += num
       count_multiple_of_9 += 1

average_even = sum_even / count_even if count_even > 0 else 0
average_odd = sum_odd / count_odd if count_odd > 0 else 0
average_multiple_of_9 = sum_multiple_of_9 / count_multiple_of_9 if count_multiple_of_9 > 0 else 0

print("Сума парних чисел:", sum_even)
print("Середнє арифметичне парних чисел:", average_even)
print("Сума непарних чисел:", sum_odd)
print("Середнє арифметичне непарних чисел:", average_odd)
print("Сума чисел, кратних 9:", sum_multiple_of_9)
print("Середнє арифметичне чисел, кратних 9:", average_multiple_of_9)