using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Введіть текст:");
        string text = Console.ReadLine();
        Console.WriteLine("Введіть заборонене слово:");
        string forbidden = Console.ReadLine();

        string result = text.Replace(forbidden, new string('*', forbidden.Length));
        int count = (text.Length - result.Replace(forbidden, "").Length) / forbidden.Length;

        Console.WriteLine("Результат:");
        Console.WriteLine(result);
        Console.WriteLine($"Кількість замін: {count}");
    }
}