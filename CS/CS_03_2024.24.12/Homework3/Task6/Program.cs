using System;

class Airplane
{
    static void Main(string[] args)
    {
        Airplane airplane = new Airplane();
        airplane.InputData();
        airplane.OutputData();
    }

    public string AirplaneName { get; set; }
    public string Manufacturer { get; set; }
    public int YearOfRelease { get; set; }
    public string AirplaneType { get; set; }

    public Airplane() { }

    public Airplane(string airplaneName, string manufacturer, int yearOfRelease, string airplaneType)
    {
        AirplaneName = airplaneName;
        Manufacturer = manufacturer;
        YearOfRelease = yearOfRelease;
        AirplaneType = airplaneType;
    }

    public void InputData()
    {
        Console.WriteLine("Enter airplane name:");
        AirplaneName = Console.ReadLine();
        Console.WriteLine("Enter manufacturer:");
        Manufacturer = Console.ReadLine();
        Console.WriteLine("Enter year of release:");
        YearOfRelease = int.Parse(Console.ReadLine());
        Console.WriteLine("Enter airplane type:");
        AirplaneType = Console.ReadLine();
    }

    public void OutputData()
    {
        Console.WriteLine($"Airplane Name: {AirplaneName}");
        Console.WriteLine($"Manufacturer: {Manufacturer}");
        Console.WriteLine($"Year of Release: {YearOfRelease}");
        Console.WriteLine($"Airplane Type: {AirplaneType}");
    }
}