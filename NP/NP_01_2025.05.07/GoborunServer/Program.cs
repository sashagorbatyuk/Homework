using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;

class Server
{
    static Dictionary<string, string> responses = new();

    static void Main()
    {
        var listener = new TcpListener(IPAddress.Any, 8080);
        listener.Start();
        Console.WriteLine("Сервер запущено на порту 8080...");

        while (true)
        {
            using var client = listener.AcceptTcpClient();
            using var stream = client.GetStream();

            byte[] buffer = new byte[1024];
            int length = stream.Read(buffer, 0, buffer.Length);
            string question = Encoding.UTF8.GetString(buffer, 0, length).Trim();

            Console.WriteLine($"Клієнт: {question}");

            string response;
            if (responses.ContainsKey(question))
            {
                response = responses[question];
            }
            else
            {
                Console.Write($"Немає відповіді. Введіть відповідь для \"{question}\": ");
                response = Console.ReadLine();
                responses[question] = response;
            }

            byte[] responseBytes = Encoding.UTF8.GetBytes(response);
            stream.Write(responseBytes, 0, responseBytes.Length);
        }
    }
}