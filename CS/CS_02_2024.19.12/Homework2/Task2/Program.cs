using System;

class Program
{
    static void Main()
    {
        int[,] array = new int[5, 5];
        Random rand = new Random();
        int min = 101, max = -101, minIndex = 0, maxIndex = 0;

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                array[i, j] = rand.Next(-100, 101);
                Console.Write(array[i, j] + " ");
                if (array[i, j] < min) { min = array[i, j]; minIndex = i * 5 + j; }
                if (array[i, j] > max) { max = array[i, j]; maxIndex = i * 5 + j; }
            }
            Console.WriteLine();
        }

        int start = Math.Min(minIndex, maxIndex), end = Math.Max(minIndex, maxIndex);
        int sum = 0;
        for (int k = start + 1; k < end; k++)
            sum += array[k / 5, k % 5];

        Console.WriteLine($"Сума між {min} і {max}: {sum}");
    }
}