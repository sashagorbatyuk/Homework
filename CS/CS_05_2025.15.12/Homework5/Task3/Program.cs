using System;

abstract class MusicalInstrument
{
    public string Name { get; set; }
    public string Description { get; set; }

    public MusicalInstrument(string name, string description)
    {
        Name = name;
        Description = description;
    }

    public abstract void Sound();
    public void Show() => Console.WriteLine($"Інструмент: {Name}");
    public void Desc() => Console.WriteLine($"Опис: {Description}");
    public abstract void History();
}

class Violin : MusicalInstrument
{
    public Violin() : base("Скрипка", "Струнний музичний інструмент.") { }

    public override void Sound() => Console.WriteLine("Віоліно звучить скрипково!");
    public override void History() => Console.WriteLine("Винайшли в Італії в 16 столітті.");
}

class Trombone : MusicalInstrument
{
    public Trombone() : base("Тромбон", "Мідний духовий інструмент.") { }

    public override void Sound() => Console.WriteLine("Тромбон звучить гучно!");
    public override void History() => Console.WriteLine("Тромбон має європейське походження з 15 століття.");
}

class Ukulele : MusicalInstrument
{
    public Ukulele() : base("Укулеле", "Гітароподібний інструмент Гавайських островів.") { }

    public override void Sound() => Console.WriteLine("Укулеле грає весело!");
    public override void History() => Console.WriteLine("Виник в Гаваях в кінці 19 століття.");
}

class Cello : MusicalInstrument
{
    public Cello() : base("Віолончель", "Великий струнний інструмент.") { }

    public override void Sound() => Console.WriteLine("Віолончель звучить велично!");
    public override void History() => Console.WriteLine("Створена в Італії в 16 столітті.");
}

class Program
{
    static void Main()
    {
        MusicalInstrument violin = new Violin();
        violin.Show();
        violin.Desc();
        violin.Sound();
        violin.History();

        Console.WriteLine();

        MusicalInstrument trombone = new Trombone();
        trombone.Show();
        trombone.Desc();
        trombone.Sound();
        trombone.History();
    }
}