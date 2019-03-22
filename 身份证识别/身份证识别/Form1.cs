using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 身份证识别
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string str = textBox1.Text;
            textBox2.Text = str.Substring(0, 6);
            textBox3.Text = str.Substring(6, 8);
            if((Convert.ToInt32(str.Substring(16,1)) % 2 == 0))
            {
                textBox4.Text = str.Substring(16, 1);
            }
            else
            {
                textBox4.Text = "男";
            }
        }

    }
}
