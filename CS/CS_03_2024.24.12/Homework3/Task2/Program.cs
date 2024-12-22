class Task2
{
    static void Main(string[] args)
    {
        int number = 8;
        Console.WriteLine($"Число {number} є числом Фібоначчі? {IsFibonacciNumber(number)}");
    }

    static bool IsFibonacciNumber(int number)
    {
        if (number < 0) return false;

        int a = 0, b = 1;
        while (b < number)
        {
            int temp = b;
            b = a + b;
            a = temp;
        }

        return b == number;
    }
}
