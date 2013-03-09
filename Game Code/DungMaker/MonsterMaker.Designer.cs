namespace DungMaker
{
    partial class MonsterMaker
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.openDngmnFile = new System.Windows.Forms.OpenFileDialog();
            this.saveDngmnFile = new System.Windows.Forms.SaveFileDialog();
            this.label1 = new System.Windows.Forms.Label();
            this.monName = new System.Windows.Forms.TextBox();
            this.monTileSizeW = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.monHp = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.monDamage = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.monTileSizeH = new System.Windows.Forms.TextBox();
            this.monAtkStyle = new System.Windows.Forms.ComboBox();
            this.monSfxH = new System.Windows.Forms.Button();
            this.monSfxA = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.spritePictureBox = new System.Windows.Forms.PictureBox();
            this.openSpriteFile = new System.Windows.Forms.OpenFileDialog();
            this.openButton = new System.Windows.Forms.Button();
            this.saveButton = new System.Windows.Forms.Button();
            this.openSfxAtk = new System.Windows.Forms.OpenFileDialog();
            this.openSfxHit = new System.Windows.Forms.OpenFileDialog();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spritePictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // openDngmnFile
            // 
            this.openDngmnFile.DefaultExt = "dngmn";
            this.openDngmnFile.FileName = "openFileDialog1";
            this.openDngmnFile.Filter = "Dungeon Monster Files|*.dngmn";
            // 
            // saveDngmnFile
            // 
            this.saveDngmnFile.DefaultExt = "dngmn";
            this.saveDngmnFile.Filter = "Dungeon Monster File|*.dngmn";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(3, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Name";
            // 
            // monName
            // 
            this.monName.Location = new System.Drawing.Point(44, 10);
            this.monName.Name = "monName";
            this.monName.Size = new System.Drawing.Size(181, 20);
            this.monName.TabIndex = 1;
            // 
            // monTileSizeW
            // 
            this.monTileSizeW.Location = new System.Drawing.Point(66, 36);
            this.monTileSizeW.Name = "monTileSizeW";
            this.monTileSizeW.Size = new System.Drawing.Size(80, 20);
            this.monTileSizeW.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(3, 39);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(57, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Size(W/H)";
            // 
            // monHp
            // 
            this.monHp.Location = new System.Drawing.Point(55, 62);
            this.monHp.Name = "monHp";
            this.monHp.Size = new System.Drawing.Size(170, 20);
            this.monHp.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(3, 65);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(46, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "HpBace";
            // 
            // monDamage
            // 
            this.monDamage.Location = new System.Drawing.Point(81, 88);
            this.monDamage.Name = "monDamage";
            this.monDamage.Size = new System.Drawing.Size(144, 20);
            this.monDamage.TabIndex = 8;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(3, 91);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(72, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "DamageBace";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(3, 117);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(30, 13);
            this.label5.TabIndex = 9;
            this.label5.Text = "Style";
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.monTileSizeH);
            this.panel1.Controls.Add(this.monAtkStyle);
            this.panel1.Controls.Add(this.monSfxH);
            this.panel1.Controls.Add(this.monSfxA);
            this.panel1.Controls.Add(this.label7);
            this.panel1.Controls.Add(this.label6);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.label5);
            this.panel1.Controls.Add(this.monName);
            this.panel1.Controls.Add(this.monDamage);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.monTileSizeW);
            this.panel1.Controls.Add(this.monHp);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Location = new System.Drawing.Point(314, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(230, 199);
            this.panel1.TabIndex = 11;
            // 
            // monTileSizeH
            // 
            this.monTileSizeH.Location = new System.Drawing.Point(152, 36);
            this.monTileSizeH.Name = "monTileSizeH";
            this.monTileSizeH.Size = new System.Drawing.Size(73, 20);
            this.monTileSizeH.TabIndex = 17;
            // 
            // monAtkStyle
            // 
            this.monAtkStyle.FormattingEnabled = true;
            this.monAtkStyle.Items.AddRange(new object[] {
            "Magic",
            "Melee",
            "Range"});
            this.monAtkStyle.Location = new System.Drawing.Point(46, 114);
            this.monAtkStyle.Name = "monAtkStyle";
            this.monAtkStyle.Size = new System.Drawing.Size(179, 21);
            this.monAtkStyle.TabIndex = 16;
            // 
            // monSfxH
            // 
            this.monSfxH.Location = new System.Drawing.Point(44, 170);
            this.monSfxH.Name = "monSfxH";
            this.monSfxH.Size = new System.Drawing.Size(181, 23);
            this.monSfxH.TabIndex = 15;
            this.monSfxH.Text = "click2load";
            this.monSfxH.UseVisualStyleBackColor = true;
            this.monSfxH.Click += new System.EventHandler(this.monSfxH_Click);
            // 
            // monSfxA
            // 
            this.monSfxA.Location = new System.Drawing.Point(44, 141);
            this.monSfxA.Name = "monSfxA";
            this.monSfxA.Size = new System.Drawing.Size(181, 23);
            this.monSfxA.TabIndex = 14;
            this.monSfxA.Text = "Click2load";
            this.monSfxA.UseVisualStyleBackColor = true;
            this.monSfxA.Click += new System.EventHandler(this.monSfxA_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(6, 175);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(35, 13);
            this.label7.TabIndex = 13;
            this.label7.Text = "SfxHit";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(6, 146);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(38, 13);
            this.label6.TabIndex = 11;
            this.label6.Text = "SfxAtk";
            // 
            // spritePictureBox
            // 
            this.spritePictureBox.Location = new System.Drawing.Point(12, 12);
            this.spritePictureBox.Name = "spritePictureBox";
            this.spritePictureBox.Size = new System.Drawing.Size(296, 296);
            this.spritePictureBox.TabIndex = 2;
            this.spritePictureBox.TabStop = false;
            this.spritePictureBox.Click += new System.EventHandler(this.spritePictureBox_Click);
            // 
            // openSpriteFile
            // 
            this.openSpriteFile.FileName = "openFileDialog2";
            this.openSpriteFile.Filter = "Images|*.png|*.bmp|*.jpg";
            // 
            // openButton
            // 
            this.openButton.Location = new System.Drawing.Point(320, 255);
            this.openButton.Name = "openButton";
            this.openButton.Size = new System.Drawing.Size(224, 23);
            this.openButton.TabIndex = 12;
            this.openButton.Text = "Open";
            this.openButton.UseVisualStyleBackColor = true;
            this.openButton.Click += new System.EventHandler(this.openButton_Click);
            // 
            // saveButton
            // 
            this.saveButton.Location = new System.Drawing.Point(320, 284);
            this.saveButton.Name = "saveButton";
            this.saveButton.Size = new System.Drawing.Size(224, 23);
            this.saveButton.TabIndex = 13;
            this.saveButton.Text = "Save";
            this.saveButton.UseVisualStyleBackColor = true;
            this.saveButton.Click += new System.EventHandler(this.saveButton_Click);
            // 
            // openSfxAtk
            // 
            this.openSfxAtk.FileName = "openFileDialog4";
            this.openSfxAtk.Filter = "Sound Files (*.wav)|*.wav";
            // 
            // openSfxHit
            // 
            this.openSfxHit.FileName = "sfxhitdialog";
            this.openSfxHit.Filter = "Sound Files (*.wav)|*.wav";
            // 
            // MonsterMaker
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(553, 315);
            this.Controls.Add(this.saveButton);
            this.Controls.Add(this.openButton);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.spritePictureBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Name = "MonsterMaker";
            this.Text = "MonsterMaker";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spritePictureBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.OpenFileDialog openDngmnFile;
        private System.Windows.Forms.SaveFileDialog saveDngmnFile;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox monName;
        private System.Windows.Forms.PictureBox spritePictureBox;
        private System.Windows.Forms.TextBox monTileSizeW;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox monHp;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox monDamage;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.OpenFileDialog openSpriteFile;
        private System.Windows.Forms.Button openButton;
        private System.Windows.Forms.Button saveButton;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button monSfxH;
        private System.Windows.Forms.Button monSfxA;
        private System.Windows.Forms.ComboBox monAtkStyle;
        private System.Windows.Forms.TextBox monTileSizeH;
        private System.Windows.Forms.OpenFileDialog openSfxAtk;
        private System.Windows.Forms.OpenFileDialog openSfxHit;
    }
}