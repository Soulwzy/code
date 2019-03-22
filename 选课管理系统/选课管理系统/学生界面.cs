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
    public partial class 学生界面 : Form
    {
        public static Form form = null;
        public static string user = null;
        public 学生界面(Form form1,string username)
        {
            InitializeComponent();
            form = form1;
            user = username;
        }

        private void 学生界面_Load(object sender, EventArgs e)
        {
            SqlConnection lo_conn = new SqlConnection("Data Source=.;Database=选课系统;Integrated Security=True");      
            string sql = "select * from 选课信息 where 已选状态 = '已选';";
            string sql2 = string.Format("select 学号  from 学生信息 where 学号 = '{0}'", user);
            string sql3 = string.Format("select 姓名  from 学生信息 where 学号 = '{0}'", user);
            string sql4 = string.Format("select 院系  from 学生信息 where 学号 = '{0}'", user);
            try
            {
                lo_conn.Open();
                SqlDataAdapter data = new SqlDataAdapter(sql, lo_conn);
                DataSet ds = new DataSet();
                data.Fill(ds,"a");
                dataGridView1.DataSource = ds.Tables["a"];

                SqlCommand command2 = new SqlCommand(sql2, lo_conn);
                SqlCommand command3 = new SqlCommand(sql3, lo_conn);
                SqlCommand command4 = new SqlCommand(sql4, lo_conn);
                label4.Text = (string)command2.ExecuteScalar();
                label5.Text = (string)command3.ExecuteScalar();
                label6.Text = (string)command4.ExecuteScalar();

                SqlCommandBuilder scb = new SqlCommandBuilder(data);//sd:SqlDataAdapter 
                data.Update(ds.Tables["a"]); //ds:dateset
                // ds.AcceptChanges();

                lo_conn.Close();
            }
            catch
            {
                MessageBox.Show("打开失败");
            }
        }

        private void 学生界面_FormClosed(object sender, FormClosedEventArgs e)
        {
            form.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            form.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form m4 = new 选课界面(this);
            m4.Show();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            SqlConnection lo_conn = new SqlConnection("Data Source=.;Database=选课系统;Integrated Security=True");
            string sql = "select * from 选课信息 where 已选状态 = '已选';";
            try
            {
                lo_conn.Open();
                SqlDataAdapter data = new SqlDataAdapter(sql, lo_conn);
                DataSet ds = new DataSet();
                data.Fill(ds, "a");
                dataGridView1.DataSource = ds.Tables["a"];
                //lo_conn.Close();
                SqlCommandBuilder scb = new SqlCommandBuilder(data);//sd:SqlDataAdapter 
                data.Update(ds.Tables["a"]); //ds:dateset
                // ds.AcceptChanges();
                lo_conn.Close();
            }
            catch
            {
                MessageBox.Show("打开失败");
            }
        }
    }
}
