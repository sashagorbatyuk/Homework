using System;
using System.Collections.Generic;
using System.Linq;

class Product
{
    public string Name { get; set; }
    public string Category { get; set; }
    public decimal Price { get; set; }
}

class Program
{
    static void Main()
    {
        List<Product> products = new List<Product>
        {
            new Product { Name = "Товар1", Category = "Категорія1", Price = 100 },
            new Product { Name = "Товар2", Category = "Категорія1", Price = 50 },
            new Product { Name = "Товар3", Category = "Категорія2", Price = 200 },
            new Product { Name = "Товар4", Category = "Категорія2", Price = 300 },
            new Product { Name = "Товар5", Category = "Категорія1", Price = 150 }
        };

        var categoryStats = products
            .GroupBy(p => p.Category)
            .Select(g => new
            {
                Category = g.Key,
                CheapestProduct = g.OrderBy(p => p.Price).First(),
                ExpensiveProduct = g.OrderByDescending(p => p.Price).First(),
                AveragePrice = g.Average(p => p.Price)
            });

        foreach (var category in categoryStats)
        {
            Console.WriteLine($"Категорія: {category.Category}");
            Console.WriteLine($"Найдешевший товар: {category.CheapestProduct.Name}, Ціна: {category.CheapestProduct.Price}");
            Console.WriteLine($"Найдорожчий товар: {category.ExpensiveProduct.Name}, Ціна: {category.ExpensiveProduct.Price}");
            Console.WriteLine($"Середня ціна: {category.AveragePrice}");
        }
    }
}