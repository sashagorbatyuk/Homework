using System;
using System.Net.Sockets;
using System.Text;

class Client
{
    static void Main()
    {
        Console.WriteLine("Підключення до сервера...");

        while (true)
        {
            Console.Write("Ви: ");
            string message = Console.ReadLine();

            using var client = new TcpClient("127.0.0.1", 8080);
            using var stream = client.GetStream();

            byte[] data = Encoding.UTF8.GetBytes(message);
            stream.Write(data, 0, data.Length);

            byte[] buffer = new byte[1024];
            int bytes = stream.Read(buffer, 0, buffer.Length);
            string response = Encoding.UTF8.GetString(buffer, 0, bytes);

            Console.WriteLine("Сервер: " + response);
        }
    }
}
