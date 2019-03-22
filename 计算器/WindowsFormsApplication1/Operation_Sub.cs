using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication1
{
    class Operation_Sub : Operation
    {
        public override double Getresult()
        {
            double result = 0;
            result = NumA - NumB;
            return result;

        }
    }
}
