# Завдання 1
# Користувач вводить із клавіатури два числа.
# Потрібно порахувати окремо суму парних чисел, непарних чисел і чисел, 
# кратних 9 у зазначеному діапазоні, а також середньоарифметичне кожної групи.

#введення 2-х чисел
startNumber = int(input("Введіть початкове число діапазону: "))
endNumber = int(input("Введіть кінцеве число діапазону: "))

#валідація
if startNumber > endNumber:
    print("Перше число діапазону має бути менше за друге число. Вихід з програми ...")
    exit(1)

#змінні
sum_even = 0
count_even = 0
sum_odd = 0
count_odd = 0
sum_multiple_of_9 = 0
count_multiple_of_9 = 0

#арифметичні дії
for num in range(startNumber, endNumber + 1):
   print(num)

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

print("Сума парних чисел: ", sum_even)
print("Середнє арифметичне парних чисел: ", average_even)

print("Сума непарних чисел:", sum_odd)
print("Середнє арифметичне непарних чисел: ", average_odd)

print("Сума чисел, кратних 9: ", sum_multiple_of_9)
print("Середнє арифметичне чисел, кратних 9: ", average_multiple_of_9)