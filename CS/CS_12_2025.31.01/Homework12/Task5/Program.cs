using System;
using System.Collections.Generic;
using System.Linq;

class Order
{
    public string CustomerName { get; set; }
    public DateTime OrderDate { get; set; }
    public decimal TotalAmount { get; set; }
}

class Program
{
    static void Main()
    {
        List<Order> orders = new List<Order>
        {
            new Order { CustomerName = "Анна", OrderDate = new DateTime(2025, 1, 5), TotalAmount = 200 },
            new Order { CustomerName = "Петро", OrderDate = new DateTime(2025, 1, 10), TotalAmount = 150 },
            new Order { CustomerName = "Олена", OrderDate = new DateTime(2025, 2, 3), TotalAmount = 300 },
            new Order { CustomerName = "Анна", OrderDate = new DateTime(2025, 1, 20), TotalAmount = 250 },
            new Order { CustomerName = "Петро", OrderDate = new DateTime(2025, 2, 5), TotalAmount = 120 }
        };

        var currentMonthOrders = orders.Where(o => o.OrderDate.Month == DateTime.Now.Month);
        var monthlyTotal = orders.GroupBy(o => o.OrderDate.Month)
                                 .Select(g => new { Month = g.Key, TotalAmount = g.Sum(o => o.TotalAmount) });
        var topCustomer = orders.GroupBy(o => o.CustomerName)
                                .OrderByDescending(g => g.Count())
                                .First();

        Console.WriteLine("Замовлення цього місяця:");
        foreach (var order in currentMonthOrders)
        {
            Console.WriteLine($"Клієнт: {order.CustomerName}, Дата: {order.OrderDate.ToShortDateString()}, Сума: {order.TotalAmount}");
        }

        Console.WriteLine("\nСумарна сума замовлень за місяць:");
        foreach (var month in monthlyTotal)
        {
            Console.WriteLine($"Місяць {month.Month}: {month.TotalAmount}");
        }

        Console.WriteLine($"\nКлієнт з найбільше замовлень: {topCustomer.Key}");
    }
}