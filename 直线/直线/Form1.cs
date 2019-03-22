using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 直线
{
    public partial class Form1 : Form
    {

        private Point Start, End;
        private Pen p;
        private Color c;
        private Graphics g;
        private int width;
        public Form1()
        {
            InitializeComponent();
            c = Color.Red;
            width = 10;
            p = new Pen(c, width);
            g = CreateGraphics();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            Start = new Point(e.X, e.Y);
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
    
            End = new Point(e.X, e.Y);
            g.DrawLine(p, Start, End);
        }

    }
}
