using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace First
{
    class Program
    {
        static void Main(string[] args)
        {
            Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            IPEndPoint ep = new IPEndPoint(IPAddress.Any, 7000);
            socket.Bind(ep);

            socket.Listen(10);

            Socket clientSocket = socket.Accept();

            byte[] buff = new byte [8192];
            while (!Console.KeyAvailable)
            {
                int n = clientSocket.Receive(buff);

                string data = Encoding.UTF8.GetString(buff, 0, n);
                Console.WriteLine(data);

                clientSocket.Send(buff, 0, n, SocketFlags.None);
            }

            clientSocket.Close();
            socket.Close();
        }
    }
}