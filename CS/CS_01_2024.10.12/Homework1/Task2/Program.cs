using System;

class Program
{
    static void Main()
    {
        Console.Write("Введіть число: ");
        if (double.TryParse(Console.ReadLine(), out double value))
        {
            Console.Write("Введіть відсоток: ");
            if (double.TryParse(Console.ReadLine(), out double percent))
            {
                double result = (value * percent) / 100;
                Console.WriteLine($"{percent}% від {value} = {result}");
            }
        }
    }
}