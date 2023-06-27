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
            label1 = new Label();
            button1 = new Button();
            label7 = new Label();
            button2 = new Button();
            button3 = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Gold;
            label1.BorderStyle = BorderStyle.Fixed3D;
            label1.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            label1.ForeColor = Color.Black;
            label1.Location = new Point(268, 70);
            label1.Name = "label1";
            label1.Size = new Size(276, 42);
            label1.TabIndex = 5;
            label1.Text = "ROOMS LIST:";
            // 
            // button1
            // 
            button1.BackColor = Color.DarkCyan;
            button1.BackgroundImage = (Image)resources.GetObject("button1.BackgroundImage");
            button1.BackgroundImageLayout = ImageLayout.Stretch;
            button1.Font = new Font("Showcard Gothic", 7.8F, FontStyle.Regular, GraphicsUnit.Point);
            button1.Location = new Point(21, 189);
            button1.Name = "button1";
            button1.Size = new Size(72, 72);
            button1.TabIndex = 30;
            button1.Text = "Refresh";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label7.Location = new Point(110, 131);
            label7.Name = "label7";
            label7.Size = new Size(578, 186);
            label7.TabIndex = 31;
            label7.Text = resources.GetString("label7.Text");
            // 
            // button2
            // 
            button2.BackColor = Color.Gold;
            button2.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            button2.Location = new Point(308, 331);
            button2.Name = "button2";
            button2.Size = new Size(188, 64);
            button2.TabIndex = 32;
            button2.Text = "JOIN";
            button2.UseVisualStyleBackColor = false;
            // 
            // button3
            // 
            button3.BackColor = Color.Transparent;
            button3.BackgroundImage = (Image)resources.GetObject("button3.BackgroundImage");
            button3.BackgroundImageLayout = ImageLayout.Stretch;
            button3.FlatStyle = FlatStyle.Flat;
            button3.ForeColor = SystemColors.ControlText;
            button3.Location = new Point(735, 366);
            button3.Name = "button3";
            button3.Size = new Size(44, 44);
            button3.TabIndex = 33;
            button3.UseVisualStyleBackColor = false;
            // 
            // joinRoomForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(label7);
            Controls.Add(button1);
            Controls.Add(label1);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "joinRoomForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            Load += joinRoomForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Button button1;
        private Label label7;
        private Button button2;
        private Button button3;
    }
}