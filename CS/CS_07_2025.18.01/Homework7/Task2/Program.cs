using System;

public class DateAndGeometryMethods
{
    // Метод для відображення поточного часу
    public static void DisplayCurrentTime()
    {
        Console.WriteLine(DateTime.Now.ToString("HH:mm:ss"));
    }

    // Метод для відображення поточної дати
    public static void DisplayCurrentDate()
    {
        Console.WriteLine(DateTime.Now.ToString("yyyy-MM-dd"));
    }

    // Метод для відображення поточного дня тижня
    public static void DisplayCurrentDayOfWeek()
    {
        Console.WriteLine(DateTime.Now.DayOfWeek);
    }

    // Метод для підрахунку площі трикутника
    public static double CalculateTriangleArea(double baseLength, double height)
    {
        return 0.5 * baseLength * height;
    }

    // Метод для підрахунку площі прямокутника
    public static double CalculateRectangleArea(double width, double height)
    {
        return width * height;
    }

    // Використання делегатів Action, Predicate та Func
    public static void ExecuteMethods()
    {
        // Action для виведення часу
        Action displayTime = DisplayCurrentTime;
        displayTime.Invoke();

        // Func для обчислення площі трикутника
        Func<double, double, double> calculateTriangle = CalculateTriangleArea;
        Console.WriteLine("Triangle Area: " + calculateTriangle(10, 5));

        // Func для обчислення площі прямокутника
        Func<double, double, double> calculateRectangle = CalculateRectangleArea;
        Console.WriteLine("Rectangle Area: " + calculateRectangle(10, 5));
    }
}