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
            Exit = new Button();
            timer1 = new System.Windows.Forms.Timer(components);
            logo = new PictureBox();
            questionLabel = new Label();
            option2 = new Button();
            timeLabel = new Label();
            option4 = new Button();
            questionCountLabel = new Label();
            questionCountBox = new Label();
            scoreLabel = new Label();
            scoreBox = new Label();
            option1 = new Button();
            option3 = new Button();
            timer = new PictureBox();
            ((System.ComponentModel.ISupportInitialize)logo).BeginInit();
            ((System.ComponentModel.ISupportInitialize)timer).BeginInit();
            SuspendLayout();
            // 
            // Exit
            // 
            Exit.BackColor = Color.Transparent;
            Exit.BackgroundImage = (Image)resources.GetObject("Exit.BackgroundImage");
            Exit.BackgroundImageLayout = ImageLayout.Stretch;
            Exit.FlatStyle = FlatStyle.Flat;
            Exit.ForeColor = SystemColors.ControlText;
            Exit.Location = new Point(12, 376);
            Exit.Name = "Exit";
            Exit.Size = new Size(44, 44);
            Exit.TabIndex = 3;
            Exit.UseVisualStyleBackColor = false;
            Exit.Click += Exit_Click;
            // 
            // timer1
            // 
            timer1.Tick += timer_Tick;
            // 
            // logo
            // 
            logo.BackColor = Color.Transparent;
            logo.BackgroundImage = (Image)resources.GetObject("logo.BackgroundImage");
            logo.BackgroundImageLayout = ImageLayout.Stretch;
            logo.Location = new Point(275, 99);
            logo.Name = "logo";
            logo.Size = new Size(256, 159);
            logo.TabIndex = 4;
            logo.TabStop = false;
            // 
            // questionLabel
            // 
            questionLabel.AutoSize = true;
            questionLabel.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            questionLabel.Location = new Point(142, 34);
            questionLabel.Name = "questionLabel";
            questionLabel.Size = new Size(536, 62);
            questionLabel.TabIndex = 29;
            questionLabel.Text = "                                                                                   \r\n                                                                                       ";
            // 
            // option2
            // 
            option2.BackColor = Color.Blue;
            option2.Location = new Point(420, 253);
            option2.Name = "option2";
            option2.Size = new Size(270, 72);
            option2.TabIndex = 31;
            option2.Text = "Option 2";
            option2.UseVisualStyleBackColor = false;
            option2.Click += option2_Click;
            // 
            // timeLabel
            // 
            timeLabel.AutoSize = true;
            timeLabel.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            timeLabel.Location = new Point(705, 99);
            timeLabel.Name = "timeLabel";
            timeLabel.Size = new Size(62, 31);
            timeLabel.TabIndex = 34;
            timeLabel.Text = "        ";
            // 
            // option4
            // 
            option4.BackColor = Color.Green;
            option4.Location = new Point(420, 330);
            option4.Name = "option4";
            option4.Size = new Size(270, 72);
            option4.TabIndex = 39;
            option4.Text = "Option 4";
            option4.UseVisualStyleBackColor = false;
            option4.Click += option4_Click;
            // 
            // questionCountLabel
            // 
            questionCountLabel.AutoSize = true;
            questionCountLabel.BackColor = Color.Transparent;
            questionCountLabel.Font = new Font("Showcard Gothic", 9F, FontStyle.Regular, GraphicsUnit.Point);
            questionCountLabel.Location = new Point(324, 9);
            questionCountLabel.Name = "questionCountLabel";
            questionCountLabel.Size = new Size(90, 18);
            questionCountLabel.TabIndex = 42;
            questionCountLabel.Text = "Question: ";
            // 
            // questionCountBox
            // 
            questionCountBox.AutoSize = true;
            questionCountBox.Font = new Font("Segoe UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            questionCountBox.Location = new Point(414, 7);
            questionCountBox.Name = "questionCountBox";
            questionCountBox.Size = new Size(41, 20);
            questionCountBox.TabIndex = 43;
            questionCountBox.Text = "        ";
            // 
            // scoreLabel
            // 
            scoreLabel.AutoSize = true;
            scoreLabel.BackColor = Color.Transparent;
            scoreLabel.Font = new Font("Showcard Gothic", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            scoreLabel.Location = new Point(3, 105);
            scoreLabel.Name = "scoreLabel";
            scoreLabel.Size = new Size(71, 21);
            scoreLabel.TabIndex = 44;
            scoreLabel.Text = "Score: ";
            // 
            // scoreBox
            // 
            scoreBox.AutoSize = true;
            scoreBox.Font = new Font("Segoe UI", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            scoreBox.Location = new Point(69, 103);
            scoreBox.Name = "scoreBox";
            scoreBox.Size = new Size(65, 23);
            scoreBox.TabIndex = 45;
            scoreBox.Text = "           ";
            // 
            // option1
            // 
            option1.BackColor = Color.Red;
            option1.Location = new Point(126, 253);
            option1.Name = "option1";
            option1.Size = new Size(270, 72);
            option1.TabIndex = 46;
            option1.Text = "Option 1";
            option1.UseVisualStyleBackColor = false;
            option1.Click += option1_Click;
            // 
            // option3
            // 
            option3.BackColor = Color.Orange;
            option3.Location = new Point(126, 330);
            option3.Name = "option3";
            option3.Size = new Size(270, 72);
            option3.TabIndex = 47;
            option3.Text = "Option 3";
            option3.UseVisualStyleBackColor = false;
            option3.Click += option3_Click;
            // 
            // timer
            // 
            timer.BackColor = Color.Transparent;
            timer.BackgroundImage = (Image)resources.GetObject("timer.BackgroundImage");
            timer.BackgroundImageLayout = ImageLayout.Stretch;
            timer.Location = new Point(707, 42);
            timer.Name = "timer";
            timer.Size = new Size(59, 54);
            timer.TabIndex = 48;
            timer.TabStop = false;
            // 
            // gameQuestionForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(timer);
            Controls.Add(option3);
            Controls.Add(option1);
            Controls.Add(scoreBox);
            Controls.Add(scoreLabel);
            Controls.Add(questionCountBox);
            Controls.Add(questionCountLabel);
            Controls.Add(option4);
            Controls.Add(timeLabel);
            Controls.Add(option2);
            Controls.Add(questionLabel);
            Controls.Add(logo);
            Controls.Add(Exit);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "gameQuestionForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            Load += gameQuestionForm_Load;
            ((System.ComponentModel.ISupportInitialize)logo).EndInit();
            ((System.ComponentModel.ISupportInitialize)timer).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private Button Exit;
        private System.Windows.Forms.Timer timer1;
        private PictureBox logo;
        private Label questionLabel;
        private Button option2;
        private Label timeLabel;
        private Button option4;
        private Label questionCountLabel;
        private Label questionCountBox;
        private Label scoreLabel;
        private Label scoreBox;
        private Button option1;
        private Button option3;
        private PictureBox timer;
    }
}