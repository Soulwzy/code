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
    public partial class 管理员界面 : Form
    {
        public static Form form = null;
        public 管理员界面(Form form1)
        {
            InitializeComponent();
            form = form1;
        }

        private void sql_Show()
        {
            SqlConnection lo_conn = new SqlConnection("Data Source=.;Database=选课系统;Integrated Security=True");
            string sql = "SELECT [课程代码],[课程名称],[任课教师],[课程性质],[学分],[周学时] FROM [dbo].[选课信息]";
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

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            form.Show();
        }

        private void 管理员界面_FormClosed(object sender, FormClosedEventArgs e)
        {
            form.Close();
        }

        private void 管理员界面_Load(object sender, EventArgs e)
        {
            sql_Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            SqlConnection lo_conn = new SqlConnection("Data Source=.;Database=选课系统;Integrated Security=True");
            string sql = string.Format("INSERT INTO [dbo].[选课信息]([课程代码],[课程名称],[任课教师],[课程性质],[学分],[周学时]) VALUES('{0}','{1}','{2}','{3}','{4}','{5}');",textBox1.Text,textBox2.Text,textBox3.Text,textBox4.Text,textBox5.Text,textBox6.Text);
            SqlCommand command = new SqlCommand(sql, lo_conn);

            try
            {
                lo_conn.Open();
                if (Convert.ToBoolean(command.ExecuteNonQuery()))
                {
                    MessageBox.Show("录入成功");
                }
                else
                {
                    MessageBox.Show("请核对代码");
                }
                lo_conn.Close();
            }
            catch
            {
                MessageBox.Show("录入失败");
            }
            sql_Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SqlConnection lo_conn = new SqlConnection("Data Source=.;Database=选课系统;Integrated Security=True");
            string sql = string.Format("delete from 选课信息 where 课程代码 = '{0}';", textBox1.Text);
            SqlCommand command = new SqlCommand(sql, lo_conn);

            try
            {
                lo_conn.Open();
                if (Convert.ToBoolean(command.ExecuteNonQuery()))
                {
                    MessageBox.Show("删除成功");
                }
                else
                {
                    MessageBox.Show("课程代码不正确");
                }
                lo_conn.Close();
            }
            catch
            {
                MessageBox.Show("删除失败");
            }
            sql_Show();
        }
    }
}
