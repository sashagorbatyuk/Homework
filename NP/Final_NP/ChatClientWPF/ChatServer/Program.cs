// Server: Program.cs
using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace ChatServer
{
    class Program
    {
        private static TcpListener listener;
        private static Dictionary<TcpClient, string> clients = new Dictionary<TcpClient, string>();
        private static object lockObj = new object();

        static void Main(string[] args)
        {
            listener = new TcpListener(IPAddress.Any, 12345);
            listener.Start();
            Console.WriteLine("Server started on port 12345...");

            while (true)
            {
                TcpClient client = listener.AcceptTcpClient();
                Thread thread = new Thread(HandleClient);
                thread.Start(client);
            }
        }

        static void HandleClient(object obj)
        {
            TcpClient client = (TcpClient)obj;
            NetworkStream stream = client.GetStream();

            byte[] buffer = new byte[1024];
            int bytesRead = stream.Read(buffer, 0, buffer.Length);
            string name = Encoding.UTF8.GetString(buffer, 0, bytesRead).Trim();

            Console.WriteLine($"{name} connected.");
            lock (lockObj)
            {
                clients.Add(client, name);
                Broadcast($"[{GetTime()}] {name} joined the chat", client);
            }

            try
            {
                while (true)
                {
                    bytesRead = stream.Read(buffer, 0, buffer.Length);
                    if (bytesRead == 0) break;

                    string message = Encoding.UTF8.GetString(buffer, 0, bytesRead).Trim();

                    if (message == "/users")
                    {
                        string userList;
                        lock (lockObj)
                        {
                            userList = string.Join(", ", clients.Values);
                        }
                        byte[] userBytes = Encoding.UTF8.GetBytes($"Active users: {userList}\n");
                        stream.Write(userBytes, 0, userBytes.Length);
                    }
                    else if (message == "/exit")
                    {
                        break;
                    }
                    else
                    {
                        string formatted = $"[{GetTime()}] {name}: {message}";
                        Broadcast(formatted, client);
                    }
                }
            }
            catch { }
            finally
            {
                lock (lockObj)
                {
                    if (clients.ContainsKey(client))
                    {
                        Console.WriteLine($"{name} disconnected.");
                        clients.Remove(client);
                        Broadcast($"[{GetTime()}] {name} left the chat", client);
                    }
                }
                client.Close();
            }
        }

        static void Broadcast(string message, TcpClient excludeClient = null)
        {
            byte[] buffer = Encoding.UTF8.GetBytes(message + "\n");
            Console.WriteLine(message);
            lock (lockObj)
            {
                foreach (var pair in clients)
                {
                        try
                        {
                            pair.Key.GetStream().Write(buffer, 0, buffer.Length);
                        }
                        catch { }
                }
            }
        }

        static string GetTime() => DateTime.Now.ToString("HH:mm:ss");
    }
}
