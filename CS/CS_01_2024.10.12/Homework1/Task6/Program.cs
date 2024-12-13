using System;

class Program
{
    static void Main()
    {
        Console.Write("Введіть температуру: ");
        if (double.TryParse(Console.ReadLine(), out double temperature))
        {
            Console.Write("Виберіть конвертацію (1 - Фаренгейт в Цельсій, 2 - Цельсій в Фаренгейт): ");
            if (int.TryParse(Console.ReadLine(), out int choice))
            {
                if (choice == 1)
                    Console.WriteLine($"Результат: {(temperature - 32) * 5 / 9} °C");
                else if (choice == 2)
                    Console.WriteLine($"Результат: {temperature * 9 / 5 + 32} °F");
            }
        }
    }
}