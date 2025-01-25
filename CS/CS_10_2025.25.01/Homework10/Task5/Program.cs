using System;
using System.Collections.Generic;
using System.IO;

class Program
{
    static void Main()
    {
        string filePath = "numbers.txt";
        var positiveNumbers = new List<int>();
        var negativeNumbers = new List<int>();
        var twoDigitNumbers = new List<int>();
        var fiveDigitNumbers = new List<int>();

        string[] numbers = File.ReadAllLines(filePath);

        foreach (var numStr in numbers)
        {
            if (int.TryParse(numStr, out int number))
            {
                if (number > 0) positiveNumbers.Add(number);
                if (number < 0) negativeNumbers.Add(number);
                if (Math.Abs(number) >= 10 && Math.Abs(number) < 100) twoDigitNumbers.Add(number);
                if (Math.Abs(number) >= 10000 && Math.Abs(number) < 100000) fiveDigitNumbers.Add(number);
            }
        }

        File.WriteAllLines("positiveNumbers.txt", positiveNumbers.ConvertAll(x => x.ToString()));
        File.WriteAllLines("negativeNumbers.txt", negativeNumbers.ConvertAll(x => x.ToString()));
        File.WriteAllLines("twoDigitNumbers.txt", twoDigitNumbers.ConvertAll(x => x.ToString()));
        File.WriteAllLines("fiveDigitNumbers.txt", fiveDigitNumbers.ConvertAll(x => x.ToString()));

        Console.WriteLine($"Кількість додатних чисел: {positiveNumbers.Count}");
        Console.WriteLine($"Кількість від'ємних чисел: {negativeNumbers.Count}");
        Console.WriteLine($"Кількість двозначних чисел: {twoDigitNumbers.Count}");
        Console.WriteLine($"Кількість п'ятизначних чисел: {fiveDigitNumbers.Count}");
    }
}