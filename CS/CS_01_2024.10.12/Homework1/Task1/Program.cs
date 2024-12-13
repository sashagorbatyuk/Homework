using System;

class Program
{
    static void Main()
    {
        Console.Write("Введіть число від 1 до 100: ");
        if (int.TryParse(Console.ReadLine(), out int number) && number >= 1 && number <= 100)
        {
            if (number % 3 == 0 && number % 5 == 0)
                Console.WriteLine("Fizz Buzz");
            else if (number % 3 == 0)
                Console.WriteLine("Fizz");
            else if (number % 5 == 0)
                Console.WriteLine("Buzz");
            else
                Console.WriteLine(number);
        }
        else
        {
            Console.WriteLine("Помилка: введіть число від 1 до 100.");
        }
    }
}