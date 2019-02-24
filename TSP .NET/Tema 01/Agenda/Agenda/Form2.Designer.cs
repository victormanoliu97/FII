namespace Agenda
{
    partial class Form2
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
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.button1 = new System.Windows.Forms.Button();
            this.nameTxtBox = new System.Windows.Forms.TextBox();
            this.surnameTxtBox = new System.Windows.Forms.TextBox();
            this.emailTxtBox = new System.Windows.Forms.TextBox();
            this.descriptionTxtBox = new System.Windows.Forms.TextBox();
            this.birthDate = new System.Windows.Forms.DateTimePicker();
            this.modifyBtn = new System.Windows.Forms.Button();
            this.deleteBtn = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(2, 30);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(170, 420);
            this.listBox1.TabIndex = 0;
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(2, 1);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(131, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "Bring Contacts";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // nameTxtBox
            // 
            this.nameTxtBox.Location = new System.Drawing.Point(218, 30);
            this.nameTxtBox.Name = "nameTxtBox";
            this.nameTxtBox.Size = new System.Drawing.Size(100, 20);
            this.nameTxtBox.TabIndex = 2;
            this.nameTxtBox.Visible = false;
            // 
            // surnameTxtBox
            // 
            this.surnameTxtBox.Location = new System.Drawing.Point(480, 30);
            this.surnameTxtBox.Name = "surnameTxtBox";
            this.surnameTxtBox.Size = new System.Drawing.Size(100, 20);
            this.surnameTxtBox.TabIndex = 3;
            this.surnameTxtBox.Visible = false;
            // 
            // emailTxtBox
            // 
            this.emailTxtBox.Location = new System.Drawing.Point(218, 102);
            this.emailTxtBox.Name = "emailTxtBox";
            this.emailTxtBox.Size = new System.Drawing.Size(182, 20);
            this.emailTxtBox.TabIndex = 4;
            this.emailTxtBox.Visible = false;
            // 
            // descriptionTxtBox
            // 
            this.descriptionTxtBox.Location = new System.Drawing.Point(480, 102);
            this.descriptionTxtBox.Name = "descriptionTxtBox";
            this.descriptionTxtBox.Size = new System.Drawing.Size(232, 20);
            this.descriptionTxtBox.TabIndex = 5;
            this.descriptionTxtBox.Visible = false;
            // 
            // birthDate
            // 
            this.birthDate.Enabled = false;
            this.birthDate.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.birthDate.Location = new System.Drawing.Point(218, 188);
            this.birthDate.Name = "birthDate";
            this.birthDate.Size = new System.Drawing.Size(197, 20);
            this.birthDate.TabIndex = 7;
            this.birthDate.Visible = false;
            // 
            // modifyBtn
            // 
            this.modifyBtn.Location = new System.Drawing.Point(218, 285);
            this.modifyBtn.Name = "modifyBtn";
            this.modifyBtn.Size = new System.Drawing.Size(119, 51);
            this.modifyBtn.TabIndex = 8;
            this.modifyBtn.Text = "Modify";
            this.modifyBtn.UseVisualStyleBackColor = true;
            this.modifyBtn.Visible = false;
            this.modifyBtn.Click += new System.EventHandler(this.modifyBtn_Click);
            // 
            // deleteBtn
            // 
            this.deleteBtn.Location = new System.Drawing.Point(429, 285);
            this.deleteBtn.Name = "deleteBtn";
            this.deleteBtn.Size = new System.Drawing.Size(119, 51);
            this.deleteBtn.TabIndex = 9;
            this.deleteBtn.Text = "Delete";
            this.deleteBtn.UseVisualStyleBackColor = true;
            this.deleteBtn.Visible = false;
            this.deleteBtn.Click += new System.EventHandler(this.deleteBtn_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(477, 11);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(58, 13);
            this.label1.TabIndex = 10;
            this.label1.Text = "Last Name";
            this.label1.Visible = false;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(215, 6);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(57, 13);
            this.label2.TabIndex = 11;
            this.label2.Text = "First Name";
            this.label2.Visible = false;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(218, 83);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(32, 13);
            this.label3.TabIndex = 12;
            this.label3.Text = "Email";
            this.label3.Visible = false;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(477, 83);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(60, 13);
            this.label4.TabIndex = 13;
            this.label4.Text = "Description";
            this.label4.Visible = false;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(218, 162);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(66, 13);
            this.label5.TabIndex = 14;
            this.label5.Text = "Date of Birth";
            this.label5.Visible = false;
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.deleteBtn);
            this.Controls.Add(this.modifyBtn);
            this.Controls.Add(this.birthDate);
            this.Controls.Add(this.descriptionTxtBox);
            this.Controls.Add(this.emailTxtBox);
            this.Controls.Add(this.surnameTxtBox);
            this.Controls.Add(this.nameTxtBox);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.listBox1);
            this.Name = "Form2";
            this.Text = "Form2";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox nameTxtBox;
        private System.Windows.Forms.TextBox surnameTxtBox;
        private System.Windows.Forms.TextBox emailTxtBox;
        private System.Windows.Forms.TextBox descriptionTxtBox;
        private System.Windows.Forms.DateTimePicker birthDate;
        private System.Windows.Forms.Button modifyBtn;
        private System.Windows.Forms.Button deleteBtn;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
    }
}