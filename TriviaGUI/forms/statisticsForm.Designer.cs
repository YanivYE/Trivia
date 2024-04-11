namespace TriviaGUI
{
    partial class statisticsForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(statisticsForm));
            leaderBoard = new Button();
            myStats = new Button();
            BackArrow = new Button();
            statsLabel = new Label();
            SuspendLayout();
            // 
            // leaderBoard
            // 
            leaderBoard.BackColor = Color.Gold;
            leaderBoard.Font = new Font("Ravie", 10.8F, FontStyle.Regular, GraphicsUnit.Point);
            leaderBoard.Location = new Point(314, 257);
            leaderBoard.Name = "leaderBoard";
            leaderBoard.Size = new Size(187, 79);
            leaderBoard.TabIndex = 4;
            leaderBoard.Text = "LeaderBoard";
            leaderBoard.UseVisualStyleBackColor = false;
            leaderBoard.Click += LeaderBoard_Click;
            // 
            // myStats
            // 
            myStats.BackColor = Color.Gold;
            myStats.Font = new Font("Ravie", 10.8F, FontStyle.Regular, GraphicsUnit.Point);
            myStats.Location = new Point(314, 152);
            myStats.Name = "myStats";
            myStats.Size = new Size(187, 79);
            myStats.TabIndex = 5;
            myStats.Text = "My Stats";
            myStats.UseVisualStyleBackColor = false;
            myStats.Click += MyStats_Click;
            // 
            // BackArrow
            // 
            BackArrow.BackColor = Color.Transparent;
            BackArrow.BackgroundImage = (Image)resources.GetObject("BackArrow.BackgroundImage");
            BackArrow.BackgroundImageLayout = ImageLayout.Stretch;
            BackArrow.FlatStyle = FlatStyle.Flat;
            BackArrow.ForeColor = SystemColors.ControlText;
            BackArrow.Location = new Point(740, 375);
            BackArrow.Name = "BackArrow";
            BackArrow.Size = new Size(44, 44);
            BackArrow.TabIndex = 8;
            BackArrow.UseVisualStyleBackColor = false;
            BackArrow.Click += BackArrow_Click;
            // 
            // statsLabel
            // 
            statsLabel.AutoSize = true;
            statsLabel.BackColor = Color.Gold;
            statsLabel.BorderStyle = BorderStyle.Fixed3D;
            statsLabel.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            statsLabel.ForeColor = Color.Black;
            statsLabel.Location = new Point(283, 74);
            statsLabel.Name = "statsLabel";
            statsLabel.Size = new Size(251, 42);
            statsLabel.TabIndex = 9;
            statsLabel.Text = "STATISTICS";
            statsLabel.Click += statsLabel_Click;
            // 
            // statisticsForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(statsLabel);
            Controls.Add(BackArrow);
            Controls.Add(myStats);
            Controls.Add(leaderBoard);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "statisticsForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            Load += statisticsForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button leaderBoard;
        private Button myStats;
        private Button BackArrow;
        private Label statsLabel;
    }
}