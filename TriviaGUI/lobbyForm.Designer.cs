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
            label3 = new Label();
            button3 = new Button();
            button2 = new Button();
            button1 = new Button();
            button4 = new Button();
            button5 = new Button();
            SuspendLayout();
            // 
            // username
            // 
            username.AutoSize = true;
            username.BackColor = Color.Transparent;
            username.Font = new Font("Showcard Gothic", 12F, FontStyle.Regular, GraphicsUnit.Point);
            username.Location = new Point(422, 39);
            username.Name = "username";
            username.Size = new Size(59, 26);
            username.TabIndex = 47;
            username.Text = "test";
            username.Click += label4_Click;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.BackColor = Color.Transparent;
            label3.Font = new Font("Showcard Gothic", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label3.Location = new Point(321, 42);
            label3.Name = "label3";
            label3.Size = new Size(95, 21);
            label3.TabIndex = 46;
            label3.Text = "Welcome ";
            // 
            // button3
            // 
            button3.BackColor = Color.Transparent;
            button3.BackgroundImage = (Image)resources.GetObject("button3.BackgroundImage");
            button3.BackgroundImageLayout = ImageLayout.Stretch;
            button3.FlatStyle = FlatStyle.Flat;
            button3.ForeColor = SystemColors.ControlText;
            button3.Location = new Point(23, 372);
            button3.Name = "button3";
            button3.Size = new Size(44, 44);
            button3.TabIndex = 48;
            button3.UseVisualStyleBackColor = false;
            button3.Click += button3_Click;
            // 
            // button2
            // 
            button2.BackColor = Color.Gold;
            button2.Font = new Font("Ravie", 10.8F, FontStyle.Regular, GraphicsUnit.Point);
            button2.Location = new Point(315, 173);
            button2.Name = "button2";
            button2.Size = new Size(187, 84);
            button2.TabIndex = 49;
            button2.Text = "Create Room";
            button2.UseVisualStyleBackColor = false;
            button2.Click += button2_Click;
            // 
            // button1
            // 
            button1.BackColor = Color.Gold;
            button1.Font = new Font("Ravie", 10.8F, FontStyle.Regular, GraphicsUnit.Point);
            button1.Location = new Point(315, 83);
            button1.Name = "button1";
            button1.Size = new Size(187, 84);
            button1.TabIndex = 50;
            button1.Text = "Join Room";
            button1.UseVisualStyleBackColor = false;
            // 
            // button4
            // 
            button4.BackColor = Color.Gold;
            button4.Font = new Font("Ravie", 10.8F, FontStyle.Regular, GraphicsUnit.Point);
            button4.Location = new Point(315, 263);
            button4.Name = "button4";
            button4.Size = new Size(187, 84);
            button4.TabIndex = 51;
            button4.Text = "Statistics";
            button4.UseVisualStyleBackColor = false;
            // 
            // button5
            // 
            button5.BackColor = Color.Firebrick;
            button5.Font = new Font("Ravie", 10.8F, FontStyle.Regular, GraphicsUnit.Point);
            button5.Location = new Point(331, 356);
            button5.Name = "button5";
            button5.Size = new Size(143, 44);
            button5.TabIndex = 52;
            button5.Text = "Log Out";
            button5.UseVisualStyleBackColor = false;
            button5.Click += button5_Click;
            // 
            // lobbyForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(button5);
            Controls.Add(button4);
            Controls.Add(button1);
            Controls.Add(button2);
            Controls.Add(button3);
            Controls.Add(username);
            Controls.Add(label3);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "lobbyForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            Load += lobbyForm_Load_2;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label username;
        private Label label3;
        private Button button3;
        private Button button2;
        private Button button1;
        private Button button4;
        private Button button5;
    }
}