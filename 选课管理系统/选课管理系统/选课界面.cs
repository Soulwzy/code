using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace 选课管理系统
{
    public partial class 选课界面 : Form
    {
        public static Form form = null;

        private void Sql_show()
        {
            // TODO:  这行代码将数据加载到表“选课系统DataSet.选课信息”中。您可以根据需要移动或删除它。
            this.选课信息TableAdapter.Fill(this.选课系统DataSet.选课信息);
            SqlConnection lo_conn = new SqlConnection("Data Source=.;Database=选课系统;Integrated Security=True");
            string sql = "SELECT * FROM 选课信息";
            try
            {
                lo_conn.Open();
                SqlDataAdapter data = new SqlDataAdapter(sql, lo_conn);
                DataSet ds = new DataSet();
                data.Fill(ds,"a");
                dataGridView1.DataSource = ds.Tables["a"];
                //lo_conn.Close();
                SqlCommandBuilder scb = new SqlCommandBuilder(data);//sd:SqlDataAdapter 
                data.Update(ds.Tables["a"]); //ds:dateset
               // ds.AcceptChanges();
                lo_conn.Close();
            }
            catch
            {
                MessageBox.Show("失败");
            }
        }

        public 选课界面(Form form1)
        {
            InitializeComponent();
            form = form1;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            form.Show();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            Sql_show();
        }

        private void Form2_FormClosed(object sender, FormClosedEventArgs e)
        {
            form.Close();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            SqlConnection lo_conn = new SqlConnection("Data Source=.;Database=选课系统;Integrated Security=True");
            string sql = string.Format("update 选课信息 set 已选状态 = '已选' where 课程代码 = '{0}'", textbox1.Text);
            SqlCommand command = new SqlCommand(sql, lo_conn);

            try
            {
                lo_conn.Open();
                if (Convert.ToBoolean(command.ExecuteNonQuery()))
                {
                    MessageBox.Show("选择成功");
                }
                else
                {
                    MessageBox.Show("失败,请核对代码");
                }
                lo_conn.Close();
            }
            catch
            {
                MessageBox.Show("选择失败");
            }
            Sql_show();
        }

        private void button1_Click_2(object sender, EventArgs e)
        {
            SqlConnection lo_conn = new SqlConnection("Data Source=.;Database=选课系统;Integrated Security=True");
            string sql = string.Format("update 选课信息 set 已选状态 = '未选' where 课程代码 = {0}", textbox1.Text);
            SqlCommand command = new SqlCommand(sql, lo_conn);

            try
            {
                lo_conn.Open();
                if (Convert.ToBoolean(command.ExecuteNonQuery()))
                {
                    MessageBox.Show("退选成功");
                }
                else
                {
                    MessageBox.Show("失败,请核对代码");
                }
                lo_conn.Close();
            }
            catch
            {
                MessageBox.Show("退选失败");
            }
            Sql_show();
        }
    }
}
