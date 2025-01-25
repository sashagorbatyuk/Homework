using System;
using System.Collections.Generic;
using System.IO;

class Program
{
    static void Main()
    {
        Console.WriteLine("Введіть шлях до файлу з текстом:");
        string textFilePath = Console.ReadLine();
        Console.WriteLine("Введіть шлях до файлу з словами для модерації:");
        string blacklistFilePath = Console.ReadLine();

        string text = File.ReadAllText(textFilePath);
        string[] blacklist = File.ReadAllLines(blacklistFilePath);

        foreach (var word in blacklist)
        {
            text = text.Replace(word, new string('*', word.Length), StringComparison.OrdinalIgnoreCase);
        }

        File.WriteAllText(textFilePath, text);

        Console.WriteLine($"Модерація завершена. Всі слова зі списку замінені.");
    }
}