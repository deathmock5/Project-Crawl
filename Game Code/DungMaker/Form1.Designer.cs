namespace DungMaker
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolname = new System.Windows.Forms.ToolStripStatusLabel();
            this.filename = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.NewButton = new System.Windows.Forms.ToolStripButton();
            this.openButton = new System.Windows.Forms.ToolStripButton();
            this.saveButton = new System.Windows.Forms.ToolStripButton();
            this.itempannel = new System.Windows.Forms.Panel();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.toolStrip2 = new System.Windows.Forms.ToolStrip();
            this.FloorTool = new System.Windows.Forms.ToolStripButton();
            this.walltool = new System.Windows.Forms.ToolStripButton();
            this.breakablewalltool = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.treasurechesttool = new System.Windows.Forms.ToolStripButton();
            this.pottool = new System.Windows.Forms.ToolStripButton();
            this.trapfloortool = new System.Windows.Forms.ToolStripButton();
            this.torchtool = new System.Windows.Forms.ToolStripButton();
            this.lowlvtool = new System.Windows.Forms.ToolStripButton();
            this.midlvtool = new System.Windows.Forms.ToolStripButton();
            this.highlvtool = new System.Windows.Forms.ToolStripButton();
            this.watertool = new System.Windows.Forms.ToolStripButton();
            this.bosstool = new System.Windows.Forms.ToolStripButton();
            this.statusStrip1.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.toolStrip2.SuspendLayout();
            this.SuspendLayout();
            // 
            // statusStrip1
            // 
            this.statusStrip1.GripMargin = new System.Windows.Forms.Padding(0);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolname,
            this.filename});
            this.statusStrip1.Location = new System.Drawing.Point(0, 524);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.RenderMode = System.Windows.Forms.ToolStripRenderMode.Professional;
            this.statusStrip1.Size = new System.Drawing.Size(571, 22);
            this.statusStrip1.SizingGrip = false;
            this.statusStrip1.TabIndex = 0;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolname
            // 
            this.toolname.Name = "toolname";
            this.toolname.Size = new System.Drawing.Size(72, 17);
            this.toolname.Text = "TOOLNAME";
            // 
            // filename
            // 
            this.filename.Name = "filename";
            this.filename.Overflow = System.Windows.Forms.ToolStripItemOverflow.Never;
            this.filename.Size = new System.Drawing.Size(372, 17);
            this.filename.Spring = true;
            this.filename.Text = "Filename";
            this.filename.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // toolStrip1
            // 
            this.toolStrip1.GripMargin = new System.Windows.Forms.Padding(0);
            this.toolStrip1.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.NewButton,
            this.openButton,
            this.saveButton});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Padding = new System.Windows.Forms.Padding(0);
            this.toolStrip1.RenderMode = System.Windows.Forms.ToolStripRenderMode.Professional;
            this.toolStrip1.Size = new System.Drawing.Size(571, 25);
            this.toolStrip1.Stretch = true;
            this.toolStrip1.TabIndex = 1;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // NewButton
            // 
            this.NewButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.NewButton.Image = global::DungMaker.Properties.Resources.open;
            this.NewButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.NewButton.Name = "NewButton";
            this.NewButton.Size = new System.Drawing.Size(35, 22);
            this.NewButton.Text = "New";
            this.NewButton.TextImageRelation = System.Windows.Forms.TextImageRelation.TextBeforeImage;
            this.NewButton.Click += new System.EventHandler(this.NewButton_Click);
            // 
            // openButton
            // 
            this.openButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.openButton.Image = ((System.Drawing.Image)(resources.GetObject("openButton.Image")));
            this.openButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.openButton.Name = "openButton";
            this.openButton.Size = new System.Drawing.Size(40, 22);
            this.openButton.Text = "Open";
            this.openButton.Click += new System.EventHandler(this.openButton_Click);
            // 
            // saveButton
            // 
            this.saveButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.saveButton.Image = ((System.Drawing.Image)(resources.GetObject("saveButton.Image")));
            this.saveButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.saveButton.Name = "saveButton";
            this.saveButton.Size = new System.Drawing.Size(35, 22);
            this.saveButton.Text = "Save";
            this.saveButton.Click += new System.EventHandler(this.saveButton_Click);
            // 
            // itempannel
            // 
            this.itempannel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.itempannel.Location = new System.Drawing.Point(27, 28);
            this.itempannel.Name = "itempannel";
            this.itempannel.Size = new System.Drawing.Size(541, 491);
            this.itempannel.TabIndex = 2;
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.DefaultExt = "dnglv";
            this.openFileDialog1.FileName = "DungFile";
            this.openFileDialog1.Filter = "Dung files|*.dnglv";
            // 
            // saveFileDialog1
            // 
            this.saveFileDialog1.DefaultExt = "dnglv";
            this.saveFileDialog1.Filter = "Dung files|*.dnglv";
            // 
            // toolStrip2
            // 
            this.toolStrip2.Dock = System.Windows.Forms.DockStyle.Left;
            this.toolStrip2.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
            this.toolStrip2.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.FloorTool,
            this.walltool,
            this.breakablewalltool,
            this.toolStripSeparator1,
            this.treasurechesttool,
            this.pottool,
            this.trapfloortool,
            this.torchtool,
            this.lowlvtool,
            this.midlvtool,
            this.highlvtool,
            this.watertool,
            this.bosstool});
            this.toolStrip2.Location = new System.Drawing.Point(0, 25);
            this.toolStrip2.Name = "toolStrip2";
            this.toolStrip2.RenderMode = System.Windows.Forms.ToolStripRenderMode.System;
            this.toolStrip2.Size = new System.Drawing.Size(24, 499);
            this.toolStrip2.TabIndex = 3;
            this.toolStrip2.Text = "toolStrip2";
            // 
            // FloorTool
            // 
            this.FloorTool.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.FloorTool.Image = global::DungMaker.Properties.Resources.floor;
            this.FloorTool.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.FloorTool.Name = "FloorTool";
            this.FloorTool.Size = new System.Drawing.Size(29, 20);
            this.FloorTool.Text = "Floor";
            this.FloorTool.Click += new System.EventHandler(this.FloorTool_Click);
            // 
            // walltool
            // 
            this.walltool.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.walltool.Image = global::DungMaker.Properties.Resources.wall;
            this.walltool.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.walltool.Name = "walltool";
            this.walltool.Size = new System.Drawing.Size(29, 20);
            this.walltool.Text = "toolStripButton2";
            this.walltool.Click += new System.EventHandler(this.walltool_Click);
            // 
            // breakablewalltool
            // 
            this.breakablewalltool.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.breakablewalltool.Image = global::DungMaker.Properties.Resources._break;
            this.breakablewalltool.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.breakablewalltool.Name = "breakablewalltool";
            this.breakablewalltool.Size = new System.Drawing.Size(29, 20);
            this.breakablewalltool.Text = "toolStripButton3";
            this.breakablewalltool.Click += new System.EventHandler(this.breakablewalltool_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(21, 6);
            // 
            // treasurechesttool
            // 
            this.treasurechesttool.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.treasurechesttool.Image = global::DungMaker.Properties.Resources.treasure;
            this.treasurechesttool.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.treasurechesttool.Name = "treasurechesttool";
            this.treasurechesttool.Size = new System.Drawing.Size(29, 20);
            this.treasurechesttool.Text = "toolStripButton4";
            this.treasurechesttool.Click += new System.EventHandler(this.treasurechesttool_Click);
            // 
            // pottool
            // 
            this.pottool.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.pottool.Image = global::DungMaker.Properties.Resources.pot;
            this.pottool.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.pottool.Name = "pottool";
            this.pottool.Size = new System.Drawing.Size(29, 20);
            this.pottool.Text = "toolStripButton5";
            this.pottool.Click += new System.EventHandler(this.pottool_Click);
            // 
            // trapfloortool
            // 
            this.trapfloortool.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.trapfloortool.Image = global::DungMaker.Properties.Resources.trap;
            this.trapfloortool.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.trapfloortool.Name = "trapfloortool";
            this.trapfloortool.Size = new System.Drawing.Size(29, 20);
            this.trapfloortool.Text = "toolStripButton6";
            this.trapfloortool.Click += new System.EventHandler(this.trapfloortool_Click);
            // 
            // torchtool
            // 
            this.torchtool.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.torchtool.Image = global::DungMaker.Properties.Resources.torch;
            this.torchtool.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.torchtool.Name = "torchtool";
            this.torchtool.Size = new System.Drawing.Size(29, 20);
            this.torchtool.Text = "toolStripButton10";
            this.torchtool.Click += new System.EventHandler(this.torchtool_Click);
            // 
            // lowlvtool
            // 
            this.lowlvtool.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.lowlvtool.Image = global::DungMaker.Properties.Resources.low;
            this.lowlvtool.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.lowlvtool.Name = "lowlvtool";
            this.lowlvtool.Size = new System.Drawing.Size(29, 20);
            this.lowlvtool.Text = "toolStripButton7";
            this.lowlvtool.Click += new System.EventHandler(this.lowlvtool_Click);
            // 
            // midlvtool
            // 
            this.midlvtool.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.midlvtool.Image = global::DungMaker.Properties.Resources.mid;
            this.midlvtool.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.midlvtool.Name = "midlvtool";
            this.midlvtool.Size = new System.Drawing.Size(29, 20);
            this.midlvtool.Text = "toolStripButton8";
            this.midlvtool.Click += new System.EventHandler(this.midlvtool_Click);
            // 
            // highlvtool
            // 
            this.highlvtool.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.highlvtool.Image = global::DungMaker.Properties.Resources.high;
            this.highlvtool.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.highlvtool.Name = "highlvtool";
            this.highlvtool.Size = new System.Drawing.Size(29, 20);
            this.highlvtool.Text = "toolStripButton9";
            this.highlvtool.Click += new System.EventHandler(this.highlvtool_Click);
            // 
            // watertool
            // 
            this.watertool.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.watertool.Image = global::DungMaker.Properties.Resources.water;
            this.watertool.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.watertool.Name = "watertool";
            this.watertool.Size = new System.Drawing.Size(29, 20);
            this.watertool.Text = "toolStripButton11";
            this.watertool.Click += new System.EventHandler(this.watertool_Click);
            // 
            // bosstool
            // 
            this.bosstool.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bosstool.Image = global::DungMaker.Properties.Resources.boss;
            this.bosstool.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.bosstool.Name = "bosstool";
            this.bosstool.Size = new System.Drawing.Size(29, 20);
            this.bosstool.Text = "toolStripButton12";
            this.bosstool.Click += new System.EventHandler(this.bosstool_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(571, 546);
            this.Controls.Add(this.toolStrip2);
            this.Controls.Add(this.itempannel);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.statusStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Dungeon Editor";
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.toolStrip2.ResumeLayout(false);
            this.toolStrip2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolname;
        private System.Windows.Forms.ToolStripStatusLabel filename;
        private System.Windows.Forms.ToolStripButton NewButton;
        private System.Windows.Forms.ToolStripButton openButton;
        private System.Windows.Forms.ToolStripButton saveButton;
        private System.Windows.Forms.Panel itempannel;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.ToolStrip toolStrip2;
        private System.Windows.Forms.ToolStripButton FloorTool;
        private System.Windows.Forms.ToolStripButton walltool;
        private System.Windows.Forms.ToolStripButton breakablewalltool;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripButton treasurechesttool;
        private System.Windows.Forms.ToolStripButton pottool;
        private System.Windows.Forms.ToolStripButton trapfloortool;
        private System.Windows.Forms.ToolStripButton lowlvtool;
        private System.Windows.Forms.ToolStripButton midlvtool;
        private System.Windows.Forms.ToolStripButton highlvtool;
        private System.Windows.Forms.ToolStripButton torchtool;
        private System.Windows.Forms.ToolStripButton watertool;
        private System.Windows.Forms.ToolStripButton bosstool;
    }
}

