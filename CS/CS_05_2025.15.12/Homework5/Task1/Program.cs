using System;

class Money
{
    public int Dollars { get; set; }
    public int Cents { get; set; }

    public Money(int dollars, int cents)
    {
        Dollars = dollars;
        Cents = cents;
    }

    public void DisplayAmount()
    {
        Console.WriteLine($"{Dollars} доларів і {Cents} центів");
    }

    public void SetAmount(int dollars, int cents)
    {
        Dollars = dollars;
        Cents = cents;
    }
}

class Product
{
    public string Name { get; set; }
    public Money Price { get; set; }

    public Product(string name, Money price)
    {
        Name = name;
        Price = price;
    }

    public void Discount(int dollars, int cents)
    {
        int totalCents = Price.Dollars * 100 + Price.Cents;
        int discountCents = dollars * 100 + cents;
        totalCents -= discountCents;

        Price.Dollars = totalCents / 100;
        Price.Cents = totalCents % 100;
    }

    public void DisplayProduct()
    {
        Console.WriteLine($"Продукт: {Name}");
        Console.Write("Ціна: ");
        Price.DisplayAmount();
    }
}

class Program
{
    static void Main()
    {
        Money price = new Money(50, 75);
        Product product = new Product("Телефон", price);
        product.DisplayProduct();

        Console.WriteLine("\nЗнижка 10 доларів і 50 центів");
        product.Discount(10, 50);
        product.DisplayProduct();
    }
}