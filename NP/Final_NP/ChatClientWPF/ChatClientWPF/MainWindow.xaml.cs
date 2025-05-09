using System;
using System.IO;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Windows;
using System.Windows.Input;

namespace ChatClientWPF
{
    public partial class MainWindow : Window
    {
        TcpClient client;
        NetworkStream stream;
        Thread receiveThread;
        bool connected = false;

        public MainWindow()
        {
            InitializeComponent();

            if (File.Exists("chat_history.txt"))
            {
                string[] history = File.ReadAllLines("chat_history.txt");
                foreach (string line in history)
                {
                    ChatBox.AppendText(line + "\n");
                }
                ChatBox.ScrollToEnd();
            }
        }

        private void Connect_Click(object sender, RoutedEventArgs e)
        {
            if (connected) return;

            try
            {
                client = new TcpClient("127.0.0.1", 12345);
                stream = client.GetStream();
                byte[] data = Encoding.UTF8.GetBytes(UsernameBox.Text);
                stream.Write(data, 0, data.Length);

                receiveThread = new Thread(ReceiveMessages);
                receiveThread.IsBackground = true;
                receiveThread.Start();

                connected = true;
                ChatBox.AppendText("✅ Connected to server.\n");
            }
            catch
            {
                ChatBox.AppendText("❌ Failed to connect to server.\n");
            }
        }

        private void ReceiveMessages()
        {
            byte[] buffer = new byte[1024];
            try
            {
                while (connected)
                {
                    int bytes = stream.Read(buffer, 0, buffer.Length);
                    if (bytes == 0) break;

                    string message = Encoding.UTF8.GetString(buffer, 0, bytes);
                    Dispatcher.Invoke(() =>
                    {
                        // Append message to ChatBox and save to file.
                        ChatBox.AppendText(message + "\n");
                        File.AppendAllText("chat_history.txt", message + Environment.NewLine);
                        ChatBox.ScrollToEnd();
                    });
                }
            }
            catch (IOException ex)
            {
                Dispatcher.Invoke(() => ChatBox.AppendText($"⚠️ Server disconnected: {ex.Message}\n"));
            }
            catch (ObjectDisposedException)
            {
                // Expected during shutdown, no action needed.
            }
            catch (Exception ex)
            {
                Dispatcher.Invoke(() => ChatBox.AppendText($"⚠️ Error: {ex.Message}\n"));
            }
        }



        private void Send_Click(object sender, RoutedEventArgs e)
        {
            SendMessage();
        }

        private void Disconnect_Click(object sender, RoutedEventArgs e)
        {
            if (connected)
            {
                try
                {
                    byte[] exitData = Encoding.UTF8.GetBytes("/exit");
                    stream.Write(exitData, 0, exitData.Length);
                }
                catch { }

                CloseConnection();
            }
            else
            {
                ChatBox.AppendText("⚠️ Already disconnected.\n");
            }
        }


        private void MessageBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                SendMessage();
                e.Handled = true;
            }
        }

        private void SendMessage()
        {
            if (!connected || string.IsNullOrWhiteSpace(MessageBox.Text)) return;

            string msg = MessageBox.Text.Trim();
            byte[] data = Encoding.UTF8.GetBytes(msg);
            stream.Write(data, 0, data.Length);

            if (msg == "/exit")
            {
                CloseConnection();
            }

            MessageBox.Clear();
        }

        private void CloseConnection()
        {
            connected = false;
            client?.Close();
            Dispatcher.Invoke(() => ChatBox.AppendText("🔌 Disconnected from server.\n"));
        }

        protected override void OnClosed(EventArgs e)
        {
            CloseConnection();
            base.OnClosed(e);
        }
    }
}