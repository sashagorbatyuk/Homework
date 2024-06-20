# Завдання 3
# Користувач вводить із клавіатури числа. 
# Якщо число більше нуля, потрібно вивести напис "Number is positive", якщо менше нуля — "Number is negative", якщо дорівнює нулю — "Number is equal to zero". Коли користувач вводить число 7, програма припиняє свою роботу і виводить на екран напис "Good bye!".

while True:
   number = int(input("Enter number:"))

   if number > 0:

       print('Number is positive')

   elif number < 0:

       print('Number is negative')

   else:

       print('Number is equal to zero')

   if number == 7:

       print('Good bye!')

       exit()