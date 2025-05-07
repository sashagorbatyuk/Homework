using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows;
using System.Threading.Tasks;

namespace UdpCalculatorClient
{
    public partial class MainWindow : Window
    {
        private UdpClient udpClient;
        private const string ServerAddress = "127.0.0.1";
        private const int ServerPort = 11000;

        public MainWindow()
        {
            InitializeComponent();
            udpClient = new UdpClient();
        }

        private async void CalculateButton_Click(object sender, RoutedEventArgs e)
        {
            string expression = ExpressionTextBox.Text.Trim();

            // Перевірка правильності формату виразу (наприклад, "5 + 3")
            if (!Regex.IsMatch(expression, @"^\d+(\.\d+)?\s([+\-*/^%]|sqrt)(\s\d+(\.\d+)?)?$"))
            {
                MessageBox.Show("Введіть коректний вираз у форматі: operand1 operator [operand2]. Наприклад: 5 + 3 або 9 sqrt.",
                    "Невірний формат", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            // Вимкнути кнопку під час обчислення
            CalculateButton.IsEnabled = false;

            try
            {
                byte[] data = Encoding.UTF8.GetBytes(expression);

                bool sent = false;
                int attempts = 0;

                while (!sent && attempts < 5)
                {
                    try
                    {
                        udpClient.Send(data, data.Length, ServerAddress, ServerPort);
                        sent = true;
                    }
                    catch
                    {
                        ResultTextBlock.Text = "Server is offline. Retrying...";
                        await Task.Delay(5000);
                        attempts++;
                    }
                }

                if (!sent)
                {
                    ResultTextBlock.Text = "Не вдалося підключитися до сервера.";
                    return;
                }

                IPEndPoint endPoint = new IPEndPoint(IPAddress.Any, ServerPort);
                byte[] resultData = await Task.Run(() => udpClient.Receive(ref endPoint));
                string result = Encoding.UTF8.GetString(resultData);

                ResultTextBlock.Text = $"Результат: {result}";
            }
            finally
            {
                // Увімкнути кнопку після обчислення
                CalculateButton.IsEnabled = true;
            }
        }

        // Очистити поля результату та введення
        private void ClearButton_Click(object sender, RoutedEventArgs e)
        {
            ExpressionTextBox.Clear();
            ResultTextBlock.Text = string.Empty;
        }

        // Закриття UDP клієнта при закритті вікна
        protected override void OnClosed(EventArgs e)
        {
            udpClient.Close();
            base.OnClosed(e);
        }
    }
}
