namespace TriviaGUI
{
    partial class roomForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(roomForm));
            label12 = new Label();
            button3 = new Button();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            label6 = new Label();
            button1 = new Button();
            label7 = new Label();
            label8 = new Label();
            label9 = new Label();
            SuspendLayout();
            // 
            // label12
            // 
            label12.AutoSize = true;
            label12.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label12.Location = new Point(341, 32);
            label12.Name = "label12";
            label12.Size = new Size(140, 31);
            label12.TabIndex = 21;
            label12.Text = "Room Name";
            // 
            // button3
            // 
            button3.BackColor = Color.Gold;
            button3.Font = new Font("Ravie", 10.8F, FontStyle.Regular, GraphicsUnit.Point);
            button3.Location = new Point(354, 354);
            button3.Name = "button3";
            button3.Size = new Size(109, 45);
            button3.TabIndex = 22;
            button3.Text = "START";
            button3.UseVisualStyleBackColor = false;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Transparent;
            label1.Font = new Font("Showcard Gothic", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label1.Location = new Point(58, 79);
            label1.Name = "label1";
            label1.Size = new Size(228, 21);
            label1.TabIndex = 23;
            label1.Text = "max number of players: ";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.BackColor = Color.Transparent;
            label2.Font = new Font("Showcard Gothic", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label2.Location = new Point(552, 79);
            label2.Name = "label2";
            label2.Size = new Size(178, 21);
            label2.TabIndex = 24;
            label2.Text = "time per question: ";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.BackColor = Color.Transparent;
            label3.Font = new Font("Showcard Gothic", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label3.Location = new Point(310, 79);
            label3.Name = "label3";
            label3.Size = new Size(206, 21);
            label3.TabIndex = 25;
            label3.Text = "number of questions: ";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label4.Location = new Point(133, 110);
            label4.Name = "label4";
            label4.Size = new Size(62, 31);
            label4.TabIndex = 26;
            label4.Text = "        ";
            label4.Click += label4_Click;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label5.Location = new Point(376, 110);
            label5.Name = "label5";
            label5.Size = new Size(62, 31);
            label5.TabIndex = 27;
            label5.Text = "        ";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label6.Location = new Point(605, 110);
            label6.Name = "label6";
            label6.Size = new Size(62, 31);
            label6.TabIndex = 28;
            label6.Text = "        ";
            // 
            // button1
            // 
            button1.BackColor = Color.Red;
            button1.Font = new Font("Ravie", 9F, FontStyle.Regular, GraphicsUnit.Point);
            button1.Location = new Point(690, 12);
            button1.Name = "button1";
            button1.Size = new Size(109, 51);
            button1.TabIndex = 29;
            button1.Text = "CLOSE ROOM";
            button1.UseVisualStyleBackColor = false;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label7.Location = new Point(130, 212);
            label7.Name = "label7";
            label7.Size = new Size(536, 124);
            label7.TabIndex = 30;
            label7.Text = "        \r\n\r\n                                                                       \r\n                                                                                       ";
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label8.Location = new Point(401, 172);
            label8.Name = "label8";
            label8.Size = new Size(116, 31);
            label8.TabIndex = 31;
            label8.Text = "                 ";
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.BackColor = Color.Transparent;
            label9.Font = new Font("Showcard Gothic", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label9.Location = new Point(303, 172);
            label9.Name = "label9";
            label9.Size = new Size(98, 29);
            label9.TabIndex = 32;
            label9.Text = "Admin: ";
            // 
            // roomForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(label9);
            Controls.Add(label8);
            Controls.Add(label7);
            Controls.Add(button1);
            Controls.Add(label6);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(button3);
            Controls.Add(label12);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "roomForm";
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            Load += roomForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label12;
        private Button button3;
        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Label label5;
        private Label label6;
        private Button button1;
        private Label label7;
        private Label label8;
        private Label label9;
    }
}