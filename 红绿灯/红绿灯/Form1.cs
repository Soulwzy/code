using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 红绿灯
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
        }

        public int i = 0;
        public int final = 6;
        public void ShutNS()
        {
            pictureBox1.Image = imageList.Images[3];
            pictureBox2.Image = imageList.Images[3];
            pictureBox3.Image = imageList.Images[3];
            pictureBox8.Image = imageList.Images[3];
            pictureBox9.Image = imageList.Images[3];
            pictureBox10.Image = imageList.Images[3];
        }
        public void ShutWE()
        {
            pictureBox4.Image = imageList.Images[3];
            pictureBox5.Image = imageList.Images[3];
            pictureBox6.Image = imageList.Images[3];
            pictureBox11.Image = imageList.Images[3];
            pictureBox12.Image = imageList.Images[3];
            pictureBox13.Image = imageList.Images[3];
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            timer2.Enabled = true;

        }

        private void button2_Click(object sender, EventArgs e)
        {
            timer1.Enabled = false;
            timer2.Enabled = false;
        }    
        private void button3_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = imageList.Images[3];
            pictureBox2.Image = imageList.Images[3];
            pictureBox3.Image = imageList.Images[3];
            pictureBox4.Image = imageList.Images[3];
            pictureBox5.Image = imageList.Images[3];
            pictureBox6.Image = imageList.Images[3];
            pictureBox8.Image = imageList.Images[3];
            pictureBox9.Image = imageList.Images[3];
            pictureBox10.Image = imageList.Images[3];
            pictureBox11.Image = imageList.Images[3];
            pictureBox12.Image = imageList.Images[3];
            pictureBox13.Image = imageList.Images[3];
            timer1.Enabled = false;
            timer2.Enabled = false;
            i = 0;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if(i % final < 2 && i % final >= 0)
            {
                ShutNS();
                pictureBox3.Image = imageList.Images[0];
                pictureBox10.Image = imageList.Images[0];
                i++;
            }
            else if (i % final == 2)
            {
                ShutNS();
                pictureBox2.Image = imageList.Images[2];
                pictureBox9.Image = imageList.Images[2];
                i++;
            }
            else
            {
                ShutNS();
                pictureBox1.Image = imageList.Images[1];
                pictureBox8.Image = imageList.Images[1];
                i++;
            }
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            if (i % final < 3 && i % final >= 0)
            {
                ShutWE();
                pictureBox4.Image = imageList.Images[1];
                pictureBox11.Image = imageList.Images[1];
            }
            else if(i % final >= 3 && i % final <5)
            {
                ShutWE();
                pictureBox6.Image = imageList.Images[0];
                pictureBox13.Image = imageList.Images[0];
            }
            else
            {
                ShutWE();
                pictureBox5.Image = imageList.Images[2];
                pictureBox12.Image = imageList.Images[2];
            }
        }


    }
}
