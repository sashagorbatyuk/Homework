using System;

class Matrix
{
    static void Main(string[] args)
    {
        Matrix matrix = new Matrix(2, 3); // Create a 2x3 matrix
        matrix.InputData();
        matrix.OutputData();
        Console.WriteLine($"Maximum value: {matrix.GetMaxValue()}");
    }

    public int[,] Data { get; set; }

    public Matrix(int rows, int cols)
    {
        Data = new int[rows, cols];
    }

    public void InputData()
    {
        Console.WriteLine("Enter matrix data:");
        for (int i = 0; i < Data.GetLength(0); i++)
        {
            for (int j = 0; j < Data.GetLength(1); j++)
            {
                bool isValidInput = false;
                while (!isValidInput)
                {
                    Console.Write($"Enter element [{i}, {j}]: ");
                    string input = Console.ReadLine();

                    // Remove any commas or spaces from the input and try to parse it
                    input = input.Replace(",", "").Trim();

                    // Try parsing the input to an integer
                    if (int.TryParse(input, out int value))
                    {
                        Data[i, j] = value;
                        isValidInput = true;  // Valid input, break out of the loop
                    }
                    else
                    {
                        Console.WriteLine("Invalid input. Please enter a valid integer.");
                    }
                }
            }
        }
    }

    public void OutputData()
    {
        Console.WriteLine("Matrix:");
        for (int i = 0; i < Data.GetLength(0); i++)
        {
            for (int j = 0; j < Data.GetLength(1); j++)
            {
                Console.Write($"{Data[i, j]} ");
            }
            Console.WriteLine();
        }
    }

    public int GetMaxValue()
    {
        int max = Data[0, 0];
        for (int i = 0; i < Data.GetLength(0); i++)
        {
            for (int j = 0; j < Data.GetLength(1); j++)
            {
                if (Data[i, j] > max)
                {
                    max = Data[i, j];
                }
            }
        }
        return max;
    }

    public int GetMinValue()
    {
        int min = Data[0, 0];
        for (int i = 0; i < Data.GetLength(0); i++)
        {
            for (int j = 0; j < Data.GetLength(1); j++)
            {
                if (Data[i, j] < min)
                {
                    min = Data[i, j];
                }
            }
        }
        return min;
    }
}