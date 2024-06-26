﻿namespace TriviaGUI
{
    partial class signupForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(signupForm));
            usernameBox = new TextBox();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            passBox = new TextBox();
            mailBox = new TextBox();
            button1 = new Button();
            SuspendLayout();
            // 
            // usernameBox
            // 
            usernameBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            usernameBox.Location = new Point(396, 104);
            usernameBox.Name = "usernameBox";
            usernameBox.Size = new Size(246, 38);
            usernameBox.TabIndex = 2;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.BackColor = Color.Gold;
            label2.Font = new Font("Ravie", 16.2F, FontStyle.Regular, GraphicsUnit.Point);
            label2.Location = new Point(166, 104);
            label2.Name = "label2";
            label2.Size = new Size(214, 38);
            label2.TabIndex = 4;
            label2.Text = "Username:";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.BackColor = Color.Gold;
            label3.Font = new Font("Ravie", 16.2F, FontStyle.Regular, GraphicsUnit.Point);
            label3.Location = new Point(166, 237);
            label3.Name = "label3";
            label3.Size = new Size(113, 38);
            label3.TabIndex = 6;
            label3.Text = "Mail:";
            label3.Click += label3_Click;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.BackColor = Color.Gold;
            label4.Font = new Font("Ravie", 16.2F, FontStyle.Regular, GraphicsUnit.Point);
            label4.Location = new Point(166, 172);
            label4.Name = "label4";
            label4.Size = new Size(214, 38);
            label4.TabIndex = 7;
            label4.Text = "Password:";
            // 
            // passBox
            // 
            passBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            passBox.Location = new Point(396, 172);
            passBox.Name = "passBox";
            passBox.Size = new Size(246, 38);
            passBox.TabIndex = 8;
            // 
            // mailBox
            // 
            mailBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            mailBox.Location = new Point(396, 237);
            mailBox.Name = "mailBox";
            mailBox.Size = new Size(246, 38);
            mailBox.TabIndex = 9;
            // 
            // button1
            // 
            button1.BackColor = Color.Gold;
            button1.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            button1.Location = new Point(318, 316);
            button1.Name = "button1";
            button1.Size = new Size(176, 64);
            button1.TabIndex = 10;
            button1.Text = "Sign Up";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // signupForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(button1);
            Controls.Add(mailBox);
            Controls.Add(passBox);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(usernameBox);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "signupForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            FormClosed += signupForm_Close;
            Load += signupForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label2;
        private Label label3;
        private Label label4;
        private TextBox usernameBox;
        private TextBox passBox;
        private TextBox mailBox;
        private Button button1;
    }
}