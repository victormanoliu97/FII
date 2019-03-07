using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator.Operation
{
    public class Operation
    {
        public String firstOperand;
        public String mathOperator;
        public String secondOperator;
        public String result;

        public Operation(string firstOperand, string mathOperator, string secondOperator, string result)
        {
            this.firstOperand = firstOperand;
            this.mathOperator = mathOperator;
            this.secondOperator = secondOperator;
            this.result = result;
        }

        public override string ToString()
        {
            return firstOperand + mathOperator + secondOperator + "=" + result;
        }
    }
}
