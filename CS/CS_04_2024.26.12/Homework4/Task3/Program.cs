using System;

class Passport
{
    public string PassportNumber { get; private set; }
    public string Name { get; private set; }
    public string IssueDate { get; private set; }

    public Passport(string passportNumber, string name, string issueDate)
    {
        if (string.IsNullOrWhiteSpace(passportNumber) || !int.TryParse(passportNumber, out _))
        {
            throw new ArgumentException("Номер паспорта має бути числом.");
        }

        if (string.IsNullOrWhiteSpace(name) || !name.Replace(" ", "").All(Char.IsLetter))
        {
            throw new ArgumentException("ПІБ має містити тільки букви.");
        }

        PassportNumber = passportNumber;
        Name = name;
        IssueDate = issueDate;
    }

    public override string ToString()
    {
        return $"Паспорт №{PassportNumber}, ПІБ: {Name}, Дата видачі: {IssueDate}";
    }
}

class Program
{
    static void Main()
    {
        try
        {
            Passport passport = new Passport("123456789", "Іван Іванов", "2024-12-23");
            Console.WriteLine(passport);
        }
        catch (ArgumentException e)
        {
            Console.WriteLine(e.Message);
        }
    }
}