namespace MLX90939_Interface
{
    partial class Form1
    {
        /// <summary>
        /// Erforderliche Designervariable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Verwendete Ressourcen bereinigen.
        /// </summary>
        /// <param name="disposing">True, wenn verwaltete Ressourcen gelöscht werden sollen; andernfalls False.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Vom Windows Form-Designer generierter Code

        /// <summary>
        /// Erforderliche Methode für die Designerunterstützung.
        /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.CB_Stopbits = new System.Windows.Forms.ComboBox();
            this.BT_Connectserial = new System.Windows.Forms.Button();
            this.CB_Paritiybit = new System.Windows.Forms.ComboBox();
            this.NUD_Databits = new System.Windows.Forms.NumericUpDown();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.TB_Baud = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.TB_Com = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.CB_T_selection = new System.Windows.Forms.CheckBox();
            this.CB_Z_selection = new System.Windows.Forms.CheckBox();
            this.CB_Y_selection = new System.Windows.Forms.CheckBox();
            this.CB_X_selection = new System.Windows.Forms.CheckBox();
            this.GB_measurement_control = new System.Windows.Forms.GroupBox();
            this.BT_NOP = new System.Windows.Forms.Button();
            this.BT_HS = new System.Windows.Forms.Button();
            this.BT_HR = new System.Windows.Forms.Button();
            this.BT_RT = new System.Windows.Forms.Button();
            this.BT_EX = new System.Windows.Forms.Button();
            this.BT_RM = new System.Windows.Forms.Button();
            this.BT_SM = new System.Windows.Forms.Button();
            this.BT_SWOC = new System.Windows.Forms.Button();
            this.BT_SB = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.LB_T = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.LB_Z = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.LB_Y = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.LB_X = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.LB_D0 = new System.Windows.Forms.Label();
            this.LB_D1 = new System.Windows.Forms.Label();
            this.LB_RS = new System.Windows.Forms.Label();
            this.LB_sed = new System.Windows.Forms.Label();
            this.LB_error = new System.Windows.Forms.Label();
            this.LB_sm_mode = new System.Windows.Forms.Label();
            this.LB_woc_mode = new System.Windows.Forms.Label();
            this.LB_time = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.LB_burst_mode = new System.Windows.Forms.Label();
            this.GB_raw = new System.Windows.Forms.GroupBox();
            this.BT_send_raw = new System.Windows.Forms.Button();
            this.TB_send_raw = new System.Windows.Forms.TextBox();
            this.BT_reset_raw = new System.Windows.Forms.Button();
            this.TB_raw = new System.Windows.Forms.TextBox();
            this.GB_MR0 = new System.Windows.Forms.GroupBox();
            this.BT_WR0 = new System.Windows.Forms.Button();
            this.BT_RR0 = new System.Windows.Forms.Button();
            this.CB_Z_Series = new System.Windows.Forms.CheckBox();
            this.label9 = new System.Windows.Forms.Label();
            this.NUD_Gain_Sel = new System.Windows.Forms.NumericUpDown();
            this.label8 = new System.Windows.Forms.Label();
            this.NUD_Hallconf = new System.Windows.Forms.NumericUpDown();
            this.GB_MR1 = new System.Windows.Forms.GroupBox();
            this.CB_Trig_Int_Sel = new System.Windows.Forms.CheckBox();
            this.label11 = new System.Windows.Forms.Label();
            this.NUD_Comm_Mode = new System.Windows.Forms.NumericUpDown();
            this.CB_Woc_Diff = new System.Windows.Forms.CheckBox();
            this.CB_Ext_Trig = new System.Windows.Forms.CheckBox();
            this.CB_Tcmp_En = new System.Windows.Forms.CheckBox();
            this.CB_Burst_Sel_T = new System.Windows.Forms.CheckBox();
            this.CB_Burst_Sel_X = new System.Windows.Forms.CheckBox();
            this.CB_Burst_Sel_Y = new System.Windows.Forms.CheckBox();
            this.BT_WR1 = new System.Windows.Forms.Button();
            this.BT_RR1 = new System.Windows.Forms.Button();
            this.CB_Burst_Sel_Z = new System.Windows.Forms.CheckBox();
            this.label13 = new System.Windows.Forms.Label();
            this.NUD_Burst_Data_Rate = new System.Windows.Forms.NumericUpDown();
            this.GB_MR2 = new System.Windows.Forms.GroupBox();
            this.label20 = new System.Windows.Forms.Label();
            this.NUD_OSR2 = new System.Windows.Forms.NumericUpDown();
            this.label19 = new System.Windows.Forms.Label();
            this.NUD_Res_Z = new System.Windows.Forms.NumericUpDown();
            this.label15 = new System.Windows.Forms.Label();
            this.NUD_Res_Y = new System.Windows.Forms.NumericUpDown();
            this.label18 = new System.Windows.Forms.Label();
            this.NUD_Res_X = new System.Windows.Forms.NumericUpDown();
            this.label55 = new System.Windows.Forms.Label();
            this.NUD_Dig_Filt = new System.Windows.Forms.NumericUpDown();
            this.BT_WR2 = new System.Windows.Forms.Button();
            this.BT_RR2 = new System.Windows.Forms.Button();
            this.label16 = new System.Windows.Forms.Label();
            this.NUD_OSR = new System.Windows.Forms.NumericUpDown();
            this.GB_MR3 = new System.Windows.Forms.GroupBox();
            this.label25 = new System.Windows.Forms.Label();
            this.NUD_Sens_Tc_Hc = new System.Windows.Forms.NumericUpDown();
            this.BT_WR3 = new System.Windows.Forms.Button();
            this.BT_RR3 = new System.Windows.Forms.Button();
            this.label26 = new System.Windows.Forms.Label();
            this.NUD_Sens_Tc_Lt = new System.Windows.Forms.NumericUpDown();
            this.GB_MR4_9 = new System.Windows.Forms.GroupBox();
            this.TB_WoXY_TH = new System.Windows.Forms.TextBox();
            this.TB_WoZ_TH = new System.Windows.Forms.TextBox();
            this.TB_WoT_TH = new System.Windows.Forms.TextBox();
            this.TB_Offset_Z = new System.Windows.Forms.TextBox();
            this.TB_Offset_Y = new System.Windows.Forms.TextBox();
            this.TB_Offset_X = new System.Windows.Forms.TextBox();
            this.label21 = new System.Windows.Forms.Label();
            this.label22 = new System.Windows.Forms.Label();
            this.label23 = new System.Windows.Forms.Label();
            this.label24 = new System.Windows.Forms.Label();
            this.label27 = new System.Windows.Forms.Label();
            this.BT_WR4_9 = new System.Windows.Forms.Button();
            this.BT_RR4_9 = new System.Windows.Forms.Button();
            this.label28 = new System.Windows.Forms.Label();
            this.GB_GMA = new System.Windows.Forms.GroupBox();
            this.NUD_Memory_Address = new System.Windows.Forms.NumericUpDown();
            this.TB_General_Memory_Value = new System.Windows.Forms.TextBox();
            this.label29 = new System.Windows.Forms.Label();
            this.BT_Write_Specified_Register = new System.Windows.Forms.Button();
            this.BT_Read_Specified_Register = new System.Windows.Forms.Button();
            this.label34 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Databits)).BeginInit();
            this.groupBox2.SuspendLayout();
            this.GB_measurement_control.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.GB_raw.SuspendLayout();
            this.GB_MR0.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Gain_Sel)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Hallconf)).BeginInit();
            this.GB_MR1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Comm_Mode)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Burst_Data_Rate)).BeginInit();
            this.GB_MR2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_OSR2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Res_Z)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Res_Y)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Res_X)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Dig_Filt)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_OSR)).BeginInit();
            this.GB_MR3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Sens_Tc_Hc)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Sens_Tc_Lt)).BeginInit();
            this.GB_MR4_9.SuspendLayout();
            this.GB_GMA.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Memory_Address)).BeginInit();
            this.SuspendLayout();
            // 
            // serialPort1
            // 
            this.serialPort1.BaudRate = 115200;
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.CB_Stopbits);
            this.groupBox1.Controls.Add(this.BT_Connectserial);
            this.groupBox1.Controls.Add(this.CB_Paritiybit);
            this.groupBox1.Controls.Add(this.NUD_Databits);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.TB_Baud);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.TB_Com);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(378, 83);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Serial connection";
            // 
            // CB_Stopbits
            // 
            this.CB_Stopbits.DisplayMember = "0";
            this.CB_Stopbits.FormattingEnabled = true;
            this.CB_Stopbits.Items.AddRange(new object[] {
            "None",
            "One",
            "Two"});
            this.CB_Stopbits.Location = new System.Drawing.Point(191, 51);
            this.CB_Stopbits.Name = "CB_Stopbits";
            this.CB_Stopbits.Size = new System.Drawing.Size(55, 21);
            this.CB_Stopbits.TabIndex = 14;
            this.CB_Stopbits.Text = "One";
            // 
            // BT_Connectserial
            // 
            this.BT_Connectserial.Location = new System.Drawing.Point(255, 51);
            this.BT_Connectserial.Name = "BT_Connectserial";
            this.BT_Connectserial.Size = new System.Drawing.Size(114, 21);
            this.BT_Connectserial.TabIndex = 13;
            this.BT_Connectserial.Text = "Connect";
            this.BT_Connectserial.UseVisualStyleBackColor = true;
            this.BT_Connectserial.Click += new System.EventHandler(this.BT_Connectserial_Click);
            // 
            // CB_Paritiybit
            // 
            this.CB_Paritiybit.DisplayMember = "0";
            this.CB_Paritiybit.FormattingEnabled = true;
            this.CB_Paritiybit.Items.AddRange(new object[] {
            "None",
            "Odd",
            "Even",
            "Mark",
            "Space"});
            this.CB_Paritiybit.Location = new System.Drawing.Point(314, 25);
            this.CB_Paritiybit.Name = "CB_Paritiybit";
            this.CB_Paritiybit.Size = new System.Drawing.Size(55, 21);
            this.CB_Paritiybit.TabIndex = 12;
            this.CB_Paritiybit.Text = "None";
            // 
            // NUD_Databits
            // 
            this.NUD_Databits.Location = new System.Drawing.Point(191, 26);
            this.NUD_Databits.Maximum = new decimal(new int[] {
            8,
            0,
            0,
            0});
            this.NUD_Databits.Minimum = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.NUD_Databits.Name = "NUD_Databits";
            this.NUD_Databits.Size = new System.Drawing.Size(55, 20);
            this.NUD_Databits.TabIndex = 11;
            this.NUD_Databits.Value = new decimal(new int[] {
            8,
            0,
            0,
            0});
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(252, 28);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(51, 13);
            this.label5.TabIndex = 9;
            this.label5.Text = "Parity-Bit:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(129, 54);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(52, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Stop-Bits:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(129, 28);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Data-Bits:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 54);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(61, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Baud-Rate:";
            // 
            // TB_Baud
            // 
            this.TB_Baud.Location = new System.Drawing.Point(68, 51);
            this.TB_Baud.Name = "TB_Baud";
            this.TB_Baud.Size = new System.Drawing.Size(55, 20);
            this.TB_Baud.TabIndex = 2;
            this.TB_Baud.Text = "115200";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(56, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "COM-Port:";
            // 
            // TB_Com
            // 
            this.TB_Com.Location = new System.Drawing.Point(68, 25);
            this.TB_Com.Name = "TB_Com";
            this.TB_Com.Size = new System.Drawing.Size(55, 20);
            this.TB_Com.TabIndex = 0;
            this.TB_Com.Text = "COM4";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.CB_T_selection);
            this.groupBox2.Controls.Add(this.CB_Z_selection);
            this.groupBox2.Controls.Add(this.CB_Y_selection);
            this.groupBox2.Controls.Add(this.CB_X_selection);
            this.groupBox2.Location = new System.Drawing.Point(12, 101);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(378, 47);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Channel selection";
            // 
            // CB_T_selection
            // 
            this.CB_T_selection.AutoSize = true;
            this.CB_T_selection.Checked = true;
            this.CB_T_selection.CheckState = System.Windows.Forms.CheckState.Checked;
            this.CB_T_selection.Location = new System.Drawing.Point(126, 19);
            this.CB_T_selection.Name = "CB_T_selection";
            this.CB_T_selection.Size = new System.Drawing.Size(33, 17);
            this.CB_T_selection.TabIndex = 3;
            this.CB_T_selection.Text = "T";
            this.CB_T_selection.UseVisualStyleBackColor = true;
            // 
            // CB_Z_selection
            // 
            this.CB_Z_selection.AutoSize = true;
            this.CB_Z_selection.Checked = true;
            this.CB_Z_selection.CheckState = System.Windows.Forms.CheckState.Checked;
            this.CB_Z_selection.Location = new System.Drawing.Point(87, 19);
            this.CB_Z_selection.Name = "CB_Z_selection";
            this.CB_Z_selection.Size = new System.Drawing.Size(33, 17);
            this.CB_Z_selection.TabIndex = 2;
            this.CB_Z_selection.Text = "Z";
            this.CB_Z_selection.UseVisualStyleBackColor = true;
            // 
            // CB_Y_selection
            // 
            this.CB_Y_selection.AutoSize = true;
            this.CB_Y_selection.Checked = true;
            this.CB_Y_selection.CheckState = System.Windows.Forms.CheckState.Checked;
            this.CB_Y_selection.Location = new System.Drawing.Point(48, 19);
            this.CB_Y_selection.Name = "CB_Y_selection";
            this.CB_Y_selection.Size = new System.Drawing.Size(33, 17);
            this.CB_Y_selection.TabIndex = 1;
            this.CB_Y_selection.Text = "Y";
            this.CB_Y_selection.UseVisualStyleBackColor = true;
            // 
            // CB_X_selection
            // 
            this.CB_X_selection.AutoSize = true;
            this.CB_X_selection.Checked = true;
            this.CB_X_selection.CheckState = System.Windows.Forms.CheckState.Checked;
            this.CB_X_selection.Location = new System.Drawing.Point(9, 19);
            this.CB_X_selection.Name = "CB_X_selection";
            this.CB_X_selection.Size = new System.Drawing.Size(33, 17);
            this.CB_X_selection.TabIndex = 0;
            this.CB_X_selection.Text = "X";
            this.CB_X_selection.UseVisualStyleBackColor = true;
            // 
            // GB_measurement_control
            // 
            this.GB_measurement_control.Controls.Add(this.BT_NOP);
            this.GB_measurement_control.Controls.Add(this.BT_HS);
            this.GB_measurement_control.Controls.Add(this.BT_HR);
            this.GB_measurement_control.Controls.Add(this.BT_RT);
            this.GB_measurement_control.Controls.Add(this.BT_EX);
            this.GB_measurement_control.Controls.Add(this.BT_RM);
            this.GB_measurement_control.Controls.Add(this.BT_SM);
            this.GB_measurement_control.Controls.Add(this.BT_SWOC);
            this.GB_measurement_control.Controls.Add(this.BT_SB);
            this.GB_measurement_control.Enabled = false;
            this.GB_measurement_control.Location = new System.Drawing.Point(12, 154);
            this.GB_measurement_control.Name = "GB_measurement_control";
            this.GB_measurement_control.Size = new System.Drawing.Size(378, 169);
            this.GB_measurement_control.TabIndex = 2;
            this.GB_measurement_control.TabStop = false;
            this.GB_measurement_control.Text = "General control";
            // 
            // BT_NOP
            // 
            this.BT_NOP.Location = new System.Drawing.Point(194, 135);
            this.BT_NOP.Name = "BT_NOP";
            this.BT_NOP.Size = new System.Drawing.Size(178, 23);
            this.BT_NOP.TabIndex = 8;
            this.BT_NOP.Text = "No Operation";
            this.BT_NOP.UseVisualStyleBackColor = true;
            this.BT_NOP.Click += new System.EventHandler(this.BT_NOP_Click);
            // 
            // BT_HS
            // 
            this.BT_HS.Location = new System.Drawing.Point(194, 106);
            this.BT_HS.Name = "BT_HS";
            this.BT_HS.Size = new System.Drawing.Size(178, 23);
            this.BT_HS.TabIndex = 7;
            this.BT_HS.Text = "Memory Store";
            this.BT_HS.UseVisualStyleBackColor = true;
            this.BT_HS.Click += new System.EventHandler(this.BT_HS_Click);
            // 
            // BT_HR
            // 
            this.BT_HR.Location = new System.Drawing.Point(9, 106);
            this.BT_HR.Name = "BT_HR";
            this.BT_HR.Size = new System.Drawing.Size(178, 23);
            this.BT_HR.TabIndex = 6;
            this.BT_HR.Text = "Memory Recall";
            this.BT_HR.UseVisualStyleBackColor = true;
            this.BT_HR.Click += new System.EventHandler(this.BT_HR_Click);
            // 
            // BT_RT
            // 
            this.BT_RT.Location = new System.Drawing.Point(9, 135);
            this.BT_RT.Name = "BT_RT";
            this.BT_RT.Size = new System.Drawing.Size(178, 23);
            this.BT_RT.TabIndex = 5;
            this.BT_RT.Text = "Reset";
            this.BT_RT.UseVisualStyleBackColor = true;
            this.BT_RT.Click += new System.EventHandler(this.BT_RT_Click);
            // 
            // BT_EX
            // 
            this.BT_EX.Location = new System.Drawing.Point(9, 77);
            this.BT_EX.Name = "BT_EX";
            this.BT_EX.Size = new System.Drawing.Size(363, 23);
            this.BT_EX.TabIndex = 4;
            this.BT_EX.Text = "Exit current mode";
            this.BT_EX.UseVisualStyleBackColor = true;
            this.BT_EX.Click += new System.EventHandler(this.BT_EX_Click);
            // 
            // BT_RM
            // 
            this.BT_RM.Location = new System.Drawing.Point(194, 48);
            this.BT_RM.Name = "BT_RM";
            this.BT_RM.Size = new System.Drawing.Size(178, 23);
            this.BT_RM.TabIndex = 3;
            this.BT_RM.Text = "Read Measurement";
            this.BT_RM.UseVisualStyleBackColor = true;
            this.BT_RM.Click += new System.EventHandler(this.BT_RM_Click);
            // 
            // BT_SM
            // 
            this.BT_SM.Location = new System.Drawing.Point(9, 48);
            this.BT_SM.Name = "BT_SM";
            this.BT_SM.Size = new System.Drawing.Size(178, 23);
            this.BT_SM.TabIndex = 2;
            this.BT_SM.Text = "Start Single Measurement";
            this.BT_SM.UseVisualStyleBackColor = true;
            this.BT_SM.Click += new System.EventHandler(this.BT_SM_Click);
            // 
            // BT_SWOC
            // 
            this.BT_SWOC.Location = new System.Drawing.Point(194, 19);
            this.BT_SWOC.Name = "BT_SWOC";
            this.BT_SWOC.Size = new System.Drawing.Size(178, 23);
            this.BT_SWOC.TabIndex = 1;
            this.BT_SWOC.Text = "Start Wake-up On Change Mode";
            this.BT_SWOC.UseVisualStyleBackColor = true;
            this.BT_SWOC.Click += new System.EventHandler(this.BT_SWOC_Click);
            // 
            // BT_SB
            // 
            this.BT_SB.Location = new System.Drawing.Point(9, 19);
            this.BT_SB.Name = "BT_SB";
            this.BT_SB.Size = new System.Drawing.Size(178, 23);
            this.BT_SB.TabIndex = 0;
            this.BT_SB.Text = "Start Burst Mode";
            this.BT_SB.UseVisualStyleBackColor = true;
            this.BT_SB.Click += new System.EventHandler(this.BT_SB_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.LB_T);
            this.groupBox4.Controls.Add(this.label14);
            this.groupBox4.Controls.Add(this.LB_Z);
            this.groupBox4.Controls.Add(this.label12);
            this.groupBox4.Controls.Add(this.LB_Y);
            this.groupBox4.Controls.Add(this.label10);
            this.groupBox4.Controls.Add(this.LB_X);
            this.groupBox4.Controls.Add(this.label6);
            this.groupBox4.Controls.Add(this.LB_D0);
            this.groupBox4.Controls.Add(this.LB_D1);
            this.groupBox4.Controls.Add(this.LB_RS);
            this.groupBox4.Controls.Add(this.LB_sed);
            this.groupBox4.Controls.Add(this.LB_error);
            this.groupBox4.Controls.Add(this.LB_sm_mode);
            this.groupBox4.Controls.Add(this.LB_woc_mode);
            this.groupBox4.Controls.Add(this.LB_time);
            this.groupBox4.Controls.Add(this.label7);
            this.groupBox4.Controls.Add(this.LB_burst_mode);
            this.groupBox4.Location = new System.Drawing.Point(12, 329);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(378, 136);
            this.groupBox4.TabIndex = 3;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Measurements";
            // 
            // LB_T
            // 
            this.LB_T.BackColor = System.Drawing.SystemColors.Control;
            this.LB_T.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.LB_T.Font = new System.Drawing.Font("Microsoft Sans Serif", 7F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LB_T.Location = new System.Drawing.Point(302, 103);
            this.LB_T.Name = "LB_T";
            this.LB_T.Size = new System.Drawing.Size(70, 23);
            this.LB_T.TabIndex = 17;
            this.LB_T.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(283, 108);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(17, 13);
            this.label14.TabIndex = 16;
            this.label14.Text = "T:";
            // 
            // LB_Z
            // 
            this.LB_Z.BackColor = System.Drawing.SystemColors.Control;
            this.LB_Z.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.LB_Z.Font = new System.Drawing.Font("Microsoft Sans Serif", 7F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LB_Z.Location = new System.Drawing.Point(210, 103);
            this.LB_Z.Name = "LB_Z";
            this.LB_Z.Size = new System.Drawing.Size(70, 23);
            this.LB_Z.TabIndex = 15;
            this.LB_Z.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(191, 108);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(17, 13);
            this.label12.TabIndex = 14;
            this.label12.Text = "Z:";
            // 
            // LB_Y
            // 
            this.LB_Y.BackColor = System.Drawing.SystemColors.Control;
            this.LB_Y.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.LB_Y.Font = new System.Drawing.Font("Microsoft Sans Serif", 7F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LB_Y.Location = new System.Drawing.Point(117, 103);
            this.LB_Y.Name = "LB_Y";
            this.LB_Y.Size = new System.Drawing.Size(70, 23);
            this.LB_Y.TabIndex = 13;
            this.LB_Y.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(98, 108);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(17, 13);
            this.label10.TabIndex = 12;
            this.label10.Text = "Y:";
            // 
            // LB_X
            // 
            this.LB_X.BackColor = System.Drawing.SystemColors.Control;
            this.LB_X.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.LB_X.Font = new System.Drawing.Font("Microsoft Sans Serif", 7F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LB_X.Location = new System.Drawing.Point(25, 103);
            this.LB_X.Name = "LB_X";
            this.LB_X.Size = new System.Drawing.Size(70, 23);
            this.LB_X.TabIndex = 11;
            this.LB_X.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(6, 108);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(17, 13);
            this.label6.TabIndex = 10;
            this.label6.Text = "X:";
            // 
            // LB_D0
            // 
            this.LB_D0.BackColor = System.Drawing.SystemColors.Control;
            this.LB_D0.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.LB_D0.Location = new System.Drawing.Point(286, 74);
            this.LB_D0.Name = "LB_D0";
            this.LB_D0.Size = new System.Drawing.Size(86, 23);
            this.LB_D0.TabIndex = 9;
            this.LB_D0.Text = "D0";
            this.LB_D0.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // LB_D1
            // 
            this.LB_D1.BackColor = System.Drawing.SystemColors.Control;
            this.LB_D1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.LB_D1.Location = new System.Drawing.Point(194, 74);
            this.LB_D1.Name = "LB_D1";
            this.LB_D1.Size = new System.Drawing.Size(86, 23);
            this.LB_D1.TabIndex = 8;
            this.LB_D1.Text = "D1";
            this.LB_D1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // LB_RS
            // 
            this.LB_RS.BackColor = System.Drawing.SystemColors.Control;
            this.LB_RS.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.LB_RS.Location = new System.Drawing.Point(101, 74);
            this.LB_RS.Name = "LB_RS";
            this.LB_RS.Size = new System.Drawing.Size(86, 23);
            this.LB_RS.TabIndex = 7;
            this.LB_RS.Text = "RS";
            this.LB_RS.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // LB_sed
            // 
            this.LB_sed.BackColor = System.Drawing.SystemColors.Control;
            this.LB_sed.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.LB_sed.Location = new System.Drawing.Point(9, 74);
            this.LB_sed.Name = "LB_sed";
            this.LB_sed.Size = new System.Drawing.Size(86, 23);
            this.LB_sed.TabIndex = 6;
            this.LB_sed.Text = "SED";
            this.LB_sed.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // LB_error
            // 
            this.LB_error.BackColor = System.Drawing.SystemColors.Control;
            this.LB_error.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.LB_error.Location = new System.Drawing.Point(286, 46);
            this.LB_error.Name = "LB_error";
            this.LB_error.Size = new System.Drawing.Size(86, 23);
            this.LB_error.TabIndex = 5;
            this.LB_error.Text = "Error";
            this.LB_error.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // LB_sm_mode
            // 
            this.LB_sm_mode.BackColor = System.Drawing.SystemColors.Control;
            this.LB_sm_mode.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.LB_sm_mode.Location = new System.Drawing.Point(194, 46);
            this.LB_sm_mode.Name = "LB_sm_mode";
            this.LB_sm_mode.Size = new System.Drawing.Size(86, 23);
            this.LB_sm_mode.TabIndex = 4;
            this.LB_sm_mode.Text = "SM-Mode";
            this.LB_sm_mode.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // LB_woc_mode
            // 
            this.LB_woc_mode.BackColor = System.Drawing.SystemColors.Control;
            this.LB_woc_mode.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.LB_woc_mode.Location = new System.Drawing.Point(101, 46);
            this.LB_woc_mode.Name = "LB_woc_mode";
            this.LB_woc_mode.Size = new System.Drawing.Size(86, 23);
            this.LB_woc_mode.TabIndex = 3;
            this.LB_woc_mode.Text = "WOC-Mode";
            this.LB_woc_mode.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // LB_time
            // 
            this.LB_time.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.LB_time.Location = new System.Drawing.Point(45, 16);
            this.LB_time.Name = "LB_time";
            this.LB_time.Size = new System.Drawing.Size(142, 23);
            this.LB_time.TabIndex = 2;
            this.LB_time.Text = "No measurement yet";
            this.LB_time.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(6, 21);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(33, 13);
            this.label7.TabIndex = 1;
            this.label7.Text = "Time:";
            // 
            // LB_burst_mode
            // 
            this.LB_burst_mode.BackColor = System.Drawing.SystemColors.Control;
            this.LB_burst_mode.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.LB_burst_mode.Location = new System.Drawing.Point(9, 46);
            this.LB_burst_mode.Name = "LB_burst_mode";
            this.LB_burst_mode.Size = new System.Drawing.Size(86, 23);
            this.LB_burst_mode.TabIndex = 0;
            this.LB_burst_mode.Text = "Burst-Mode";
            this.LB_burst_mode.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // GB_raw
            // 
            this.GB_raw.Controls.Add(this.BT_send_raw);
            this.GB_raw.Controls.Add(this.TB_send_raw);
            this.GB_raw.Controls.Add(this.BT_reset_raw);
            this.GB_raw.Controls.Add(this.TB_raw);
            this.GB_raw.Enabled = false;
            this.GB_raw.Location = new System.Drawing.Point(396, 12);
            this.GB_raw.Name = "GB_raw";
            this.GB_raw.Size = new System.Drawing.Size(378, 271);
            this.GB_raw.TabIndex = 4;
            this.GB_raw.TabStop = false;
            this.GB_raw.Text = "Raw communication";
            // 
            // BT_send_raw
            // 
            this.BT_send_raw.Location = new System.Drawing.Point(246, 242);
            this.BT_send_raw.Name = "BT_send_raw";
            this.BT_send_raw.Size = new System.Drawing.Size(60, 20);
            this.BT_send_raw.TabIndex = 3;
            this.BT_send_raw.Text = "Send";
            this.BT_send_raw.UseVisualStyleBackColor = true;
            this.BT_send_raw.Click += new System.EventHandler(this.BT_send_raw_Click);
            // 
            // TB_send_raw
            // 
            this.TB_send_raw.Location = new System.Drawing.Point(6, 242);
            this.TB_send_raw.Name = "TB_send_raw";
            this.TB_send_raw.Size = new System.Drawing.Size(234, 20);
            this.TB_send_raw.TabIndex = 2;
            // 
            // BT_reset_raw
            // 
            this.BT_reset_raw.Location = new System.Drawing.Point(312, 242);
            this.BT_reset_raw.Name = "BT_reset_raw";
            this.BT_reset_raw.Size = new System.Drawing.Size(60, 20);
            this.BT_reset_raw.TabIndex = 1;
            this.BT_reset_raw.Text = "Reset";
            this.BT_reset_raw.UseVisualStyleBackColor = true;
            this.BT_reset_raw.Click += new System.EventHandler(this.BT_reset_raw_Click);
            // 
            // TB_raw
            // 
            this.TB_raw.Location = new System.Drawing.Point(6, 19);
            this.TB_raw.Multiline = true;
            this.TB_raw.Name = "TB_raw";
            this.TB_raw.ReadOnly = true;
            this.TB_raw.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.TB_raw.Size = new System.Drawing.Size(366, 217);
            this.TB_raw.TabIndex = 0;
            // 
            // GB_MR0
            // 
            this.GB_MR0.Controls.Add(this.BT_WR0);
            this.GB_MR0.Controls.Add(this.BT_RR0);
            this.GB_MR0.Controls.Add(this.CB_Z_Series);
            this.GB_MR0.Controls.Add(this.label9);
            this.GB_MR0.Controls.Add(this.NUD_Gain_Sel);
            this.GB_MR0.Controls.Add(this.label8);
            this.GB_MR0.Controls.Add(this.NUD_Hallconf);
            this.GB_MR0.Enabled = false;
            this.GB_MR0.Location = new System.Drawing.Point(12, 471);
            this.GB_MR0.Name = "GB_MR0";
            this.GB_MR0.Size = new System.Drawing.Size(378, 78);
            this.GB_MR0.TabIndex = 5;
            this.GB_MR0.TabStop = false;
            this.GB_MR0.Text = "Memory Register 0";
            // 
            // BT_WR0
            // 
            this.BT_WR0.Location = new System.Drawing.Point(194, 45);
            this.BT_WR0.Name = "BT_WR0";
            this.BT_WR0.Size = new System.Drawing.Size(178, 23);
            this.BT_WR0.TabIndex = 7;
            this.BT_WR0.Text = "Write Register 0";
            this.BT_WR0.UseVisualStyleBackColor = true;
            this.BT_WR0.Click += new System.EventHandler(this.BT_WR0_Click);
            // 
            // BT_RR0
            // 
            this.BT_RR0.Location = new System.Drawing.Point(9, 45);
            this.BT_RR0.Name = "BT_RR0";
            this.BT_RR0.Size = new System.Drawing.Size(178, 23);
            this.BT_RR0.TabIndex = 6;
            this.BT_RR0.Text = "Read Register 0";
            this.BT_RR0.UseVisualStyleBackColor = true;
            this.BT_RR0.Click += new System.EventHandler(this.BT_RR0_Click);
            // 
            // CB_Z_Series
            // 
            this.CB_Z_Series.AutoSize = true;
            this.CB_Z_Series.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.CB_Z_Series.Location = new System.Drawing.Point(301, 20);
            this.CB_Z_Series.Name = "CB_Z_Series";
            this.CB_Z_Series.Size = new System.Drawing.Size(68, 17);
            this.CB_Z_Series.TabIndex = 4;
            this.CB_Z_Series.Text = "Z-Series:";
            this.CB_Z_Series.UseVisualStyleBackColor = true;
            this.CB_Z_Series.CheckedChanged += new System.EventHandler(this.CB_Z_Series_CheckedChanged);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(137, 21);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(50, 13);
            this.label9.TabIndex = 17;
            this.label9.Text = "Gain-Sel:";
            // 
            // NUD_Gain_Sel
            // 
            this.NUD_Gain_Sel.Location = new System.Drawing.Point(191, 19);
            this.NUD_Gain_Sel.Maximum = new decimal(new int[] {
            7,
            0,
            0,
            0});
            this.NUD_Gain_Sel.Name = "NUD_Gain_Sel";
            this.NUD_Gain_Sel.Size = new System.Drawing.Size(55, 20);
            this.NUD_Gain_Sel.TabIndex = 16;
            this.NUD_Gain_Sel.Value = new decimal(new int[] {
            7,
            0,
            0,
            0});
            this.NUD_Gain_Sel.ValueChanged += new System.EventHandler(this.NUD_Gain_Sel_ValueChanged);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(13, 21);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(49, 13);
            this.label8.TabIndex = 15;
            this.label8.Text = "Hallconf:";
            // 
            // NUD_Hallconf
            // 
            this.NUD_Hallconf.Location = new System.Drawing.Point(68, 19);
            this.NUD_Hallconf.Maximum = new decimal(new int[] {
            15,
            0,
            0,
            0});
            this.NUD_Hallconf.Name = "NUD_Hallconf";
            this.NUD_Hallconf.Size = new System.Drawing.Size(55, 20);
            this.NUD_Hallconf.TabIndex = 12;
            this.NUD_Hallconf.Value = new decimal(new int[] {
            12,
            0,
            0,
            0});
            this.NUD_Hallconf.ValueChanged += new System.EventHandler(this.NUD_Hallconf_ValueChanged);
            // 
            // GB_MR1
            // 
            this.GB_MR1.Controls.Add(this.CB_Trig_Int_Sel);
            this.GB_MR1.Controls.Add(this.label11);
            this.GB_MR1.Controls.Add(this.NUD_Comm_Mode);
            this.GB_MR1.Controls.Add(this.CB_Woc_Diff);
            this.GB_MR1.Controls.Add(this.CB_Ext_Trig);
            this.GB_MR1.Controls.Add(this.CB_Tcmp_En);
            this.GB_MR1.Controls.Add(this.CB_Burst_Sel_T);
            this.GB_MR1.Controls.Add(this.CB_Burst_Sel_X);
            this.GB_MR1.Controls.Add(this.CB_Burst_Sel_Y);
            this.GB_MR1.Controls.Add(this.BT_WR1);
            this.GB_MR1.Controls.Add(this.BT_RR1);
            this.GB_MR1.Controls.Add(this.CB_Burst_Sel_Z);
            this.GB_MR1.Controls.Add(this.label13);
            this.GB_MR1.Controls.Add(this.NUD_Burst_Data_Rate);
            this.GB_MR1.Enabled = false;
            this.GB_MR1.Location = new System.Drawing.Point(12, 555);
            this.GB_MR1.Name = "GB_MR1";
            this.GB_MR1.Size = new System.Drawing.Size(378, 129);
            this.GB_MR1.TabIndex = 18;
            this.GB_MR1.TabStop = false;
            this.GB_MR1.Text = "Memory Register 1";
            // 
            // CB_Trig_Int_Sel
            // 
            this.CB_Trig_Int_Sel.AutoSize = true;
            this.CB_Trig_Int_Sel.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.CB_Trig_Int_Sel.Location = new System.Drawing.Point(292, 47);
            this.CB_Trig_Int_Sel.Name = "CB_Trig_Int_Sel";
            this.CB_Trig_Int_Sel.Size = new System.Drawing.Size(80, 17);
            this.CB_Trig_Int_Sel.TabIndex = 24;
            this.CB_Trig_Int_Sel.Text = "Trig-Int-Sel:";
            this.CB_Trig_Int_Sel.UseVisualStyleBackColor = true;
            this.CB_Trig_Int_Sel.CheckedChanged += new System.EventHandler(this.CB_Trig_Int_Sel_CheckedChanged);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(23, 71);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(69, 13);
            this.label11.TabIndex = 23;
            this.label11.Text = "Comm-Mode:";
            // 
            // NUD_Comm_Mode
            // 
            this.NUD_Comm_Mode.Location = new System.Drawing.Point(98, 69);
            this.NUD_Comm_Mode.Maximum = new decimal(new int[] {
            63,
            0,
            0,
            0});
            this.NUD_Comm_Mode.Name = "NUD_Comm_Mode";
            this.NUD_Comm_Mode.Size = new System.Drawing.Size(55, 20);
            this.NUD_Comm_Mode.TabIndex = 22;
            this.NUD_Comm_Mode.ValueChanged += new System.EventHandler(this.NUD_Comm_Mode_ValueChanged);
            // 
            // CB_Woc_Diff
            // 
            this.CB_Woc_Diff.AutoSize = true;
            this.CB_Woc_Diff.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.CB_Woc_Diff.Location = new System.Drawing.Point(209, 47);
            this.CB_Woc_Diff.Name = "CB_Woc_Diff";
            this.CB_Woc_Diff.Size = new System.Drawing.Size(71, 17);
            this.CB_Woc_Diff.TabIndex = 21;
            this.CB_Woc_Diff.Text = "Woc-Diff:";
            this.CB_Woc_Diff.UseVisualStyleBackColor = true;
            this.CB_Woc_Diff.CheckedChanged += new System.EventHandler(this.CB_Woc_Diff_CheckedChanged);
            // 
            // CB_Ext_Trig
            // 
            this.CB_Ext_Trig.AutoSize = true;
            this.CB_Ext_Trig.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.CB_Ext_Trig.Location = new System.Drawing.Point(122, 47);
            this.CB_Ext_Trig.Name = "CB_Ext_Trig";
            this.CB_Ext_Trig.Size = new System.Drawing.Size(65, 17);
            this.CB_Ext_Trig.TabIndex = 20;
            this.CB_Ext_Trig.Text = "Ext-Trig:";
            this.CB_Ext_Trig.UseVisualStyleBackColor = true;
            this.CB_Ext_Trig.CheckedChanged += new System.EventHandler(this.CB_Ext_Trig_CheckedChanged);
            // 
            // CB_Tcmp_En
            // 
            this.CB_Tcmp_En.AutoSize = true;
            this.CB_Tcmp_En.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.CB_Tcmp_En.Location = new System.Drawing.Point(23, 47);
            this.CB_Tcmp_En.Name = "CB_Tcmp_En";
            this.CB_Tcmp_En.Size = new System.Drawing.Size(72, 17);
            this.CB_Tcmp_En.TabIndex = 19;
            this.CB_Tcmp_En.Text = "Tcmp-En:";
            this.CB_Tcmp_En.UseVisualStyleBackColor = true;
            this.CB_Tcmp_En.CheckedChanged += new System.EventHandler(this.CB_Tcmp_En_CheckedChanged);
            // 
            // CB_Burst_Sel_T
            // 
            this.CB_Burst_Sel_T.AutoSize = true;
            this.CB_Burst_Sel_T.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.CB_Burst_Sel_T.Location = new System.Drawing.Point(336, 22);
            this.CB_Burst_Sel_T.Name = "CB_Burst_Sel_T";
            this.CB_Burst_Sel_T.Size = new System.Drawing.Size(36, 17);
            this.CB_Burst_Sel_T.TabIndex = 18;
            this.CB_Burst_Sel_T.Text = "T:";
            this.CB_Burst_Sel_T.UseVisualStyleBackColor = true;
            this.CB_Burst_Sel_T.CheckedChanged += new System.EventHandler(this.CB_Burst_Sel_T_CheckedChanged);
            // 
            // CB_Burst_Sel_X
            // 
            this.CB_Burst_Sel_X.AutoSize = true;
            this.CB_Burst_Sel_X.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.CB_Burst_Sel_X.Location = new System.Drawing.Point(294, 22);
            this.CB_Burst_Sel_X.Name = "CB_Burst_Sel_X";
            this.CB_Burst_Sel_X.Size = new System.Drawing.Size(36, 17);
            this.CB_Burst_Sel_X.TabIndex = 17;
            this.CB_Burst_Sel_X.Text = "X:";
            this.CB_Burst_Sel_X.UseVisualStyleBackColor = true;
            this.CB_Burst_Sel_X.CheckedChanged += new System.EventHandler(this.CB_Burst_Sel_X_CheckedChanged);
            // 
            // CB_Burst_Sel_Y
            // 
            this.CB_Burst_Sel_Y.AutoSize = true;
            this.CB_Burst_Sel_Y.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.CB_Burst_Sel_Y.Location = new System.Drawing.Point(252, 22);
            this.CB_Burst_Sel_Y.Name = "CB_Burst_Sel_Y";
            this.CB_Burst_Sel_Y.Size = new System.Drawing.Size(36, 17);
            this.CB_Burst_Sel_Y.TabIndex = 16;
            this.CB_Burst_Sel_Y.Text = "Y:";
            this.CB_Burst_Sel_Y.UseVisualStyleBackColor = true;
            this.CB_Burst_Sel_Y.CheckedChanged += new System.EventHandler(this.CB_Burst_Sel_Y_CheckedChanged);
            // 
            // BT_WR1
            // 
            this.BT_WR1.Location = new System.Drawing.Point(194, 95);
            this.BT_WR1.Name = "BT_WR1";
            this.BT_WR1.Size = new System.Drawing.Size(178, 23);
            this.BT_WR1.TabIndex = 7;
            this.BT_WR1.Text = "Write Register 1";
            this.BT_WR1.UseVisualStyleBackColor = true;
            this.BT_WR1.Click += new System.EventHandler(this.BT_WR1_Click);
            // 
            // BT_RR1
            // 
            this.BT_RR1.Location = new System.Drawing.Point(9, 95);
            this.BT_RR1.Name = "BT_RR1";
            this.BT_RR1.Size = new System.Drawing.Size(178, 23);
            this.BT_RR1.TabIndex = 6;
            this.BT_RR1.Text = "Read Register 1";
            this.BT_RR1.UseVisualStyleBackColor = true;
            this.BT_RR1.Click += new System.EventHandler(this.BT_RR1_Click);
            // 
            // CB_Burst_Sel_Z
            // 
            this.CB_Burst_Sel_Z.AutoSize = true;
            this.CB_Burst_Sel_Z.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.CB_Burst_Sel_Z.Location = new System.Drawing.Point(162, 22);
            this.CB_Burst_Sel_Z.Name = "CB_Burst_Sel_Z";
            this.CB_Burst_Sel_Z.Size = new System.Drawing.Size(84, 17);
            this.CB_Burst_Sel_Z.TabIndex = 4;
            this.CB_Burst_Sel_Z.Text = "Burst-Sel: Z:";
            this.CB_Burst_Sel_Z.UseVisualStyleBackColor = true;
            this.CB_Burst_Sel_Z.CheckedChanged += new System.EventHandler(this.CB_Burst_Sel_Z_CheckedChanged);
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(6, 23);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(86, 13);
            this.label13.TabIndex = 15;
            this.label13.Text = "Burst-Data-Rate:";
            // 
            // NUD_Burst_Data_Rate
            // 
            this.NUD_Burst_Data_Rate.Location = new System.Drawing.Point(98, 21);
            this.NUD_Burst_Data_Rate.Maximum = new decimal(new int[] {
            63,
            0,
            0,
            0});
            this.NUD_Burst_Data_Rate.Name = "NUD_Burst_Data_Rate";
            this.NUD_Burst_Data_Rate.Size = new System.Drawing.Size(55, 20);
            this.NUD_Burst_Data_Rate.TabIndex = 12;
            this.NUD_Burst_Data_Rate.ValueChanged += new System.EventHandler(this.NUD_Burst_Data_Rate_ValueChanged);
            // 
            // GB_MR2
            // 
            this.GB_MR2.Controls.Add(this.label20);
            this.GB_MR2.Controls.Add(this.NUD_OSR2);
            this.GB_MR2.Controls.Add(this.label19);
            this.GB_MR2.Controls.Add(this.NUD_Res_Z);
            this.GB_MR2.Controls.Add(this.label15);
            this.GB_MR2.Controls.Add(this.NUD_Res_Y);
            this.GB_MR2.Controls.Add(this.label18);
            this.GB_MR2.Controls.Add(this.NUD_Res_X);
            this.GB_MR2.Controls.Add(this.label55);
            this.GB_MR2.Controls.Add(this.NUD_Dig_Filt);
            this.GB_MR2.Controls.Add(this.BT_WR2);
            this.GB_MR2.Controls.Add(this.BT_RR2);
            this.GB_MR2.Controls.Add(this.label16);
            this.GB_MR2.Controls.Add(this.NUD_OSR);
            this.GB_MR2.Enabled = false;
            this.GB_MR2.Location = new System.Drawing.Point(396, 289);
            this.GB_MR2.Name = "GB_MR2";
            this.GB_MR2.Size = new System.Drawing.Size(378, 108);
            this.GB_MR2.TabIndex = 25;
            this.GB_MR2.TabStop = false;
            this.GB_MR2.Text = "Memory Register 2";
            // 
            // label20
            // 
            this.label20.AutoSize = true;
            this.label20.Location = new System.Drawing.Point(272, 23);
            this.label20.Name = "label20";
            this.label20.Size = new System.Drawing.Size(39, 13);
            this.label20.TabIndex = 34;
            this.label20.Text = "OSR2:";
            // 
            // NUD_OSR2
            // 
            this.NUD_OSR2.Location = new System.Drawing.Point(317, 21);
            this.NUD_OSR2.Maximum = new decimal(new int[] {
            3,
            0,
            0,
            0});
            this.NUD_OSR2.Name = "NUD_OSR2";
            this.NUD_OSR2.Size = new System.Drawing.Size(55, 20);
            this.NUD_OSR2.TabIndex = 33;
            this.NUD_OSR2.ValueChanged += new System.EventHandler(this.NUD_OSR2_ValueChanged);
            // 
            // label19
            // 
            this.label19.AutoSize = true;
            this.label19.Location = new System.Drawing.Point(272, 49);
            this.label19.Name = "label19";
            this.label19.Size = new System.Drawing.Size(39, 13);
            this.label19.TabIndex = 32;
            this.label19.Text = "Res-Z:";
            // 
            // NUD_Res_Z
            // 
            this.NUD_Res_Z.Location = new System.Drawing.Point(317, 47);
            this.NUD_Res_Z.Maximum = new decimal(new int[] {
            3,
            0,
            0,
            0});
            this.NUD_Res_Z.Name = "NUD_Res_Z";
            this.NUD_Res_Z.Size = new System.Drawing.Size(55, 20);
            this.NUD_Res_Z.TabIndex = 31;
            this.NUD_Res_Z.ValueChanged += new System.EventHandler(this.NUD_Res_Z_ValueChanged);
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(141, 49);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(39, 13);
            this.label15.TabIndex = 30;
            this.label15.Text = "Res-Y:";
            // 
            // NUD_Res_Y
            // 
            this.NUD_Res_Y.Location = new System.Drawing.Point(186, 47);
            this.NUD_Res_Y.Maximum = new decimal(new int[] {
            3,
            0,
            0,
            0});
            this.NUD_Res_Y.Name = "NUD_Res_Y";
            this.NUD_Res_Y.Size = new System.Drawing.Size(55, 20);
            this.NUD_Res_Y.TabIndex = 29;
            this.NUD_Res_Y.ValueChanged += new System.EventHandler(this.NUD_Res_Y_ValueChanged);
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(6, 49);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(39, 13);
            this.label18.TabIndex = 28;
            this.label18.Text = "Res-X:";
            // 
            // NUD_Res_X
            // 
            this.NUD_Res_X.Location = new System.Drawing.Point(51, 47);
            this.NUD_Res_X.Maximum = new decimal(new int[] {
            3,
            0,
            0,
            0});
            this.NUD_Res_X.Name = "NUD_Res_X";
            this.NUD_Res_X.Size = new System.Drawing.Size(55, 20);
            this.NUD_Res_X.TabIndex = 27;
            this.NUD_Res_X.ValueChanged += new System.EventHandler(this.NUD_Res_X_ValueChanged);
            // 
            // label55
            // 
            this.label55.AutoSize = true;
            this.label55.Location = new System.Drawing.Point(138, 23);
            this.label55.Name = "label55";
            this.label55.Size = new System.Drawing.Size(42, 13);
            this.label55.TabIndex = 26;
            this.label55.Text = "Dig-Filt:";
            // 
            // NUD_Dig_Filt
            // 
            this.NUD_Dig_Filt.Location = new System.Drawing.Point(186, 21);
            this.NUD_Dig_Filt.Maximum = new decimal(new int[] {
            7,
            0,
            0,
            0});
            this.NUD_Dig_Filt.Name = "NUD_Dig_Filt";
            this.NUD_Dig_Filt.Size = new System.Drawing.Size(55, 20);
            this.NUD_Dig_Filt.TabIndex = 25;
            this.NUD_Dig_Filt.ValueChanged += new System.EventHandler(this.NUD_Dig_Filt_ValueChanged);
            // 
            // BT_WR2
            // 
            this.BT_WR2.Location = new System.Drawing.Point(194, 73);
            this.BT_WR2.Name = "BT_WR2";
            this.BT_WR2.Size = new System.Drawing.Size(178, 23);
            this.BT_WR2.TabIndex = 7;
            this.BT_WR2.Text = "Write Register 2";
            this.BT_WR2.UseVisualStyleBackColor = true;
            this.BT_WR2.Click += new System.EventHandler(this.BT_WR2_Click);
            // 
            // BT_RR2
            // 
            this.BT_RR2.Location = new System.Drawing.Point(9, 73);
            this.BT_RR2.Name = "BT_RR2";
            this.BT_RR2.Size = new System.Drawing.Size(178, 23);
            this.BT_RR2.TabIndex = 6;
            this.BT_RR2.Text = "Read Register 2";
            this.BT_RR2.UseVisualStyleBackColor = true;
            this.BT_RR2.Click += new System.EventHandler(this.BT_RR2_Click);
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(12, 23);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(33, 13);
            this.label16.TabIndex = 15;
            this.label16.Text = "OSR:";
            // 
            // NUD_OSR
            // 
            this.NUD_OSR.Location = new System.Drawing.Point(51, 21);
            this.NUD_OSR.Maximum = new decimal(new int[] {
            3,
            0,
            0,
            0});
            this.NUD_OSR.Name = "NUD_OSR";
            this.NUD_OSR.Size = new System.Drawing.Size(55, 20);
            this.NUD_OSR.TabIndex = 12;
            this.NUD_OSR.ValueChanged += new System.EventHandler(this.NUD_OSR_ValueChanged);
            // 
            // GB_MR3
            // 
            this.GB_MR3.Controls.Add(this.label25);
            this.GB_MR3.Controls.Add(this.NUD_Sens_Tc_Hc);
            this.GB_MR3.Controls.Add(this.BT_WR3);
            this.GB_MR3.Controls.Add(this.BT_RR3);
            this.GB_MR3.Controls.Add(this.label26);
            this.GB_MR3.Controls.Add(this.NUD_Sens_Tc_Lt);
            this.GB_MR3.Enabled = false;
            this.GB_MR3.Location = new System.Drawing.Point(396, 403);
            this.GB_MR3.Name = "GB_MR3";
            this.GB_MR3.Size = new System.Drawing.Size(378, 78);
            this.GB_MR3.TabIndex = 35;
            this.GB_MR3.TabStop = false;
            this.GB_MR3.Text = "Memory Register 3";
            // 
            // label25
            // 
            this.label25.AutoSize = true;
            this.label25.Location = new System.Drawing.Point(241, 21);
            this.label25.Name = "label25";
            this.label25.Size = new System.Drawing.Size(64, 13);
            this.label25.TabIndex = 26;
            this.label25.Text = "Sens-Tc-Ht:";
            // 
            // NUD_Sens_Tc_Hc
            // 
            this.NUD_Sens_Tc_Hc.Location = new System.Drawing.Point(317, 19);
            this.NUD_Sens_Tc_Hc.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.NUD_Sens_Tc_Hc.Name = "NUD_Sens_Tc_Hc";
            this.NUD_Sens_Tc_Hc.Size = new System.Drawing.Size(55, 20);
            this.NUD_Sens_Tc_Hc.TabIndex = 25;
            this.NUD_Sens_Tc_Hc.ValueChanged += new System.EventHandler(this.NUD_Sens_Tc_Hc_ValueChanged);
            // 
            // BT_WR3
            // 
            this.BT_WR3.Location = new System.Drawing.Point(194, 45);
            this.BT_WR3.Name = "BT_WR3";
            this.BT_WR3.Size = new System.Drawing.Size(178, 23);
            this.BT_WR3.TabIndex = 7;
            this.BT_WR3.Text = "Write Register 3";
            this.BT_WR3.UseVisualStyleBackColor = true;
            this.BT_WR3.Click += new System.EventHandler(this.BT_WR3_Click);
            // 
            // BT_RR3
            // 
            this.BT_RR3.Location = new System.Drawing.Point(9, 45);
            this.BT_RR3.Name = "BT_RR3";
            this.BT_RR3.Size = new System.Drawing.Size(178, 23);
            this.BT_RR3.TabIndex = 6;
            this.BT_RR3.Text = "Read Register 3";
            this.BT_RR3.UseVisualStyleBackColor = true;
            this.BT_RR3.Click += new System.EventHandler(this.BT_RR3_Click);
            // 
            // label26
            // 
            this.label26.AutoSize = true;
            this.label26.Location = new System.Drawing.Point(6, 21);
            this.label26.Name = "label26";
            this.label26.Size = new System.Drawing.Size(62, 13);
            this.label26.TabIndex = 15;
            this.label26.Text = "Sens-Tc-Lt:";
            // 
            // NUD_Sens_Tc_Lt
            // 
            this.NUD_Sens_Tc_Lt.Location = new System.Drawing.Point(74, 19);
            this.NUD_Sens_Tc_Lt.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.NUD_Sens_Tc_Lt.Name = "NUD_Sens_Tc_Lt";
            this.NUD_Sens_Tc_Lt.Size = new System.Drawing.Size(55, 20);
            this.NUD_Sens_Tc_Lt.TabIndex = 12;
            this.NUD_Sens_Tc_Lt.ValueChanged += new System.EventHandler(this.NUD_Sens_Tc_Lt_ValueChanged);
            // 
            // GB_MR4_9
            // 
            this.GB_MR4_9.Controls.Add(this.TB_WoXY_TH);
            this.GB_MR4_9.Controls.Add(this.TB_WoZ_TH);
            this.GB_MR4_9.Controls.Add(this.TB_WoT_TH);
            this.GB_MR4_9.Controls.Add(this.TB_Offset_Z);
            this.GB_MR4_9.Controls.Add(this.TB_Offset_Y);
            this.GB_MR4_9.Controls.Add(this.TB_Offset_X);
            this.GB_MR4_9.Controls.Add(this.label21);
            this.GB_MR4_9.Controls.Add(this.label22);
            this.GB_MR4_9.Controls.Add(this.label23);
            this.GB_MR4_9.Controls.Add(this.label24);
            this.GB_MR4_9.Controls.Add(this.label27);
            this.GB_MR4_9.Controls.Add(this.BT_WR4_9);
            this.GB_MR4_9.Controls.Add(this.BT_RR4_9);
            this.GB_MR4_9.Controls.Add(this.label28);
            this.GB_MR4_9.Enabled = false;
            this.GB_MR4_9.Location = new System.Drawing.Point(396, 487);
            this.GB_MR4_9.Name = "GB_MR4_9";
            this.GB_MR4_9.Size = new System.Drawing.Size(378, 108);
            this.GB_MR4_9.TabIndex = 35;
            this.GB_MR4_9.TabStop = false;
            this.GB_MR4_9.Text = "Memory Registers 4 - 9";
            // 
            // TB_WoXY_TH
            // 
            this.TB_WoXY_TH.Location = new System.Drawing.Point(71, 46);
            this.TB_WoXY_TH.Name = "TB_WoXY_TH";
            this.TB_WoXY_TH.Size = new System.Drawing.Size(55, 20);
            this.TB_WoXY_TH.TabIndex = 40;
            this.TB_WoXY_TH.TextChanged += new System.EventHandler(this.TB_WoXY_TH_TextChanged);
            // 
            // TB_WoZ_TH
            // 
            this.TB_WoZ_TH.Location = new System.Drawing.Point(192, 45);
            this.TB_WoZ_TH.Name = "TB_WoZ_TH";
            this.TB_WoZ_TH.Size = new System.Drawing.Size(55, 20);
            this.TB_WoZ_TH.TabIndex = 39;
            this.TB_WoZ_TH.TextChanged += new System.EventHandler(this.TB_WoZ_TH_TextChanged);
            // 
            // TB_WoT_TH
            // 
            this.TB_WoT_TH.Location = new System.Drawing.Point(317, 46);
            this.TB_WoT_TH.Name = "TB_WoT_TH";
            this.TB_WoT_TH.Size = new System.Drawing.Size(55, 20);
            this.TB_WoT_TH.TabIndex = 38;
            this.TB_WoT_TH.TextChanged += new System.EventHandler(this.TB_WoT_TH_TextChanged);
            // 
            // TB_Offset_Z
            // 
            this.TB_Offset_Z.Location = new System.Drawing.Point(317, 20);
            this.TB_Offset_Z.Name = "TB_Offset_Z";
            this.TB_Offset_Z.Size = new System.Drawing.Size(55, 20);
            this.TB_Offset_Z.TabIndex = 37;
            this.TB_Offset_Z.TextChanged += new System.EventHandler(this.TB_Offset_Z_TextChanged);
            // 
            // TB_Offset_Y
            // 
            this.TB_Offset_Y.Location = new System.Drawing.Point(192, 20);
            this.TB_Offset_Y.Name = "TB_Offset_Y";
            this.TB_Offset_Y.Size = new System.Drawing.Size(55, 20);
            this.TB_Offset_Y.TabIndex = 36;
            this.TB_Offset_Y.TextChanged += new System.EventHandler(this.TB_Offset_Y_TextChanged);
            // 
            // TB_Offset_X
            // 
            this.TB_Offset_X.Location = new System.Drawing.Point(71, 20);
            this.TB_Offset_X.Name = "TB_Offset_X";
            this.TB_Offset_X.Size = new System.Drawing.Size(55, 20);
            this.TB_Offset_X.TabIndex = 35;
            this.TB_Offset_X.TextChanged += new System.EventHandler(this.TB_Offset_X_TextChanged);
            // 
            // label21
            // 
            this.label21.AutoSize = true;
            this.label21.Location = new System.Drawing.Point(263, 23);
            this.label21.Name = "label21";
            this.label21.Size = new System.Drawing.Size(48, 13);
            this.label21.TabIndex = 34;
            this.label21.Text = "Offset-Z:";
            // 
            // label22
            // 
            this.label22.AutoSize = true;
            this.label22.Location = new System.Drawing.Point(256, 49);
            this.label22.Name = "label22";
            this.label22.Size = new System.Drawing.Size(53, 13);
            this.label22.TabIndex = 32;
            this.label22.Text = "WoT_Th:";
            // 
            // label23
            // 
            this.label23.AutoSize = true;
            this.label23.Location = new System.Drawing.Point(134, 49);
            this.label23.Name = "label23";
            this.label23.Size = new System.Drawing.Size(50, 13);
            this.label23.TabIndex = 30;
            this.label23.Text = "WoZ-Th:";
            // 
            // label24
            // 
            this.label24.AutoSize = true;
            this.label24.Location = new System.Drawing.Point(6, 49);
            this.label24.Name = "label24";
            this.label24.Size = new System.Drawing.Size(57, 13);
            this.label24.TabIndex = 28;
            this.label24.Text = "WoXY-Th:";
            // 
            // label27
            // 
            this.label27.AutoSize = true;
            this.label27.Location = new System.Drawing.Point(138, 23);
            this.label27.Name = "label27";
            this.label27.Size = new System.Drawing.Size(48, 13);
            this.label27.TabIndex = 26;
            this.label27.Text = "Offset-Y:";
            // 
            // BT_WR4_9
            // 
            this.BT_WR4_9.Location = new System.Drawing.Point(194, 73);
            this.BT_WR4_9.Name = "BT_WR4_9";
            this.BT_WR4_9.Size = new System.Drawing.Size(178, 23);
            this.BT_WR4_9.TabIndex = 7;
            this.BT_WR4_9.Text = "Write Registers 4 - 9";
            this.BT_WR4_9.UseVisualStyleBackColor = true;
            this.BT_WR4_9.Click += new System.EventHandler(this.BT_WR4_9_Click);
            // 
            // BT_RR4_9
            // 
            this.BT_RR4_9.Location = new System.Drawing.Point(9, 73);
            this.BT_RR4_9.Name = "BT_RR4_9";
            this.BT_RR4_9.Size = new System.Drawing.Size(178, 23);
            this.BT_RR4_9.TabIndex = 6;
            this.BT_RR4_9.Text = "Read Registers 4 - 9";
            this.BT_RR4_9.UseVisualStyleBackColor = true;
            this.BT_RR4_9.Click += new System.EventHandler(this.BT_RR4_9_Click);
            // 
            // label28
            // 
            this.label28.AutoSize = true;
            this.label28.Location = new System.Drawing.Point(17, 23);
            this.label28.Name = "label28";
            this.label28.Size = new System.Drawing.Size(48, 13);
            this.label28.TabIndex = 15;
            this.label28.Text = "Offset-X:";
            // 
            // GB_GMA
            // 
            this.GB_GMA.Controls.Add(this.NUD_Memory_Address);
            this.GB_GMA.Controls.Add(this.TB_General_Memory_Value);
            this.GB_GMA.Controls.Add(this.label29);
            this.GB_GMA.Controls.Add(this.BT_Write_Specified_Register);
            this.GB_GMA.Controls.Add(this.BT_Read_Specified_Register);
            this.GB_GMA.Controls.Add(this.label34);
            this.GB_GMA.Enabled = false;
            this.GB_GMA.Location = new System.Drawing.Point(396, 601);
            this.GB_GMA.Name = "GB_GMA";
            this.GB_GMA.Size = new System.Drawing.Size(378, 83);
            this.GB_GMA.TabIndex = 41;
            this.GB_GMA.TabStop = false;
            this.GB_GMA.Text = "General Memory Access";
            // 
            // NUD_Memory_Address
            // 
            this.NUD_Memory_Address.Location = new System.Drawing.Point(100, 21);
            this.NUD_Memory_Address.Maximum = new decimal(new int[] {
            31,
            0,
            0,
            0});
            this.NUD_Memory_Address.Name = "NUD_Memory_Address";
            this.NUD_Memory_Address.Size = new System.Drawing.Size(55, 20);
            this.NUD_Memory_Address.TabIndex = 27;
            this.NUD_Memory_Address.ValueChanged += new System.EventHandler(this.NUD_Memory_Address_ValueChanged);
            // 
            // TB_General_Memory_Value
            // 
            this.TB_General_Memory_Value.Location = new System.Drawing.Point(317, 20);
            this.TB_General_Memory_Value.Name = "TB_General_Memory_Value";
            this.TB_General_Memory_Value.Size = new System.Drawing.Size(55, 20);
            this.TB_General_Memory_Value.TabIndex = 37;
            this.TB_General_Memory_Value.TextChanged += new System.EventHandler(this.TB_General_Memory_Value_TextChanged);
            // 
            // label29
            // 
            this.label29.AutoSize = true;
            this.label29.Location = new System.Drawing.Point(274, 27);
            this.label29.Name = "label29";
            this.label29.Size = new System.Drawing.Size(37, 13);
            this.label29.TabIndex = 34;
            this.label29.Text = "Value:";
            // 
            // BT_Write_Specified_Register
            // 
            this.BT_Write_Specified_Register.Location = new System.Drawing.Point(194, 47);
            this.BT_Write_Specified_Register.Name = "BT_Write_Specified_Register";
            this.BT_Write_Specified_Register.Size = new System.Drawing.Size(178, 23);
            this.BT_Write_Specified_Register.TabIndex = 7;
            this.BT_Write_Specified_Register.Text = "Write Specified Register";
            this.BT_Write_Specified_Register.UseVisualStyleBackColor = true;
            this.BT_Write_Specified_Register.Click += new System.EventHandler(this.BT_Write_Specified_Register_Click);
            // 
            // BT_Read_Specified_Register
            // 
            this.BT_Read_Specified_Register.Location = new System.Drawing.Point(9, 47);
            this.BT_Read_Specified_Register.Name = "BT_Read_Specified_Register";
            this.BT_Read_Specified_Register.Size = new System.Drawing.Size(178, 23);
            this.BT_Read_Specified_Register.TabIndex = 6;
            this.BT_Read_Specified_Register.Text = "Read Specified Register";
            this.BT_Read_Specified_Register.UseVisualStyleBackColor = true;
            this.BT_Read_Specified_Register.Click += new System.EventHandler(this.BT_Read_Specified_Register_Click);
            // 
            // label34
            // 
            this.label34.AutoSize = true;
            this.label34.Location = new System.Drawing.Point(6, 23);
            this.label34.Name = "label34";
            this.label34.Size = new System.Drawing.Size(88, 13);
            this.label34.TabIndex = 15;
            this.label34.Text = "Memory Address:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(785, 693);
            this.Controls.Add(this.GB_GMA);
            this.Controls.Add(this.GB_MR4_9);
            this.Controls.Add(this.GB_MR3);
            this.Controls.Add(this.GB_MR2);
            this.Controls.Add(this.GB_MR1);
            this.Controls.Add(this.GB_MR0);
            this.Controls.Add(this.GB_raw);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.GB_measurement_control);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Cursor = System.Windows.Forms.Cursors.Default;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "MLX90393 Interface V1.0";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Databits)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.GB_measurement_control.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.GB_raw.ResumeLayout(false);
            this.GB_raw.PerformLayout();
            this.GB_MR0.ResumeLayout(false);
            this.GB_MR0.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Gain_Sel)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Hallconf)).EndInit();
            this.GB_MR1.ResumeLayout(false);
            this.GB_MR1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Comm_Mode)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Burst_Data_Rate)).EndInit();
            this.GB_MR2.ResumeLayout(false);
            this.GB_MR2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_OSR2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Res_Z)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Res_Y)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Res_X)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Dig_Filt)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_OSR)).EndInit();
            this.GB_MR3.ResumeLayout(false);
            this.GB_MR3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Sens_Tc_Hc)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Sens_Tc_Lt)).EndInit();
            this.GB_MR4_9.ResumeLayout(false);
            this.GB_MR4_9.PerformLayout();
            this.GB_GMA.ResumeLayout(false);
            this.GB_GMA.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Memory_Address)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox TB_Baud;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox TB_Com;
        private System.Windows.Forms.ComboBox CB_Paritiybit;
        private System.Windows.Forms.NumericUpDown NUD_Databits;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button BT_Connectserial;
        private System.Windows.Forms.ComboBox CB_Stopbits;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.CheckBox CB_T_selection;
        private System.Windows.Forms.CheckBox CB_Z_selection;
        private System.Windows.Forms.CheckBox CB_Y_selection;
        private System.Windows.Forms.CheckBox CB_X_selection;
        private System.Windows.Forms.GroupBox GB_measurement_control;
        private System.Windows.Forms.Button BT_RT;
        private System.Windows.Forms.Button BT_EX;
        private System.Windows.Forms.Button BT_RM;
        private System.Windows.Forms.Button BT_SM;
        private System.Windows.Forms.Button BT_SWOC;
        private System.Windows.Forms.Button BT_SB;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Label LB_T;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label LB_Z;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label LB_Y;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label LB_X;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label LB_D0;
        private System.Windows.Forms.Label LB_D1;
        private System.Windows.Forms.Label LB_RS;
        private System.Windows.Forms.Label LB_sed;
        private System.Windows.Forms.Label LB_error;
        private System.Windows.Forms.Label LB_sm_mode;
        private System.Windows.Forms.Label LB_woc_mode;
        private System.Windows.Forms.Label LB_time;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label LB_burst_mode;
        private System.Windows.Forms.GroupBox GB_raw;
        private System.Windows.Forms.Button BT_reset_raw;
        private System.Windows.Forms.TextBox TB_raw;
        private System.Windows.Forms.Button BT_send_raw;
        private System.Windows.Forms.TextBox TB_send_raw;
        private System.Windows.Forms.GroupBox GB_MR0;
        private System.Windows.Forms.Button BT_WR0;
        private System.Windows.Forms.Button BT_RR0;
        private System.Windows.Forms.CheckBox CB_Z_Series;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.NumericUpDown NUD_Gain_Sel;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.NumericUpDown NUD_Hallconf;
        private System.Windows.Forms.GroupBox GB_MR1;
        private System.Windows.Forms.CheckBox CB_Trig_Int_Sel;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.NumericUpDown NUD_Comm_Mode;
        private System.Windows.Forms.CheckBox CB_Woc_Diff;
        private System.Windows.Forms.CheckBox CB_Ext_Trig;
        private System.Windows.Forms.CheckBox CB_Tcmp_En;
        private System.Windows.Forms.CheckBox CB_Burst_Sel_T;
        private System.Windows.Forms.CheckBox CB_Burst_Sel_X;
        private System.Windows.Forms.CheckBox CB_Burst_Sel_Y;
        private System.Windows.Forms.Button BT_WR1;
        private System.Windows.Forms.Button BT_RR1;
        private System.Windows.Forms.CheckBox CB_Burst_Sel_Z;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.NumericUpDown NUD_Burst_Data_Rate;
        private System.Windows.Forms.GroupBox GB_MR2;
        private System.Windows.Forms.Label label20;
        private System.Windows.Forms.NumericUpDown NUD_OSR2;
        private System.Windows.Forms.Label label19;
        private System.Windows.Forms.NumericUpDown NUD_Res_Z;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.NumericUpDown NUD_Res_Y;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.NumericUpDown NUD_Res_X;
        private System.Windows.Forms.Label label55;
        private System.Windows.Forms.NumericUpDown NUD_Dig_Filt;
        private System.Windows.Forms.Button BT_WR2;
        private System.Windows.Forms.Button BT_RR2;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.NumericUpDown NUD_OSR;
        private System.Windows.Forms.Button BT_NOP;
        private System.Windows.Forms.Button BT_HS;
        private System.Windows.Forms.Button BT_HR;
        private System.Windows.Forms.GroupBox GB_MR3;
        private System.Windows.Forms.Label label25;
        private System.Windows.Forms.NumericUpDown NUD_Sens_Tc_Hc;
        private System.Windows.Forms.Button BT_WR3;
        private System.Windows.Forms.Button BT_RR3;
        private System.Windows.Forms.Label label26;
        private System.Windows.Forms.NumericUpDown NUD_Sens_Tc_Lt;
        private System.Windows.Forms.GroupBox GB_MR4_9;
        private System.Windows.Forms.TextBox TB_WoXY_TH;
        private System.Windows.Forms.TextBox TB_WoZ_TH;
        private System.Windows.Forms.TextBox TB_WoT_TH;
        private System.Windows.Forms.TextBox TB_Offset_Z;
        private System.Windows.Forms.TextBox TB_Offset_Y;
        private System.Windows.Forms.TextBox TB_Offset_X;
        private System.Windows.Forms.Label label21;
        private System.Windows.Forms.Label label22;
        private System.Windows.Forms.Label label23;
        private System.Windows.Forms.Label label24;
        private System.Windows.Forms.Label label27;
        private System.Windows.Forms.Button BT_WR4_9;
        private System.Windows.Forms.Button BT_RR4_9;
        private System.Windows.Forms.Label label28;
        private System.Windows.Forms.GroupBox GB_GMA;
        private System.Windows.Forms.NumericUpDown NUD_Memory_Address;
        private System.Windows.Forms.TextBox TB_General_Memory_Value;
        private System.Windows.Forms.Label label29;
        private System.Windows.Forms.Button BT_Write_Specified_Register;
        private System.Windows.Forms.Button BT_Read_Specified_Register;
        private System.Windows.Forms.Label label34;
    }
}

