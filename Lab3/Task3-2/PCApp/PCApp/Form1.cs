using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.IO.Ports;

namespace PCApp
{
    public partial class Form1 : Form
    {
        SerialPort serialPort = new SerialPort("COM7", 9600);

        public Form1()
        {
            InitializeComponent();

            try
            {
                // 開啟 COM6
                serialPort.Open();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Serial Port 開啟失敗：\n" + ex.Message);
            }
        }

        private void btnOn_Click(object sender, EventArgs e)
        {
            if (serialPort.IsOpen)
            {
                // 傳送字元 1 給 Arduino
                serialPort.Write("1");
            }
        }

        private void btnOff_Click(object sender, EventArgs e)
        {
            if (serialPort.IsOpen)
            {
                // 傳送字元 0 給 Arduino
                serialPort.Write("0");
            }
        }

        protected override void OnFormClosing(FormClosingEventArgs e)
        {
            // 關閉程式前把 Serial Port 關掉
            if (serialPort.IsOpen)
            {
                serialPort.Close();
            }

            base.OnFormClosing(e);
        }
    }
}
