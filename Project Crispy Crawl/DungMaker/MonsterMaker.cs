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
            spritePictureBox.Tag = null;
            monSfxA.Tag = null;
            monSfxH.Tag = null;
        }

        public MonsterMaker(string file)
        {
            InitializeComponent();
            spritePictureBox.SizeMode = PictureBoxSizeMode.StretchImage;
            spritePictureBox.Tag = null;
            monSfxA.Tag = null;
            monSfxH.Tag = null;
            Openfile(file);
        }

        private void spritePictureBox_Click(object sender, EventArgs e)
        {
            DialogResult result = openSpriteFile.ShowDialog();
            string file = openSpriteFile.FileName;
            if (result == DialogResult.OK)
            {
                System.IO.StreamReader sr = new System.IO.StreamReader(file);
                spritePictureBox.Image = Bitmap.FromFile(file);
                spritePictureBox.Tag = file;
                sr.Close();
            }
        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            DialogResult result = saveDngmnFile.ShowDialog();
            if (result == DialogResult.OK)
            {
                System.IO.StreamWriter sw = new System.IO.StreamWriter(saveDngmnFile.FileName);
                /*
                    Name:Slime
                    Tile:Slime.png
                    SizeH:32.0
                    SizeW:32.0
                    SfxAtk:splat.wav
                    SfxHit:whack.wav
                    HpBace:25
                    DamageBace:15
                    AtackStyle:melee
                */
                sw.WriteLine(monName.Text);
                sw.WriteLine(monName.Text + ".png");
                sw.WriteLine(monTileSizeW.Text);
                sw.WriteLine(monTileSizeH.Text);
                sw.WriteLine(monName.Text + "atk" + getFileExtension(monSfxA.Text));
                sw.WriteLine(monName.Text + "hit" + getFileExtension(monSfxH.Text));
                sw.WriteLine(monHp.Text);
                sw.WriteLine(monDamage.Text);
                sw.WriteLine(monAtkStyle.Text);
                if (spritePictureBox.Tag != null)
                {
                    System.IO.File.Copy(spritePictureBox.Tag.ToString(), saveDngmnFile.FileName.Substring(0, saveDngmnFile.FileName.LastIndexOf("\\") + 1) + monName.Text.Replace(".dngmn", "") + ".png");
                }
                if (monSfxA != null)
                {
                    System.IO.File.Copy(monSfxA.Tag.ToString(), saveDngmnFile.FileName.Substring(0, saveDngmnFile.FileName.LastIndexOf("\\") + 1) + monName.Text.Replace(".dngmn", "") + "atk" + getFileExtension(monSfxA.Tag.ToString()));
                }
                if (monSfxH != null)
                {
                    System.IO.File.Copy(monSfxH.Tag.ToString(), saveDngmnFile.FileName.Substring(0, saveDngmnFile.FileName.LastIndexOf("\\") + 1) + monName.Text.Replace(".dngmn", "") + "hit" + getFileExtension(monSfxH.Tag.ToString()));
                }
               //TODO: update so resaveing dosent cause errors
                sw.Close();
            }
        }

        private void openButton_Click(object sender, EventArgs e)
        {
            DialogResult result = openDngmnFile.ShowDialog();
            if (result == DialogResult.OK)
            {
                Openfile(openDngmnFile.FileName);
            }
        }

        private void monSfxA_Click(object sender, EventArgs e)
        {
            DialogResult result = openSfxAtk.ShowDialog();
           
            if (result == DialogResult.OK)
            {
                string file = openSfxAtk.FileName;
                monSfxA.Tag = file;
                monSfxA.Text = file.Substring(file.LastIndexOf("/")+1);
            }
        }

        private void monSfxH_Click(object sender, EventArgs e)
        {
            DialogResult result = openSfxHit.ShowDialog();
            if (result == DialogResult.OK)
            {
                string file = openSfxHit.FileName;
                monSfxH.Tag = file;
                monSfxH.Text = file.Substring(file.LastIndexOf("/") + 1);
            }
        }

        private void Openfile(string file)
        {
            System.IO.StreamReader sw = new System.IO.StreamReader(file);
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
            spritePictureBox.Image = Bitmap.FromFile(file.Substring(0, file.LastIndexOf("\\") + 1) + sw.ReadLine());
            monTileSizeW.Text = sw.ReadLine();
            monTileSizeH.Text = sw.ReadLine();
            monSfxA.Text = sw.ReadLine();
            monSfxH.Text = sw.ReadLine();
            monHp.Text = sw.ReadLine();
            monDamage.Text = sw.ReadLine();
            monAtkStyle.Text = sw.ReadLine();
            sw.Close();
        }
        private string getFileName(string file)
        {
            string name = file.Substring(file.LastIndexOf("/") + 1);
            name = file.Substring(0, file.LastIndexOf("."));
            return name;
        }
        private string getFileNameWithExtension(string file)
        {
            string name = file.Substring(file.LastIndexOf("/") + 1);
            return name;
        }
        private string getFileExtension(string file)
        {
            string name = "." + file.Substring(file.LastIndexOf(".") + 1);
            return name;
        }
    }
}
