using System;

class Task1
{
    static void Main(string[] args)
    {
        // Введення меж діапазону
        int start = 1, end = 5;
        Console.WriteLine($"Добуток чисел від {start} до {end} = {CalculateProduct(start, end)}");
    }

    static int CalculateProduct(int start, int end)
    {
        int product = 1;
        for (int i = start; i <= end; i++)
        {
            product *= i;
        }
        return product;
    }
}
