using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Program
{
    static void Main()
    {
        string filePath = "your_file.txt";

        string searchWord = "LINQ";

        var lines = File.ReadAllLines(filePath);

        var result = lines
            .Select((line, index) => new { Line = line, LineNumber = index + 1 }) // Додаємо номер рядка
            .Where(x => x.Line.Contains(searchWord)) // Фільтруємо за наявністю слова
            .ToList();

        if (result.Any())
        {
            foreach (var item in result)
            {
                Console.WriteLine($"Рядок {item.LineNumber}: {item.Line}");
            }
        }
        else
        {
            Console.WriteLine("Не знайдено рядків, що містять слово '" + searchWord + "'");
        }
    }
}