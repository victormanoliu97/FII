using System.Windows.Forms;

namespace Calculator
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.resultTextBox = new System.Windows.Forms.TextBox();
            this.n1 = new System.Windows.Forms.Button();
            this.n2 = new System.Windows.Forms.Button();
            this.n3 = new System.Windows.Forms.Button();
            this.n4 = new System.Windows.Forms.Button();
            this.n5 = new System.Windows.Forms.Button();
            this.n6 = new System.Windows.Forms.Button();
            this.n7 = new System.Windows.Forms.Button();
            this.n8 = new System.Windows.Forms.Button();
            this.n9 = new System.Windows.Forms.Button();
            this.n0 = new System.Windows.Forms.Button();
            this.nPoint = new System.Windows.Forms.Button();
            this.nEquals = new System.Windows.Forms.Button();
            this.nDivide = new System.Windows.Forms.Button();
            this.nMultiply = new System.Windows.Forms.Button();
            this.nMinus = new System.Windows.Forms.Button();
            this.nPlus = new System.Windows.Forms.Button();
            this.operationsHistoryListBox = new System.Windows.Forms.ListBox();
            this.clear_btn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // resultTextBox
            // 
            this.resultTextBox.Location = new System.Drawing.Point(0, 0);
            this.resultTextBox.Multiline = true;
            this.resultTextBox.Name = "resultTextBox";
            this.resultTextBox.Size = new System.Drawing.Size(904, 73);
            this.resultTextBox.TabIndex = 0;
            this.resultTextBox.Text = "0";
            this.resultTextBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.resultTextBox_KeyPress);
            // 
            // n1
            // 
            this.n1.Location = new System.Drawing.Point(12, 115);
            this.n1.Name = "n1";
            this.n1.Size = new System.Drawing.Size(85, 68);
            this.n1.TabIndex = 1;
            this.n1.Text = "1";
            this.n1.UseVisualStyleBackColor = true;
            this.n1.Click += new System.EventHandler(this.n1_Click);
            // 
            // n2
            // 
            this.n2.Location = new System.Drawing.Point(132, 115);
            this.n2.Name = "n2";
            this.n2.Size = new System.Drawing.Size(90, 68);
            this.n2.TabIndex = 2;
            this.n2.Text = "2";
            this.n2.UseVisualStyleBackColor = true;
            this.n2.Click += new System.EventHandler(this.n2_Click);
            // 
            // n3
            // 
            this.n3.Location = new System.Drawing.Point(250, 115);
            this.n3.Name = "n3";
            this.n3.Size = new System.Drawing.Size(89, 68);
            this.n3.TabIndex = 3;
            this.n3.Text = "3";
            this.n3.UseVisualStyleBackColor = true;
            this.n3.Click += new System.EventHandler(this.n3_Click);
            // 
            // n4
            // 
            this.n4.Location = new System.Drawing.Point(12, 198);
            this.n4.Name = "n4";
            this.n4.Size = new System.Drawing.Size(85, 68);
            this.n4.TabIndex = 4;
            this.n4.Text = "4";
            this.n4.UseVisualStyleBackColor = true;
            this.n4.Click += new System.EventHandler(this.n4_Click);
            // 
            // n5
            // 
            this.n5.Location = new System.Drawing.Point(132, 198);
            this.n5.Name = "n5";
            this.n5.Size = new System.Drawing.Size(90, 68);
            this.n5.TabIndex = 5;
            this.n5.Text = "5";
            this.n5.UseVisualStyleBackColor = true;
            this.n5.Click += new System.EventHandler(this.n5_Click);
            // 
            // n6
            // 
            this.n6.Location = new System.Drawing.Point(250, 198);
            this.n6.Name = "n6";
            this.n6.Size = new System.Drawing.Size(89, 68);
            this.n6.TabIndex = 6;
            this.n6.Text = "6";
            this.n6.UseVisualStyleBackColor = true;
            this.n6.Click += new System.EventHandler(this.n6_Click);
            // 
            // n7
            // 
            this.n7.Location = new System.Drawing.Point(12, 294);
            this.n7.Name = "n7";
            this.n7.Size = new System.Drawing.Size(85, 68);
            this.n7.TabIndex = 7;
            this.n7.Text = "7";
            this.n7.UseVisualStyleBackColor = true;
            this.n7.Click += new System.EventHandler(this.n7_Click);
            // 
            // n8
            // 
            this.n8.Location = new System.Drawing.Point(132, 294);
            this.n8.Name = "n8";
            this.n8.Size = new System.Drawing.Size(90, 68);
            this.n8.TabIndex = 8;
            this.n8.Text = "8";
            this.n8.UseVisualStyleBackColor = true;
            this.n8.Click += new System.EventHandler(this.n8_Click);
            // 
            // n9
            // 
            this.n9.Location = new System.Drawing.Point(250, 294);
            this.n9.Name = "n9";
            this.n9.Size = new System.Drawing.Size(89, 68);
            this.n9.TabIndex = 9;
            this.n9.Text = "9";
            this.n9.UseVisualStyleBackColor = true;
            this.n9.Click += new System.EventHandler(this.n9_Click);
            // 
            // n0
            // 
            this.n0.Location = new System.Drawing.Point(12, 400);
            this.n0.Name = "n0";
            this.n0.Size = new System.Drawing.Size(85, 68);
            this.n0.TabIndex = 10;
            this.n0.Text = "0";
            this.n0.UseVisualStyleBackColor = true;
            this.n0.Click += new System.EventHandler(this.n0_Click);
            // 
            // nPoint
            // 
            this.nPoint.Location = new System.Drawing.Point(137, 400);
            this.nPoint.Name = "nPoint";
            this.nPoint.Size = new System.Drawing.Size(85, 68);
            this.nPoint.TabIndex = 11;
            this.nPoint.Text = ".";
            this.nPoint.UseVisualStyleBackColor = true;
            this.nPoint.Click += new System.EventHandler(this.nPoint_Click_1);
            // 
            // nEquals
            // 
            this.nEquals.Location = new System.Drawing.Point(254, 402);
            this.nEquals.Name = "nEquals";
            this.nEquals.Size = new System.Drawing.Size(85, 68);
            this.nEquals.TabIndex = 12;
            this.nEquals.Text = "=";
            this.nEquals.UseVisualStyleBackColor = true;
            this.nEquals.Click += new System.EventHandler(this.nEquals_Click);
            // 
            // nDivide
            // 
            this.nDivide.Location = new System.Drawing.Point(368, 115);
            this.nDivide.Name = "nDivide";
            this.nDivide.Size = new System.Drawing.Size(85, 68);
            this.nDivide.TabIndex = 13;
            this.nDivide.Text = "/";
            this.nDivide.UseVisualStyleBackColor = true;
            this.nDivide.Click += new System.EventHandler(this.nDivide_Click);
            // 
            // nMultiply
            // 
            this.nMultiply.Location = new System.Drawing.Point(368, 198);
            this.nMultiply.Name = "nMultiply";
            this.nMultiply.Size = new System.Drawing.Size(85, 68);
            this.nMultiply.TabIndex = 14;
            this.nMultiply.Text = "*";
            this.nMultiply.UseVisualStyleBackColor = true;
            this.nMultiply.Click += new System.EventHandler(this.nMultiply_Click);
            // 
            // nMinus
            // 
            this.nMinus.Location = new System.Drawing.Point(368, 294);
            this.nMinus.Name = "nMinus";
            this.nMinus.Size = new System.Drawing.Size(85, 68);
            this.nMinus.TabIndex = 15;
            this.nMinus.Text = "-";
            this.nMinus.UseVisualStyleBackColor = true;
            this.nMinus.Click += new System.EventHandler(this.nMinus_Click);
            // 
            // nPlus
            // 
            this.nPlus.Location = new System.Drawing.Point(368, 402);
            this.nPlus.Name = "nPlus";
            this.nPlus.Size = new System.Drawing.Size(85, 68);
            this.nPlus.TabIndex = 16;
            this.nPlus.Text = "+";
            this.nPlus.UseVisualStyleBackColor = true;
            this.nPlus.Click += new System.EventHandler(this.nPlus_Click);
            // 
            // operationsHistoryListBox
            // 
            this.operationsHistoryListBox.FormattingEnabled = true;
            this.operationsHistoryListBox.Location = new System.Drawing.Point(579, 115);
            this.operationsHistoryListBox.Name = "operationsHistoryListBox";
            this.operationsHistoryListBox.Size = new System.Drawing.Size(298, 355);
            this.operationsHistoryListBox.TabIndex = 17;
            this.operationsHistoryListBox.SelectedIndexChanged += new System.EventHandler(this.operationsHistoryListBox_SelectedIndexChanged);
            // 
            // clear_btn
            // 
            this.clear_btn.Location = new System.Drawing.Point(480, 115);
            this.clear_btn.Name = "clear_btn";
            this.clear_btn.Size = new System.Drawing.Size(76, 67);
            this.clear_btn.TabIndex = 18;
            this.clear_btn.Text = "C";
            this.clear_btn.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(905, 545);
            this.Controls.Add(this.clear_btn);
            this.Controls.Add(this.operationsHistoryListBox);
            this.Controls.Add(this.nPlus);
            this.Controls.Add(this.nMinus);
            this.Controls.Add(this.nMultiply);
            this.Controls.Add(this.nDivide);
            this.Controls.Add(this.nEquals);
            this.Controls.Add(this.nPoint);
            this.Controls.Add(this.n0);
            this.Controls.Add(this.n9);
            this.Controls.Add(this.n8);
            this.Controls.Add(this.n7);
            this.Controls.Add(this.n6);
            this.Controls.Add(this.n5);
            this.Controls.Add(this.n4);
            this.Controls.Add(this.n3);
            this.Controls.Add(this.n2);
            this.Controls.Add(this.n1);
            this.Controls.Add(this.resultTextBox);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox resultTextBox;
        private System.Windows.Forms.Button n1;
        private System.Windows.Forms.Button n2;
        private System.Windows.Forms.Button n3;
        private System.Windows.Forms.Button n4;
        private System.Windows.Forms.Button n5;
        private System.Windows.Forms.Button n6;
        private System.Windows.Forms.Button n7;
        private System.Windows.Forms.Button n8;
        private System.Windows.Forms.Button n9;
        private System.Windows.Forms.Button n0;
        private System.Windows.Forms.Button nPoint;
        private System.Windows.Forms.Button nEquals;
        private System.Windows.Forms.Button nDivide;
        private System.Windows.Forms.Button nMultiply;
        private System.Windows.Forms.Button nMinus;
        private System.Windows.Forms.Button nPlus;
        private ListBox operationsHistoryListBox;
        private Button clear_btn;
    }
}

