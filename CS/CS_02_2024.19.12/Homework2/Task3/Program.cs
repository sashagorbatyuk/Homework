using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Введіть текст:");
        string input = Console.ReadLine();
        Console.WriteLine("Введіть зсув:");
        int shift = int.Parse(Console.ReadLine());

        string Encrypt(string text, int s)
        {
            string result = "";
            foreach (char c in text)
                result += char.IsLetter(c) ? (char)((c + s - (char.IsUpper(c) ? 'A' : 'a')) % 26 + (char.IsUpper(c) ? 'A' : 'a')) : c;
            return result;
        }

        string encrypted = Encrypt(input, shift);
        string decrypted = Encrypt(encrypted, -shift);

        Console.WriteLine($"Зашифровано: {encrypted}");
        Console.WriteLine($"Розшифровано: {decrypted}");
    }
}