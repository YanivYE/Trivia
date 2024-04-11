namespace TriviaGUI
{
    partial class joinRoomForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(joinRoomForm));
            roomsListLabel = new Label();
            roomList = new Label();
            Join = new Button();
            BackArrow = new Button();
            roomID = new TextBox();
            roomIdLabel = new Label();
            SuspendLayout();
            // 
            // roomsListLabel
            // 
            roomsListLabel.AutoSize = true;
            roomsListLabel.BackColor = Color.Gold;
            roomsListLabel.BorderStyle = BorderStyle.Fixed3D;
            roomsListLabel.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            roomsListLabel.ForeColor = Color.Black;
            roomsListLabel.Location = new Point(268, 70);
            roomsListLabel.Name = "roomsListLabel";
            roomsListLabel.Size = new Size(276, 42);
            roomsListLabel.TabIndex = 5;
            roomsListLabel.Text = "ROOMS LIST:";
            roomsListLabel.Click += roomList_Click;
            // 
            // roomList
            // 
            roomList.AutoSize = true;
            roomList.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            roomList.Location = new Point(110, 131);
            roomList.Name = "roomList";
            roomList.Size = new Size(578, 186);
            roomList.TabIndex = 31;
            roomList.Text = resources.GetString("roomList.Text");
            // 
            // Join
            // 
            Join.BackColor = Color.Gold;
            Join.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            Join.Location = new Point(500, 333);
            Join.Name = "Join";
            Join.Size = new Size(188, 64);
            Join.TabIndex = 32;
            Join.Text = "JOIN";
            Join.UseVisualStyleBackColor = false;
            Join.Click += JoinRoom_Click;
            // 
            // BackArrow
            // 
            BackArrow.BackColor = Color.Transparent;
            BackArrow.BackgroundImage = (Image)resources.GetObject("BackArrow.BackgroundImage");
            BackArrow.BackgroundImageLayout = ImageLayout.Stretch;
            BackArrow.FlatStyle = FlatStyle.Flat;
            BackArrow.ForeColor = SystemColors.ControlText;
            BackArrow.Location = new Point(735, 366);
            BackArrow.Name = "BackArrow";
            BackArrow.Size = new Size(44, 44);
            BackArrow.TabIndex = 33;
            BackArrow.UseVisualStyleBackColor = false;
            // 
            // roomID
            // 
            roomID.Font = new Font("Segoe UI", 24F, FontStyle.Regular, GraphicsUnit.Point);
            roomID.Location = new Point(319, 334);
            roomID.Name = "roomID";
            roomID.Size = new Size(175, 61);
            roomID.TabIndex = 34;
            roomID.KeyPress += joinRoomName_KeyPress;
            // 
            // roomIdLabel
            // 
            roomIdLabel.AutoSize = true;
            roomIdLabel.BackColor = Color.Gold;
            roomIdLabel.BorderStyle = BorderStyle.Fixed3D;
            roomIdLabel.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            roomIdLabel.ForeColor = Color.Black;
            roomIdLabel.Location = new Point(110, 348);
            roomIdLabel.Name = "roomIdLabel";
            roomIdLabel.Size = new Size(203, 42);
            roomIdLabel.TabIndex = 35;
            roomIdLabel.Text = "ROOM ID:";
            // 
            // joinRoomForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(roomIdLabel);
            Controls.Add(roomID);
            Controls.Add(BackArrow);
            Controls.Add(Join);
            Controls.Add(roomList);
            Controls.Add(roomsListLabel);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "joinRoomForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            FormClosed += joinRoomForm_Close;
            Load += joinRoomForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label roomsListLabel;
        private Label roomList;
        private Button Join;
        private Button BackArrow;
        private TextBox roomID;
        private Label roomIdLabel;
    }
}