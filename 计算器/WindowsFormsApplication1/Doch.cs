using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication1
{
    class Doch
    {
        private
            char str;
            bool type = false;         //0是字符,1是double数据
            double num;
        public
            Doch(double n)
        {
            num = n;
            type = true;
        }
        public 
            Doch(char ch)
        {
            str = ch;
            type = false;
        }
        public double Get_Num()
        {
            return num;
        }
        public char Get_Opr()
        {
            return str;
        }
        public bool Is_Num()
        {
            return type;
        }
    }
}
