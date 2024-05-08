namespace TriviaGUI
{
    partial class loginForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(loginForm));
            usernameBox = new TextBox();
            passwordBox = new TextBox();
            usernameLabel = new Label();
            Login = new Button();
            passwordLabel = new Label();
            backArrow = new Button();
            SuspendLayout();
            // 
            // usernameBox
            // 
            usernameBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            usernameBox.Location = new Point(395, 136);
            usernameBox.Name = "usernameBox";
            usernameBox.Size = new Size(246, 38);
            usernameBox.TabIndex = 1;
            // 
            // passwordBox
            // 
            passwordBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            passwordBox.Location = new Point(395, 214);
            passwordBox.Name = "passwordBox";
            passwordBox.Size = new Size(246, 38);
            passwordBox.TabIndex = 2;
            // 
            // usernameLabel
            // 
            usernameLabel.AutoSize = true;
            usernameLabel.BackColor = Color.Gold;
            usernameLabel.Font = new Font("Ravie", 16.2F, FontStyle.Regular, GraphicsUnit.Point);
            usernameLabel.Location = new Point(166, 136);
            usernameLabel.Name = "usernameLabel";
            usernameLabel.Size = new Size(214, 38);
            usernameLabel.TabIndex = 3;
            usernameLabel.Text = "Username:";
            // 
            // Login
            // 
            Login.BackColor = Color.Gold;
            Login.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            Login.Location = new Point(322, 312);
            Login.Name = "Login";
            Login.Size = new Size(176, 64);
            Login.TabIndex = 4;
            Login.Text = "Login";
            Login.UseVisualStyleBackColor = false;
            Login.Click += Login_Click;
            // 
            // passwordLabel
            // 
            passwordLabel.AutoSize = true;
            passwordLabel.BackColor = Color.Gold;
            passwordLabel.Font = new Font("Ravie", 16.2F, FontStyle.Regular, GraphicsUnit.Point);
            passwordLabel.Location = new Point(166, 214);
            passwordLabel.Name = "passwordLabel";
            passwordLabel.Size = new Size(214, 38);
            passwordLabel.TabIndex = 5;
            passwordLabel.Text = "Password:";
            // 
            // backArrow
            // 
            backArrow.BackColor = Color.Transparent;
            backArrow.BackgroundImage = (Image)resources.GetObject("backArrow.BackgroundImage");
            backArrow.BackgroundImageLayout = ImageLayout.Stretch;
            backArrow.FlatStyle = FlatStyle.Flat;
            backArrow.ForeColor = SystemColors.ControlText;
            backArrow.Location = new Point(733, 378);
            backArrow.Name = "backArrow";
            backArrow.Size = new Size(44, 44);
            backArrow.TabIndex = 7;
            backArrow.UseVisualStyleBackColor = false;
            backArrow.Click += Back_Click;
            // 
            // loginForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(backArrow);
            Controls.Add(passwordLabel);
            Controls.Add(Login);
            Controls.Add(usernameLabel);
            Controls.Add(passwordBox);
            Controls.Add(usernameBox);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "loginForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            FormClosed += loginForm_Close;
            Load += loginForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox usernameBox;
        private TextBox passwordBox;
        private Label usernameLabel;
        private Button Login;
        private Label passwordLabel;
        private Button backArrow;
    }
}