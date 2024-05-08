namespace TriviaGUI
{
    partial class scoresForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(scoresForm));
            winnerLabel = new Label();
            medal1 = new PictureBox();
            nameBox = new Label();
            scoreBox = new Label();
            exit = new Button();
            ((System.ComponentModel.ISupportInitialize)medal1).BeginInit();
            SuspendLayout();
            // 
            // winnerLabel
            // 
            winnerLabel.AutoSize = true;
            winnerLabel.BackColor = Color.Gold;
            winnerLabel.BorderStyle = BorderStyle.Fixed3D;
            winnerLabel.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            winnerLabel.ForeColor = Color.Black;
            winnerLabel.Location = new Point(211, 49);
            winnerLabel.Name = "winnerLabel";
            winnerLabel.Size = new Size(182, 42);
            winnerLabel.TabIndex = 10;
            winnerLabel.Text = "WINNER";
            // 
            // medal1
            // 
            medal1.BackColor = Color.Transparent;
            medal1.BackgroundImage = (Image)resources.GetObject("medal1.BackgroundImage");
            medal1.BackgroundImageLayout = ImageLayout.Stretch;
            medal1.Location = new Point(141, 129);
            medal1.Name = "medal1";
            medal1.Size = new Size(56, 52);
            medal1.TabIndex = 11;
            medal1.TabStop = false;
            // 
            // nameBox
            // 
            nameBox.AutoSize = true;
            nameBox.BackColor = Color.LightSeaGreen;
            nameBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            nameBox.Location = new Point(222, 141);
            nameBox.Name = "nameBox";
            nameBox.Size = new Size(146, 31);
            nameBox.TabIndex = 46;
            nameBox.Text = "                      ";
            // 
            // scoreBox
            // 
            scoreBox.AutoSize = true;
            scoreBox.BackColor = Color.LightSeaGreen;
            scoreBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            scoreBox.Location = new Point(396, 141);
            scoreBox.Name = "scoreBox";
            scoreBox.Size = new Size(56, 31);
            scoreBox.TabIndex = 47;
            scoreBox.Text = "       ";
            // 
            // exit
            // 
            exit.BackColor = Color.Transparent;
            exit.BackgroundImage = (Image)resources.GetObject("exit.BackgroundImage");
            exit.BackgroundImageLayout = ImageLayout.Stretch;
            exit.FlatStyle = FlatStyle.Flat;
            exit.ForeColor = SystemColors.ControlText;
            exit.Location = new Point(22, 195);
            exit.Name = "exit";
            exit.Size = new Size(44, 44);
            exit.TabIndex = 49;
            exit.UseVisualStyleBackColor = false;
            exit.Click += exit_Click;
            // 
            // scoresForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Center;
            ClientSize = new Size(573, 251);
            Controls.Add(exit);
            Controls.Add(scoreBox);
            Controls.Add(nameBox);
            Controls.Add(medal1);
            Controls.Add(winnerLabel);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "scoresForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            ((System.ComponentModel.ISupportInitialize)medal1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label winnerLabel;
        private PictureBox medal1;
        private Label nameBox;
        private Label scoreBox;
        private Button exit;
    }
}