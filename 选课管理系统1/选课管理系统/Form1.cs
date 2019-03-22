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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO:  这行代码将数据加载到表“学生信息.Students”中。您可以根据需要移动或删除它。
            this.studentsTableAdapter.Fill(this.学生信息.Students);
            SqlConnection lo_conn = new SqlConnection("Server=DESKTOP-I8II2BF;Database=学生信息;Integrated Security=True");
            lo_conn.Open();
            //SqlCommand lo_cmd = new SqlCommand();
            string sql = "SELECT * FROM Students";
            SqlDataAdapter data = new SqlDataAdapter(sql, lo_conn);
            DataSet ds = new DataSet();
            data.Fill(ds);
            lo_conn.Close();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
