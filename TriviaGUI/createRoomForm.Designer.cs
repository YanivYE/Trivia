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
            label2 = new Label();
            name = new TextBox();
            button1 = new Button();
            label1 = new Label();
            label3 = new Label();
            label4 = new Label();
            numPlayers = new TextBox();
            numQuestions = new TextBox();
            time = new TextBox();
            button3 = new Button();
            SuspendLayout();
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.BackColor = Color.Gold;
            label2.Font = new Font("Ravie", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label2.Location = new Point(99, 72);
            label2.Name = "label2";
            label2.Size = new Size(190, 32);
            label2.TabIndex = 5;
            label2.Text = "Roon Name:";
            // 
            // name
            // 
            name.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            name.Location = new Point(457, 69);
            name.Name = "name";
            name.Size = new Size(241, 38);
            name.TabIndex = 6;
            // 
            // button1
            // 
            button1.BackColor = Color.Gold;
            button1.Font = new Font("Ravie", 18F, FontStyle.Regular, GraphicsUnit.Point);
            button1.Location = new Point(294, 334);
            button1.Name = "button1";
            button1.Size = new Size(188, 64);
            button1.TabIndex = 11;
            button1.Text = "CREATE";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Gold;
            label1.Font = new Font("Ravie", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label1.Location = new Point(99, 278);
            label1.Name = "label1";
            label1.Size = new Size(305, 32);
            label1.TabIndex = 12;
            label1.Text = "Time Per question:";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.BackColor = Color.Gold;
            label3.Font = new Font("Ravie", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label3.Location = new Point(99, 139);
            label3.Name = "label3";
            label3.Size = new Size(315, 32);
            label3.TabIndex = 13;
            label3.Text = "Number Of Players:";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.BackColor = Color.Gold;
            label4.Font = new Font("Ravie", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label4.Location = new Point(99, 210);
            label4.Name = "label4";
            label4.Size = new Size(347, 32);
            label4.TabIndex = 14;
            label4.Text = "Number Of Questions:";
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
            // button3
            // 
            button3.BackColor = Color.Transparent;
            button3.BackgroundImage = (Image)resources.GetObject("button3.BackgroundImage");
            button3.BackgroundImageLayout = ImageLayout.Stretch;
            button3.FlatStyle = FlatStyle.Flat;
            button3.ForeColor = SystemColors.ControlText;
            button3.Location = new Point(12, 373);
            button3.Name = "button3";
            button3.Size = new Size(44, 44);
            button3.TabIndex = 18;
            button3.UseVisualStyleBackColor = false;
            button3.Click += button3_Click;
            // 
            // createRoomForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(button3);
            Controls.Add(time);
            Controls.Add(numQuestions);
            Controls.Add(numPlayers);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label1);
            Controls.Add(button1);
            Controls.Add(name);
            Controls.Add(label2);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "createRoomForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label2;
        private TextBox name;
        private Button button1;
        private Label label1;
        private Label label3;
        private Label label4;
        private TextBox numPlayers;
        private TextBox numQuestions;
        private TextBox time;
        private Button button3;
    }
}