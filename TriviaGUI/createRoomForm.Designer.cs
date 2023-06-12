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
            usernameBox = new TextBox();
            button1 = new Button();
            label1 = new Label();
            label3 = new Label();
            label4 = new Label();
            textBox1 = new TextBox();
            textBox2 = new TextBox();
            textBox3 = new TextBox();
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
            // usernameBox
            // 
            usernameBox.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            usernameBox.Location = new Point(457, 69);
            usernameBox.Name = "usernameBox";
            usernameBox.Size = new Size(241, 38);
            usernameBox.TabIndex = 6;
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
            // textBox1
            // 
            textBox1.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            textBox1.Location = new Point(457, 136);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(246, 38);
            textBox1.TabIndex = 15;
            // 
            // textBox2
            // 
            textBox2.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            textBox2.Location = new Point(457, 204);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(246, 38);
            textBox2.TabIndex = 16;
            // 
            // textBox3
            // 
            textBox3.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            textBox3.Location = new Point(457, 272);
            textBox3.Name = "textBox3";
            textBox3.Size = new Size(246, 38);
            textBox3.TabIndex = 17;
            // 
            // button3
            // 
            button3.BackColor = Color.Transparent;
            button3.BackgroundImage = (Image)resources.GetObject("button3.BackgroundImage");
            button3.BackgroundImageLayout = ImageLayout.Stretch;
            button3.FlatStyle = FlatStyle.Flat;
            button3.ForeColor = SystemColors.ControlText;
            button3.Location = new Point(741, 368);
            button3.Name = "button3";
            button3.Size = new Size(44, 44);
            button3.TabIndex = 18;
            button3.UseVisualStyleBackColor = false;
            // 
            // createRoomForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(button3);
            Controls.Add(textBox3);
            Controls.Add(textBox2);
            Controls.Add(textBox1);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label1);
            Controls.Add(button1);
            Controls.Add(usernameBox);
            Controls.Add(label2);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "createRoomForm";
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label2;
        private TextBox usernameBox;
        private Button button1;
        private Label label1;
        private Label label3;
        private Label label4;
        private TextBox textBox1;
        private TextBox textBox2;
        private TextBox textBox3;
        private Button button3;
    }
}