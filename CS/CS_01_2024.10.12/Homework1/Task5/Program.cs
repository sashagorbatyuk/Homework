using System;
using System.Globalization;

class Program
{
    static void Main()
    {
        Console.Write("Введіть дату (дд.мм.рррр): ");
        if (DateTime.TryParseExact(Console.ReadLine(), "dd.MM.yyyy", null, DateTimeStyles.None, out DateTime date))
        {
            string season = GetSeason(date);
            string dayOfWeek = date.ToString("dddd", new CultureInfo("en-US"));
            Console.WriteLine($"{season} {dayOfWeek}");
        }
        else
        {
            Console.WriteLine("Помилка: введіть дату у форматі дд.мм.рррр.");
        }
    }

    static string GetSeason(DateTime date)
    {
        int month = date.Month;
        if (month == 12 || month == 1 || month == 2) return "Winter";
        if (month >= 3 && month <= 5) return "Spring";
        if (month >= 6 && month <= 8) return "Summer";
        return "Autumn";
    }
}