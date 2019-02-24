namespace Agenda
{
    partial class Form3
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
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.modifyBtn = new System.Windows.Forms.Button();
            this.birthDate = new System.Windows.Forms.DateTimePicker();
            this.descriptionTxtBox = new System.Windows.Forms.TextBox();
            this.emailTxtBox = new System.Windows.Forms.TextBox();
            this.surnameTxtBox = new System.Windows.Forms.TextBox();
            this.nameTxtBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(93, 162);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(66, 13);
            this.label5.TabIndex = 25;
            this.label5.Text = "Date of Birth";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(352, 83);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(60, 13);
            this.label4.TabIndex = 24;
            this.label4.Text = "Description";
            this.label4.Visible = false;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(93, 83);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(32, 13);
            this.label3.TabIndex = 23;
            this.label3.Text = "Email";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(352, 11);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(58, 13);
            this.label1.TabIndex = 22;
            this.label1.Text = "Last Name";
            // 
            // modifyBtn
            // 
            this.modifyBtn.Location = new System.Drawing.Point(96, 261);
            this.modifyBtn.Name = "modifyBtn";
            this.modifyBtn.Size = new System.Drawing.Size(119, 51);
            this.modifyBtn.TabIndex = 20;
            this.modifyBtn.Text = "Modify";
            this.modifyBtn.UseVisualStyleBackColor = true;
            this.modifyBtn.Click += new System.EventHandler(this.modifyBtn_Click);
            // 
            // birthDate
            // 
            this.birthDate.Location = new System.Drawing.Point(93, 188);
            this.birthDate.Name = "birthDate";
            this.birthDate.Size = new System.Drawing.Size(197, 20);
            this.birthDate.TabIndex = 19;
            // 
            // descriptionTxtBox
            // 
            this.descriptionTxtBox.Location = new System.Drawing.Point(355, 102);
            this.descriptionTxtBox.Multiline = true;
            this.descriptionTxtBox.Name = "descriptionTxtBox";
            this.descriptionTxtBox.Size = new System.Drawing.Size(264, 48);
            this.descriptionTxtBox.TabIndex = 18;
            this.descriptionTxtBox.Visible = false;
            // 
            // emailTxtBox
            // 
            this.emailTxtBox.Location = new System.Drawing.Point(93, 102);
            this.emailTxtBox.Name = "emailTxtBox";
            this.emailTxtBox.Size = new System.Drawing.Size(182, 20);
            this.emailTxtBox.TabIndex = 17;
            // 
            // surnameTxtBox
            // 
            this.surnameTxtBox.Location = new System.Drawing.Point(355, 30);
            this.surnameTxtBox.Name = "surnameTxtBox";
            this.surnameTxtBox.Size = new System.Drawing.Size(100, 20);
            this.surnameTxtBox.TabIndex = 16;
            // 
            // nameTxtBox
            // 
            this.nameTxtBox.Location = new System.Drawing.Point(93, 30);
            this.nameTxtBox.Name = "nameTxtBox";
            this.nameTxtBox.Size = new System.Drawing.Size(100, 20);
            this.nameTxtBox.TabIndex = 15;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(93, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(57, 13);
            this.label2.TabIndex = 26;
            this.label2.Text = "First Name";
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(680, 347);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.modifyBtn);
            this.Controls.Add(this.birthDate);
            this.Controls.Add(this.descriptionTxtBox);
            this.Controls.Add(this.emailTxtBox);
            this.Controls.Add(this.surnameTxtBox);
            this.Controls.Add(this.nameTxtBox);
            this.Name = "Form3";
            this.Text = "Form3";
            this.Load += new System.EventHandler(this.Form3_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button modifyBtn;
        private System.Windows.Forms.DateTimePicker birthDate;
        private System.Windows.Forms.TextBox descriptionTxtBox;
        private System.Windows.Forms.TextBox emailTxtBox;
        private System.Windows.Forms.TextBox surnameTxtBox;
        private System.Windows.Forms.TextBox nameTxtBox;
        private System.Windows.Forms.Label label2;
    }
}