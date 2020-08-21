using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MLX90939_Interface
{
    public partial class Form1 : Form
    {
        delegate void DataReceivedCallback();
        int bytesExpected = 0;
        int byteIndex = 0;
        byte[] bytes_buffer = new byte[256];
        bool initial_read_registers = true;
        enum Commands
        {
            EX,
            SB,
            SWOC,
            SM,
            RM,
            RR,
            WR,
            RT,
            HR,
            HS,
            NOP
        }
        Commands current_command = Commands.NOP;
        int current_register = 10;

        double[,] sens_xy = new double[8, 4] {  { 0.805, 1.610, 3.220, 6.440 },
                                                { 0.644, 1.288, 2.576, 5.152 },
                                                { 0.483, 0.966, 1.932, 3.864 },
                                                { 0.403, 0.805, 1.610, 3.220 },
                                                { 0.322, 0.644, 1.288, 2.576 },
                                                { 0.268, 0.537, 1.073, 2.147 },
                                                { 0.215, 0.429, 0.859, 1.717 },
                                                { 0.161, 0.322, 0.644, 1.288 } };

        double[,] sens_z = new double[8, 4] {   { 1.468, 2.936, 5.872, 11.744 },
                                                { 1.174, 2.349, 4.698, 9.395 },
                                                { 0.881, 1.762, 3.523, 7.046 },
                                                { 0.734, 1.468, 2.936, 5.872 },
                                                { 0.587, 1.174, 2.349, 4.698 },
                                                { 0.489, 0.979, 1.957, 3.915 },
                                                { 0.391, 0.783, 1.566, 3.132 },
                                                { 0.294, 0.587, 1.174, 2.349 } };
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (BT_Connectserial.Text == "Disconnect")
            {
                serialPort1.Close();
            }
        }

        private void BT_Connectserial_Click(object sender, EventArgs e)
        {
            if (BT_Connectserial.Text == "Connect")
            {
                serialPort1.PortName = TB_Com.Text;
                serialPort1.BaudRate = Convert.ToInt32(TB_Baud.Text);
                serialPort1.DataBits = Convert.ToInt32(NUD_Databits.Value);
                serialPort1.StopBits = (StopBits)Enum.Parse(typeof(StopBits), CB_Stopbits.Text);
                serialPort1.Parity = (Parity)Enum.Parse(typeof(Parity), CB_Paritiybit.Text);
                try
                {
                    serialPort1.Open();
                    if (serialPort1.IsOpen)
                    {
                        BT_Connectserial.Text = "Disconnect";
                        TB_Baud.Enabled = false;
                        TB_Com.Enabled = false;
                        NUD_Databits.Enabled = false;
                        CB_Stopbits.Enabled = false;
                        CB_Paritiybit.Enabled = false;
                        GB_measurement_control.Enabled = true;
                        GB_raw.Enabled = true;
                        GB_MR0.Enabled = true;
                        GB_MR1.Enabled = true;
                        GB_MR2.Enabled = true;
                        GB_MR3.Enabled = true;
                        GB_MR4_9.Enabled = true;
                        GB_GMA.Enabled = true;
                        TB_raw.Text = "";

                        byte address = 0 << 2;
                        byte command = Convert.ToByte(0b01010000);
                        serialPort1.Write(new byte[] { command, address }, 0, 2);
                        bytesExpected = 3;
                        byteIndex = 0;
                        current_command = Commands.RR;
                        current_register = 0;
                        if (TB_raw.Text != "")
                        {
                            TB_raw.Text += "\r\n";
                        }
                        TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
                        TB_raw.Text += BitConverter.ToString(new byte[] { command, address }, 0, 2);
                        TB_raw.SelectionStart = TB_raw.Text.Length;
                        TB_raw.ScrollToCaret();
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            else
            {
                serialPort1.Close();
                BT_Connectserial.Text = "Connect";
                TB_Baud.Enabled = true;
                TB_Com.Enabled = true;
                NUD_Databits.Enabled = true;
                CB_Stopbits.Enabled = true;
                CB_Paritiybit.Enabled = true;
                GB_measurement_control.Enabled = false;
                GB_raw.Enabled = false;
                GB_MR0.Enabled = false;
                GB_MR1.Enabled = false;
                GB_MR2.Enabled = false;
                GB_MR3.Enabled = false;
                GB_MR4_9.Enabled = false;
                GB_GMA.Enabled = false;
                initial_read_registers = true;
            }
        }

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            int nbr = serialPort1.BytesToRead;
            serialPort1.Read(bytes_buffer, byteIndex, nbr);
            byteIndex += nbr;
            if (byteIndex >= bytesExpected)
                this.BeginInvoke(new DataReceivedCallback(DataReceived));
        }

        private void DataReceived()
        {
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": < ";
            TB_raw.Text += BitConverter.ToString(bytes_buffer, 0, bytesExpected);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();

            if ((bytes_buffer[0] & (1 << 7)) != 0)
                LB_burst_mode.BackColor = Color.LightGreen;
            else
                LB_burst_mode.BackColor = SystemColors.Control;
            if ((bytes_buffer[0] & (1 << 6)) != 0)
                LB_woc_mode.BackColor = Color.LightGreen;
            else
                LB_woc_mode.BackColor = SystemColors.Control;
            if ((bytes_buffer[0] & (1 << 5)) != 0)
                LB_sm_mode.BackColor = Color.LightGreen;
            else
                LB_sm_mode.BackColor = SystemColors.Control;
            if ((bytes_buffer[0] & (1 << 4)) != 0)
                LB_error.BackColor = Color.LightGreen;
            else
                LB_error.BackColor = SystemColors.Control;
            if ((bytes_buffer[0] & (1 << 3)) != 0)
                LB_sed.BackColor = Color.LightGreen;
            else
                LB_sed.BackColor = SystemColors.Control;
            if ((bytes_buffer[0] & (1 << 2)) != 0)
                LB_RS.BackColor = Color.LightGreen;
            else
                LB_RS.BackColor = SystemColors.Control;
            if ((bytes_buffer[0] & (1 << 1)) != 0)
                LB_D1.BackColor = Color.LightGreen;
            else
                LB_D1.BackColor = SystemColors.Control;
            if ((bytes_buffer[0] & (1 << 0)) != 0)
                LB_D0.BackColor = Color.LightGreen;
            else
                LB_D0.BackColor = SystemColors.Control;
            switch (current_command)
            {
                case Commands.RM:
                    LB_time.Text = DateTime.Now.ToString("HH:mm:ss");
                    int i = 1;
                    if (CB_T_selection.Checked)
                    {
                        double temperature = BitConverter.ToUInt16(new byte[] { bytes_buffer[i + 1], bytes_buffer[i] }, 0);
                        temperature -= 45121;
                        temperature /= 45.2;
                        LB_T.Text = string.Format("{0:N2}°C", temperature);
                        i += 2;
                        LB_T.BackColor = Color.LightGreen;
                    }
                    else
                    {
                        LB_T.Text = "";
                        LB_T.BackColor = SystemColors.Control;
                    }
                    if (CB_X_selection.Checked)
                    {
                        double mag_x;
                        if (CB_Tcmp_En.Checked || NUD_Res_X.Value == 2)
                        {
                            mag_x = BitConverter.ToUInt16(new byte[] { bytes_buffer[i + 1], bytes_buffer[i] }, 0) - 32768;
                        }
                        else if (NUD_Res_X.Value == 3)
                        {
                            mag_x = BitConverter.ToUInt16(new byte[] { bytes_buffer[i + 1], bytes_buffer[i] }, 0) - 16384;
                        }
                        else
                        {
                            mag_x = BitConverter.ToInt16(new byte[] { bytes_buffer[i + 1], bytes_buffer[i] }, 0);
                        }
                        mag_x *= sens_xy[Convert.ToInt32(NUD_Gain_Sel.Value), Convert.ToInt32(NUD_Res_X.Value)] / 1000.0;

                        LB_X.Text = string.Format("{0:N3}mT", mag_x);
                        i += 2;
                        LB_X.BackColor = Color.LightGreen;
                    }
                    else
                    {
                        LB_X.Text = "";
                        LB_X.BackColor = SystemColors.Control;
                    }
                    if (CB_Y_selection.Checked)
                    {
                        double mag_y;
                        if (CB_Tcmp_En.Checked || NUD_Res_Y.Value == 2)
                        {
                            mag_y = BitConverter.ToUInt16(new byte[] { bytes_buffer[i + 1], bytes_buffer[i] }, 0) - 32768;
                        }
                        else if (NUD_Res_Y.Value == 3)
                        {
                            mag_y = BitConverter.ToUInt16(new byte[] { bytes_buffer[i + 1], bytes_buffer[i] }, 0) - 16384;
                        }
                        else
                        {
                            mag_y = BitConverter.ToInt16(new byte[] { bytes_buffer[i + 1], bytes_buffer[i] }, 0);
                        }
                        mag_y *= sens_xy[Convert.ToInt32(NUD_Gain_Sel.Value), Convert.ToInt32(NUD_Res_Y.Value)] / 1000.0;

                        LB_Y.Text = string.Format("{0:N3}mT", mag_y);
                        i += 2;
                        LB_Y.BackColor = Color.LightGreen;
                    }
                    else
                    {
                        LB_Y.Text = "";
                        LB_Y.BackColor = SystemColors.Control;
                    }
                    if (CB_Z_selection.Checked)
                    {
                        double mag_z;
                        if (CB_Tcmp_En.Checked || NUD_Res_Z.Value == 2)
                        {
                            mag_z = BitConverter.ToUInt16(new byte[] { bytes_buffer[i + 1], bytes_buffer[i] }, 0) - 32768;
                        }
                        else if (NUD_Res_X.Value == 3)
                        {
                            mag_z = BitConverter.ToUInt16(new byte[] { bytes_buffer[i + 1], bytes_buffer[i] }, 0) - 16384;
                        }
                        else
                        {
                            mag_z = BitConverter.ToInt16(new byte[] { bytes_buffer[i + 1], bytes_buffer[i] }, 0);
                        }
                        mag_z *= sens_z[Convert.ToInt32(NUD_Gain_Sel.Value), Convert.ToInt32(NUD_Res_Z.Value)] / 1000.0;

                        LB_Z.Text = string.Format("{0:N3}mT", mag_z);
                        LB_Z.BackColor = Color.LightGreen;
                    }
                    else
                    {
                        LB_Z.Text = "";
                        LB_Z.BackColor = SystemColors.Control;
                    }
                    break;

                case Commands.RR:
                    if (current_register == 0)
                    {
                        CB_Z_Series.Checked = (bytes_buffer[2] & (1 << 7)) > 0;
                        NUD_Gain_Sel.Value = (bytes_buffer[2] & 0b01110000) >> 4;
                        NUD_Hallconf.Value = (bytes_buffer[2] & 0b00001111) >> 0;

                        CB_Z_Series.BackColor = SystemColors.Control;
                        NUD_Gain_Sel.BackColor = SystemColors.Control;
                        NUD_Hallconf.BackColor = SystemColors.Control;
                    }
                    else if (current_register == 1)
                    {
                        CB_Trig_Int_Sel.Checked = (bytes_buffer[1] & (1 << 7)) > 0;
                        NUD_Comm_Mode.Value = (bytes_buffer[1] & 0b01100000) >> 5;
                        CB_Woc_Diff.Checked = (bytes_buffer[1] & (1 << 4)) > 0;
                        CB_Ext_Trig.Checked = (bytes_buffer[1] & (1 << 3)) > 0;
                        CB_Tcmp_En.Checked = (bytes_buffer[1] & (1 << 2)) > 0;
                        CB_Burst_Sel_Z.Checked = (bytes_buffer[1] & (1 << 1)) > 0;
                        CB_Burst_Sel_Y.Checked = (bytes_buffer[1] & (1 << 0)) > 0;

                        CB_Burst_Sel_X.Checked = (bytes_buffer[2] & (1 << 7)) > 0;
                        CB_Burst_Sel_T.Checked = (bytes_buffer[2] & (1 << 6)) > 0;
                        NUD_Burst_Data_Rate.Value = (bytes_buffer[2] & 0b00111111) >> 0;

                        CB_Trig_Int_Sel.BackColor = SystemColors.Control;
                        NUD_Comm_Mode.BackColor = SystemColors.Control;
                        CB_Woc_Diff.BackColor = SystemColors.Control;
                        CB_Ext_Trig.BackColor = SystemColors.Control;
                        CB_Tcmp_En.BackColor = SystemColors.Control;
                        CB_Burst_Sel_Z.BackColor = SystemColors.Control;
                        CB_Burst_Sel_Y.BackColor = SystemColors.Control;
                        CB_Burst_Sel_X.BackColor = SystemColors.Control;
                        CB_Burst_Sel_T.BackColor = SystemColors.Control;
                        NUD_Burst_Data_Rate.BackColor = SystemColors.Control;
                    }
                    else if (current_register == 2)
                    {
                        NUD_OSR2.Value = (bytes_buffer[1] & 0b00011000) >> 3;
                        NUD_Res_Z.Value = (bytes_buffer[1] & 0b00000110) >> 1;
                        NUD_Res_Y.Value = (bytes_buffer[1] & 0b00000001) << 1;

                        NUD_Res_Y.Value += (bytes_buffer[2] & 0b10000000) >> 7;
                        NUD_Res_X.Value = (bytes_buffer[2] & 0b01100000) >> 5;
                        NUD_Dig_Filt.Value = (bytes_buffer[2] & 0b00011100) >> 2;
                        NUD_OSR.Value = (bytes_buffer[2] & 0b00000011) >> 0;

                        NUD_OSR2.BackColor = SystemColors.Control;
                        NUD_Res_Z.BackColor = SystemColors.Control;
                        NUD_Res_Y.BackColor = SystemColors.Control;
                        NUD_Res_X.BackColor = SystemColors.Control;
                        NUD_Dig_Filt.BackColor = SystemColors.Control;
                        NUD_OSR.BackColor = SystemColors.Control;
                    }
                    else if (current_register == 3)
                    {
                        NUD_Sens_Tc_Hc.Value = bytes_buffer[1];
                        NUD_Sens_Tc_Lt.Value = bytes_buffer[2];

                        NUD_Sens_Tc_Hc.BackColor = SystemColors.Control;
                        NUD_Sens_Tc_Lt.BackColor = SystemColors.Control;
                    }
                    else if (current_register == 4)
                    {
                        TB_Offset_X.Text = Convert.ToString(BitConverter.ToUInt16(new byte[] { bytes_buffer[2], bytes_buffer[1] }, 0));
                        TB_Offset_X.BackColor = SystemColors.Control;
                    }
                    else if (current_register == 5)
                    {
                        TB_Offset_Y.Text = Convert.ToString(BitConverter.ToUInt16(new byte[] { bytes_buffer[2], bytes_buffer[1] }, 0));
                        TB_Offset_Y.BackColor = SystemColors.Control;
                    }
                    else if (current_register == 6)
                    {
                        TB_Offset_Z.Text = Convert.ToString(BitConverter.ToUInt16(new byte[] { bytes_buffer[2], bytes_buffer[1] }, 0));
                        TB_Offset_Z.BackColor = SystemColors.Control;
                    }
                    else if (current_register == 7)
                    {
                        TB_WoXY_TH.Text = Convert.ToString(BitConverter.ToUInt16(new byte[] { bytes_buffer[2], bytes_buffer[1] }, 0));
                        TB_WoXY_TH.BackColor = SystemColors.Control;
                    }
                    else if (current_register == 8)
                    {
                        TB_WoZ_TH.Text = Convert.ToString(BitConverter.ToUInt16(new byte[] { bytes_buffer[2], bytes_buffer[1] }, 0));
                        TB_WoZ_TH.BackColor = SystemColors.Control;
                    }
                    else if (current_register == 9)
                    {
                        TB_WoT_TH.Text = Convert.ToString(BitConverter.ToUInt16(new byte[] { bytes_buffer[2], bytes_buffer[1] }, 0));
                        TB_WoT_TH.BackColor = SystemColors.Control;
                        initial_read_registers = false;
                    }
                    else if (current_register > 9)
                    {
                        TB_General_Memory_Value.Text = Convert.ToString(BitConverter.ToUInt16(new byte[] { bytes_buffer[2], bytes_buffer[1] }, 0));
                        TB_General_Memory_Value.BackColor = SystemColors.Control;
                    }

                    if (initial_read_registers || (current_register >= 4 && current_register < 9))
                    {
                        current_register++;
                        byte address = Convert.ToByte(current_register << 2);
                        byte command = Convert.ToByte(0b01010000);
                        serialPort1.Write(new byte[] { command, address }, 0, 2);
                        bytesExpected = 3;
                        byteIndex = 0;
                        current_command = Commands.RR;

                        if (TB_raw.Text != "")
                        {
                            TB_raw.Text += "\r\n";
                        }
                        TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
                        TB_raw.Text += BitConverter.ToString(new byte[] { command, address }, 0, 2);
                        TB_raw.SelectionStart = TB_raw.Text.Length;
                        TB_raw.ScrollToCaret();
                    }
                    break;
                case Commands.WR:
                    if (current_register >= 4 && current_register < 9)
                    {
                        current_register++;
                        byte address = Convert.ToByte(current_register << 2);
                        byte MSB = 0, LSB = 0;
                        switch (current_register)
                        {
                            case 5:
                                MSB = Convert.ToByte(Convert.ToInt32(TB_Offset_Y.Text) >> 8);
                                LSB = Convert.ToByte(Convert.ToInt32(TB_Offset_Y.Text) % 256);
                                break;
                            case 6:
                                MSB = Convert.ToByte(Convert.ToInt32(TB_Offset_Z.Text) >> 8);
                                LSB = Convert.ToByte(Convert.ToInt32(TB_Offset_Z.Text) % 256);
                                break;
                            case 7:
                                MSB = Convert.ToByte(Convert.ToInt32(TB_WoXY_TH.Text) >> 8);
                                LSB = Convert.ToByte(Convert.ToInt32(TB_WoXY_TH.Text) % 256);
                                break;
                            case 8:
                                MSB = Convert.ToByte(Convert.ToInt32(TB_WoZ_TH.Text) >> 8);
                                LSB = Convert.ToByte(Convert.ToInt32(TB_WoZ_TH.Text) % 256);
                                break;
                            case 9:
                                MSB = Convert.ToByte(Convert.ToInt32(TB_WoT_TH.Text) >> 8);
                                LSB = Convert.ToByte(Convert.ToInt32(TB_WoT_TH.Text) % 256);
                                break;
                        }
                        byte command = Convert.ToByte(0b01100000);
                        serialPort1.Write(new byte[] { command, MSB, LSB, address }, 0, 4);
                        bytesExpected = 1;
                        byteIndex = 0;
                        current_command = Commands.WR;
                        if (TB_raw.Text != "")
                        {
                            TB_raw.Text += "\r\n";
                        }
                        TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
                        TB_raw.Text += BitConverter.ToString(new byte[] { command, MSB, LSB, address }, 0, 4);
                        TB_raw.SelectionStart = TB_raw.Text.Length;
                        TB_raw.ScrollToCaret();
                    }
                    break;
            }
        }

        private int getChannels()
        {
            int channels = Convert.ToInt32(CB_T_selection.Checked) * 1;
            channels += Convert.ToInt32(CB_X_selection.Checked) * 2;
            channels += Convert.ToInt32(CB_Y_selection.Checked) * 4;
            channels += Convert.ToInt32(CB_Z_selection.Checked) * 8;
            return channels;
        }
        #region General Command Buttons
        private void BT_SB_Click(object sender, EventArgs e)
        {
            byte command = Convert.ToByte(0b00010000 + getChannels());
            serialPort1.Write(new byte[] { command }, 0, 1);
            bytesExpected = 1;
            byteIndex = 0;
            current_command = Commands.SB;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command }, 0, 1);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();
        }

        private void BT_SWOC_Click(object sender, EventArgs e)
        {
            byte command = Convert.ToByte(0b00100000 + getChannels());
            serialPort1.Write(new byte[] { command }, 0, 1);
            bytesExpected = 1;
            byteIndex = 0;
            current_command = Commands.SWOC;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command }, 0, 1);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();
        }

        private void BT_SM_Click(object sender, EventArgs e)
        {
            byte command = Convert.ToByte(0b00110000 + getChannels());
            serialPort1.Write(new byte[] { command }, 0, 1);
            bytesExpected = 1;
            byteIndex = 0;
            current_command = Commands.SM;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command }, 0, 1);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();
        }

        private void BT_RM_Click(object sender, EventArgs e)
        {
            byte command = Convert.ToByte(0b01000000 + getChannels());
            serialPort1.Write(new byte[] { command }, 0, 1);
            bytesExpected = 1 + 2 * (Convert.ToInt32(CB_T_selection.Checked) + Convert.ToInt32(CB_X_selection.Checked) + 
                Convert.ToInt32(CB_Y_selection.Checked) + Convert.ToInt32(CB_Z_selection.Checked));
            byteIndex = 0;
            current_command = Commands.RM;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command }, 0, 1);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();
        }

        private void BT_EX_Click(object sender, EventArgs e)
        {
            byte command = Convert.ToByte(0b10000000);
            serialPort1.Write(new byte[] { command }, 0, 1);
            bytesExpected = 1;
            byteIndex = 0;
            current_command = Commands.EX;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command }, 0, 1);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();
        }

        private void BT_RT_Click(object sender, EventArgs e)
        {
            byte command = Convert.ToByte(0b11110000);
            serialPort1.Write(new byte[] { command }, 0, 1);
            bytesExpected = 1;
            byteIndex = 0;
            current_command = Commands.RT;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command }, 0, 1);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();
        }

        private void BT_HR_Click(object sender, EventArgs e)
        {
            byte command = Convert.ToByte(0b11010000);
            serialPort1.Write(new byte[] { command }, 0, 1);
            bytesExpected = 1;
            byteIndex = 0;
            current_command = Commands.HR;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command }, 0, 1);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();
        }

        private void BT_HS_Click(object sender, EventArgs e)
        {
            byte command = Convert.ToByte(0b11100000);
            serialPort1.Write(new byte[] { command }, 0, 1);
            bytesExpected = 1;
            byteIndex = 0;
            current_command = Commands.HS;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command }, 0, 1);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();
        }

        private void BT_NOP_Click(object sender, EventArgs e)
        {
            byte command = Convert.ToByte(0b00000000);
            serialPort1.Write(new byte[] { command }, 0, 1);
            bytesExpected = 1;
            byteIndex = 0;
            current_command = Commands.NOP;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command }, 0, 1);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();
        }
        #endregion
        #region Raw communication buttons
        private void BT_reset_raw_Click(object sender, EventArgs e)
        {
            TB_raw.Text = "";
        }

        private void BT_send_raw_Click(object sender, EventArgs e)
        {
            serialPort1.Write(TB_send_raw.Text);
            TB_send_raw.Text = "";
        }
        #endregion
        #region Text/Value Changed
        private void TB_Offset_X_TextChanged(object sender, EventArgs e)
        {
            TB_Offset_X.BackColor = Color.LightPink;
            if (TB_Offset_X.Text != "")
            {
                try
                {
                    ushort value = UInt16.Parse(TB_Offset_X.Text);
                }
                catch (FormatException)
                {
                    TB_Offset_X.Text = "";
                    MessageBox.Show("Offset-X: \nYes, there are (some) sanity checks ;) \nWrong Format! Try again!");
                }
                catch (OverflowException)
                {
                    TB_Offset_X.Text = "";
                    MessageBox.Show("Offset-X: \nYes, there are (some) sanity checks ;) \nValue out of bounds. Enter value between 0 and 65'535! Try again!");
                }
            }
        }
        
        private void TB_Offset_Y_TextChanged(object sender, EventArgs e)
        {
            TB_Offset_Y.BackColor = Color.LightPink;
            if (TB_Offset_Y.Text != "")
            {
                try
                {
                    ushort value = UInt16.Parse(TB_Offset_Y.Text);
                }
                catch (FormatException)
                {
                    TB_Offset_Y.Text = "";
                    MessageBox.Show("Offset-Y: \nYes, there are (some) sanity checks ;) \nWrong Format! Try again!");
                }
                catch (OverflowException)
                {
                    TB_Offset_Y.Text = "";
                    MessageBox.Show("Offset-Y: \nYes, there are (some) sanity checks ;) \nValue out of bounds. Enter value between 0 and 65'535! Try again!");
                }
            }
        }

        private void TB_Offset_Z_TextChanged(object sender, EventArgs e)
        {
            TB_Offset_Z.BackColor = Color.LightPink;
            if (TB_Offset_Z.Text != "")
            {
                try
                {
                    ushort value = UInt16.Parse(TB_Offset_Z.Text);
                }
                catch (FormatException)
                {
                    TB_Offset_Z.Text = "";
                    MessageBox.Show("Offset-Z: \nYes, there are (some) sanity checks ;) \nWrong Format! Try again!");
                }
                catch (OverflowException)
                {
                    TB_Offset_Z.Text = "";
                    MessageBox.Show("Offset-Z: \nYes, there are (some) sanity checks ;) \nValue out of bounds. Enter value between 0 and 65'535! Try again!");
                }
            }
        }

        private void TB_WoXY_TH_TextChanged(object sender, EventArgs e)
        {
            TB_WoXY_TH.BackColor = Color.LightPink;
            if (TB_WoXY_TH.Text != "")
            {
                try
                {
                    ushort value = UInt16.Parse(TB_WoXY_TH.Text);
                }
                catch (FormatException)
                {
                    TB_WoXY_TH.Text = "";
                    MessageBox.Show("TB_WoXY_TH: \nYes, there are (some) sanity checks ;) \nWrong Format! Try again!");
                }
                catch (OverflowException)
                {
                    TB_WoXY_TH.Text = "";
                    MessageBox.Show("TB_WoXY_TH: \nYes, there are (some) sanity checks ;) \nValue out of bounds. Enter value between 0 and 65'535! Try again!");
                }
            }
        }

        private void TB_WoZ_TH_TextChanged(object sender, EventArgs e)
        {
            TB_WoZ_TH.BackColor = Color.LightPink;
            if (TB_WoZ_TH.Text != "")
            {
                try
                {
                    ushort value = UInt16.Parse(TB_WoZ_TH.Text);
                }
                catch (FormatException)
                {
                    TB_WoZ_TH.Text = "";
                    MessageBox.Show("TB_WoZ_TH: \nYes, there are (some) sanity checks ;) \nWrong Format! Try again!");
                }
                catch (OverflowException)
                {
                    TB_WoZ_TH.Text = "";
                    MessageBox.Show("TB_WoZ_TH: \nYes, there are (some) sanity checks ;) \nValue out of bounds. Enter value between 0 and 65'535! Try again!");
                }
            }
        }

        private void TB_WoT_TH_TextChanged(object sender, EventArgs e)
        {
            TB_WoT_TH.BackColor = Color.LightPink;
            if (TB_WoT_TH.Text != "")
            {
                try
                {
                    ushort value = UInt16.Parse(TB_WoT_TH.Text);
                }
                catch (FormatException)
                {
                    TB_WoT_TH.Text = "";
                    MessageBox.Show("TB_WoT_TH: \nYes, there are (some) sanity checks ;) \nWrong Format! Try again!");
                }
                catch (OverflowException)
                {
                    TB_WoT_TH.Text = "";
                    MessageBox.Show("TB_WoT_TH: \nYes, there are (some) sanity checks ;) \nValue out of bounds. Enter value between 0 and 65'535! Try again!");
                }
            }
        }

        private void TB_General_Memory_Value_TextChanged(object sender, EventArgs e)
        {
            TB_General_Memory_Value.BackColor = Color.LightPink;
            if (TB_General_Memory_Value.Text != "")
            {
                try
                {
                    ushort value = UInt16.Parse(TB_General_Memory_Value.Text);
                }
                catch (FormatException)
                {
                    TB_General_Memory_Value.Text = "";
                    MessageBox.Show("TB_General_Memory_Value: \nYes, there are (some) sanity checks ;) \nWrong Format! Try again!");
                }
                catch (OverflowException)
                {
                    TB_General_Memory_Value.Text = "";
                    MessageBox.Show("TB_General_Memory_Value: \nYes, there are (some) sanity checks ;) \nValue out of bounds. Enter value between 0 and 65'535! Try again!");
                }
            }
        }

        private void NUD_Hallconf_ValueChanged(object sender, EventArgs e)
        {
            NUD_Hallconf.BackColor = Color.LightPink;
        }

        private void NUD_Gain_Sel_ValueChanged(object sender, EventArgs e)
        {
            NUD_Gain_Sel.BackColor = Color.LightPink;
        }

        private void CB_Z_Series_CheckedChanged(object sender, EventArgs e)
        {
            CB_Z_Series.BackColor = Color.LightPink;
        }

        private void NUD_Burst_Data_Rate_ValueChanged(object sender, EventArgs e)
        {
            NUD_Burst_Data_Rate.BackColor = Color.LightPink;
        }

        private void CB_Burst_Sel_Z_CheckedChanged(object sender, EventArgs e)
        {
            CB_Burst_Sel_Z.BackColor = Color.LightPink;
        }

        private void CB_Burst_Sel_Y_CheckedChanged(object sender, EventArgs e)
        {
            CB_Burst_Sel_Y.BackColor = Color.LightPink;
        }

        private void CB_Burst_Sel_X_CheckedChanged(object sender, EventArgs e)
        {
            CB_Burst_Sel_X.BackColor = Color.LightPink;
        }

        private void CB_Burst_Sel_T_CheckedChanged(object sender, EventArgs e)
        {
            CB_Burst_Sel_T.BackColor = Color.LightPink;
        }

        private void CB_Tcmp_En_CheckedChanged(object sender, EventArgs e)
        {
            CB_Tcmp_En.BackColor = Color.LightPink;
        }

        private void CB_Ext_Trig_CheckedChanged(object sender, EventArgs e)
        {
            CB_Ext_Trig.BackColor = Color.LightPink;
        }

        private void CB_Woc_Diff_CheckedChanged(object sender, EventArgs e)
        {
            CB_Woc_Diff.BackColor = Color.LightPink;
        }

        private void CB_Trig_Int_Sel_CheckedChanged(object sender, EventArgs e)
        {
            CB_Trig_Int_Sel.BackColor = Color.LightPink;
        }

        private void NUD_Comm_Mode_ValueChanged(object sender, EventArgs e)
        {
            NUD_Comm_Mode.BackColor = Color.LightPink;
            MessageBox.Show("Be careful with this!!!");
        }

        private void NUD_OSR_ValueChanged(object sender, EventArgs e)
        {
            NUD_OSR.BackColor = Color.LightPink;
        }

        private void NUD_Dig_Filt_ValueChanged(object sender, EventArgs e)
        {
            NUD_Dig_Filt.BackColor = Color.LightPink;
        }

        private void NUD_OSR2_ValueChanged(object sender, EventArgs e)
        {
            NUD_OSR2.BackColor = Color.LightPink;
        }

        private void NUD_Res_X_ValueChanged(object sender, EventArgs e)
        {
            NUD_Res_X.BackColor = Color.LightPink;
        }

        private void NUD_Res_Y_ValueChanged(object sender, EventArgs e)
        {
            NUD_Res_Y.BackColor = Color.LightPink;
        }

        private void NUD_Res_Z_ValueChanged(object sender, EventArgs e)
        {
            NUD_Res_Z.BackColor = Color.LightPink;
        }

        private void NUD_Sens_Tc_Lt_ValueChanged(object sender, EventArgs e)
        {
            NUD_Sens_Tc_Lt.BackColor = Color.LightPink;
        }

        private void NUD_Sens_Tc_Hc_ValueChanged(object sender, EventArgs e)
        {
            NUD_Sens_Tc_Hc.BackColor = Color.LightPink;
        }

        private void NUD_Memory_Address_ValueChanged(object sender, EventArgs e)
        {

        }
        #endregion
        #region Memory buttons click
        private void BT_WR0_Click(object sender, EventArgs e)
        {
            byte address = 0 << 2;
            byte MSB = 0;
            byte LSB =  Convert.ToByte(
                        (Convert.ToInt32(CB_Z_Series.Checked) << 7) + 
                        (Convert.ToInt32(NUD_Gain_Sel.Value) << 4) + 
                        (Convert.ToInt32(NUD_Hallconf.Value) << 0));
            byte command = Convert.ToByte(0b01100000);
            serialPort1.Write(new byte[] { command, MSB, LSB, address }, 0, 4);
            bytesExpected = 1;
            byteIndex = 0;
            current_command = Commands.WR;
            current_register = 0;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command, MSB, LSB, address }, 0, 4);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();

            CB_Z_Series.BackColor = SystemColors.Control;
            NUD_Gain_Sel.BackColor = SystemColors.Control;
            NUD_Hallconf.BackColor = SystemColors.Control;
        }

        private void BT_RR0_Click(object sender, EventArgs e)
        {
            byte address = 0 << 2;
            byte command = Convert.ToByte(0b01010000);
            serialPort1.Write(new byte[] { command, address }, 0, 2);
            bytesExpected = 3;
            byteIndex = 0;
            current_command = Commands.RR;
            current_register = 0;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command, address }, 0, 2);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();

            CB_Z_Series.BackColor = SystemColors.Control;
            NUD_Gain_Sel.BackColor = SystemColors.Control;
            NUD_Hallconf.BackColor = SystemColors.Control;
        }

        private void BT_WR1_Click(object sender, EventArgs e)
        {
            byte address = 1 << 2;
            byte MSB = Convert.ToByte(
                        (Convert.ToInt32(CB_Trig_Int_Sel.Checked) << 7) +
                        (Convert.ToInt32(NUD_Comm_Mode.Value) << 5) +
                        (Convert.ToInt32(CB_Woc_Diff.Checked) << 4) +
                        (Convert.ToInt32(CB_Ext_Trig.Checked) << 3) +
                        (Convert.ToInt32(CB_Tcmp_En.Checked) << 2) +
                        (Convert.ToInt32(CB_Burst_Sel_Z.Checked) << 1) +
                        (Convert.ToInt32(CB_Burst_Sel_Y.Checked) << 0));
            byte LSB =  Convert.ToByte(
                        (Convert.ToInt32(CB_Burst_Sel_X.Checked) << 7) +
                        (Convert.ToInt32(CB_Burst_Sel_T.Checked) << 6) + 
                        (Convert.ToInt32(NUD_Burst_Data_Rate.Value) << 0));
            byte command = Convert.ToByte(0b01100000);
            serialPort1.Write(new byte[] { command, MSB, LSB, address }, 0, 4);
            bytesExpected = 1;
            byteIndex = 0;
            current_command = Commands.WR;
            current_register = 1;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command, MSB, LSB, address }, 0, 4);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();

            CB_Trig_Int_Sel.BackColor = SystemColors.Control;
            NUD_Comm_Mode.BackColor = SystemColors.Control;
            CB_Woc_Diff.BackColor = SystemColors.Control;
            CB_Ext_Trig.BackColor = SystemColors.Control;
            CB_Tcmp_En.BackColor = SystemColors.Control;
            CB_Burst_Sel_Z.BackColor = SystemColors.Control;
            CB_Burst_Sel_Y.BackColor = SystemColors.Control;
            CB_Burst_Sel_X.BackColor = SystemColors.Control;
            CB_Burst_Sel_T.BackColor = SystemColors.Control;
            NUD_Burst_Data_Rate.BackColor = SystemColors.Control;
        }

        private void BT_RR1_Click(object sender, EventArgs e)
        {
            byte address = 1 << 2;
            byte command = Convert.ToByte(0b01010000);
            serialPort1.Write(new byte[] { command, address }, 0, 2);
            bytesExpected = 3;
            byteIndex = 0;
            current_command = Commands.RR;
            current_register = 1;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command, address }, 0, 2);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();

            CB_Trig_Int_Sel.BackColor = SystemColors.Control;
            NUD_Comm_Mode.BackColor = SystemColors.Control;
            CB_Woc_Diff.BackColor = SystemColors.Control;
            CB_Ext_Trig.BackColor = SystemColors.Control;
            CB_Tcmp_En.BackColor = SystemColors.Control;
            CB_Burst_Sel_Z.BackColor = SystemColors.Control;
            CB_Burst_Sel_Y.BackColor = SystemColors.Control;
            CB_Burst_Sel_X.BackColor = SystemColors.Control;
            CB_Burst_Sel_T.BackColor = SystemColors.Control;
            NUD_Burst_Data_Rate.BackColor = SystemColors.Control;
        }

        private void BT_WR2_Click(object sender, EventArgs e)
        {
            byte address = 2 << 2;
            byte MSB = Convert.ToByte(
                        (Convert.ToInt32(NUD_OSR2.Value) << 3) +
                        (Convert.ToInt32(NUD_Res_Z.Value) << 1) +
                        (Convert.ToInt32(NUD_Res_Y.Value > 1) << 0));
            byte LSB = Convert.ToByte(
                        (Convert.ToInt32(NUD_Res_Y.Value % 2 == 1) << 7) +
                        (Convert.ToInt32(NUD_Res_X.Value) << 5) +
                        (Convert.ToInt32(NUD_Dig_Filt.Value) << 2) +
                        (Convert.ToInt32(NUD_OSR.Value) << 0));
            byte command = Convert.ToByte(0b01100000);
            serialPort1.Write(new byte[] { command, MSB, LSB, address }, 0, 4);
            bytesExpected = 1;
            byteIndex = 0;
            current_command = Commands.WR;
            current_register = 2;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command, MSB, LSB, address }, 0, 4);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();

            NUD_OSR2.BackColor = SystemColors.Control;
            NUD_Res_Z.BackColor = SystemColors.Control;
            NUD_Res_Y.BackColor = SystemColors.Control;
            NUD_Res_X.BackColor = SystemColors.Control;
            NUD_Dig_Filt.BackColor = SystemColors.Control;
            NUD_OSR.BackColor = SystemColors.Control;
        }

        private void BT_RR2_Click(object sender, EventArgs e)
        {
            byte address = 2 << 2;
            byte command = Convert.ToByte(0b01010000);
            serialPort1.Write(new byte[] { command, address }, 0, 2);
            bytesExpected = 3;
            byteIndex = 0;
            current_command = Commands.RR;
            current_register = 2;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command, address }, 0, 2);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();

            NUD_OSR2.BackColor = SystemColors.Control;
            NUD_Res_Z.BackColor = SystemColors.Control;
            NUD_Res_Y.BackColor = SystemColors.Control;
            NUD_Res_X.BackColor = SystemColors.Control;
            NUD_Dig_Filt.BackColor = SystemColors.Control;
            NUD_OSR.BackColor = SystemColors.Control;
        }

        private void BT_WR3_Click(object sender, EventArgs e)
        {
            byte address = 3 << 2;
            byte MSB = Convert.ToByte(NUD_Sens_Tc_Hc.Value);
            byte LSB = Convert.ToByte(NUD_Sens_Tc_Lt.Value);
            byte command = Convert.ToByte(0b01100000);
            serialPort1.Write(new byte[] { command, MSB, LSB, address }, 0, 4);
            bytesExpected = 1;
            byteIndex = 0;
            current_command = Commands.WR;
            current_register = 3;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command, MSB, LSB, address }, 0, 4);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();

            NUD_Sens_Tc_Hc.BackColor = SystemColors.Control;
            NUD_Sens_Tc_Lt.BackColor = SystemColors.Control;
        }

        private void BT_RR3_Click(object sender, EventArgs e)
        {
            byte address = 3 << 2;
            byte command = Convert.ToByte(0b01010000);
            serialPort1.Write(new byte[] { command, address }, 0, 2);
            bytesExpected = 3;
            byteIndex = 0;
            current_command = Commands.RR;
            current_register = 3;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command, address }, 0, 2);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();

            NUD_Sens_Tc_Hc.BackColor = SystemColors.Control;
            NUD_Sens_Tc_Lt.BackColor = SystemColors.Control;
        }

        private void BT_WR4_9_Click(object sender, EventArgs e)
        {
            byte address = 4 << 2;
            byte MSB = Convert.ToByte(Convert.ToInt32(TB_Offset_X.Text) >> 8);
            byte LSB = Convert.ToByte(Convert.ToInt32(TB_Offset_X.Text) % 256);
            byte command = Convert.ToByte(0b01100000);
            serialPort1.Write(new byte[] { command, MSB, LSB, address }, 0, 4);
            bytesExpected = 1;
            byteIndex = 0;
            current_command = Commands.WR;
            current_register = 4;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command, MSB, LSB, address }, 0, 4);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();

            TB_Offset_X.BackColor = SystemColors.Control;
            TB_Offset_Y.BackColor = SystemColors.Control;
            TB_Offset_Z.BackColor = SystemColors.Control;
            TB_WoT_TH.BackColor = SystemColors.Control;
            TB_WoXY_TH.BackColor = SystemColors.Control;
            TB_WoZ_TH.BackColor = SystemColors.Control;

        }

        private void BT_RR4_9_Click(object sender, EventArgs e)
        {
            byte address = 4 << 2;
            byte command = Convert.ToByte(0b01010000);
            serialPort1.Write(new byte[] { command, address }, 0, 2);
            bytesExpected = 3;
            byteIndex = 0;
            current_command = Commands.RR;
            current_register = 4;
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command, address }, 0, 2);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();

            TB_Offset_X.BackColor = SystemColors.Control;
            TB_Offset_Y.BackColor = SystemColors.Control;
            TB_Offset_Z.BackColor = SystemColors.Control;
            TB_WoT_TH.BackColor = SystemColors.Control;
            TB_WoXY_TH.BackColor = SystemColors.Control;
            TB_WoZ_TH.BackColor = SystemColors.Control;
        }

        private void BT_Write_Specified_Register_Click(object sender, EventArgs e)
        {
            byte address = Convert.ToByte(Convert.ToInt32(NUD_Memory_Address.Value) << 2);
            byte MSB = Convert.ToByte(Convert.ToInt32(TB_General_Memory_Value.Text) >> 8);
            byte LSB = Convert.ToByte(Convert.ToInt32(TB_General_Memory_Value.Text) % 256);
            byte command = Convert.ToByte(0b01100000);
            serialPort1.Write(new byte[] { command, MSB, LSB, address }, 0, 4);
            bytesExpected = 1;
            byteIndex = 0;
            current_command = Commands.WR;
            current_register = Convert.ToInt32(NUD_Memory_Address.Value);
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command, MSB, LSB, address }, 0, 4);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();

            TB_General_Memory_Value.BackColor = SystemColors.Control;
        }

        private void BT_Read_Specified_Register_Click(object sender, EventArgs e)
        {
            byte address = Convert.ToByte(Convert.ToInt32(NUD_Memory_Address.Value) << 2);
            byte command = Convert.ToByte(0b01010000);
            serialPort1.Write(new byte[] { command, address }, 0, 2);
            bytesExpected = 3;
            byteIndex = 0;
            current_command = Commands.RR;
            current_register = Convert.ToInt32(NUD_Memory_Address.Value);
            if (TB_raw.Text != "")
            {
                TB_raw.Text += "\r\n";
            }
            TB_raw.Text += DateTime.Now.ToString("HH:mm:ss") + ": > ";
            TB_raw.Text += BitConverter.ToString(new byte[] { command, address }, 0, 2);
            TB_raw.SelectionStart = TB_raw.Text.Length;
            TB_raw.ScrollToCaret();

            TB_General_Memory_Value.BackColor = SystemColors.Control;
        }
        #endregion
    }
}
