using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 抓住我
{

    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        
        private void button1_Click(object sender, System.EventArgs e)
        {

            MessageBox.Show("真厉害，还是让你抓到了！");

        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            int border = 50;

            int x = e.X;

            int y = e.Y;

            int left = button1.Left;

            int right = button1.Right;

            int top = button1.Top;

            int bottom = button1.Bottom;

            //鼠标到按钮附近(20个象素)

            if (x > left - border && x < right + border && y > top - border && y < bottom + border)
            {

                button1.Top += (y > top ? -20 : 20);

                if (button1.Top > Form1.ActiveForm.Size.Height || button1.Bottom < 0)
                {

                    button1.Top = Form1.ActiveForm.Size.Height / 2;

                }

                button1.Left += (x > left ? -20 : 20);

                if (button1.Left > Form1.ActiveForm.Size.Width || button1.Right < 0)
                {

                    button1.Left = Form1.ActiveForm.Size.Width / 2;

                }

            }
        }


    }

}
