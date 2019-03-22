using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace 选课管理系统
{
    public partial class 教师界面 : Form
    {
        public static Form form = null;
        public 教师界面(Form form1)
        {
            InitializeComponent();
            form = form1;
        }

        private void sql_show()
        {
            SqlConnection lo_conn = new SqlConnection("Data Source=.;Database=选课系统;Integrated Security=True");
            string sql = "SELECT [学号],[姓名],[院系],[选择课程],[学分],[周学时],[已选状态],[成绩] FROM [dbo].[学生信息]";
            try
            {
                lo_conn.Open();
                SqlDataAdapter data = new SqlDataAdapter(sql, lo_conn);
                DataSet ds = new DataSet();
                data.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
                lo_conn.Close();
            }
            catch
            {
                MessageBox.Show("失败");
            }
        }

        private void back_Click(object sender, EventArgs e)
        {
            this.Hide();
            form.Show();
        }

        private void Form3_FormClosed(object sender, FormClosedEventArgs e)
        {
            form.Close();
        }

        private void 教师界面_Load(object sender, EventArgs e)
        {
            sql_show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //SqlConnection lo_conn = new SqlConnection("Data Source=.;Database=选课系统;Integrated Security=True");
            //string sql = string.Format("update 学生信息 set 成绩 = '{0}' where 学号 = '{1}'", textBox2.Text, textBox1.Text);
            //SqlCommand command = new SqlCommand(sql, lo_conn);

            //try
            //{
            //    lo_conn.Open();
            //    if (Convert.ToBoolean(command.ExecuteNonQuery()))
            //    {
            //        MessageBox.Show("录入成功");
            //    }
            //    else
            //    {
            //        MessageBox.Show("错误,请核对学号");
            //    }
            //    lo_conn.Close();
            //}
            //catch
            //{
            //    MessageBox.Show("错误！");
            //}
            //sql_show();
            SqlConnection lo_conn = new SqlConnection("Data Source=.;Database=选课系统;Integrated Security=True");
            string sql = "SELECT [学号],[姓名],[院系],[选择课程],[学分],[周学时],[已选状态],[成绩] FROM [dbo].[学生信息]";
            try
            {
                lo_conn.Open();
                SqlDataAdapter data = new SqlDataAdapter(sql, lo_conn);
                DataSet ds = new DataSet();
                data.Update(ds);
                ds.AcceptChanges();
                data.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
                lo_conn.Close();
            }
            catch
            {
                MessageBox.Show("失败");
            }
        }
    }
}
