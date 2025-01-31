using System;
using System.Collections.Generic;
using System.Linq;

public class Student
{
    public string Name { get; set; }
    public int Age { get; set; }
    public double Grade { get; set; }
}

public class Program
{
    public static void Main()
    {
        var students = new List<Student>
        {
            new Student { Name = "Іван", Age = 22, Grade = 90 },
            new Student { Name = "Марія", Age = 19, Grade = 88 },
            new Student { Name = "Петро", Age = 23, Grade = 92 },
            new Student { Name = "Олена", Age = 21, Grade = 84 }
        };

        var filteredStudents = students
            .Where(s => s.Age > 20 && s.Grade > 85)
            .OrderByDescending(s => s.Grade)
            .Select(s => new { s.Name, s.Grade });

        foreach (var student in filteredStudents)
        {
            Console.WriteLine($"Ім'я: {student.Name}, Оцінка: {student.Grade}");
        }
    }
}