using System;
using System.Collections;
using System.Collections.Generic;

public class FootballTeam : IEnumerable<Player>
{
    private List<Player> players;

    public FootballTeam()
    {
        players = new List<Player>();
    }

    public void AddPlayer(Player player)
    {
        players.Add(player);
    }

    public IEnumerator<Player> GetEnumerator()
    {
        return players.GetEnumerator();
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
}

public class Player
{
    public string Name { get; set; }
    public int Number { get; set; }

    public Player(string name, int number)
    {
        Name = name;
        Number = number;
    }

    public override string ToString()
    {
        return $"{Name} (No. {Number})";
    }
}

public class Program
{
    public static void Main()
    {
        FootballTeam team = new FootballTeam();
        team.AddPlayer(new Player("Lionel Messi", 10));
        team.AddPlayer(new Player("Cristiano Ronaldo", 7));

        foreach (var player in team)
        {
            Console.WriteLine(player);
        }
    }
}