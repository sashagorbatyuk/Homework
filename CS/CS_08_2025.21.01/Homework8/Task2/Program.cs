using System;

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

    // Деструктор (необов'язковий, але можна використовувати для звільнення ресурсів)
    ~Magazin()
    {
        Console.WriteLine($"Деструктор для магазину '{Nazva}' викликано.");
    }
}

class Program
{
    static void Main(string[] args)
    {
        // Створення екземпляра магазину
        using (Magazin magazin = new Magazin("Супермаркет", "вул. Київська 10", "Продовольчий"))
        {
            magazin.ShowInfo();
        } // Викликається Dispose, коли блок using завершується.

        // Вигляд після завершення
        Console.WriteLine("Програма завершена.");
    }
}