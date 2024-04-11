namespace TriviaGUI
{
    partial class LeaderBoardForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(LeaderBoardForm));
            medal3 = new PictureBox();
            medal1 = new PictureBox();
            medal2 = new PictureBox();
            leaderboardLabel = new Label();
            first = new Label();
            second = new Label();
            third = new Label();
            BackArrow = new Button();
            ((System.ComponentModel.ISupportInitialize)medal3).BeginInit();
            ((System.ComponentModel.ISupportInitialize)medal1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)medal2).BeginInit();
            SuspendLayout();
            // 
            // medal3
            // 
            medal3.BackColor = Color.LightSeaGreen;
            medal3.BackgroundImage = (Image)resources.GetObject("medal3.BackgroundImage");
            medal3.BackgroundImageLayout = ImageLayout.Center;
            medal3.Location = new Point(170, 322);
            medal3.Name = "medal3";
            medal3.Size = new Size(63, 62);
            medal3.TabIndex = 1;
            medal3.TabStop = false;
            // 
            // medal1
            // 
            medal1.BackColor = Color.LightSeaGreen;
            medal1.BackgroundImage = (Image)resources.GetObject("medal1.BackgroundImage");
            medal1.BackgroundImageLayout = ImageLayout.Stretch;
            medal1.Location = new Point(170, 127);
            medal1.Name = "medal1";
            medal1.Size = new Size(63, 62);
            medal1.TabIndex = 2;
            medal1.TabStop = false;
            // 
            // medal2
            // 
            medal2.BackColor = Color.LightSeaGreen;
            medal2.BackgroundImage = (Image)resources.GetObject("medal2.BackgroundImage");
            medal2.BackgroundImageLayout = ImageLayout.Stretch;
            medal2.Location = new Point(170, 224);
            medal2.Name = "medal2";
            medal2.Size = new Size(63, 62);
            medal2.TabIndex = 3;
            medal2.TabStop = false;
            // 
            // leaderboardLabel
            // 
            leaderboardLabel.AutoSize = true;
            leaderboardLabel.BackColor = Color.Gold;
            leaderboardLabel.BorderStyle = BorderStyle.Fixed3D;
            leaderboardLabel.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            leaderboardLabel.ForeColor = Color.Black;
            leaderboardLabel.Location = new Point(253, 47);
            leaderboardLabel.Name = "leaderboardLabel";
            leaderboardLabel.Size = new Size(313, 42);
            leaderboardLabel.TabIndex = 4;
            leaderboardLabel.Text = "LEADERBOARD";
            // 
            // first
            // 
            first.AutoSize = true;
            first.BackColor = Color.LightSeaGreen;
            first.Font = new Font("Ravie", 36F, FontStyle.Regular, GraphicsUnit.Point);
            first.ForeColor = Color.Black;
            first.Location = new Point(151, 117);
            first.Name = "first";
            first.Size = new Size(515, 81);
            first.TabIndex = 6;
            first.Text = "                    ";
            // 
            // second
            // 
            second.AutoSize = true;
            second.BackColor = Color.LightSeaGreen;
            second.Font = new Font("Ravie", 36F, FontStyle.Regular, GraphicsUnit.Point);
            second.ForeColor = Color.Black;
            second.Location = new Point(151, 215);
            second.Name = "second";
            second.Size = new Size(515, 81);
            second.TabIndex = 7;
            second.Text = "                    ";
            // 
            // third
            // 
            third.AutoSize = true;
            third.BackColor = Color.LightSeaGreen;
            third.Font = new Font("Ravie", 36F, FontStyle.Regular, GraphicsUnit.Point);
            third.ForeColor = Color.Black;
            third.Location = new Point(151, 312);
            third.Name = "third";
            third.Size = new Size(515, 81);
            third.TabIndex = 8;
            third.Text = "                    ";
            // 
            // BackArrow
            // 
            BackArrow.BackColor = Color.Transparent;
            BackArrow.BackgroundImage = (Image)resources.GetObject("BackArrow.BackgroundImage");
            BackArrow.BackgroundImageLayout = ImageLayout.Stretch;
            BackArrow.FlatStyle = FlatStyle.Flat;
            BackArrow.ForeColor = SystemColors.ControlText;
            BackArrow.Location = new Point(737, 372);
            BackArrow.Name = "BackArrow";
            BackArrow.Size = new Size(44, 44);
            BackArrow.TabIndex = 9;
            BackArrow.UseVisualStyleBackColor = false;
            BackArrow.Click += BackArrow_Click;
            // 
            // LeaderBoardForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(BackArrow);
            Controls.Add(medal3);
            Controls.Add(medal2);
            Controls.Add(third);
            Controls.Add(second);
            Controls.Add(medal1);
            Controls.Add(first);
            Controls.Add(leaderboardLabel);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "LeaderBoardForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            Load += LeaderBoardForm_Load;
            ((System.ComponentModel.ISupportInitialize)medal3).EndInit();
            ((System.ComponentModel.ISupportInitialize)medal1).EndInit();
            ((System.ComponentModel.ISupportInitialize)medal2).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private PictureBox medal3;
        private PictureBox medal1;
        private PictureBox medal2;
        private Label leaderboardLabel;
        private Label first;
        private Label second;
        private Label third;
        private Button BackArrow;
    }
}