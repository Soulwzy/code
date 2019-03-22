using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication1
{
    class Operation
    {
        private double numA = 0;
        private double numB = 0;

        public double NumA
        {
            get
            {
                return numA;
            }
            set
            {
                numA = value;
            }
        }

        public double NumB
        {
            get
            {
                return numB;
            }
            set
            {
                numB = value;
            }
        }

        public virtual double Getresult()
        {
            double result = 0;
            return result;
        }
    }
}
