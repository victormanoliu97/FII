using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;
using static Calculator.Operation.Operation;

namespace Calculator
{
    public partial class Form1 : Form
    {
        public ValidationUtils.ValidationUtils ValidationUtils = new ValidationUtils.ValidationUtils();
        private String _mathematicalExpression = null;
        private List<Operation.Operation> operationsHistoryList = new List<Operation.Operation>();

        public Form1()
        {
            InitializeComponent();
        }

        private void resultTextBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            var regexNumbersSymbols = new Regex(@"[^0-9\.\-\+\=\b/]");
            if (regexNumbersSymbols.IsMatch(e.KeyChar.ToString()))
            {
                e.Handled = true;
            }
        }

        private void n1_Click(object sender, EventArgs e)
        {
            if (resultTextBox.Text == "0" && resultTextBox.Text != null)
            {
                resultTextBox.Text = n1.Text;
                _mathematicalExpression += n1.Text;
            }
            else
            {
                resultTextBox.Text = resultTextBox.Text + n1.Text;
                _mathematicalExpression += resultTextBox;
            }
        }

        private void n2_Click(object sender, EventArgs e)
        {
            if (resultTextBox.Text == "0" && resultTextBox.Text != null)
            {
                resultTextBox.Text = n2.Text;
                _mathematicalExpression += n2.Text;
            }
            else
            {
                resultTextBox.Text = resultTextBox.Text + n2.Text;
                _mathematicalExpression += resultTextBox;
            }
        }

        private void n3_Click(object sender, EventArgs e)
        {
            if (resultTextBox.Text == "0" && resultTextBox.Text != null)
            {
                resultTextBox.Text = n3.Text;
                _mathematicalExpression += n3.Text;
            }
            else
            {
                resultTextBox.Text = resultTextBox.Text + n3.Text;
                _mathematicalExpression += resultTextBox;
            }
        }

        private void n4_Click(object sender, EventArgs e)
        {
            if (resultTextBox.Text == "0" && resultTextBox.Text != null)
            {
                resultTextBox.Text = n4.Text;
                _mathematicalExpression += n4.Text;
            }
            else
            {
                resultTextBox.Text = resultTextBox.Text + n4.Text;
                _mathematicalExpression += resultTextBox;
            }
        }

        private void n5_Click(object sender, EventArgs e)
        {
            if (resultTextBox.Text == "0" && resultTextBox.Text != null)
            {
                resultTextBox.Text = n5.Text;
                _mathematicalExpression += n5.Text;
            }
            else
            {
                resultTextBox.Text = resultTextBox.Text + n5.Text;
                _mathematicalExpression += resultTextBox;
            }
        }

        private void n6_Click(object sender, EventArgs e)
        {
            if (resultTextBox.Text == "0" && resultTextBox.Text != null)
            {
                resultTextBox.Text = n6.Text;
                _mathematicalExpression += n6.Text;
            }
            else
            {
                resultTextBox.Text = resultTextBox.Text + n6.Text;
                _mathematicalExpression += resultTextBox;
            }
        }

        private void n7_Click(object sender, EventArgs e)
        {
            if (resultTextBox.Text == "0" && resultTextBox.Text != null)
            {
                resultTextBox.Text = n7.Text;
                _mathematicalExpression += n7.Text;
            }
            else
            {
                resultTextBox.Text = resultTextBox.Text + n7.Text;
                _mathematicalExpression += resultTextBox;
            }
        }

        private void n8_Click(object sender, EventArgs e)
        {
            if (resultTextBox.Text == "0" && resultTextBox.Text != null)
            {
                resultTextBox.Text = n8.Text;
                _mathematicalExpression += n8.Text;
            }
            else
            {
                resultTextBox.Text = resultTextBox.Text + n8.Text;
                _mathematicalExpression += resultTextBox;
            }
        }

        private void n9_Click(object sender, EventArgs e)
        {
            if (resultTextBox.Text == "0" && resultTextBox.Text != null)
            {
                resultTextBox.Text = n9.Text;
                _mathematicalExpression += n0.Text;
            }
            else
            {
                resultTextBox.Text = resultTextBox.Text + n9.Text;
                _mathematicalExpression += resultTextBox;
            }
        }

        private void n0_Click(object sender, EventArgs e)
        {
            if (resultTextBox.Text == "0" && resultTextBox.Text != null)
            {
                resultTextBox.Text = n0.Text;
                _mathematicalExpression += n0.Text;
            }
            else
            {
                resultTextBox.Text = resultTextBox.Text + n0.Text;
                _mathematicalExpression += resultTextBox;
            }
        }

        private void nPoint_Click_1(object sender, EventArgs e)
        {
            if (resultTextBox.Text.Length == 1 && resultTextBox.Text == "0")
            {
                resultTextBox.Text = null;
            }
            else //if (ValidationUtils.IsJustNumberOrDigit(resultTextBox.Text[resultTextBox.Text.Length - 1].ToString()))
            {
                resultTextBox.Text = resultTextBox.Text + nPoint.Text;
                _mathematicalExpression = resultTextBox.Text;
            }

        }

        private void nEquals_Click(object sender, EventArgs e)
        {
            double result = 0;
            if (resultTextBox.Text == "0" && resultTextBox.Text.Length == 1)
            {
                resultTextBox.Text = null;
            }
            try
            {
                if (ValidationUtils.IsJustNumberOrDigit(resultTextBox.Text[resultTextBox.Text.Length - 1].ToString()) &&
                    ValidationUtils.IsJustNumberOrDigit(resultTextBox.Text[resultTextBox.Text.Length - 3].ToString()) &&
                    ValidationUtils.checkIfOperand(resultTextBox.Text[resultTextBox.Text.Length - 2].ToString()))
                {
                    resultTextBox.Text = resultTextBox.Text + nEquals.Text;
                    _mathematicalExpression = resultTextBox.Text;

                    String mathOperator = resultTextBox.Text[ValidationUtils.extractOperatorIndex(resultTextBox.Text)]
                        .ToString();

                    double firstOperand = ValidationUtils.extractFirstOperand(resultTextBox.Text, mathOperator);

                    var indexOperator = resultTextBox.Text.IndexOf(mathOperator);
                    var indexEqual = resultTextBox.Text.IndexOf("=");

                    var stringSecondOperator = resultTextBox.Text.Substring(indexOperator + 1,
                        indexEqual - indexOperator - 1);
                        
                    double secondOperand = Convert.ToDouble(stringSecondOperator);

                    if (secondOperand.Equals(0))
                    {
                        MessageBox.Show("You can't divide by 0");
                        resultTextBox.Text = "0";
                    }
                    else
                    {
                        result = ValidationUtils
                            .ComputeExpression(firstOperand, secondOperand, Convert.ToChar(mathOperator));

                        resultTextBox.Text = ValidationUtils
                            .ComputeExpression(firstOperand, secondOperand, Convert.ToChar(mathOperator)).ToString();
                    }
                    operationsHistoryList.Add(new Operation.Operation(firstOperand.ToString(), 
                        mathOperator, secondOperand.ToString(), result.ToString()));


                    foreach (Operation.Operation i in operationsHistoryList)
                    {
                        if (!operationsHistoryListBox.Items.Contains(i))
                        {
                            operationsHistoryListBox.Items.Add(i);
                        }
                    }
                }
            }
            catch (IndexOutOfRangeException exception)
            {
                Console.WriteLine(exception);
            }

        }

        private void nDivide_Click(object sender, EventArgs e)
        {
            if (resultTextBox.Text.Length == 1 && resultTextBox.Text == "0")
            {
                resultTextBox.Text = resultTextBox.Text;
            }
            else if(ValidationUtils.IsJustNumberOrDigit(resultTextBox.Text[resultTextBox.Text.Length - 1].ToString()))
            {
                resultTextBox.Text = resultTextBox.Text + nDivide.Text;
                _mathematicalExpression = resultTextBox.Text;
            }

        }

        private void nMultiply_Click(object sender, EventArgs e)
        {
            if (resultTextBox.Text.Length == 1 && resultTextBox.Text == "0")
            {
                resultTextBox.Text = resultTextBox.Text;
            }
            else if (ValidationUtils.IsJustNumberOrDigit(resultTextBox.Text[resultTextBox.Text.Length - 1].ToString()))
            {
                resultTextBox.Text = resultTextBox.Text + nMultiply.Text;
                _mathematicalExpression = resultTextBox.Text;
            }
            
        }

        private void nMinus_Click(object sender, EventArgs e)
        {
            if (resultTextBox.Text.Length == 1 && resultTextBox.Text == "0")
            {
                resultTextBox.Text = resultTextBox.Text;
            }
            else if (ValidationUtils.IsJustNumberOrDigit(resultTextBox.Text[resultTextBox.Text.Length - 1].ToString()))
            {
                resultTextBox.Text = resultTextBox.Text + nMinus.Text;
                _mathematicalExpression = resultTextBox.Text;
            }
        }

        private void nPlus_Click(object sender, EventArgs e)
        {
            if (resultTextBox.Text.Length == 1 && resultTextBox.Text == "0")
            {
                resultTextBox.Text = resultTextBox.Text;
            }
            else if (ValidationUtils.IsJustNumberOrDigit(resultTextBox.Text[resultTextBox.Text.Length - 1].ToString()))
            {
                resultTextBox.Text = resultTextBox.Text + nPlus.Text;
                _mathematicalExpression = resultTextBox.Text;
            }
        }

        private void operationsHistoryListBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            var selectedOperationIndex = operationsHistoryListBox.SelectedIndex;

            double sum = 0;
            for (int i = 0; i <= selectedOperationIndex; i++)
            {
                sum += double.Parse(operationsHistoryList.ElementAt(i).result);
            }

            MessageBox.Show("Sum of all result: " + sum);
        }
    }
}
