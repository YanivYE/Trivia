namespace TriviaGUI
{
    partial class mainForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(mainForm));
            Login = new Button();
            SignUp = new Button();
            Exit = new Button();
            Title = new Label();
            SuspendLayout();
            // 
            // Login
            // 
            Login.BackColor = Color.Gold;
            Login.Font = new Font("Ravie", 10.8F, FontStyle.Regular, GraphicsUnit.Point);
            Login.ForeColor = Color.Black;
            Login.Location = new Point(335, 170);
            Login.Name = "Login";
            Login.Size = new Size(143, 60);
            Login.TabIndex = 0;
            Login.Text = "Login";
            Login.UseVisualStyleBackColor = false;
            Login.Click += Login_Click;
            // 
            // SignUp
            // 
            SignUp.BackColor = Color.Gold;
            SignUp.Font = new Font("Ravie", 10.8F, FontStyle.Regular, GraphicsUnit.Point);
            SignUp.Location = new Point(335, 98);
            SignUp.Name = "SignUp";
            SignUp.Size = new Size(143, 60);
            SignUp.TabIndex = 1;
            SignUp.Text = "Sign Up";
            SignUp.UseVisualStyleBackColor = false;
            SignUp.Click += Signup_Click;
            // 
            // Exit
            // 
            Exit.BackColor = Color.Transparent;
            Exit.BackgroundImage = (Image)resources.GetObject("Exit.BackgroundImage");
            Exit.BackgroundImageLayout = ImageLayout.Stretch;
            Exit.FlatStyle = FlatStyle.Flat;
            Exit.ForeColor = SystemColors.ControlText;
            Exit.Location = new Point(24, 377);
            Exit.Name = "Exit";
            Exit.Size = new Size(44, 44);
            Exit.TabIndex = 2;
            Exit.UseVisualStyleBackColor = false;
            Exit.Click += Exit_Click;
            // 
            // Title
            // 
            Title.AutoSize = true;
            Title.BackColor = Color.Gold;
            Title.BorderStyle = BorderStyle.Fixed3D;
            Title.Font = new Font("Ravie", 18F, FontStyle.Bold, GraphicsUnit.Point);
            Title.ForeColor = Color.Black;
            Title.Location = new Point(259, 36);
            Title.Name = "Title";
            Title.Size = new Size(308, 42);
            Title.TabIndex = 3;
            Title.Text = "TRIVIA NIGHT";
            Title.Click += Title_Click;
            // 
            // mainForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(Title);
            Controls.Add(Exit);
            Controls.Add(SignUp);
            Controls.Add(Login);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "mainForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            Load += mainForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button Login;
        private Button SignUp;
        private Button Exit;
        private Label Title;
    }
}