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
            passBox = new TextBox();
            label2 = new Label();
            button1 = new Button();
            label1 = new Label();
            button3 = new Button();
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
            // passBox
            // 
            passBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            passBox.Location = new Point(395, 214);
            passBox.Name = "passBox";
            passBox.Size = new Size(246, 38);
            passBox.TabIndex = 2;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.BackColor = Color.Gold;
            label2.Font = new Font("Ravie", 16.2F, FontStyle.Regular, GraphicsUnit.Point);
            label2.Location = new Point(166, 136);
            label2.Name = "label2";
            label2.Size = new Size(214, 38);
            label2.TabIndex = 3;
            label2.Text = "Username:";
            // 
            // button1
            // 
            button1.BackColor = Color.Gold;
            button1.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            button1.Location = new Point(322, 312);
            button1.Name = "button1";
            button1.Size = new Size(176, 64);
            button1.TabIndex = 4;
            button1.Text = "Login";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Gold;
            label1.Font = new Font("Ravie", 16.2F, FontStyle.Regular, GraphicsUnit.Point);
            label1.Location = new Point(166, 214);
            label1.Name = "label1";
            label1.Size = new Size(214, 38);
            label1.TabIndex = 5;
            label1.Text = "Password:";
            // 
            // button3
            // 
            button3.BackColor = Color.Transparent;
            button3.BackgroundImage = (Image)resources.GetObject("button3.BackgroundImage");
            button3.BackgroundImageLayout = ImageLayout.Stretch;
            button3.FlatStyle = FlatStyle.Flat;
            button3.ForeColor = SystemColors.ControlText;
            button3.Location = new Point(738, 374);
            button3.Name = "button3";
            button3.Size = new Size(44, 44);
            button3.TabIndex = 7;
            button3.UseVisualStyleBackColor = false;
            // 
            // loginForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(button3);
            Controls.Add(label1);
            Controls.Add(button1);
            Controls.Add(label2);
            Controls.Add(passBox);
            Controls.Add(usernameBox);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "loginForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            FormClosed += loginForm_Close;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox usernameBox;
        private TextBox passBox;
        private Label label2;
        private Button button1;
        private Label label1;
        private Button button3;
    }
}