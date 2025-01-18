using System;
using System.Collections.Generic;
using System.Linq;

public class ArrayMethods
{
    // Делегат для фільтрації масиву
    public delegate bool NumberFilter(int number);

    // Метод для отримання усіх парних чисел
    public static List<int> GetEvenNumbers(int[] array)
    {
        return FilterArray(array, number => number % 2 == 0);
    }

    // Метод для отримання усіх непарних чисел
    public static List<int> GetOddNumbers(int[] array)
    {
        return FilterArray(array, number => number % 2 != 0);
    }

    // Метод для перевірки простих чисел
    public static bool IsPrime(int number)
    {
        if (number < 2) return false;
        for (int i = 2; i <= Math.Sqrt(number); i++)
        {
            if (number % i == 0) return false;
        }
        return true;
    }

    // Метод для отримання усіх простих чисел
    public static List<int> GetPrimeNumbers(int[] array)
    {
        return FilterArray(array, IsPrime);
    }

    // Метод для перевірки чисел Фібоначчі
    public static bool IsFibonacci(int number)
    {
        int a = 0, b = 1;
        while (b < number)
        {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return b == number || number == 0;
    }

    // Метод для отримання усіх чисел Фібоначчі
    public static List<int> GetFibonacciNumbers(int[] array)
    {
        return FilterArray(array, IsFibonacci);
    }

    // Загальний метод фільтрації масиву за допомогою делегата
    private static List<int> FilterArray(int[] array, NumberFilter filter)
    {
        return array.Where(number => filter(number)).ToList();
    }
}