class Task3
{
    static void Main(string[] args)
    {
        int[] arr = { 5, 2, 9, 1, 5, 6 };
        Console.WriteLine("Масив до сортування:");
        PrintArray(arr);
        SortArray(arr, true); // true для зростання
        Console.WriteLine("Масив після сортування за зростанням:");
        PrintArray(arr);
    }

    static void SortArray(int[] arr, bool ascending)
    {
        int temp;
        for (int i = 0; i < arr.Length - 1; i++)
        {
            for (int j = i + 1; j < arr.Length; j++)
            {
                if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j]))
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    static void PrintArray(int[] arr)
    {
        foreach (var item in arr)
        {
            Console.Write(item + " ");
        }
        Console.WriteLine();
    }
}
