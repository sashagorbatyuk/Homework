using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace UdpCalculatorServer
{
    class Program
    {
        static void Main(string[] args)
        {
            int port = 11000;
            UdpClient udpServer = new(port);

            Console.WriteLine("UDP калькулятор сервер запущений на порту {0}", port);

            // Очікування на повідомлення від клієнта
            while (true)
            {
                try
                {
                    // Отримання пакету від клієнта
                    IPEndPoint endPoint = new IPEndPoint(IPAddress.Any, port);
                    byte[] data = udpServer.Receive(ref endPoint);
                    string receivedMessage = Encoding.UTF8.GetString(data);
                    Console.WriteLine($"Отримано вираз: {receivedMessage}");

                    // Обробка виразу
                    string result = ProcessExpression(receivedMessage);

                    // Відправка результату назад клієнту
                    byte[] resultData = Encoding.UTF8.GetBytes(result);
                    udpServer.Send(resultData, resultData.Length, endPoint);
                    Console.WriteLine($"Відправлено результат: {result}");
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Помилка: {ex.Message}");
                }
            }
        }

        // Обробка математичного виразу
        static string ProcessExpression(string expression)
        {
            try
            {
                expression = expression.Trim();
                var parts = expression.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                if (parts.Length < 2 || parts.Length > 3)
                    return "Невірний формат";

                double operand1 = Convert.ToDouble(parts[0]);
                string operatorSymbol = parts[1];
                double operand2 = parts.Length == 3 ? Convert.ToDouble(parts[2]) : 0;

                double result = operatorSymbol switch
                {
                    "+" => operand1 + operand2,
                    "-" => operand1 - operand2,
                    "*" => operand1 * operand2,
                    "/" => operand2 == 0 ? throw new DivideByZeroException() : operand1 / operand2,
                    "^" => Math.Pow(operand1, operand2),
                    "sqrt" => Math.Sqrt(operand1),
                    "%" => (operand1 / 100.0) * operand2,
                    _ => throw new InvalidOperationException("Невідомий оператор")
                };

                return result.ToString();
            }
            catch (DivideByZeroException)
            {
                return "Error: Division by zero!";
            }
            catch (Exception)
            {
                return "Помилка в обчисленні";
            }
        }
    }
}