using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Введіть вираз (+ або -):");
        string input = Console.ReadLine();
        string[] parts = input.Split(new char[] { '+', '-' });
        int a = int.Parse(parts[0]), b = int.Parse(parts[1]);
        int result = input.Contains('+') ? a + b : a - b;
        Console.WriteLine("Результат: " + result);
    }
}