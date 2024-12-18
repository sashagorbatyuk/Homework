using System;

class Program
{
    static void Main()
    {
        int[,] matrix1 = { { 1, 2 }, { 3, 4 } };
        int[,] matrix2 = { { 5, 6 }, { 7, 8 } };
        int[,] result = new int[2, 2];

        Console.WriteLine("Множення матриці на число (2):");
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                Console.Write(matrix1[i, j] * 2 + " ");
            Console.WriteLine();
        }

        Console.WriteLine("Додавання матриць:");
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                Console.Write(matrix1[i, j] + matrix2[i, j] + " ");
            Console.WriteLine();
        }

        Console.WriteLine("Добуток матриць:");
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result[i, j] = matrix1[i, 0] * matrix2[0, j] + matrix1[i, 1] * matrix2[1, j];
                Console.Write(result[i, j] + " ");
            }
            Console.WriteLine();
        }
    }
}