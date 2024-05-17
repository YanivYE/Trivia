namespace TriviaGUI
{
    partial class createRoomForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(createRoomForm));
            roomNameLabel = new Label();
            name = new TextBox();
            createRoom = new Button();
            questionTimeLabel = new Label();
            playersNumLabel = new Label();
            questionsNumLabel = new Label();
            numPlayers = new TextBox();
            numQuestions = new TextBox();
            time = new TextBox();
            BackArrow = new Button();
            SuspendLayout();
            // 
            // roomNameLabel
            // 
            roomNameLabel.AutoSize = true;
            roomNameLabel.BackColor = Color.Gold;
            roomNameLabel.Font = new Font("Ravie", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            roomNameLabel.Location = new Point(99, 72);
            roomNameLabel.Name = "roomNameLabel";
            roomNameLabel.Size = new Size(190, 32);
            roomNameLabel.TabIndex = 5;
            roomNameLabel.Text = "Roon Name:";
            // 
            // name
            // 
            name.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            name.Location = new Point(457, 69);
            name.Name = "name";
            name.Size = new Size(241, 38);
            name.TabIndex = 6;
            // 
            // createRoom
            // 
            createRoom.BackColor = Color.Gold;
            createRoom.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            createRoom.Location = new Point(294, 334);
            createRoom.Name = "createRoom";
            createRoom.Size = new Size(188, 64);
            createRoom.TabIndex = 11;
            createRoom.Text = "CREATE";
            createRoom.UseVisualStyleBackColor = false;
            createRoom.Click += CreateRoom_Click;
            // 
            // questionTimeLabel
            // 
            questionTimeLabel.AutoSize = true;
            questionTimeLabel.BackColor = Color.Gold;
            questionTimeLabel.Font = new Font("Ravie", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            questionTimeLabel.Location = new Point(99, 278);
            questionTimeLabel.Name = "questionTimeLabel";
            questionTimeLabel.Size = new Size(305, 32);
            questionTimeLabel.TabIndex = 12;
            questionTimeLabel.Text = "Time Per question:";
            // 
            // playersNumLabel
            // 
            playersNumLabel.AutoSize = true;
            playersNumLabel.BackColor = Color.Gold;
            playersNumLabel.Font = new Font("Ravie", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            playersNumLabel.Location = new Point(99, 139);
            playersNumLabel.Name = "playersNumLabel";
            playersNumLabel.Size = new Size(315, 32);
            playersNumLabel.TabIndex = 13;
            playersNumLabel.Text = "Number Of Players:";
            // 
            // questionsNumLabel
            // 
            questionsNumLabel.AutoSize = true;
            questionsNumLabel.BackColor = Color.Gold;
            questionsNumLabel.Font = new Font("Ravie", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            questionsNumLabel.Location = new Point(99, 210);
            questionsNumLabel.Name = "questionsNumLabel";
            questionsNumLabel.Size = new Size(347, 32);
            questionsNumLabel.TabIndex = 14;
            questionsNumLabel.Text = "Number Of Questions:";
            // 
            // numPlayers
            // 
            numPlayers.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            numPlayers.Location = new Point(457, 136);
            numPlayers.Name = "numPlayers";
            numPlayers.Size = new Size(246, 38);
            numPlayers.TabIndex = 15;
            numPlayers.KeyPress += numPlayers_KeyPress;
            // 
            // numQuestions
            // 
            numQuestions.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            numQuestions.Location = new Point(457, 204);
            numQuestions.Name = "numQuestions";
            numQuestions.Size = new Size(246, 38);
            numQuestions.TabIndex = 16;
            numQuestions.KeyPress += numQuestions_KeyPress;
            // 
            // time
            // 
            time.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            time.Location = new Point(457, 272);
            time.Name = "time";
            time.Size = new Size(246, 38);
            time.TabIndex = 17;
            time.KeyPress += time_KeyPress;
            // 
            // BackArrow
            // 
            BackArrow.BackColor = Color.Transparent;
            BackArrow.BackgroundImage = (Image)resources.GetObject("BackArrow.BackgroundImage");
            BackArrow.BackgroundImageLayout = ImageLayout.Stretch;
            BackArrow.FlatStyle = FlatStyle.Flat;
            BackArrow.ForeColor = SystemColors.ControlText;
            BackArrow.Location = new Point(734, 375);
            BackArrow.Name = "BackArrow";
            BackArrow.Size = new Size(44, 44);
            BackArrow.TabIndex = 34;
            BackArrow.UseVisualStyleBackColor = false;
            BackArrow.Click += BackArrow_Click_1;
            // 
            // createRoomForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(BackArrow);
            Controls.Add(time);
            Controls.Add(numQuestions);
            Controls.Add(numPlayers);
            Controls.Add(questionsNumLabel);
            Controls.Add(playersNumLabel);
            Controls.Add(questionTimeLabel);
            Controls.Add(createRoom);
            Controls.Add(name);
            Controls.Add(roomNameLabel);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "createRoomForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            FormClosed += createRoomForm_Close;
            Load += createRoomForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label roomNameLabel;
        private TextBox name;
        private Button createRoom;
        private Label questionTimeLabel;
        private Label playersNumLabel;
        private Label questionsNumLabel;
        private TextBox numPlayers;
        private TextBox numQuestions;
        private TextBox time;
        private Button BackArrow;
    }
}