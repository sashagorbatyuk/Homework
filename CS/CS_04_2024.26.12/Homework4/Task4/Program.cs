using System;

class Program
{
    static void EvaluateLogicalExpression()
    {
        Console.Write("Введіть логічний вираз (наприклад, 3 > 2): ");
        string expression = Console.ReadLine();

        try
        {
            bool result = Convert.ToBoolean(new System.Data.DataTable().Compute(expression, null));
            Console.WriteLine($"Результат: {result}");
        }
        catch
        {
            Console.WriteLine("Невірне введення.");
        }
    }

    static void Main()
    {
        EvaluateLogicalExpression();
    }
}