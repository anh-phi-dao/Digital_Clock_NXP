namespace WindowsForms_MOCK
{
    partial class Serial_status_label
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.ComPortCombobox = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.BaudrateComboBox = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.Sacn_com_port_button = new System.Windows.Forms.Button();
            this.Open_com_port_button = new System.Windows.Forms.Button();
            this.Close_com_port_button = new System.Windows.Forms.Button();
            this.Send_day_time_button = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.Send_real_time_button = new System.Windows.Forms.Button();
            this.Year_TextBox = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.Hour_ComboBox = new System.Windows.Forms.ComboBox();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.Minute_ComboBox = new System.Windows.Forms.ComboBox();
            this.label12 = new System.Windows.Forms.Label();
            this.Second_ComboBox = new System.Windows.Forms.ComboBox();
            this.label14 = new System.Windows.Forms.Label();
            this.label16 = new System.Windows.Forms.Label();
            this.Serial_status_textbox = new System.Windows.Forms.TextBox();
            this.Month_TextBox = new System.Windows.Forms.TextBox();
            this.Day_TextBox = new System.Windows.Forms.TextBox();
            this.Date_received_TextBox = new System.Windows.Forms.TextBox();
            this.Time_received_TextBox = new System.Windows.Forms.TextBox();
            this.label13 = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.Name_label = new System.Windows.Forms.Label();
            this.sendTxt = new System.Windows.Forms.TextBox();
            this.sendBtn = new System.Windows.Forms.Button();
            this.recevieTxt = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.SuspendLayout();
            // 
            // serialPort1
            // 
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // ComPortCombobox
            // 
            this.ComPortCombobox.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ComPortCombobox.FormattingEnabled = true;
            this.ComPortCombobox.Location = new System.Drawing.Point(112, 76);
            this.ComPortCombobox.Name = "ComPortCombobox";
            this.ComPortCombobox.Size = new System.Drawing.Size(121, 25);
            this.ComPortCombobox.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(26, 83);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(78, 17);
            this.label1.TabIndex = 1;
            this.label1.Text = "COMPORT";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(290, 83);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(83, 17);
            this.label2.TabIndex = 2;
            this.label2.Text = "BAUDRATE";
            // 
            // BaudrateComboBox
            // 
            this.BaudrateComboBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.BaudrateComboBox.FormattingEnabled = true;
            this.BaudrateComboBox.Location = new System.Drawing.Point(414, 73);
            this.BaudrateComboBox.Name = "BaudrateComboBox";
            this.BaudrateComboBox.Size = new System.Drawing.Size(121, 25);
            this.BaudrateComboBox.TabIndex = 3;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
            this.label3.Location = new System.Drawing.Point(219, 25);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(225, 18);
            this.label3.TabIndex = 4;
            this.label3.Text = "Serial port connection config";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // Sacn_com_port_button
            // 
            this.Sacn_com_port_button.Location = new System.Drawing.Point(29, 25);
            this.Sacn_com_port_button.Name = "Sacn_com_port_button";
            this.Sacn_com_port_button.Size = new System.Drawing.Size(94, 31);
            this.Sacn_com_port_button.TabIndex = 5;
            this.Sacn_com_port_button.Text = "Scan Com port";
            this.Sacn_com_port_button.UseVisualStyleBackColor = true;
            this.Sacn_com_port_button.Click += new System.EventHandler(this.Sacn_com_port_button_Click);
            // 
            // Open_com_port_button
            // 
            this.Open_com_port_button.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.Open_com_port_button.FlatAppearance.BorderColor = System.Drawing.Color.Green;
            this.Open_com_port_button.FlatAppearance.BorderSize = 3;
            this.Open_com_port_button.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Open_com_port_button.ForeColor = System.Drawing.Color.Green;
            this.Open_com_port_button.Location = new System.Drawing.Point(112, 133);
            this.Open_com_port_button.Name = "Open_com_port_button";
            this.Open_com_port_button.Size = new System.Drawing.Size(142, 31);
            this.Open_com_port_button.TabIndex = 6;
            this.Open_com_port_button.Text = "Open com port";
            this.Open_com_port_button.UseVisualStyleBackColor = false;
            this.Open_com_port_button.Click += new System.EventHandler(this.Open_com_port_button_Click);
            // 
            // Close_com_port_button
            // 
            this.Close_com_port_button.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.Close_com_port_button.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Close_com_port_button.ForeColor = System.Drawing.Color.Red;
            this.Close_com_port_button.Location = new System.Drawing.Point(312, 133);
            this.Close_com_port_button.Name = "Close_com_port_button";
            this.Close_com_port_button.Size = new System.Drawing.Size(142, 31);
            this.Close_com_port_button.TabIndex = 7;
            this.Close_com_port_button.Text = "Close com port";
            this.Close_com_port_button.UseVisualStyleBackColor = false;
            this.Close_com_port_button.Click += new System.EventHandler(this.Close_com_port_button_Click);
            // 
            // Send_day_time_button
            // 
            this.Send_day_time_button.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Send_day_time_button.Location = new System.Drawing.Point(29, 245);
            this.Send_day_time_button.Name = "Send_day_time_button";
            this.Send_day_time_button.Size = new System.Drawing.Size(116, 61);
            this.Send_day_time_button.TabIndex = 8;
            this.Send_day_time_button.Text = "Send predefine date and time";
            this.Send_day_time_button.UseVisualStyleBackColor = true;
            this.Send_day_time_button.Click += new System.EventHandler(this.Send_day_time_button_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label4.Location = new System.Drawing.Point(434, 258);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(44, 20);
            this.label4.TabIndex = 10;
            this.label4.Text = "Date";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label5.Location = new System.Drawing.Point(432, 355);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(43, 20);
            this.label5.TabIndex = 12;
            this.label5.Text = "Time";
            // 
            // Send_real_time_button
            // 
            this.Send_real_time_button.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Send_real_time_button.Location = new System.Drawing.Point(29, 422);
            this.Send_real_time_button.Name = "Send_real_time_button";
            this.Send_real_time_button.Size = new System.Drawing.Size(116, 50);
            this.Send_real_time_button.TabIndex = 13;
            this.Send_real_time_button.Text = "Send real time";
            this.Send_real_time_button.UseVisualStyleBackColor = true;
            this.Send_real_time_button.Click += new System.EventHandler(this.Send_real_time_button_Click);
            // 
            // Year_TextBox
            // 
            this.Year_TextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Year_TextBox.Location = new System.Drawing.Point(312, 256);
            this.Year_TextBox.Name = "Year_TextBox";
            this.Year_TextBox.Size = new System.Drawing.Size(84, 26);
            this.Year_TextBox.TabIndex = 19;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(164, 227);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(26, 13);
            this.label7.TabIndex = 20;
            this.label7.Text = "Day";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(236, 227);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(37, 13);
            this.label8.TabIndex = 21;
            this.label8.Text = "Month";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(309, 227);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(29, 13);
            this.label9.TabIndex = 22;
            this.label9.Text = "Year";
            // 
            // Hour_ComboBox
            // 
            this.Hour_ComboBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Hour_ComboBox.FormattingEnabled = true;
            this.Hour_ComboBox.Location = new System.Drawing.Point(167, 347);
            this.Hour_ComboBox.Name = "Hour_ComboBox";
            this.Hour_ComboBox.Size = new System.Drawing.Size(66, 28);
            this.Hour_ComboBox.TabIndex = 23;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(164, 321);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(35, 13);
            this.label10.TabIndex = 24;
            this.label10.Text = "Hours";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(236, 321);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(44, 13);
            this.label11.TabIndex = 26;
            this.label11.Text = "Minutes";
            // 
            // Minute_ComboBox
            // 
            this.Minute_ComboBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Minute_ComboBox.FormattingEnabled = true;
            this.Minute_ComboBox.Location = new System.Drawing.Point(239, 347);
            this.Minute_ComboBox.Name = "Minute_ComboBox";
            this.Minute_ComboBox.Size = new System.Drawing.Size(66, 28);
            this.Minute_ComboBox.TabIndex = 25;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(309, 321);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(44, 13);
            this.label12.TabIndex = 28;
            this.label12.Text = "Second";
            // 
            // Second_ComboBox
            // 
            this.Second_ComboBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Second_ComboBox.FormattingEnabled = true;
            this.Second_ComboBox.Location = new System.Drawing.Point(312, 347);
            this.Second_ComboBox.Name = "Second_ComboBox";
            this.Second_ComboBox.Size = new System.Drawing.Size(66, 28);
            this.Second_ComboBox.TabIndex = 27;
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label14.ForeColor = System.Drawing.Color.Blue;
            this.label14.Location = new System.Drawing.Point(733, 245);
            this.label14.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(120, 20);
            this.label14.TabIndex = 31;
            this.label14.Text = "Date received";
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label16.ForeColor = System.Drawing.Color.Fuchsia;
            this.label16.Location = new System.Drawing.Point(733, 286);
            this.label16.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(119, 20);
            this.label16.TabIndex = 33;
            this.label16.Text = "Time received";
            // 
            // Serial_status_textbox
            // 
            this.Serial_status_textbox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Serial_status_textbox.ForeColor = System.Drawing.SystemColors.Desktop;
            this.Serial_status_textbox.Location = new System.Drawing.Point(628, 73);
            this.Serial_status_textbox.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Serial_status_textbox.Name = "Serial_status_textbox";
            this.Serial_status_textbox.ReadOnly = true;
            this.Serial_status_textbox.Size = new System.Drawing.Size(211, 24);
            this.Serial_status_textbox.TabIndex = 34;
            // 
            // Month_TextBox
            // 
            this.Month_TextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Month_TextBox.Location = new System.Drawing.Point(239, 256);
            this.Month_TextBox.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Month_TextBox.Name = "Month_TextBox";
            this.Month_TextBox.Size = new System.Drawing.Size(48, 26);
            this.Month_TextBox.TabIndex = 35;
            // 
            // Day_TextBox
            // 
            this.Day_TextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Day_TextBox.Location = new System.Drawing.Point(166, 256);
            this.Day_TextBox.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Day_TextBox.Name = "Day_TextBox";
            this.Day_TextBox.Size = new System.Drawing.Size(51, 26);
            this.Day_TextBox.TabIndex = 36;
            // 
            // Date_received_TextBox
            // 
            this.Date_received_TextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Date_received_TextBox.Location = new System.Drawing.Point(580, 241);
            this.Date_received_TextBox.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Date_received_TextBox.Name = "Date_received_TextBox";
            this.Date_received_TextBox.ReadOnly = true;
            this.Date_received_TextBox.Size = new System.Drawing.Size(140, 26);
            this.Date_received_TextBox.TabIndex = 38;
            // 
            // Time_received_TextBox
            // 
            this.Time_received_TextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Time_received_TextBox.Location = new System.Drawing.Point(580, 286);
            this.Time_received_TextBox.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Time_received_TextBox.Name = "Time_received_TextBox";
            this.Time_received_TextBox.ReadOnly = true;
            this.Time_received_TextBox.Size = new System.Drawing.Size(140, 26);
            this.Time_received_TextBox.TabIndex = 39;
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label13.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.label13.Location = new System.Drawing.Point(628, 42);
            this.label13.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(110, 20);
            this.label13.TabIndex = 42;
            this.label13.Text = "Serial status";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::WindowsForms_MOCK.Properties.Resources.hcmut_1;
            this.pictureBox1.Location = new System.Drawing.Point(554, 422);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(110, 105);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pictureBox1.TabIndex = 43;
            this.pictureBox1.TabStop = false;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Image = global::WindowsForms_MOCK.Properties.Resources.Icon_fpt;
            this.pictureBox2.Location = new System.Drawing.Point(660, 422);
            this.pictureBox2.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(200, 94);
            this.pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pictureBox2.TabIndex = 41;
            this.pictureBox2.TabStop = false;
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(628, 124);
            this.progressBar1.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(210, 31);
            this.progressBar1.TabIndex = 44;
            // 
            // Name_label
            // 
            this.Name_label.AutoSize = true;
            this.Name_label.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name_label.Location = new System.Drawing.Point(26, 502);
            this.Name_label.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.Name_label.Name = "Name_label";
            this.Name_label.Size = new System.Drawing.Size(52, 17);
            this.Name_label.TabIndex = 45;
            this.Name_label.Text = "label6";
            // 
            // sendTxt
            // 
            this.sendTxt.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.sendTxt.Location = new System.Drawing.Point(863, 71);
            this.sendTxt.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.sendTxt.Name = "sendTxt";
            this.sendTxt.Size = new System.Drawing.Size(130, 29);
            this.sendTxt.TabIndex = 46;
            // 
            // sendBtn
            // 
            this.sendBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.sendBtn.Location = new System.Drawing.Point(863, 124);
            this.sendBtn.Name = "sendBtn";
            this.sendBtn.Size = new System.Drawing.Size(84, 31);
            this.sendBtn.TabIndex = 47;
            this.sendBtn.Text = "Send";
            this.sendBtn.UseVisualStyleBackColor = true;
            // 
            // recevieTxt
            // 
            this.recevieTxt.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.recevieTxt.Location = new System.Drawing.Point(863, 180);
            this.recevieTxt.Margin = new System.Windows.Forms.Padding(2);
            this.recevieTxt.Name = "recevieTxt";
            this.recevieTxt.Size = new System.Drawing.Size(130, 29);
            this.recevieTxt.TabIndex = 48;
            // 
            // Serial_status_label
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1052, 540);
            this.Controls.Add(this.recevieTxt);
            this.Controls.Add(this.sendBtn);
            this.Controls.Add(this.sendTxt);
            this.Controls.Add(this.Name_label);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.pictureBox2);
            this.Controls.Add(this.Time_received_TextBox);
            this.Controls.Add(this.Date_received_TextBox);
            this.Controls.Add(this.Day_TextBox);
            this.Controls.Add(this.Month_TextBox);
            this.Controls.Add(this.Serial_status_textbox);
            this.Controls.Add(this.label16);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.Second_ComboBox);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.Minute_ComboBox);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.Hour_ComboBox);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.Year_TextBox);
            this.Controls.Add(this.Send_real_time_button);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.Send_day_time_button);
            this.Controls.Add(this.Close_com_port_button);
            this.Controls.Add(this.Open_com_port_button);
            this.Controls.Add(this.Sacn_com_port_button);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.BaudrateComboBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.ComPortCombobox);
            this.Name = "Serial_status_label";
            this.Text = "Mock_serial_window_form";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.ComboBox ComPortCombobox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox BaudrateComboBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button Sacn_com_port_button;
        private System.Windows.Forms.Button Open_com_port_button;
        private System.Windows.Forms.Button Close_com_port_button;
        private System.Windows.Forms.Button Send_day_time_button;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button Send_real_time_button;
        private System.Windows.Forms.TextBox Year_TextBox;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.ComboBox Hour_ComboBox;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.ComboBox Minute_ComboBox;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.ComboBox Second_ComboBox;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.TextBox Serial_status_textbox;
        private System.Windows.Forms.TextBox Month_TextBox;
        private System.Windows.Forms.TextBox Day_TextBox;
        private System.Windows.Forms.TextBox Date_received_TextBox;
        private System.Windows.Forms.TextBox Time_received_TextBox;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.Label Name_label;
        private System.Windows.Forms.TextBox sendTxt;
        private System.Windows.Forms.Button sendBtn;
        private System.Windows.Forms.TextBox recevieTxt;
    }
}

