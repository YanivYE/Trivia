namespace TriviaGUI
{
    partial class roomForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(roomForm));
            label12 = new Label();
            button3 = new Button();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            maxNumber = new Label();
            numQuestions = new Label();
            answerTimeout = new Label();
            button1 = new Button();
            label7 = new Label();
            adminLabel = new Label();
            label9 = new Label();
            roomName = new Label();
            SuspendLayout();
            // 
            // label12
            // 
            label12.AutoSize = true;
            label12.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label12.Location = new Point(238, 32);
            label12.Name = "label12";
            label12.Size = new Size(140, 31);
            label12.TabIndex = 21;
            label12.Text = "Room Name";
            // 
            // button3
            // 
            button3.BackColor = Color.Gold;
            button3.Font = new Font("Ravie", 10.8F, FontStyle.Regular, GraphicsUnit.Point);
            button3.Location = new Point(354, 354);
            button3.Name = "button3";
            button3.Size = new Size(109, 45);
            button3.TabIndex = 22;
            button3.Text = "START";
            button3.UseVisualStyleBackColor = false;
            button3.Click += button3_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Transparent;
            label1.Font = new Font("Showcard Gothic", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label1.Location = new Point(58, 79);
            label1.Name = "label1";
            label1.Size = new Size(228, 21);
            label1.TabIndex = 23;
            label1.Text = "max number of players: ";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.BackColor = Color.Transparent;
            label2.Font = new Font("Showcard Gothic", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label2.Location = new Point(552, 79);
            label2.Name = "label2";
            label2.Size = new Size(178, 21);
            label2.TabIndex = 24;
            label2.Text = "time per question: ";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.BackColor = Color.Transparent;
            label3.Font = new Font("Showcard Gothic", 10.2F, FontStyle.Regular, GraphicsUnit.Point);
            label3.Location = new Point(310, 79);
            label3.Name = "label3";
            label3.Size = new Size(206, 21);
            label3.TabIndex = 25;
            label3.Text = "number of questions: ";
            // 
            // maxNumber
            // 
            maxNumber.AutoSize = true;
            maxNumber.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            maxNumber.Location = new Point(133, 110);
            maxNumber.Name = "maxNumber";
            maxNumber.Size = new Size(62, 31);
            maxNumber.TabIndex = 26;
            maxNumber.Text = "        ";
            maxNumber.Click += label4_Click;
            // 
            // numQuestions
            // 
            numQuestions.AutoSize = true;
            numQuestions.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            numQuestions.Location = new Point(376, 110);
            numQuestions.Name = "numQuestions";
            numQuestions.Size = new Size(62, 31);
            numQuestions.TabIndex = 27;
            numQuestions.Text = "        ";
            // 
            // answerTimeout
            // 
            answerTimeout.AutoSize = true;
            answerTimeout.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            answerTimeout.Location = new Point(605, 110);
            answerTimeout.Name = "answerTimeout";
            answerTimeout.Size = new Size(62, 31);
            answerTimeout.TabIndex = 28;
            answerTimeout.Text = "        ";
            // 
            // button1
            // 
            button1.BackColor = Color.Red;
            button1.Font = new Font("Ravie", 9F, FontStyle.Regular, GraphicsUnit.Point);
            button1.Location = new Point(690, 12);
            button1.Name = "button1";
            button1.Size = new Size(109, 51);
            button1.TabIndex = 29;
            button1.Text = "CLOSE ROOM";
            button1.UseVisualStyleBackColor = false;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label7.Location = new Point(130, 212);
            label7.Name = "label7";
            label7.Size = new Size(536, 124);
            label7.TabIndex = 30;
            label7.Text = "        \r\n\r\n                                                                       \r\n                                                                                       ";
            // 
            // adminLabel
            // 
            adminLabel.AutoSize = true;
            adminLabel.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            adminLabel.Location = new Point(401, 172);
            adminLabel.Name = "adminLabel";
            adminLabel.Size = new Size(116, 31);
            adminLabel.TabIndex = 31;
            adminLabel.Text = "                 ";
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.BackColor = Color.Transparent;
            label9.Font = new Font("Showcard Gothic", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label9.Location = new Point(303, 172);
            label9.Name = "label9";
            label9.Size = new Size(98, 29);
            label9.TabIndex = 32;
            label9.Text = "Admin: ";
            // 
            // roomName
            // 
            roomName.AutoSize = true;
            roomName.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            roomName.Location = new Point(384, 32);
            roomName.Name = "roomName";
            roomName.Size = new Size(52, 31);
            roomName.TabIndex = 33;
            roomName.Text = "test";
            // 
            // roomForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            BackgroundImageLayout = ImageLayout.Stretch;
            ClientSize = new Size(811, 450);
            Controls.Add(roomName);
            Controls.Add(label9);
            Controls.Add(adminLabel);
            Controls.Add(label7);
            Controls.Add(button1);
            Controls.Add(answerTimeout);
            Controls.Add(numQuestions);
            Controls.Add(maxNumber);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(button3);
            Controls.Add(label12);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "roomForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Trivia Night By Elior Yousefi And Yaniv Yehezkel";
            FormClosed += roomForm_Close;
            Load += roomForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label12;
        private Button button3;
        private Label label1;
        private Label label2;
        private Label label3;
        private Label maxNumber;
        private Label numQuestions;
        private Label answerTimeout;
        private Button button1;
        private Label label7;
        private Label adminLabel;
        private Label label9;
        private Label roomName;
    }
}