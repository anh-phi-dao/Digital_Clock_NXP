using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsForms_MOCK
{
    public partial class Serial_status_label : Form
    {
        public Serial_status_label()
        {
            InitializeComponent();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Control.CheckForIllegalCrossThreadCalls = false;
            string[] Baudrate = {"600","1200","4800","9600","19200","115200"};
            BaudrateComboBox.Items.AddRange(Baudrate);
            string[] Port=SerialPort.GetPortNames();
            ComPortCombobox.Items.AddRange(Port);
            
            string[] hour = { "00","01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23"};
            Hour_ComboBox.Items.AddRange(hour);
            string[] minute = new string[60];
            for(int i=0;i<60;i++)
            {
                if(i<=9)
                {
                    minute[i] = "0"+(i).ToString();
                }
                else
                {
                    minute[i] = (i).ToString();
                }
            }
            Minute_ComboBox.Items.AddRange(minute);
            string[] second = new string[60];
            for (int i = 0; i < 60; i++)
            {

                if (i <= 9)
                {
                    second[i] = "0" + (i).ToString();
                }
                else
                {
                    second[i] = (i).ToString();
                }
            }
            Second_ComboBox.Items.AddRange(second);
            progressBar1.Value = 0;
            Name_label.Text = "@author : Vu Quoc Khanh\n@author : Dao Anh Phi";

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void Open_com_port_button_Click(object sender, EventArgs e)
        {
            try
            {

                serialPort1.BaudRate = Convert.ToInt32(BaudrateComboBox.Text);
                serialPort1.PortName = ComPortCombobox.Text;
                serialPort1.Parity = System.IO.Ports.Parity.None;
                serialPort1.DataBits = 8;
                serialPort1.StopBits = System.IO.Ports.StopBits.One;
                if (!serialPort1.IsOpen)
                {
                    serialPort1.Open();
                    Serial_status_textbox.ForeColor = Color.Green;
                    Serial_status_textbox.BackColor = Color.WhiteSmoke;
                    Serial_status_textbox.Text = "Status: Connected";
                    progressBar1.Value = 100;
                    timer1.Enabled = true;
                    
                }
                else
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message,"Error",MessageBoxButtons.OK,MessageBoxIcon.Error);
            }
            
        }

        private void Close_com_port_button_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                timer1.Enabled= false;
                serialPort1.Close();
                Serial_status_textbox.Text = "Status: Disconnected";
                Serial_status_textbox.ForeColor = Color.DarkRed;
                Serial_status_textbox.BackColor = Color.WhiteSmoke;
                progressBar1.Value = 0;
            }
            else
            {
                MessageBox.Show("The port has already been closed", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void Send_day_time_button_Click(object sender, EventArgs e)
        {
            int a;
            try
            {
                a = Convert.ToInt16(Year_TextBox.Text);
                if (a < 0)
                {
                    MessageBox.Show("The year format is wrong", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message + '\n' + "Year has not been filled or year is having wrong format", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            int leap = 0;
            if (a % 4 == 0 && a % 100 != 0)
            {
                leap = 1;
            }
            int month;
            try
            {
                month = Convert.ToInt16(Month_TextBox.Text);
                if (month > 12 || month < 0)
                {
                    MessageBox.Show("The month can not be greater than 12 and the format needs to be correct", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message + '\n' + "Month has not been filled or the month format is being wrong", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            int day = 1;
            switch (month)
            {
                case 1:
                    day = 31;
                    break;
                case 2:
                    if (leap == 1)
                        day = 29;
                    else
                        day = 28;
                    break;
                case 3:
                    day = 31;
                    break;
                case 4:
                    day = 30;
                    break;
                case 5:
                    day = 31;
                    break;
                case 6:
                    day = 30;
                    break;
                case 7:
                    day = 31;
                    break;
                case 8:
                    day = 31;
                    break;
                case 9:
                    day = 30;
                    break;
                case 10:
                    day = 31;
                    break;
                case 11:
                    day = 30;
                    break;
                case 12:
                    day = 31;
                    break;
                default:
                    break;
            }
            int input_day;
            try
            {
                input_day = Convert.ToInt16(Day_TextBox.Text);
                if (input_day > day || input_day < 0)
                {
                    MessageBox.Show("The day value is not correct with current month and year", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message + '\n' + "Day has not been filled or the day format is being wrong", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            try
            {
                int hour = Convert.ToInt16(Hour_ComboBox.Text);
                if (hour > 23 || hour < 0)
                {
                    MessageBox.Show("Invalid hour", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message + '\n' + "Hour has not been filled or the hours format is being wrong", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            try
            {
                int minute = Convert.ToInt16(Minute_ComboBox.Text);
                if (minute > 59 || minute < 0)
                {
                    MessageBox.Show("Invalid minute", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message + '\n' + "Minute has not been filled or the minute format is being wrong", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            try
            {
                int second = Convert.ToInt16(Second_ComboBox.Text);
                if (second > 59 || second < 0)
                {
                    MessageBox.Show("Invalid second", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message + '\n' + "Second has not been filled or the second format is being wrong", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            string send = Hour_ComboBox.Text +'.' +Minute_ComboBox.Text + '.' +Second_ComboBox.Text + '.' + Day_TextBox.Text + '.' + Month_TextBox.Text + '.' + Year_TextBox.Text;
            if(serialPort1.IsOpen )
            {
                serialPort1.WriteLine(send);
                MessageBox.Show("The data has been transmitted", "", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Serial port has not opened yet", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
           
        }

        private void Send_real_time_button_Click(object sender, EventArgs e)
        {
            DateTime localdate= DateTime.Now;
            string[] cultureNames = { "en-US", "en-GB", "fr-FR","de-DE", "ru-RU" };
            var culture = new CultureInfo(cultureNames[3]);
            string [] day_time= localdate.ToString(culture).Split(' ');
            string[] date_month_year = day_time[0].Split('.');
            string[] hour_minute_second = day_time[1].Split(':');
            string send = hour_minute_second[0] + '.' + hour_minute_second[1] + '.' + hour_minute_second[2] + '.' + date_month_year[0] + '.' + date_month_year[1] + '.' + date_month_year[2]; 
            if (serialPort1.IsOpen)
            {
                serialPort1.WriteLine(send);
                MessageBox.Show("The data has been transmitted", "", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Serial port has not opened yet","Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
           
        }

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            try
            {
                string recevie = serialPort1.ReadLine();
                string[] date_time = recevie.Split('-');
                Time_received_TextBox.ForeColor=Color.Purple;
                Time_received_TextBox.BackColor=Color.WhiteSmoke;
                Time_received_TextBox.Text = date_time[0];
                Date_received_TextBox.ForeColor = Color.DarkBlue;
                Date_received_TextBox.BackColor = Color.WhiteSmoke;
                Date_received_TextBox.Text = date_time[1];
            }
            catch(Exception)
            {

            }
        }

        


        private void Sacn_com_port_button_Click(object sender, EventArgs e)
        {
            ComPortCombobox.Items.Clear();
            string[] Port = SerialPort.GetPortNames();
            ComPortCombobox.Items.AddRange(Port);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if(!serialPort1.IsOpen)
            {
                timer1.Enabled = false;
                Serial_status_textbox.Text = "Status: Disconnected";
                Serial_status_textbox.ForeColor = Color.DarkRed;
                Serial_status_textbox.BackColor = Color.WhiteSmoke;
                progressBar1.Value = 0;
                MessageBox.Show("The port is suddenly disconnected","Error",MessageBoxButtons.OK, MessageBoxIcon.Error);
            }    
        }
    }
}
