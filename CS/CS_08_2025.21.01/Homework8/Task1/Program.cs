using System;

public class Piesa
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

    // Деструктор
    ~Piesa()
    {
        Console.WriteLine($"Деструктор для п'єси '{Nazva}' викликано.");
    }
}

class Program
{
    static void Main(string[] args)
    {
        // Створення екземпляра п'єси
        Piesa piesa = new Piesa("Ревізор", "Николай Гоголь", "Комедія", 1836);
        piesa.ShowInfo();

        // Деструктор буде викликаний автоматично під час завершення роботи програми або видалення об'єкта з пам'яті.
    }
}