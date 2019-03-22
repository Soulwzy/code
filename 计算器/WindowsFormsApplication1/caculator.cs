using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class caculator : Form
    {
        public caculator()
        {
            InitializeComponent();
        }

        public void Value_num(int num)
        {
            Textbox.Text += num.ToString();
            Textbox.Select(Textbox.Text.Length, 0);
            //Textbox.Select(Textbox.SelectionStart, 0);
        }

        public void Value_num(char ch)
        {
            Textbox.Text += ch;
            Textbox.Select(Textbox.Text.Length, 0);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Value_num(1);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Value_num(2);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Value_num(3);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Value_num(4);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Value_num(5);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Value_num(6);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Value_num(7);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            Value_num(8);
        }

        private void button9_Click(object sender, EventArgs e)
        {
            Value_num(9);
        }

        private void button10_Click(object sender, EventArgs e)
        {
            Value_num(0);
        }

        private void button11_Click(object sender, EventArgs e)
        {
            Value_num('.');
        }

        private void button12_Click(object sender, EventArgs e)
        {
            Value_num('+');
        }

        private void button13_Click(object sender, EventArgs e)
        {
            Value_num('-');
        }

        private void button14_Click(object sender, EventArgs e)
        {
            Value_num('*');
        }

        private void button15_Click(object sender, EventArgs e)
        {
            Value_num('/');
        }

        private void button16_Click(object sender, EventArgs e)
        {
            Textbox.Text = null;
        }

        private void button17_Click(object sender, EventArgs e)
        {
            Value_num('(');
        }

        private void button19_Click(object sender, EventArgs e)
        {
            Value_num(')');
        }

        private void button20_Click(object sender, EventArgs e)
        {
            Textbox.Focus();
            SendKeys.Send("{BACKSPACE}");
        }

        private void button22_Click(object sender, EventArgs e)
        {
            Textbox.Focus();
            SendKeys.Send("{LEFT}");
        }

        private void button21_Click(object sender, EventArgs e)
        {
            Textbox.Focus();
            SendKeys.Send("{RIGHT}");
        }

        private void button18_Click(object sender, EventArgs e)
        {
            //后缀转中缀表达式
                                    
            string text = Textbox.Text;
            Stack<Doch> Num_Stack = new Stack<Doch>();
            Stack<char> Opr_Stack = new Stack<char>();

            for(int i = 0; i < text.Length; i++)
            {
                if (text[i] >= '0' && text[i] <= '9' || text[i] == '.')
                {

                    bool flg = true;              //1是大于0的数，0是小数
                    double n = 1;
                    double num = 0;

                    while(i < text.Length && ((text[i] >= '0' && text[i] <= '9')|| text[i] == '.'))
                    {
                        if(text[i] == '.')
                        {
                            flg = false;
                            i++;
                            continue;
                        }
                        if(flg)
                        {
                            //num = num * 10 + Convert.ToDouble(text[i]);
                            num = num * 10 + text[i] - '0';
                            i++;
                        }
                        else
                        {
                            n *= 0.1;
                            num = num + (text[i] - '0') * n;
                            i++;
                        }
                    }
                    i--;
                    Num_Stack.Push(new Doch(num));
                }
                else if (text[i] == '(')
                {
                    Opr_Stack.Push(text[i]);
                }
                else if (text[i] == ')')
                {
                    while (Opr_Stack.Peek() != '(')
                    {
                        Num_Stack.Push(new Doch(Opr_Stack.Pop()));
                    }
                    Opr_Stack.Pop();
                }
                else
                {
                    if (Opr_Stack.Count == 0 || Opr_Stack.Peek() == '(')
                    {
                        Opr_Stack.Push(text[i]);
                    }
                    else if (text[i] == '*' || text[i] == '/')
                    {
                        Opr_Stack.Push(text[i]);
                    }
                    else if (text[i] == '+' || text[i] == '-')
                    {
                        if (Opr_Stack.Peek() == '+' || Opr_Stack.Peek() == '-')
                        {
                            Opr_Stack.Push(text[i]);
                        }
                        else
                        {
                            while (!(Opr_Stack.Count == 0 || Opr_Stack.Peek() == '+' || Opr_Stack.Peek() == '-' || Opr_Stack.Peek() == '('))
                            {
                                Num_Stack.Push(new Doch(Opr_Stack.Pop()));
                            }
                            Opr_Stack.Push(text[i]);
                        }
                    }

                }
            }
            while(Opr_Stack.Count != 0)
            {
                Num_Stack.Push(new Doch(Opr_Stack.Pop()));
            }

            //栈逆置
              
            Stack<Doch> New_Stack = new Stack<Doch>();
            while(Num_Stack.Count != 0)
            {
                New_Stack.Push(Num_Stack.Pop());
            }

            //计算结果

            while(New_Stack.Count != 0)
            {
                Doch doch;
                doch = New_Stack.Pop();
                if(!doch.Is_Num())
                {
                    Operation oper = Operation_Fac.Value(Convert.ToString(doch.Get_Opr()));
                    oper.NumB = Num_Stack.Pop().Get_Num();
                    oper.NumA = Num_Stack.Pop().Get_Num();
                    Num_Stack.Push(new Doch(oper.Getresult()));
                }
                else
                {
                    Num_Stack.Push(doch);
                }
            }

            Textbox.Text = Convert.ToString(Num_Stack.Pop().Get_Num());
        }
    }
}
