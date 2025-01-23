using System;
using System.Collections;
using System.Collections.Generic;

public class Oceanarium : IEnumerable<SeaCreature>
{
    private List<SeaCreature> creatures;

    public Oceanarium()
    {
        creatures = new List<SeaCreature>();
    }

    public void AddCreature(SeaCreature creature)
    {
        creatures.Add(creature);
    }

    public IEnumerator<SeaCreature> GetEnumerator()
    {
        return creatures.GetEnumerator();
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
}

public class SeaCreature
{
    public string Name { get; set; }
    public string Species { get; set; }

    public SeaCreature(string name, string species)
    {
        Name = name;
        Species = species;
    }

    public override string ToString()
    {
        return $"{Name} ({Species})";
    }
}

public class Program
{
    public static void Main()
    {
        Oceanarium oceanarium = new Oceanarium();
        oceanarium.AddCreature(new SeaCreature("Nemo", "Clownfish"));
        oceanarium.AddCreature(new SeaCreature("Dory", "Blue Tang"));

        foreach (var creature in oceanarium)
        {
            Console.WriteLine(creature);
        }
    }
}