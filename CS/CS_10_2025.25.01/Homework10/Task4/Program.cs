using System;
using System.IO;

class Program
{
    static void Main()
    {
        Console.WriteLine("Введіть шлях до файлу:");
        string filePath = Console.ReadLine();

        string text = File.ReadAllText(filePath);
        char[] reversedText = text.ToCharArray();
        Array.Reverse(reversedText);

        File.WriteAllText("reversed.txt", new string(reversedText));

        Console.WriteLine("Вміст файлу перевернуто і записано у 'reversed.txt'.");
    }
}