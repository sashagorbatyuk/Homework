using System;

class Employee
{
    static void Main(string[] args)
    {
        Employee employee = new Employee();
        employee.InputData();
        employee.OutputData();
    }

    public string FullName { get; set; }
    public DateTime DateOfBirth { get; set; }
    public string ContactPhone { get; set; }
    public string WorkEmail { get; set; }
    public string Position { get; set; }
    public string JobDescription { get; set; }

    public void InputData()
    {
        Console.WriteLine("Enter full name:");
        FullName = Console.ReadLine();
        Console.WriteLine("Enter date of birth (yyyy-mm-dd):");
        DateOfBirth = DateTime.Parse(Console.ReadLine());
        Console.WriteLine("Enter contact phone:");
        ContactPhone = Console.ReadLine();
        Console.WriteLine("Enter work email:");
        WorkEmail = Console.ReadLine();
        Console.WriteLine("Enter position:");
        Position = Console.ReadLine();
        Console.WriteLine("Enter job description:");
        JobDescription = Console.ReadLine();
    }

    public void OutputData()
    {
        Console.WriteLine($"Full Name: {FullName}");
        Console.WriteLine($"Date of Birth: {DateOfBirth.ToShortDateString()}");
        Console.WriteLine($"Contact Phone: {ContactPhone}");
        Console.WriteLine($"Work Email: {WorkEmail}");
        Console.WriteLine($"Position: {Position}");
        Console.WriteLine($"Job Description: {JobDescription}");
    }
}
