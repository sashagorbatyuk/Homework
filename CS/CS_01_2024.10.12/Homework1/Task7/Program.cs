using System;

class Program
{
    static void Main()
    {
        Console.Write("Введіть два числа: ");
        if (int.TryParse(Console.ReadLine(), out int num1) &&
            int.TryParse(Console.ReadLine(), out int num2))
        {
            int start = Math.Min(num1, num2);
            int end = Math.Max(num1, num2);

            Console.WriteLine("Парні числа у діапазоні:");
            for (int i = start; i <= end; i++)
            {
                if (i % 2 == 0)
                    Console.Write(i + " ");
            }
        }
    }
}