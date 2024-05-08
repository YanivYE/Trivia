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
            statsLabel = new Label();
            rightAnswersLabel = new Label();
            gamesPlayedLabel = new Label();
            avgTimeLabel = new Label();
            wrongAnswersLabel = new Label();
            BackArrow = new Button();
            avgTimeBox = new Label();
            wrongAnswersBox = new Label();
            rightAnswersBox = new Label();
            gamesPlayedBox = new Label();
            SuspendLayout();
            // 
            // statsLabel
            // 
            statsLabel.AutoSize = true;
            statsLabel.BackColor = Color.Gold;
            statsLabel.BorderStyle = BorderStyle.Fixed3D;
            statsLabel.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            statsLabel.ForeColor = Color.Black;
            statsLabel.Location = new Point(301, 46);
            statsLabel.Name = "statsLabel";
            statsLabel.Size = new Size(225, 42);
            statsLabel.TabIndex = 5;
            statsLabel.Text = "MY STATS";
            // 
            // rightAnswersLabel
            // 
            rightAnswersLabel.AutoSize = true;
            rightAnswersLabel.BackColor = Color.Gold;
            rightAnswersLabel.Font = new Font("Ravie", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            rightAnswersLabel.ForeColor = Color.Black;
            rightAnswersLabel.Location = new Point(145, 180);
            rightAnswersLabel.Name = "rightAnswersLabel";
            rightAnswersLabel.Size = new Size(255, 32);
            rightAnswersLabel.TabIndex = 6;
            rightAnswersLabel.Text = "Right Answers:";
            // 
            // gamesPlayedLabel
            // 
            gamesPlayedLabel.AutoSize = true;
            gamesPlayedLabel.BackColor = Color.Gold;
            gamesPlayedLabel.Font = new Font("Ravie", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            gamesPlayedLabel.ForeColor = Color.Black;
            gamesPlayedLabel.Location = new Point(145, 119);
            gamesPlayedLabel.Name = "gamesPlayedLabel";
            gamesPlayedLabel.Size = new Size(234, 32);
            gamesPlayedLabel.TabIndex = 7;
            gamesPlayedLabel.Text = "Games Played:";
            // 
            // avgTimeLabel
            // 
            avgTimeLabel.AutoSize = true;
            avgTimeLabel.BackColor = Color.Gold;
            avgTimeLabel.Font = new Font("Ravie", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            avgTimeLabel.ForeColor = Color.Black;
            avgTimeLabel.Location = new Point(145, 301);
            avgTimeLabel.Name = "avgTimeLabel";
            avgTimeLabel.Size = new Size(419, 32);
            avgTimeLabel.TabIndex = 8;
            avgTimeLabel.Text = "Average time per answer:";
            avgTimeLabel.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // wrongAnswersLabel
            // 
            wrongAnswersLabel.AutoSize = true;
            wrongAnswersLabel.BackColor = Color.Gold;
            wrongAnswersLabel.Font = new Font("Ravie", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            wrongAnswersLabel.ForeColor = Color.Black;
            wrongAnswersLabel.Location = new Point(145, 241);
            wrongAnswersLabel.Name = "wrongAnswersLabel";
            wrongAnswersLabel.Size = new Size(266, 32);
            wrongAnswersLabel.TabIndex = 9;
            wrongAnswersLabel.Text = "Wrong Answers:";
            // 
            // BackArrow
            // 
            BackArrow.BackColor = Color.Transparent;
            BackArrow.BackgroundImage = (Image)resources.GetObject("BackArrow.BackgroundImage");
            BackArrow.BackgroundImageLayout = ImageLayout.Stretch;
            BackArrow.FlatStyle = FlatStyle.Flat;
            BackArrow.ForeColor = SystemColors.ControlText;
            BackArrow.Location = new Point(737, 373);
            BackArrow.Name = "BackArrow";
            BackArrow.Size = new Size(44, 44);
            BackArrow.TabIndex = 10;
            BackArrow.UseVisualStyleBackColor = false;
            BackArrow.Click += BackArrow_Click;
            // 
            // avgTimeBox
            // 
            avgTimeBox.AutoSize = true;
            avgTimeBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            avgTimeBox.Location = new Point(586, 302);
            avgTimeBox.Name = "avgTimeBox";
            avgTimeBox.Size = new Size(98, 31);
            avgTimeBox.TabIndex = 18;
            avgTimeBox.Text = "              ";
            // 
            // wrongAnswersBox
            // 
            wrongAnswersBox.AutoSize = true;
            wrongAnswersBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            wrongAnswersBox.Location = new Point(586, 242);
            wrongAnswersBox.Name = "wrongAnswersBox";
            wrongAnswersBox.Size = new Size(98, 31);
            wrongAnswersBox.TabIndex = 19;
            wrongAnswersBox.Text = "              ";
            // 
            // rightAnswersBox
            // 
            rightAnswersBox.AutoSize = true;
            rightAnswersBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            rightAnswersBox.Location = new Point(586, 181);
            rightAnswersBox.Name = "rightAnswersBox";
            rightAnswersBox.Size = new Size(98, 31);
            rightAnswersBox.TabIndex = 20;
            rightAnswersBox.Text = "              ";
            // 
            // gamesPlayedBox
            // 
            gamesPlayedBox.AutoSize = true;
            gamesPlayedBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            gamesPlayedBox.Location = new Point(586, 120);
            gamesPlayedBox.Name = "gamesPlayedBox";
            gamesPlayedBox.Size = new Size(98, 31);
            gamesPlayedBox.TabIndex = 21;
            gamesPlayedBox.Text = "              ";
            // 
            // userStatusForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(gamesPlayedBox);
            Controls.Add(rightAnswersBox);
            Controls.Add(wrongAnswersBox);
            Controls.Add(avgTimeBox);
            Controls.Add(BackArrow);
            Controls.Add(wrongAnswersLabel);
            Controls.Add(avgTimeLabel);
            Controls.Add(gamesPlayedLabel);
            Controls.Add(rightAnswersLabel);
            Controls.Add(statsLabel);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "userStatusForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            Load += userStatusForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label statsLabel;
        private Label rightAnswersLabel;
        private Label gamesPlayedLabel;
        private Label avgTimeLabel;
        private Label wrongAnswersLabel;
        private Button BackArrow;
        private Label avgTimeBox;
        private Label wrongAnswersBox;
        private Label rightAnswersBox;
        private Label gamesPlayedBox;
    }
}