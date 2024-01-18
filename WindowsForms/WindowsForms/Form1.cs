using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Drawing.Text;

namespace WindowsForms
{
	public partial class Form1 : Form
	{
		bool showDate;
		bool showControls;
		ChooseFont chooseFont;
		public Form1()
		{
			InitializeComponent();
			this.StartPosition = FormStartPosition.Manual;
			int startX = Screen.PrimaryScreen.Bounds.Width - this.Width - 25;
			int startY = 25;
			this.SetDesktopLocation(startX, startY);
			ControlsVisibility(false);
			showDate = false;
			showControls = false;
			Directory.SetCurrentDirectory("..\\..\\Fonts");
			chooseFont = new ChooseFont();
			label1.ForeColor = Color.Red;
			label1.BackColor = Color.Black;
		}
		void ControlsVisibility(bool visible)
		{
			cbShowDate.Visible = visible;
			btnExit.Visible = visible;
			btnHideControls.Visible = visible;
			btnChooseFont.Visible = visible;
			this.ShowInTaskbar = visible;
			this.TransparencyKey = !visible ? SystemColors.Control : Color.White;
			this.FormBorderStyle = !visible ? FormBorderStyle.None : FormBorderStyle.Sizable;
			showControlsToolStripMenuItem.Checked = visible;
		}

		private void timer1_Tick(object sender, EventArgs e)
		{
			//https://learn.microsoft.com/en-us/dotnet/standard/base-types/standard-date-and-time-format-strings
			//https://learn.microsoft.com/en-us/dotnet/standard/base-types/custom-date-and-time-format-strings
			label1.Text = DateTime.Now.ToString("hh:mm:ss tt");
			//label2.Text = DateTime.Now.ToString("yyyy.MM.dd ddd");
			//label2.Visible = cbShowDate.Checked;
			if (cbShowDate.Checked)
			{
				string date = DateTime.Now.ToString("yyyy.MM.dd ddd");
				label1.Text = $"{label1.Text}\n{date}";
			}
		}

		private void btnExit_Click(object sender, EventArgs e)
		{
			this.Close();
		}

		private void btnHideControls_Click(object sender, EventArgs e)
		{
			showControls = false;
			ControlsVisibility(showControls);
		}

		private void label1_MouseHover(object sender, EventArgs e)
		{
			ControlsVisibility(true);
		}

		private void showDateToolStripMenuItem_Click(object sender, EventArgs e)
		{
			showDate = showDateToolStripMenuItem.Checked;
			cbShowDate.Checked = showDate;
		}

		private void showControlsToolStripMenuItem_Click(object sender, EventArgs e)
		{
			showControls = showControlsToolStripMenuItem.Checked;
			ControlsVisibility(showControls);
		}

		private void btnChooseFont_Click(object sender, EventArgs e)
		{
			//chooseFont.NewFont = label1.Font;
			DialogResult result = chooseFont.ShowDialog(this);
			if (result == DialogResult.OK)
			{
				label1.Font = chooseFont.NewFont; 
			}
		}
	}
}
