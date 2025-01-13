using System;

abstract class Worker
{
    public string Name { get; set; }
    public int Age { get; set; }

    public Worker(string name, int age)
    {
        Name = name;
        Age = age;
    }

    public abstract void Print();
}

class President : Worker
{
    public President(string name, int age) : base(name, age) { }

    public override void Print() => Console.WriteLine($"Президент: {Name}, Вік: {Age}");
}

class Security : Worker
{
    public Security(string name, int age) : base(name, age) { }

    public override void Print() => Console.WriteLine($"Охоронець: {Name}, Вік: {Age}");
}

class Manager : Worker
{
    public Manager(string name, int age) : base(name, age) { }

    public override void Print() => Console.WriteLine($"Менеджер: {Name}, Вік: {Age}");
}

class Engineer : Worker
{
    public Engineer(string name, int age) : base(name, age) { }

    public override void Print() => Console.WriteLine($"Інженер: {Name}, Вік: {Age}");
}

class Program
{
    static void Main()
    {
        Worker president = new President("Іван", 45);
        Worker security = new Security("Олександр", 30);
        Worker manager = new Manager("Анна", 38);
        Worker engineer = new Engineer("Сергій", 28);

        president.Print();
        security.Print();
        manager.Print();
        engineer.Print();
    }
}