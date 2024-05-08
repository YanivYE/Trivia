namespace TriviaGUI
{
    partial class lobbyForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(lobbyForm));
            username = new Label();
            welcome = new Label();
            exit = new Button();
            createRoom = new Button();
            joinRoom = new Button();
            stats = new Button();
            logout = new Button();
            SuspendLayout();
            // 
            // username
            // 
            username.AutoSize = true;
            username.BackColor = Color.Transparent;
            username.Font = new Font("Showcard Gothic", 12F, FontStyle.Regular, GraphicsUnit.Point);
            username.Location = new Point(419, 39);
            username.Name = "username";
            username.Size = new Size(0, 26);
            username.TabIndex = 47;
            username.Click += username_Click;
            // 
            // welcome
            // 
            welcome.AutoSize = true;
            welcome.BackColor = Color.Transparent;
            welcome.Font = new Font("Showcard Gothic", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            welcome.Location = new Point(324, 42);
            welcome.Name = "welcome";
            welcome.Size = new Size(95, 21);
            welcome.TabIndex = 46;
            welcome.Text = "Welcome ";
            // 
            // exit
            // 
            exit.BackColor = Color.Transparent;
            exit.BackgroundImage = (Image)resources.GetObject("exit.BackgroundImage");
            exit.BackgroundImageLayout = ImageLayout.Stretch;
            exit.FlatStyle = FlatStyle.Flat;
            exit.ForeColor = SystemColors.ControlText;
            exit.Location = new Point(23, 372);
            exit.Name = "exit";
            exit.Size = new Size(44, 44);
            exit.TabIndex = 48;
            exit.UseVisualStyleBackColor = false;
            exit.Click += Exit_Click;
            // 
            // createRoom
            // 
            createRoom.BackColor = Color.Gold;
            createRoom.Font = new Font("Ravie", 10.8F, FontStyle.Regular, GraphicsUnit.Point);
            createRoom.Location = new Point(315, 173);
            createRoom.Name = "createRoom";
            createRoom.Size = new Size(187, 84);
            createRoom.TabIndex = 49;
            createRoom.Text = "Create Room";
            createRoom.UseVisualStyleBackColor = false;
            createRoom.Click += CreateRoom_Click;
            // 
            // joinRoom
            // 
            joinRoom.BackColor = Color.Gold;
            joinRoom.Font = new Font("Ravie", 10.8F, FontStyle.Regular, GraphicsUnit.Point);
            joinRoom.Location = new Point(315, 83);
            joinRoom.Name = "joinRoom";
            joinRoom.Size = new Size(187, 84);
            joinRoom.TabIndex = 50;
            joinRoom.Text = "Join Room";
            joinRoom.UseVisualStyleBackColor = false;
            joinRoom.Click += JoinRoom_Click;
            // 
            // stats
            // 
            stats.BackColor = Color.Gold;
            stats.Font = new Font("Ravie", 10.8F, FontStyle.Regular, GraphicsUnit.Point);
            stats.Location = new Point(315, 263);
            stats.Name = "stats";
            stats.Size = new Size(187, 84);
            stats.TabIndex = 51;
            stats.Text = "Statistics";
            stats.UseVisualStyleBackColor = false;
            stats.Click += Stats_Click;
            // 
            // logout
            // 
            logout.BackColor = Color.Firebrick;
            logout.Font = new Font("Ravie", 10.8F, FontStyle.Regular, GraphicsUnit.Point);
            logout.Location = new Point(331, 356);
            logout.Name = "logout";
            logout.Size = new Size(143, 44);
            logout.TabIndex = 52;
            logout.Text = "Log Out";
            logout.UseVisualStyleBackColor = false;
            logout.Click += Logout_Click;
            // 
            // lobbyForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(logout);
            Controls.Add(stats);
            Controls.Add(joinRoom);
            Controls.Add(createRoom);
            Controls.Add(exit);
            Controls.Add(username);
            Controls.Add(welcome);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "lobbyForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            Load += lobbyForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label username;
        private Label welcome;
        private Button exit;
        private Button createRoom;
        private Button joinRoom;
        private Button stats;
        private Button logout;
    }
}