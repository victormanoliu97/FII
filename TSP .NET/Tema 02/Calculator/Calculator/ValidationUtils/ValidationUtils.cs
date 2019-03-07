using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator.ValidationUtils
{
    public class ValidationUtils
    {
        public bool IsJustNumberOrDigit(String text)
        {
            var regexNumbersSymbols = new Regex(@"[0-9]");
            return regexNumbersSymbols.IsMatch(text);
        }

        public bool checkIfOperand(String text)
        {
            switch (char.Parse(text))
            {
                case '/':
                case '*':
                case '+':
                case '-':
                    return true;
                default:
                    return false;
            }
        }

        public double ComputeExpression(double a, double b, char operand)
        {
            switch (operand)
            {
                case '+':
                    return a + b;
                case '-':
                    return a - b;
                case '*':
                    return a * b;
                case '/':
                    return a / b;
                default:
                    return 0;
            }
        }

        public double extractFirstOperand(String text, String mathOperator)
        {
            string stringBeforeChar = text.Substring(0, text.IndexOf(mathOperator));
            return Convert.ToDouble(stringBeforeChar);
        }

        public double extractSecondOperand(String text, String mathOperator)
        {
            var firstOperand = extractFirstOperand(text, mathOperator).ToString();
            text.Remove(text.IndexOf(firstOperand));
            text.Replace(mathOperator, "");
            text.Replace("=", "");
            return Convert.ToDouble(text);
        }

        public int extractOperatorIndex(String text)
        {
            if (text.IndexOf('-') != -1)
            {
                return text.IndexOf('-');
            }

            if (text.IndexOf('+') != -1)
            {
                return text.IndexOf('+');
            }
            if (text.IndexOf('*') != -1)
            {
                return text.IndexOf('*');
            }
            if (text.IndexOf('/') != -1)
            {
                return text.IndexOf('/');
            }
            return -1;
        }

    }
}
