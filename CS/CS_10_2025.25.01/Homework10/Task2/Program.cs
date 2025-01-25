using System;
using System.IO;

class Program
{
    static void Main()
    {
        Console.WriteLine("Введіть шлях до файлу:");
        string filePath = Console.ReadLine();
        Console.WriteLine("Введіть слово для пошуку:");
        string searchWord = Console.ReadLine();
        Console.WriteLine("Введіть слово для заміни:");
        string replaceWord = Console.ReadLine();

        string text = File.ReadAllText(filePath);
        int occurrences = 0;

        text = text.Replace(searchWord, replaceWord, StringComparison.OrdinalIgnoreCase);
        occurrences = (text.Length - text.Replace(searchWord, "").Length) / searchWord.Length;

        File.WriteAllText(filePath, text);

        Console.WriteLine($"Заміни виконано: {occurrences}");
    }
}