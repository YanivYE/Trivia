namespace TriviaGUI
{
    partial class gameQuestionForm
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
            components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(gameQuestionForm));
            button3 = new Button();
            timer1 = new System.Windows.Forms.Timer(components);
            pictureBox2 = new PictureBox();
            label6 = new Label();
            button2 = new Button();
            label5 = new Label();
            button4 = new Button();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            button1 = new Button();
            button5 = new Button();
            pictureBox1 = new PictureBox();
            ((System.ComponentModel.ISupportInitialize)pictureBox2).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            SuspendLayout();
            // 
            // button3
            // 
            button3.BackColor = Color.Transparent;
            button3.BackgroundImage = (Image)resources.GetObject("button3.BackgroundImage");
            button3.BackgroundImageLayout = ImageLayout.Stretch;
            button3.FlatStyle = FlatStyle.Flat;
            button3.ForeColor = SystemColors.ControlText;
            button3.Location = new Point(12, 376);
            button3.Name = "button3";
            button3.Size = new Size(44, 44);
            button3.TabIndex = 3;
            button3.UseVisualStyleBackColor = false;
            // 
            // timer1
            // 
            timer1.Tick += timer1_Tick;
            // 
            // pictureBox2
            // 
            pictureBox2.BackColor = Color.Transparent;
            pictureBox2.BackgroundImage = (Image)resources.GetObject("pictureBox2.BackgroundImage");
            pictureBox2.BackgroundImageLayout = ImageLayout.Stretch;
            pictureBox2.Location = new Point(278, 101);
            pictureBox2.Name = "pictureBox2";
            pictureBox2.Size = new Size(256, 148);
            pictureBox2.TabIndex = 4;
            pictureBox2.TabStop = false;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label6.Location = new Point(142, 34);
            label6.Name = "label6";
            label6.Size = new Size(536, 62);
            label6.TabIndex = 29;
            label6.Text = "                                                                                   \r\n                                                                                       ";
            // 
            // button2
            // 
            button2.BackColor = Color.Blue;
            button2.Location = new Point(420, 253);
            button2.Name = "button2";
            button2.Size = new Size(270, 72);
            button2.TabIndex = 31;
            button2.Text = "Option 2";
            button2.UseVisualStyleBackColor = false;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label5.Location = new Point(705, 99);
            label5.Name = "label5";
            label5.Size = new Size(62, 31);
            label5.TabIndex = 34;
            label5.Text = "        ";
            // 
            // button4
            // 
            button4.BackColor = Color.Green;
            button4.Location = new Point(420, 330);
            button4.Name = "button4";
            button4.Size = new Size(270, 72);
            button4.TabIndex = 39;
            button4.Text = "Option 4";
            button4.UseVisualStyleBackColor = false;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Transparent;
            label1.Font = new Font("Showcard Gothic", 9F, FontStyle.Regular, GraphicsUnit.Point);
            label1.Location = new Point(324, 9);
            label1.Name = "label1";
            label1.Size = new Size(90, 18);
            label1.TabIndex = 42;
            label1.Text = "Question: ";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            label2.Location = new Point(414, 7);
            label2.Name = "label2";
            label2.Size = new Size(41, 20);
            label2.TabIndex = 43;
            label2.Text = "        ";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.BackColor = Color.Transparent;
            label3.Font = new Font("Showcard Gothic", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label3.Location = new Point(3, 105);
            label3.Name = "label3";
            label3.Size = new Size(71, 21);
            label3.TabIndex = 44;
            label3.Text = "Score: ";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label4.Location = new Point(69, 103);
            label4.Name = "label4";
            label4.Size = new Size(65, 23);
            label4.TabIndex = 45;
            label4.Text = "           ";
            // 
            // button1
            // 
            button1.BackColor = Color.Red;
            button1.Location = new Point(126, 253);
            button1.Name = "button1";
            button1.Size = new Size(270, 72);
            button1.TabIndex = 46;
            button1.Text = "Option 1";
            button1.UseVisualStyleBackColor = false;
            // 
            // button5
            // 
            button5.BackColor = Color.Orange;
            button5.Location = new Point(126, 330);
            button5.Name = "button5";
            button5.Size = new Size(270, 72);
            button5.TabIndex = 47;
            button5.Text = "Option 3";
            button5.UseVisualStyleBackColor = false;
            // 
            // pictureBox1
            // 
            pictureBox1.BackColor = Color.Transparent;
            pictureBox1.BackgroundImage = (Image)resources.GetObject("pictureBox1.BackgroundImage");
            pictureBox1.BackgroundImageLayout = ImageLayout.Stretch;
            pictureBox1.Location = new Point(707, 42);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(59, 54);
            pictureBox1.TabIndex = 48;
            pictureBox1.TabStop = false;
            // 
            // gameQuestionForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(pictureBox1);
            Controls.Add(button5);
            Controls.Add(button1);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(button4);
            Controls.Add(label5);
            Controls.Add(button2);
            Controls.Add(label6);
            Controls.Add(pictureBox2);
            Controls.Add(button3);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "gameQuestionForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            ((System.ComponentModel.ISupportInitialize)pictureBox2).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private Button button3;
        private System.Windows.Forms.Timer timer1;
        private PictureBox pictureBox2;
        private Label label6;
        private Button button2;
        private Label label5;
        private Button button4;
        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Button button1;
        private Button button5;
        private PictureBox pictureBox1;
    }
}