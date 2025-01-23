using System;
using System.Collections;
using System.Collections.Generic;

public class Cafe : IEnumerable<StaffMember>
{
    private List<StaffMember> staff;

    public Cafe()
    {
        staff = new List<StaffMember>();
    }

    public void AddStaffMember(StaffMember member)
    {
        staff.Add(member);
    }

    public IEnumerator<StaffMember> GetEnumerator()
    {
        return staff.GetEnumerator();
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
}

public class StaffMember
{
    public string Name { get; set; }
    public string Role { get; set; }

    public StaffMember(string name, string role)
    {
        Name = name;
        Role = role;
    }

    public override string ToString()
    {
        return $"{Name} ({Role})";
    }
}

public class Program
{
    public static void Main()
    {
        Cafe cafe = new Cafe();
        cafe.AddStaffMember(new StaffMember("Alice", "Waitress"));
        cafe.AddStaffMember(new StaffMember("Bob", "Chef"));

        foreach (var staff in cafe)
        {
            Console.WriteLine(staff);
        }
    }
}