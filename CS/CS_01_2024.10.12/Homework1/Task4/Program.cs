using System;

class Program
{
    static void Main()
    {
        Console.Write("Введіть шестизначне число: ");
        string number = Console.ReadLine();

        if (number.Length == 6 && int.TryParse(number, out _))
        {
            Console.Write("Введіть позиції для заміни (через пробіл): ");
            string[] positions = Console.ReadLine().Split();
            if (positions.Length == 2 &&
                int.TryParse(positions[0], out int pos1) &&
                int.TryParse(positions[1], out int pos2) &&
                pos1 >= 1 && pos1 <= 6 && pos2 >= 1 && pos2 <= 6)
            {
                char[] digits = number.ToCharArray();
                (digits[pos1 - 1], digits[pos2 - 1]) = (digits[pos2 - 1], digits[pos1 - 1]);
                Console.WriteLine($"Результат: {new string(digits)}");
            }
        }
        else
        {
            Console.WriteLine("Помилка: введіть коректне шестизначне число.");
        }
    }
}