using System;
using System.Linq;

public interface ICalc2
{
    int CountDistinct();
    int EqualToValue(int valueToCompare);
}

public class Array : ICalc2
{
    private int[] arr;

    public Array(int[] inputArray)
    {
        arr = inputArray;
    }

    public int CountDistinct()
    {
        return arr.Distinct().Count();
    }

    public int EqualToValue(int valueToCompare)
    {
        return arr.Count(x => x == valueToCompare);
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        Array array = new Array(new int[] { 1, 5, 3, 7, 2, 9, 4, 5, 3 });

        Console.WriteLine("Кількість унікальних елементів: " + array.CountDistinct());
        Console.WriteLine("Кількість елементів, рівних 5: " + array.EqualToValue(5));
    }
}