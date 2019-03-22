using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication1
{
    class Operation_Fac : Operation
    {
        public static Operation Value(string sym)
        {
            Operation opr = null;
            switch(sym)
            {
                case "+":
                    opr = new Operation_Add();
                    break;
                case "-":
                    opr = new Operation_Sub();
                    break;
                case "*":
                    opr = new Operation_Mul();
                    break;
                case "/":
                    opr = new Operation_Div();
                    break;
                default:
                    throw new Exception("错误!");
            }
            return opr;
        }
    }
}
