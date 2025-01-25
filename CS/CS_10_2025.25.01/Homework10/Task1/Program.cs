using System;
using System.Collections.Generic;
using System.IO;

class Program
{
    static void Main()
    {
        Random rand = new Random();
        List<int> primeNumbers = new List<int>();
        List<int> fibonacciNumbers = new List<int>();

        for (int i = 0; i < 100; i++)
        {
            int number = rand.Next(-1000, 1000);
            if (IsPrime(number))
                primeNumbers.Add(number);
            if (IsFibonacci(number))
                fibonacciNumbers.Add(number);
        }

        // Запис простих чисел у файл
        File.WriteAllLines("primes.txt", primeNumbers.ConvertAll(x => x.ToString()));

        // Запис чисел Фібоначчі у файл
        File.WriteAllLines("fibonacci.txt", fibonacciNumbers.ConvertAll(x => x.ToString()));

        // Виведення статистики
        Console.WriteLine($"Простих чисел: {primeNumbers.Count}");
        Console.WriteLine($"Чисел Фібоначчі: {fibonacciNumbers.Count}");
    }

    static bool IsPrime(int num)
    {
        if (num <= 1) return false;
        for (int i = 2; i <= Math.Sqrt(num); i++)
        {
            if (num % i == 0) return false;
        }
        return true;
    }

    static bool IsFibonacci(int num)
    {
        if (num < 0) return false;
        int a = 0, b = 1;
        while (b < num)
        {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return b == num;
    }
}