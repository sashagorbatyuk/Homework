using System;

class Program
{
    static void Main()
    {
        double[] A = new double[5];
        Console.WriteLine("Введіть 5 чисел для масиву A:");
        for (int i = 0; i < A.Length; i++)
        {
            A[i] = double.Parse(Console.ReadLine());
        }

        double[,] B = new double[3, 4];
        Random rand = new Random();
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                B[i, j] = rand.NextDouble() * 10;

        Console.WriteLine("Масив A:");
        Console.WriteLine(string.Join(" ", A));

        Console.WriteLine("Масив B:");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
                Console.Write($"{B[i, j]:F2} ");
            Console.WriteLine();
        }
    }
}