namespace 选课管理系统
{
    partial class 登陆界面
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(登陆界面));
            this.background = new System.Windows.Forms.PictureBox();
            this.radio_student = new System.Windows.Forms.RadioButton();
            this.radio_teatcher = new System.Windows.Forms.RadioButton();
            this.username = new System.Windows.Forms.TextBox();
            this.password = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.confirm = new System.Windows.Forms.PictureBox();
            this.reset = new System.Windows.Forms.PictureBox();
            this.radio_admin = new System.Windows.Forms.RadioButton();
            ((System.ComponentModel.ISupportInitialize)(this.background)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.confirm)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.reset)).BeginInit();
            this.SuspendLayout();
            // 
            // background
            // 
            this.background.Image = ((System.Drawing.Image)(resources.GetObject("background.Image")));
            this.background.Location = new System.Drawing.Point(2, -1);
            this.background.Name = "background";
            this.background.Size = new System.Drawing.Size(630, 442);
            this.background.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.background.TabIndex = 0;
            this.background.TabStop = false;
            // 
            // radio_student
            // 
            this.radio_student.AutoSize = true;
            this.radio_student.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(229)))), ((int)(((byte)(241)))), ((int)(((byte)(253)))));
            this.radio_student.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(17)))), ((int)(((byte)(69)))), ((int)(((byte)(158)))));
            this.radio_student.Location = new System.Drawing.Point(212, 290);
            this.radio_student.Name = "radio_student";
            this.radio_student.Size = new System.Drawing.Size(58, 19);
            this.radio_student.TabIndex = 1;
            this.radio_student.TabStop = true;
            this.radio_student.Text = "学生";
            this.radio_student.UseVisualStyleBackColor = false;
            // 
            // radio_teatcher
            // 
            this.radio_teatcher.AutoSize = true;
            this.radio_teatcher.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(229)))), ((int)(((byte)(241)))), ((int)(((byte)(253)))));
            this.radio_teatcher.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(17)))), ((int)(((byte)(69)))), ((int)(((byte)(158)))));
            this.radio_teatcher.Location = new System.Drawing.Point(313, 290);
            this.radio_teatcher.Name = "radio_teatcher";
            this.radio_teatcher.Size = new System.Drawing.Size(58, 19);
            this.radio_teatcher.TabIndex = 2;
            this.radio_teatcher.TabStop = true;
            this.radio_teatcher.Text = "教师";
            this.radio_teatcher.UseVisualStyleBackColor = false;
            // 
            // username
            // 
            this.username.Location = new System.Drawing.Point(246, 140);
            this.username.Name = "username";
            this.username.Size = new System.Drawing.Size(207, 25);
            this.username.TabIndex = 3;
            // 
            // password
            // 
            this.password.Location = new System.Drawing.Point(246, 188);
            this.password.Name = "password";
            this.password.PasswordChar = '*';
            this.password.Size = new System.Drawing.Size(207, 25);
            this.password.TabIndex = 4;
            // 
            // textBox2
            // 
            this.textBox2.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.textBox2.Location = new System.Drawing.Point(246, 237);
            this.textBox2.Multiline = true;
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(92, 31);
            this.textBox2.TabIndex = 5;
            // 
            // confirm
            // 
            this.confirm.Image = ((System.Drawing.Image)(resources.GetObject("confirm.Image")));
            this.confirm.Location = new System.Drawing.Point(236, 331);
            this.confirm.Name = "confirm";
            this.confirm.Size = new System.Drawing.Size(85, 30);
            this.confirm.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.confirm.TabIndex = 6;
            this.confirm.TabStop = false;
            this.confirm.Click += new System.EventHandler(this.confirm_Click);
            // 
            // reset
            // 
            this.reset.Image = ((System.Drawing.Image)(resources.GetObject("reset.Image")));
            this.reset.Location = new System.Drawing.Point(339, 331);
            this.reset.Name = "reset";
            this.reset.Size = new System.Drawing.Size(84, 30);
            this.reset.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.reset.TabIndex = 7;
            this.reset.TabStop = false;
            this.reset.Click += new System.EventHandler(this.reset_Click);
            // 
            // radio_admin
            // 
            this.radio_admin.AutoSize = true;
            this.radio_admin.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(229)))), ((int)(((byte)(241)))), ((int)(((byte)(253)))));
            this.radio_admin.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(17)))), ((int)(((byte)(69)))), ((int)(((byte)(158)))));
            this.radio_admin.Location = new System.Drawing.Point(402, 290);
            this.radio_admin.Name = "radio_admin";
            this.radio_admin.Size = new System.Drawing.Size(73, 19);
            this.radio_admin.TabIndex = 8;
            this.radio_admin.TabStop = true;
            this.radio_admin.Text = "管理员";
            this.radio_admin.UseVisualStyleBackColor = false;
            // 
            // 登陆界面
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(631, 441);
            this.Controls.Add(this.radio_admin);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.password);
            this.Controls.Add(this.username);
            this.Controls.Add(this.radio_teatcher);
            this.Controls.Add(this.radio_student);
            this.Controls.Add(this.confirm);
            this.Controls.Add(this.reset);
            this.Controls.Add(this.background);
            this.Name = "登陆界面";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "教务管理系统";
            ((System.ComponentModel.ISupportInitialize)(this.background)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.confirm)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.reset)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox background;
        private System.Windows.Forms.RadioButton radio_student;
        private System.Windows.Forms.RadioButton radio_teatcher;
        private System.Windows.Forms.TextBox username;
        private System.Windows.Forms.TextBox password;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.PictureBox confirm;
        private System.Windows.Forms.PictureBox reset;
        private System.Windows.Forms.RadioButton radio_admin;

    }
}

