using System;

public interface IOutput2
{
    void ShowEven();
    void ShowOdd();
}

public class Array : IOutput2
{
    private int[] arr;

    public Array(int[] inputArray)
    {
        arr = inputArray;
    }

    public void ShowEven()
    {
        Console.WriteLine("Парні числа:");
        foreach (var item in arr)
        {
            if (item % 2 == 0)
            {
                Console.Write(item + " ");
            }
        }
        Console.WriteLine();
    }

    public void ShowOdd()
    {
        Console.WriteLine("Непарні числа:");
        foreach (var item in arr)
        {
            if (item % 2 != 0)
            {
                Console.Write(item + " ");
            }
        }
        Console.WriteLine();
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        Array array = new Array(new int[] { 1, 5, 3, 7, 2, 9, 4 });

        array.ShowEven();
        array.ShowOdd();
    }
}