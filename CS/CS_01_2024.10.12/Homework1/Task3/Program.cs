using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Введіть чотири цифри по черзі:");
        string result = "";
        for (int i = 0; i < 4; i++)
        {
            Console.Write($"Цифра {i + 1}: ");
            result += Console.ReadLine();
        }
        Console.WriteLine($"Сформоване число: {result}");
    }
}