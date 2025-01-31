using System;
using System.IO;
using System.Linq;

class Program
{
    static void Main()
    {
        string text = File.ReadAllText("text.txt");
        var wordCount = text.Split(new[] { ' ', '\n', '\r', '.', ',', '!', '?', ';' }, StringSplitOptions.RemoveEmptyEntries)
                            .GroupBy(word => word.ToLower())
                            .Select(group => new { Word = group.Key, Count = group.Count() });

        foreach (var word in wordCount)
        {
            Console.WriteLine($"Слово: {word.Word}, Кількість: {word.Count}");
        }
    }
}