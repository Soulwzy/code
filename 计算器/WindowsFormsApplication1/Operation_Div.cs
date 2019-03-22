using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication1
{
    class Operation_Div : Operation
    {
        public override double Getresult()
        {
            double result = 0;
            if(NumB == 0)
            {
                throw new Exception("错误");
            }
            else
            {
                result = NumA / NumB;
            }
            return result;
        }
    }
}
