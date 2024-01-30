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
using WMPLib;

namespace WindowsForms
{
	public partial class Alarms : Form
	{
		public Alarms()
		{
			InitializeComponent();
		}

		private void btnSelectSound_Click(object sender, EventArgs e)
		{
			OpenFileDialog openFileDialog = new OpenFileDialog();
			openFileDialog.Multiselect = false;
			DialogResult result = openFileDialog.ShowDialog();
			lblSoundFile.Text = openFileDialog.SafeFileName;
			lblCurrentDirectory.Text = Directory.GetCurrentDirectory();
			Stream file = openFileDialog.OpenFile();

			axWindowsMediaPlayer1.URL = openFileDialog.FileName;
			axWindowsMediaPlayer1.Ctlcontrols.play();
		}

		private void btnAddAlarm_Click(object sender, EventArgs e)
		{
			AddAlarm addAlarm = new AddAlarm();
			DialogResult result = addAlarm.ShowDialog(this);
			if (result == DialogResult.OK)
			{
				listBoxAlarms.Items.Add(addAlarm.Alarm.ToString());
			}
		}
	}
}
