class City
{
    static void Main(string[] args)
    {
        City city = new City();
        city.InputData();
        city.OutputData();
    }

    public string CityName { get; set; }
    public string CountryName { get; set; }
    public int Population { get; set; }
    public string PhoneCode { get; set; }
    public string Districts { get; set; }

    public void InputData()
    {
        Console.WriteLine("Enter city name:");
        CityName = Console.ReadLine();
        Console.WriteLine("Enter country name:");
        CountryName = Console.ReadLine();
        Console.WriteLine("Enter population:");
        Population = int.Parse(Console.ReadLine());
        Console.WriteLine("Enter phone code:");
        PhoneCode = Console.ReadLine();
        Console.WriteLine("Enter districts:");
        Districts = Console.ReadLine();
    }

    public void OutputData()
    {
        Console.WriteLine($"City: {CityName}");
        Console.WriteLine($"Country: {CountryName}");
        Console.WriteLine($"Population: {Population}");
        Console.WriteLine($"Phone Code: {PhoneCode}");
        Console.WriteLine($"Districts: {Districts}");
    }
}
