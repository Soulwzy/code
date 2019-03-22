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
    public partial class 登陆界面 : Form
    {
        public 登陆界面()
        {
            InitializeComponent();
        }
  
        private void confirm_Click(object sender, EventArgs e)
        {

            SqlConnection lo_conn = new SqlConnection("Data Source=.;Database=选课系统;Integrated Security=True");
            string sql = string.Format("select count(*) from 学生信息 where 学号 = {0} and 密码 = {1}", username.Text, password.Text);
            SqlCommand command = new SqlCommand(sql, lo_conn);

            if(radio_student.Checked == true)
            {
                try
                {

                    lo_conn.Open();
                    //if ((int)command.ExecuteScalar() > 0)
                    //{
                    //    this.Hide();
                    //    Form m2 = new 学生界面(this, username.Text);
                    //    m2.Show();
                    //}
                    //else
                    //{
                    //    MessageBox.Show("密码错误");
                    //}
                    this.Hide();
                    Form m2 = new 学生界面(this, username.Text);
                    m2.Show();
                    lo_conn.Close();
                }
                catch
                {
                    MessageBox.Show("账号密码不匹配");
                }

            }
            else if(radio_teatcher.Checked == true)
            {
                this.Hide();
                Form m3 = new 教师界面(this);
                m3.Show();
            }
            else if(radio_admin.Checked == true)
            {
                this.Hide();
                Form m3 = new 管理员界面(this);
                m3.Show();
            }
        }

        private void reset_Click(object sender, EventArgs e)
        {
            password.Text = null;
            username.Text = null;
        }

    }
}
