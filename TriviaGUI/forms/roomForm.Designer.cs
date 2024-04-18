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
            roomNameLabel = new Label();
            StartGame = new Button();
            maxNumbersLabel = new Label();
            answerTimeoutLabel = new Label();
            questionsNumLabel = new Label();
            maxNumberBox = new Label();
            questionsNumBox = new Label();
            answerTimeoutBox = new Label();
            closeRoom = new Button();
            playersList = new Label();
            adminBox = new Label();
            adminLabel = new Label();
            roomName = new Label();
            SuspendLayout();
            // 
            // roomNameLabel
            // 
            roomNameLabel.AutoSize = true;
            roomNameLabel.BackColor = Color.Transparent;
            roomNameLabel.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            roomNameLabel.Location = new Point(272, 32);
            roomNameLabel.Name = "roomNameLabel";
            roomNameLabel.Size = new Size(145, 31);
            roomNameLabel.TabIndex = 21;
            roomNameLabel.Text = "Room Name:";
            // 
            // StartGame
            // 
            StartGame.BackColor = Color.Gold;
            StartGame.Font = new Font("Ravie", 10.8F, FontStyle.Regular, GraphicsUnit.Point);
            StartGame.Location = new Point(354, 354);
            StartGame.Name = "StartGame";
            StartGame.Size = new Size(109, 45);
            StartGame.TabIndex = 22;
            StartGame.Text = "START";
            StartGame.UseVisualStyleBackColor = false;
            StartGame.Click += StartGame_Click;
            // 
            // maxNumbersLabel
            // 
            maxNumbersLabel.AutoSize = true;
            maxNumbersLabel.BackColor = Color.Transparent;
            maxNumbersLabel.Font = new Font("Showcard Gothic", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            maxNumbersLabel.Location = new Point(58, 79);
            maxNumbersLabel.Name = "maxNumbersLabel";
            maxNumbersLabel.Size = new Size(228, 21);
            maxNumbersLabel.TabIndex = 23;
            maxNumbersLabel.Text = "max number of players: ";
            // 
            // answerTimeoutLabel
            // 
            answerTimeoutLabel.AutoSize = true;
            answerTimeoutLabel.BackColor = Color.Transparent;
            answerTimeoutLabel.Font = new Font("Showcard Gothic", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            answerTimeoutLabel.Location = new Point(552, 79);
            answerTimeoutLabel.Name = "answerTimeoutLabel";
            answerTimeoutLabel.Size = new Size(178, 21);
            answerTimeoutLabel.TabIndex = 24;
            answerTimeoutLabel.Text = "time per question: ";
            // 
            // questionsNumLabel
            // 
            questionsNumLabel.AutoSize = true;
            questionsNumLabel.BackColor = Color.Transparent;
            questionsNumLabel.Font = new Font("Showcard Gothic", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            questionsNumLabel.Location = new Point(310, 79);
            questionsNumLabel.Name = "questionsNumLabel";
            questionsNumLabel.Size = new Size(206, 21);
            questionsNumLabel.TabIndex = 25;
            questionsNumLabel.Text = "number of questions: ";
            // 
            // maxNumberBox
            // 
            maxNumberBox.AutoSize = true;
            maxNumberBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            maxNumberBox.Location = new Point(133, 110);
            maxNumberBox.Name = "maxNumberBox";
            maxNumberBox.Size = new Size(62, 31);
            maxNumberBox.TabIndex = 26;
            maxNumberBox.Text = "        ";
            // 
            // questionsNumBox
            // 
            questionsNumBox.AutoSize = true;
            questionsNumBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            questionsNumBox.Location = new Point(376, 110);
            questionsNumBox.Name = "questionsNumBox";
            questionsNumBox.Size = new Size(62, 31);
            questionsNumBox.TabIndex = 27;
            questionsNumBox.Text = "        ";
            // 
            // answerTimeoutBox
            // 
            answerTimeoutBox.AutoSize = true;
            answerTimeoutBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            answerTimeoutBox.Location = new Point(605, 110);
            answerTimeoutBox.Name = "answerTimeoutBox";
            answerTimeoutBox.Size = new Size(62, 31);
            answerTimeoutBox.TabIndex = 28;
            answerTimeoutBox.Text = "        ";
            // 
            // closeRoom
            // 
            closeRoom.BackColor = Color.Red;
            closeRoom.Font = new Font("Ravie", 9F, FontStyle.Regular, GraphicsUnit.Point);
            closeRoom.Location = new Point(690, 12);
            closeRoom.Name = "closeRoom";
            closeRoom.Size = new Size(109, 51);
            closeRoom.TabIndex = 29;
            closeRoom.Text = "CLOSE ROOM";
            closeRoom.UseVisualStyleBackColor = false;
            closeRoom.Click += closeRoom_Click;
            // 
            // playersList
            // 
            playersList.AutoSize = true;
            playersList.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            playersList.Location = new Point(133, 212);
            playersList.Name = "playersList";
            playersList.Size = new Size(536, 124);
            playersList.TabIndex = 30;
            playersList.Text = "        \r\n\r\n                                                                       \r\n                                                                                       ";
            // 
            // adminBox
            // 
            adminBox.AutoSize = true;
            adminBox.BackColor = Color.Transparent;
            adminBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            adminBox.Location = new Point(376, 172);
            adminBox.Name = "adminBox";
            adminBox.Size = new Size(116, 31);
            adminBox.TabIndex = 31;
            adminBox.Text = "                 ";
            // 
            // adminLabel
            // 
            adminLabel.AutoSize = true;
            adminLabel.BackColor = Color.Transparent;
            adminLabel.Font = new Font("Showcard Gothic", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            adminLabel.Location = new Point(272, 173);
            adminLabel.Name = "adminLabel";
            adminLabel.Size = new Size(98, 29);
            adminLabel.TabIndex = 32;
            adminLabel.Text = "Admin: ";
            // 
            // roomName
            // 
            roomName.AutoSize = true;
            roomName.BackColor = Color.Transparent;
            roomName.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            roomName.Location = new Point(418, 32);
            roomName.Name = "roomName";
            roomName.Size = new Size(52, 31);
            roomName.TabIndex = 33;
            roomName.Text = "test";
            // 
            // roomForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(roomName);
            Controls.Add(adminLabel);
            Controls.Add(adminBox);
            Controls.Add(playersList);
            Controls.Add(closeRoom);
            Controls.Add(answerTimeoutBox);
            Controls.Add(questionsNumBox);
            Controls.Add(maxNumberBox);
            Controls.Add(questionsNumLabel);
            Controls.Add(answerTimeoutLabel);
            Controls.Add(maxNumbersLabel);
            Controls.Add(StartGame);
            Controls.Add(roomNameLabel);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "roomForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            FormClosed += roomForm_Close;
            Load += roomForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label roomNameLabel;
        private Button StartGame;
        private Label maxNumbersLabel;
        private Label answerTimeoutLabel;
        private Label questionsNumLabel;
        private Label maxNumberBox;
        private Label questionsNumBox;
        private Label answerTimeoutBox;
        private Button closeRoom;
        private Label playersList;
        private Label adminBox;
        private Label adminLabel;
        private Label roomName;
    }
}