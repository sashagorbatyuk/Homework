using System;

class Program
{
    static void ConvertNumber()
    {
        Console.WriteLine("Виберіть напрямок конвертації:");
        Console.WriteLine("1. Десяткова -> Двійкова");
        Console.WriteLine("2. Десяткова -> Вісімкова");
        Console.WriteLine("3. Десяткова -> Шістнадцяткова");
        Console.WriteLine("4. Двійкова -> Десяткова");

        string choice = Console.ReadLine();

        try
        {
            if (choice == "1")
            {
                Console.Write("Введіть число в десятковій системі: ");
                int decimalNumber = int.Parse(Console.ReadLine());
                Console.WriteLine($"Число в двійковій системі: {Convert.ToString(decimalNumber, 2)}");
            }
            else if (choice == "2")
            {
                Console.Write("Введіть число в десятковій системі: ");
                int decimalNumber = int.Parse(Console.ReadLine());
                Console.WriteLine($"Число в вісімковій системі: {Convert.ToString(decimalNumber, 8)}");
            }
            else if (choice == "3")
            {
                Console.Write("Введіть число в десятковій системі: ");
                int decimalNumber = int.Parse(Console.ReadLine());
                Console.WriteLine($"Число в шістнадцятковій системі: {decimalNumber:X}");
            }
            else if (choice == "4")
            {
                Console.Write("Введіть число в двійковій системі: ");
                string binaryNumber = Console.ReadLine();
                int decimalNumber = Convert.ToInt32(binaryNumber, 2);
                Console.WriteLine($"Число в десятковій системі: {decimalNumber}");
            }
            else
            {
                Console.WriteLine("Невірний вибір.");
            }
        }
        catch (FormatException)
        {
            Console.WriteLine("Невірне введення числа.");
        }
    }

    static void Main()
    {
        ConvertNumber();
    }
}