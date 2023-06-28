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
            roomList = new Label();
            button2 = new Button();
            button3 = new Button();
            joinRoomName = new TextBox();
            label2 = new Label();
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
            // button2
            // 
            button2.BackColor = Color.Gold;
            button2.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            button2.Location = new Point(500, 333);
            button2.Name = "button2";
            button2.Size = new Size(188, 64);
            button2.TabIndex = 32;
            button2.Text = "JOIN";
            button2.UseVisualStyleBackColor = false;
            button2.Click += button2_Click;
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
            // joinRoomName
            // 
            joinRoomName.Font = new Font("Segoe UI", 24F, FontStyle.Regular, GraphicsUnit.Point);
            joinRoomName.Location = new Point(319, 334);
            joinRoomName.Name = "joinRoomName";
            joinRoomName.Size = new Size(175, 61);
            joinRoomName.TabIndex = 34;
            joinRoomName.KeyPress += joinRoomName_KeyPress;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.BackColor = Color.Gold;
            label2.BorderStyle = BorderStyle.Fixed3D;
            label2.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            label2.ForeColor = Color.Black;
            label2.Location = new Point(110, 348);
            label2.Name = "label2";
            label2.Size = new Size(203, 42);
            label2.TabIndex = 35;
            label2.Text = "ROOM ID:";
            // 
            // joinRoomForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(label2);
            Controls.Add(joinRoomName);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(roomList);
            Controls.Add(label1);
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

        private Label label1;
        private Label roomList;
        private Button button2;
        private Button button3;
        private TextBox joinRoomName;
        private Label label2;
    }
}