using System;

abstract class Device
{
    public string Name { get; set; }
    public string Description { get; set; }

    public Device(string name, string description)
    {
        Name = name;
        Description = description;
    }

    public abstract void Sound();
    public void Show() => Console.WriteLine($"Назва пристрою: {Name}");
    public void Desc() => Console.WriteLine($"Опис: {Description}");
}

class Kettle : Device
{
    public Kettle() : base("Чайник", "Пристрій для кип'ятіння води.") { }

    public override void Sound() => Console.WriteLine("Шипить!");
}

class Microwave : Device
{
    public Microwave() : base("Мікрохвильовка", "Пристрій для розігріву їжі.") { }

    public override void Sound() => Console.WriteLine("Бі-бі-бі!");
}

class Car : Device
{
    public Car() : base("Автомобіль", "Транспортний засіб для пересування по дорозі.") { }

    public override void Sound() => Console.WriteLine("Бі-бі!");
}

class Steamboat : Device
{
    public Steamboat() : base("Пароплав", "Корабель, що рухається за допомогою пари.") { }

    public override void Sound() => Console.WriteLine("Гудіти!");
}

class Program
{
    static void Main()
    {
        Device kettle = new Kettle();
        kettle.Show();
        kettle.Desc();
        kettle.Sound();

        Console.WriteLine();

        Device microwave = new Microwave();
        microwave.Show();
        microwave.Desc();
        microwave.Sound();
    }
}