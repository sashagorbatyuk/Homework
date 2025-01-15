using System;

public interface ICalc
{
    int Less(int valueToCompare);
    int Greater(int valueToCompare);
}

public class Array : ICalc
{
    private int[] arr;

    public Array(int[] inputArray)
    {
        arr = inputArray;
    }

    public int Less(int valueToCompare)
    {
        int count = 0;
        foreach (var item in arr)
        {
            if (item < valueToCompare)
            {
                count++;
            }
        }
        return count;
    }

    public int Greater(int valueToCompare)
    {
        int count = 0;
        foreach (var item in arr)
        {
            if (item > valueToCompare)
            {
                count++;
            }
        }
        return count;
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        Array array = new Array(new int[] { 1, 5, 3, 7, 2, 9, 4 });

        Console.WriteLine("Кількість елементів менших за 5: " + array.Less(5));
        Console.WriteLine("Кількість елементів більших за 5: " + array.Greater(5));
    }
}