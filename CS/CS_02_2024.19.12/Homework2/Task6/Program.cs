using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Введіть текст:");
        string text = Console.ReadLine();

        string[] sentences = text.Split(new[] { '.', '!', '?' });
        for (int i = 0; i < sentences.Length; i++)
        {
            string sentence = sentences[i].Trim();
            if (sentence.Length > 0)
                sentences[i] = char.ToUpper(sentence[0]) + sentence.Substring(1);
        }

        Console.WriteLine(string.Join(". ", sentences) + ".");
    }
}