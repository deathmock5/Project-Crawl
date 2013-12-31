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
    public partial class Form1 : Form
    {
        const int rows = 17;
        const int cols = 23;
        private PictureBox[,] tiles = new PictureBox[rows,cols];
        private char[,] tilevars = new char[rows,cols];
        public enum tool {FLOOR,WALL,BWALL,TREAS,POT,TRAP,TORCH,LOWLV,MIDLV,HIGLV,WATE,BOSS};
        public tool curenttool = tool.FLOOR;
        public Image floortile;
        public Image walltile;
        public Image walltilebreakable;
        public Image treasuretile;
        public Image pottile;
        public Image traptile;
        public Image torchtile;
        public Image lowlvenemytile;
        public Image midlvenemytile;
        public Image highlvenemytile;
        public Image watertile;
        public Image bosstile;

        public Form1()
        {
            InitializeComponent();
            try
            {
                floortile = FloorTool.Image;
                walltile = walltool.Image;
                walltilebreakable = breakablewalltool.Image;
                treasuretile = treasurechesttool.Image;
                pottile = pottool.Image;
                traptile = trapfloortool.Image;
                torchtile = torchtool.Image;
                lowlvenemytile = lowlvtool.Image;
                midlvenemytile = midlvtool.Image;
                highlvenemytile = highlvtool.Image;
                watertile = watertool.Image;
                bosstile = bosstool.Image;
                
            }
            catch (Exception e)
            {
                MessageBox.Show(e.ToString());
            }
            for (int r = 0; r < rows; r++)
            {
                for (int c = 0; c < cols; c++)
                {
                    tiles[r, c] = new PictureBox();
                    tiles[r, c].Size = new Size(itempannel.Size.Width / cols, itempannel.Size.Height / rows);
                    tiles[r, c].Location = new Point((itempannel.Size.Width / cols) * c, (itempannel.Size.Height / rows) * r);
                    tiles[r, c].SizeMode = PictureBoxSizeMode.StretchImage;
                    tiles[r, c].Click += new System.EventHandler(this.tileClick);
                    tiles[r, c].Tag = r + "," + c;
                    itempannel.Controls.Add(tiles[r, c]);
                }
            }
            filename.Text = "No File Selected";
            toolname.Text = "Floor";
        }

        public Form1(string file)
        {
            InitializeComponent();
            try
            {
                floortile = FloorTool.Image;
                walltile = walltool.Image;
                walltilebreakable = breakablewalltool.Image;
                treasuretile = treasurechesttool.Image;
                pottile = pottool.Image;
                traptile = trapfloortool.Image;
                torchtile = torchtool.Image;
                lowlvenemytile = lowlvtool.Image;
                midlvenemytile = midlvtool.Image;
                highlvenemytile = highlvtool.Image;
                watertile = watertool.Image;
                bosstile = bosstool.Image;

            }
            catch (Exception e)
            {
                MessageBox.Show(e.ToString());
            }
            for (int r = 0; r < rows; r++)
            {
                for (int c = 0; c < cols; c++)
                {
                    tiles[r, c] = new PictureBox();
                    tiles[r, c].Size = new Size(itempannel.Size.Width / cols, itempannel.Size.Height / rows);
                    tiles[r, c].Location = new Point((itempannel.Size.Width / cols) * c, (itempannel.Size.Height / rows) * r);
                    tiles[r, c].SizeMode = PictureBoxSizeMode.StretchImage;
                    tiles[r, c].Click += new System.EventHandler(this.tileClick);
                    tiles[r, c].Tag = r + "," + c;
                    itempannel.Controls.Add(tiles[r, c]);
                }
            }
            filename.Text = "No File Selected";
            toolname.Text = "Floor";
            Openfile(file);
        }
        private void setDungImages()
        {
            for (int r = 0; r < rows; r++)
            {
                for (int c = 0; c < cols; c++)
                {
                    switch (tilevars[r, c])
                    {
                        case '#':
                            tiles[r, c].Image = floortile;
                            break;
                        case '@':
                            //wall
                            tiles[r, c].Image = walltile;
                            break;
                        case '$':
                            //breakable wall
                            tiles[r, c].Image = walltilebreakable;
                            break;
                        case '1':
                            //treasure
                            tiles[r, c].Image = treasuretile;
                            break;
                        case '2':
                            //pot
                            tiles[r, c].Image = pottile;
                            break;
                        case '3':
                            //trap
                            tiles[r, c].Image = traptile;
                            break;
                        case '4':
                            //torch
                            tiles[r, c].Image = torchtile;
                            break;
                        case '5':
                            //low level enemys
                            tiles[r, c].Image = lowlvenemytile;
                            break;
                        case '6':
                            //med level enemy
                            tiles[r, c].Image = midlvenemytile;
                            break;
                        case '7':
                            //high level enemys
                            tiles[r, c].Image = highlvenemytile;
                            break;
                        case '8':
                            //liquid
                            tiles[r, c].Image = watertile;
                            break;
                        case '9':
                            //boss
                            tiles[r, c].Image = bosstile;
                            break;
                        default:
                            MessageBox.Show("Unknown Type: " + tilevars[r, c]);
                            break;
                    }
                }
            }
        }

        private Image tileImageOfType()
        {
            switch (curenttool)
            {
                case tool.FLOOR:
                    return floortile;
                case tool.WALL:
                    return walltile;
                case tool.BWALL:
                    return walltilebreakable;
                case tool.TREAS:
                    return treasuretile;
                case tool.POT:
                    return pottile;
                case tool.TRAP:
                    return traptile;
                case tool.TORCH:
                    return torchtile;
                case tool.LOWLV:
                    return lowlvenemytile;
                case tool.MIDLV:
                    return midlvenemytile;
                case tool.HIGLV:
                    return highlvenemytile;
                case tool.WATE:
                    return watertile;
                case tool.BOSS:
                    return bosstile;
                default:
                    return floortile;
            }
        }

        private char charOfType()
        {
            switch (curenttool)
            {
                case tool.FLOOR:
                    return '#';
                case tool.WALL:
                    return '@';
                case tool.BWALL:
                    return '$';
                case tool.TREAS:
                    return '1';
                case tool.POT:
                    return '2';
                case tool.TRAP:
                    return '3';
                case tool.TORCH:
                    return '4';
                case tool.LOWLV:
                    return '5';
                case tool.MIDLV:
                    return '6';
                case tool.HIGLV:
                    return '7';
                case tool.WATE:
                    return '8';
                case tool.BOSS:
                    return '9';
                default:
                    return '#';
            }
        }
        private void openButton_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                string file = openFileDialog1.FileName;
                Openfile(file);
            }
        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                System.IO.StreamWriter sw = new
                   System.IO.StreamWriter(saveFileDialog1.FileName);
                for (int r = 0; r < rows; r++)
                {
                    for (int c = 0; c < cols; c++)
                    {
                        sw.Write(tilevars[r, c]);
                    }
                    sw.WriteLine();
                }
                //MessageBox.Show(sr.ReadToEnd());

                sw.Close();
                MessageBox.Show("Saved!");
            }
        }

        private void NewButton_Click(object sender, EventArgs e)
        {

        }

        private void tileClick(object sender, EventArgs e)
        {
            //get the tile clicked
            //set the selected brush tile type as the clicked tile
            //refresh the image
            PictureBox mypic = (PictureBox)sender;
            //MessageBox.Show(mypic.Tag.ToString());
            mypic.Image = tileImageOfType();
            string tag = mypic.Tag.ToString();
            int var1 = Convert.ToInt16(tag.Substring(0, tag.IndexOf(',')));
            int var2 = Convert.ToInt16(tag.Substring(tag.IndexOf(',') + 1));
            tilevars[var1,var2] = charOfType();
        }

        private void FloorTool_Click(object sender, EventArgs e)
        {
            toolname.Text = "Floor";
            curenttool = tool.FLOOR;
        }
        private void walltool_Click(object sender, EventArgs e)
        {
            toolname.Text = "Wall";
            curenttool = tool.WALL;
        }
        private void breakablewalltool_Click(object sender, EventArgs e)
        {
            toolname.Text = "Breakable Wall";
            curenttool = tool.BWALL;
        }
        private void treasurechesttool_Click(object sender, EventArgs e)
        {
            toolname.Text = "Treasure Chest";
            curenttool = tool.TREAS;
        }
        private void pottool_Click(object sender, EventArgs e)
        {
            toolname.Text = "Breakable Loot";
            curenttool = tool.POT;
        }
        private void trapfloortool_Click(object sender, EventArgs e)
        {
            toolname.Text = "Damage Tile";
            curenttool = tool.TRAP;
        }
        private void torchtool_Click(object sender, EventArgs e)
        {
            toolname.Text = "LightSource";
            curenttool = tool.TORCH;
        }
        private void lowlvtool_Click(object sender, EventArgs e)
        {
            toolname.Text = "Low Lv Enemy Spawn";
            curenttool = tool.LOWLV;
        }
        private void midlvtool_Click(object sender, EventArgs e)
        {
            toolname.Text = "Mid Lv Enemy Spawn";
            curenttool = tool.MIDLV;
        }
        private void highlvtool_Click(object sender, EventArgs e)
        {
            toolname.Text = "High Lv Enemy Spawn";
            curenttool = tool.HIGLV;
        }
        private void watertool_Click(object sender, EventArgs e)
        {
            toolname.Text = "Impassable Non-Wall";
            curenttool = tool.WATE;
        }
        private void bosstool_Click(object sender, EventArgs e)
        {
            toolname.Text = "Boss Class Enemy Spawn";
            curenttool = tool.BOSS;
        }

        private void Openfile(string file)
        {
            System.IO.StreamReader sr = new
               System.IO.StreamReader(file);
            for (int r = 0; r < rows; r++)
            {
                string var = sr.ReadLine();
                for (int c = 0; c < cols; c++)
                {
                    tilevars[r, c] = var[c];
                }
            }
            filename.Text = file;
            filename.ToolTipText = file;
            toolname.Text = "Floor";
            sr.Close();
            setDungImages();
        }
    }
}
