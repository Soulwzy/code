namespace 选课管理系统
{
    partial class 选课界面
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
            this.components = new System.ComponentModel.Container();
            this.back = new System.Windows.Forms.Button();
            this.选课信息BindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.选课系统DataSetBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.选课系统DataSet = new 选课管理系统.选课系统DataSet();
            this.选课信息TableAdapter = new 选课管理系统.选课系统DataSetTableAdapters.选课信息TableAdapter();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.课程代码DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.课程名称DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.任课教师DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.课程性质DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.学分DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.周学时DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.已选状态DataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.select = new System.Windows.Forms.Button();
            this.textbox1 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.tableAdapterManager1 = new 选课管理系统.选课系统DataSetTableAdapters.TableAdapterManager();
            this.label2 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.选课信息BindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.选课系统DataSetBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.选课系统DataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // back
            // 
            this.back.BackColor = System.Drawing.Color.SpringGreen;
            this.back.ForeColor = System.Drawing.SystemColors.MenuHighlight;
            this.back.Location = new System.Drawing.Point(912, 149);
            this.back.Name = "back";
            this.back.Size = new System.Drawing.Size(75, 35);
            this.back.TabIndex = 0;
            this.back.Text = "返回";
            this.back.UseVisualStyleBackColor = false;
            this.back.Click += new System.EventHandler(this.button1_Click);
            // 
            // 选课信息BindingSource
            // 
            this.选课信息BindingSource.DataMember = "选课信息";
            this.选课信息BindingSource.DataSource = this.选课系统DataSetBindingSource;
            // 
            // 选课系统DataSetBindingSource
            // 
            this.选课系统DataSetBindingSource.DataSource = this.选课系统DataSet;
            this.选课系统DataSetBindingSource.Position = 0;
            // 
            // 选课系统DataSet
            // 
            this.选课系统DataSet.DataSetName = "选课系统DataSet";
            this.选课系统DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // 选课信息TableAdapter
            // 
            this.选课信息TableAdapter.ClearBeforeFill = true;
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridView1.BackgroundColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.课程代码DataGridViewTextBoxColumn,
            this.课程名称DataGridViewTextBoxColumn,
            this.任课教师DataGridViewTextBoxColumn,
            this.课程性质DataGridViewTextBoxColumn,
            this.学分DataGridViewTextBoxColumn,
            this.周学时DataGridViewTextBoxColumn,
            this.已选状态DataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.选课信息BindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(29, 232);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 27;
            this.dataGridView1.Size = new System.Drawing.Size(941, 340);
            this.dataGridView1.TabIndex = 1;
            // 
            // 课程代码DataGridViewTextBoxColumn
            // 
            this.课程代码DataGridViewTextBoxColumn.DataPropertyName = "课程代码";
            this.课程代码DataGridViewTextBoxColumn.HeaderText = "课程代码";
            this.课程代码DataGridViewTextBoxColumn.Name = "课程代码DataGridViewTextBoxColumn";
            // 
            // 课程名称DataGridViewTextBoxColumn
            // 
            this.课程名称DataGridViewTextBoxColumn.DataPropertyName = "课程名称";
            this.课程名称DataGridViewTextBoxColumn.HeaderText = "课程名称";
            this.课程名称DataGridViewTextBoxColumn.Name = "课程名称DataGridViewTextBoxColumn";
            // 
            // 任课教师DataGridViewTextBoxColumn
            // 
            this.任课教师DataGridViewTextBoxColumn.DataPropertyName = "任课教师";
            this.任课教师DataGridViewTextBoxColumn.HeaderText = "任课教师";
            this.任课教师DataGridViewTextBoxColumn.Name = "任课教师DataGridViewTextBoxColumn";
            // 
            // 课程性质DataGridViewTextBoxColumn
            // 
            this.课程性质DataGridViewTextBoxColumn.DataPropertyName = "课程性质";
            this.课程性质DataGridViewTextBoxColumn.HeaderText = "课程性质";
            this.课程性质DataGridViewTextBoxColumn.Name = "课程性质DataGridViewTextBoxColumn";
            // 
            // 学分DataGridViewTextBoxColumn
            // 
            this.学分DataGridViewTextBoxColumn.DataPropertyName = "学分";
            this.学分DataGridViewTextBoxColumn.HeaderText = "学分";
            this.学分DataGridViewTextBoxColumn.Name = "学分DataGridViewTextBoxColumn";
            // 
            // 周学时DataGridViewTextBoxColumn
            // 
            this.周学时DataGridViewTextBoxColumn.DataPropertyName = "周学时";
            this.周学时DataGridViewTextBoxColumn.HeaderText = "周学时";
            this.周学时DataGridViewTextBoxColumn.Name = "周学时DataGridViewTextBoxColumn";
            // 
            // 已选状态DataGridViewTextBoxColumn
            // 
            this.已选状态DataGridViewTextBoxColumn.DataPropertyName = "已选状态";
            this.已选状态DataGridViewTextBoxColumn.HeaderText = "已选状态";
            this.已选状态DataGridViewTextBoxColumn.Name = "已选状态DataGridViewTextBoxColumn";
            // 
            // select
            // 
            this.select.BackColor = System.Drawing.Color.SpringGreen;
            this.select.ForeColor = System.Drawing.SystemColors.MenuHighlight;
            this.select.Location = new System.Drawing.Point(649, 149);
            this.select.Name = "select";
            this.select.Size = new System.Drawing.Size(75, 35);
            this.select.TabIndex = 2;
            this.select.Text = "选择";
            this.select.UseVisualStyleBackColor = false;
            this.select.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // textbox1
            // 
            this.textbox1.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.textbox1.Location = new System.Drawing.Point(213, 149);
            this.textbox1.Multiline = true;
            this.textbox1.Name = "textbox1";
            this.textbox1.Size = new System.Drawing.Size(170, 32);
            this.textbox1.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("宋体", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.ForeColor = System.Drawing.Color.Aqua;
            this.label1.Location = new System.Drawing.Point(74, 152);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(110, 24);
            this.label1.TabIndex = 4;
            this.label1.Text = "课程代码";
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.SpringGreen;
            this.button1.ForeColor = System.Drawing.SystemColors.MenuHighlight;
            this.button1.Location = new System.Drawing.Point(780, 149);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 35);
            this.button1.TabIndex = 5;
            this.button1.Text = "退选";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click_2);
            // 
            // tableAdapterManager1
            // 
            this.tableAdapterManager1.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager1.UpdateOrder = 选课管理系统.选课系统DataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            this.tableAdapterManager1.学生信息TableAdapter = null;
            this.tableAdapterManager1.选课信息TableAdapter = this.选课信息TableAdapter;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Font = new System.Drawing.Font("宋体", 22.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label2.ForeColor = System.Drawing.Color.Aqua;
            this.label2.Location = new System.Drawing.Point(370, 46);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(329, 38);
            this.label2.TabIndex = 6;
            this.label2.Text = "欢迎进入选课界面";
            this.label2.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // 选课界面
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoValidate = System.Windows.Forms.AutoValidate.Disable;
            this.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.ClientSize = new System.Drawing.Size(1009, 600);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textbox1);
            this.Controls.Add(this.select);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.back);
            this.Name = "选课界面";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form2";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form2_FormClosed);
            this.Load += new System.EventHandler(this.Form2_Load);
            ((System.ComponentModel.ISupportInitialize)(this.选课信息BindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.选课系统DataSetBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.选课系统DataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button back;
        private System.Windows.Forms.BindingSource 选课系统DataSetBindingSource;
        private 选课系统DataSet 选课系统DataSet;
        private System.Windows.Forms.BindingSource 选课信息BindingSource;
        private 选课系统DataSetTableAdapters.选课信息TableAdapter 选课信息TableAdapter;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button select;
        private System.Windows.Forms.TextBox textbox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button1;
        private 选课系统DataSetTableAdapters.TableAdapterManager tableAdapterManager1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.DataGridViewTextBoxColumn 课程代码DataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn 课程名称DataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn 任课教师DataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn 课程性质DataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn 学分DataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn 周学时DataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn 已选状态DataGridViewTextBoxColumn;

    }
}