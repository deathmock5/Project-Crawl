using System;
using System.IO;
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
    public partial class MonsterMaker : Form
    {
        public MonsterMaker()
        {
            InitializeComponent();
            spritePictureBox.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        private void spritePictureBox_Click(object sender, EventArgs e)
        {
            DialogResult result = openFileDialog2.ShowDialog();
            string file = openFileDialog2.FileName;
            if (result == DialogResult.OK)
            {
                System.IO.StreamReader sr = new
               System.IO.StreamReader(file);
                spritePictureBox.Image = Bitmap.FromFile(file);
                spritePictureBox.Tag = file;
                sr.Close();
            }
        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            DialogResult result = saveFileDialog1.ShowDialog();
            if (result == DialogResult.OK)
            {
                System.IO.StreamWriter sw = new System.IO.StreamWriter(saveFileDialog1.FileName);
                /*
                Name:Slime
                Tile:Slime.png
                Size:32.0
                SfxAtk:splat.ogg
                SfxHit:splat.ogg
                HpBace:25
                DamageBace:15
                */
                sw.WriteLine(monName.Text);
                sw.WriteLine(monName.Text + ".png");
                sw.WriteLine(monTileSizeW.Text);
                sw.WriteLine(monTileSizeH.Text);
                sw.WriteLine(monSfxA.Text);
                //copy audiofile to dir
                sw.WriteLine(monSfxH.Text);
                sw.WriteLine(monHp.Text);
                sw.WriteLine(monDamage.Text);
                System.IO.File.Copy(spritePictureBox.Tag.ToString(), saveFileDialog1.FileName.Substring(0, saveFileDialog1.FileName.LastIndexOf("\\") + 1) + monName.Text.Replace(".dngmn", "") + ".png");
                sw.Close();
            }
        }

        private void openButton_Click(object sender, EventArgs e)
        {
            DialogResult result = openFileDialog1.ShowDialog();
            if (result == DialogResult.OK)
            {
                System.IO.StreamReader sw = new System.IO.StreamReader(openFileDialog1.FileName);
                /*
                Name:Slime
                Tile:Slime.png
                Size:32.0
                SfxAtk:splat.ogg
                SfxHit:splat.ogg
                HpBace:25
                DamageBace:15
                */
                monName.Text = sw.ReadLine();
                spritePictureBox.Image = Bitmap.FromFile(openFileDialog1.FileName.Substring(0, openFileDialog1.FileName.LastIndexOf("\\") + 1) + sw.ReadLine());
                monTileSizeW.Text = sw.ReadLine();
                monTileSizeH.Text = sw.ReadLine();
                monSfxA.Text = sw.ReadLine();
                monSfxH.Text = sw.ReadLine();
                monHp.Text = sw.ReadLine();
                monDamage.Text = sw.ReadLine();
                sw.Close();
            }
        }

        private void monSfxA_Click(object sender, EventArgs e)
        {

        }

        private void monSfxH_Click(object sender, EventArgs e)
        {

        }

    }
}
