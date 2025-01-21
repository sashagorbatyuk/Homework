using System;

public class Piesa : IDisposable
{
    // Властивості
    public string Nazva { get; set; }
    public string Avtor { get; set; }
    public string Zhannr { get; set; }
    public int Rik { get; set; }

    // Конструктор
    public Piesa(string nazva, string avtor, string zhannr, int rik)
    {
        Nazva = nazva;
        Avtor = avtor;
        Zhannr = zhannr;
        Rik = rik;
    }

    // Метод для виведення інформації про п'єсу
    public void ShowInfo()
    {
        Console.WriteLine($"Назва: {Nazva}");
        Console.WriteLine($"Автор: {Avtor}");
        Console.WriteLine($"Жанр: {Zhannr}");
        Console.WriteLine($"Рік: {Rik}");
    }

    // Реалізація методу Dispose
    public void Dispose()
    {
        // Очистка ресурсів (якщо необхідно)
        Console.WriteLine($"П'єса '{Nazva}' завершила свою роботу.");
        GC.SuppressFinalize(this);
    }

    // Деструктор
    ~Piesa()
    {
        Console.WriteLine($"Деструктор для п'єси '{Nazva}' викликано.");
    }
}

public class Magazin : IDisposable
{
    // Властивості
    public string Nazva { get; set; }
    public string Adresa { get; set; }
    public string Typ { get; set; }

    // Конструктор
    public Magazin(string nazva, string adresa, string typ)
    {
        Nazva = nazva;
        Adresa = adresa;
        Typ = typ;
    }

    // Метод для виведення інформації про магазин
    public void ShowInfo()
    {
        Console.WriteLine($"Назва магазину: {Nazva}");
        Console.WriteLine($"Адреса: {Adresa}");
        Console.WriteLine($"Тип магазину: {Typ}");
    }

    // Реалізація методу Dispose
    public void Dispose()
    {
        // Очищення ресурсів
        Console.WriteLine($"Магазин '{Nazva}' був закритий.");
        GC.SuppressFinalize(this);
    }

    // Деструктор
    ~Magazin()
    {
        Console.WriteLine($"Деструктор для магазину '{Nazva}' викликано.");
    }
}

class Program
{
    static void Main(string[] args)
    {
        // Створення екземпляра п'єси з Dispose
        using (Piesa piesa = new Piesa("Ревізор", "Николай Гоголь", "Комедія", 1836))
        {
            piesa.ShowInfo();
        } // Викликається Dispose для п'єси.

        // Створення екземпляра магазину з Dispose
        using (Magazin magazin = new Magazin("Супермаркет", "вул. Київська 10", "Продовольчий"))
        {
            magazin.ShowInfo();
        } // Викликається Dispose для магазину.

        // Завершення програми
        Console.WriteLine("Програма завершена.");
    }
}