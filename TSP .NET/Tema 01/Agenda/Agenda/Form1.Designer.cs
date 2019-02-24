namespace Agenda
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
            this.nameTxtBox = new System.Windows.Forms.TextBox();
            this.surnameTxtBox = new System.Windows.Forms.TextBox();
            this.emailTxtBox = new System.Windows.Forms.TextBox();
            this.descriptionTxtBox = new System.Windows.Forms.TextBox();
            this.submitBtn = new System.Windows.Forms.Button();
            this.nameLabel = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.birthPicker = new System.Windows.Forms.DateTimePicker();
            this.SuspendLayout();
            // 
            // nameTxtBox
            // 
            this.nameTxtBox.Location = new System.Drawing.Point(173, 38);
            this.nameTxtBox.Name = "nameTxtBox";
            this.nameTxtBox.Size = new System.Drawing.Size(100, 20);
            this.nameTxtBox.TabIndex = 0;
            // 
            // surnameTxtBox
            // 
            this.surnameTxtBox.Location = new System.Drawing.Point(173, 93);
            this.surnameTxtBox.Name = "surnameTxtBox";
            this.surnameTxtBox.Size = new System.Drawing.Size(100, 20);
            this.surnameTxtBox.TabIndex = 1;
            // 
            // emailTxtBox
            // 
            this.emailTxtBox.Location = new System.Drawing.Point(173, 156);
            this.emailTxtBox.Name = "emailTxtBox";
            this.emailTxtBox.Size = new System.Drawing.Size(149, 20);
            this.emailTxtBox.TabIndex = 2;
            // 
            // descriptionTxtBox
            // 
            this.descriptionTxtBox.Location = new System.Drawing.Point(396, 92);
            this.descriptionTxtBox.Multiline = true;
            this.descriptionTxtBox.Name = "descriptionTxtBox";
            this.descriptionTxtBox.Size = new System.Drawing.Size(200, 40);
            this.descriptionTxtBox.TabIndex = 4;
            // 
            // submitBtn
            // 
            this.submitBtn.Location = new System.Drawing.Point(257, 219);
            this.submitBtn.Name = "submitBtn";
            this.submitBtn.Size = new System.Drawing.Size(193, 41);
            this.submitBtn.TabIndex = 5;
            this.submitBtn.Text = "Submit";
            this.submitBtn.UseVisualStyleBackColor = true;
            this.submitBtn.Click += new System.EventHandler(this.submitBtn_Click);
            // 
            // nameLabel
            // 
            this.nameLabel.AutoSize = true;
            this.nameLabel.Location = new System.Drawing.Point(170, 22);
            this.nameLabel.Name = "nameLabel";
            this.nameLabel.Size = new System.Drawing.Size(57, 13);
            this.nameLabel.TabIndex = 6;
            this.nameLabel.Text = "First Name";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(173, 74);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(58, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "Last Name";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(176, 140);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(32, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "Email";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(396, 13);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(66, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "Date of Birth";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(399, 74);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(60, 13);
            this.label4.TabIndex = 10;
            this.label4.Text = "Description";
            // 
            // birthPicker
            // 
            this.birthPicker.CustomFormat = "MM/yyyy";
            this.birthPicker.Location = new System.Drawing.Point(396, 35);
            this.birthPicker.Name = "birthPicker";
            this.birthPicker.Size = new System.Drawing.Size(200, 20);
            this.birthPicker.TabIndex = 3;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.nameLabel);
            this.Controls.Add(this.submitBtn);
            this.Controls.Add(this.descriptionTxtBox);
            this.Controls.Add(this.birthPicker);
            this.Controls.Add(this.emailTxtBox);
            this.Controls.Add(this.surnameTxtBox);
            this.Controls.Add(this.nameTxtBox);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox nameTxtBox;
        private System.Windows.Forms.TextBox surnameTxtBox;
        private System.Windows.Forms.TextBox emailTxtBox;
        private System.Windows.Forms.TextBox descriptionTxtBox;
        private System.Windows.Forms.Button submitBtn;
        private System.Windows.Forms.Label nameLabel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.DateTimePicker birthPicker;
    }
}

