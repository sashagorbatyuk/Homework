using System;
using System.Collections.Generic;

class Program
{
    static void WordToDigit()
    {
        var words = new Dictionary<string, int>
        {
            {"zero", 0},
            {"one", 1},
            {"two", 2},
            {"three", 3},
            {"four", 4},
            {"five", 5},
            {"six", 6},
            {"seven", 7},
            {"eight", 8},
            {"nine", 9}
        };

        Console.Write("Введіть цифру словами (наприклад, 'five'): ");
        string word = Console.ReadLine().ToLower();

        if (words.ContainsKey(word))
        {
            Console.WriteLine($"Цифра: {words[word]}");
        }
        else
        {
            Console.WriteLine("Невірне введення.");
        }
    }

    static void Main()
    {
        WordToDigit();
    }
}