using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DungMaker
{
    public partial class ListMenu : Form
    {
        public ListMenu()
        {
            InitializeComponent();
            if (AppDomain.CurrentDomain.SetupInformation.ActivationArguments.ActivationData != null)
            {
                string file = AppDomain.CurrentDomain.SetupInformation.ActivationArguments.ActivationData[0];
                //MessageBox.Show();
                switch (getFileExtension(file))
                {
                    case "dngmn":
                        Application.Run(new MonsterMaker(file));
                        break;
                    case "dnglv":
                        Application.Run(new Form1(file));
                        break;
                    default:

                        break;
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MonsterMaker dialog = new MonsterMaker();
            dialog.ShowDialog();
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form1 dialog = new Form1();
            dialog.ShowDialog();
        }

        private string getFileExtension(string file)
        {
            string ext;
            ext = file.Substring(file.LastIndexOf(".") + 1);
            return ext;
        }
    }
}
