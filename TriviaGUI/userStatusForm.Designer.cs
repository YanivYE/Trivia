namespace TriviaGUI
{
    partial class userStatusForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(userStatusForm));
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            button3 = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Gold;
            label1.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            label1.ForeColor = Color.Black;
            label1.Location = new Point(301, 46);
            label1.Name = "label1";
            label1.Size = new Size(223, 40);
            label1.TabIndex = 5;
            label1.Text = "MY STATS";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.BackColor = Color.RoyalBlue;
            label2.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            label2.ForeColor = Color.Black;
            label2.Location = new Point(145, 165);
            label2.Name = "label2";
            label2.Size = new Size(333, 40);
            label2.TabIndex = 6;
            label2.Text = "Right Answers:";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.BackColor = Color.RoyalBlue;
            label3.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            label3.ForeColor = Color.Black;
            label3.Location = new Point(145, 108);
            label3.Name = "label3";
            label3.Size = new Size(304, 40);
            label3.TabIndex = 7;
            label3.Text = "Games Played:";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.BackColor = Color.RoyalBlue;
            label4.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            label4.ForeColor = Color.Black;
            label4.Location = new Point(145, 293);
            label4.Name = "label4";
            label4.Size = new Size(384, 80);
            label4.TabIndex = 8;
            label4.Text = "Average time per \r\nanswer:";
            label4.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.BackColor = Color.RoyalBlue;
            label5.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            label5.ForeColor = Color.Black;
            label5.Location = new Point(145, 228);
            label5.Name = "label5";
            label5.Size = new Size(345, 40);
            label5.TabIndex = 9;
            label5.Text = "Wrong Answers:";
            // 
            // button3
            // 
            button3.BackColor = Color.Transparent;
            button3.BackgroundImage = (Image)resources.GetObject("button3.BackgroundImage");
            button3.BackgroundImageLayout = ImageLayout.Stretch;
            button3.FlatStyle = FlatStyle.Flat;
            button3.ForeColor = SystemColors.ControlText;
            button3.Location = new Point(737, 373);
            button3.Name = "button3";
            button3.Size = new Size(44, 44);
            button3.TabIndex = 10;
            button3.UseVisualStyleBackColor = false;
            // 
            // userStatusForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(button3);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "userStatusForm";
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Label label5;
        private Button button3;
    }
}