using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Media;

namespace WindowsForms
{
	public partial class AddAlarm : Form
	{
		int index;
		public bool IntervalOK { get; private set; }
		HashSet<Alarm> alarms;
		public Alarm Alarm { get; set; }
		public AddAlarm()
		{
			InitializeComponent();
			dateTimePickerTime.CustomFormat = "hh:mm:ss";
			dateTimePickerTime.ShowUpDown = true;
			IntervalOK = true;
			index = -1;
		}
		public AddAlarm(HashSet<Alarm> alarms) : this()
		{
			this.alarms = new HashSet<Alarm>(alarms);
		}
		public AddAlarm(HashSet<Alarm> alarms, int index) : this(alarms)
		{
			Alarm = alarms.ToArray()[index];
			SetDataFormAlarm();
			buttonAdd.Text = "Apply";
			this.index = index;
		}
		void SetDataFormAlarm()
		{
			if(Alarm.Date != new DateTime())dateTimePickerDate.Value = Alarm.Date;
			dateTimePickerTime.Value = Alarm.Time;
			labelFilename.Text = Alarm.ToString();
			axWindowsMediaPlayer1.URL = Alarm.Filename;
			axWindowsMediaPlayer1.Ctlcontrols.stop();
		}
		public byte GetBitSet()
		{
			byte days = 0;
			for (int i = 0; i < checkedListBoxDays.CheckedIndices.Count; i++)
			{
				byte day = (byte)Math.Pow(2, checkedListBoxDays.CheckedIndices[i]);
				days += day;
			}
			return days;
		}

		private void buttonChooseFile_Click(object sender, EventArgs e)
		{
			string filename = "";
			OpenFileDialog openFileDialog = new OpenFileDialog();
			openFileDialog.Multiselect = false;
			DialogResult result = openFileDialog.ShowDialog();
			if (result == DialogResult.OK)
			{
				filename = openFileDialog.FileName;
				if (Alarm == null) Alarm = new Alarm(dateTimePickerTime.Value, filename);
				else Alarm.Filename = filename;
				labelFilename.Text = Alarm.ToString();
				axWindowsMediaPlayer1.URL = Alarm.Filename;
				axWindowsMediaPlayer1.Ctlcontrols.stop();
			}
		}
		[DllImport("kernel32.dll")]
		static extern bool AllocConsole();

		private void checkedListBoxDays_SelectedIndexChanged(object sender, EventArgs e)
		{
			//AllocConsole();
			//Console.Write($"Days:\t");
			//for (int i = 0; i < checkedListBoxDays.CheckedItems.Count; i++)
			//{
			//	Console.Write(checkedListBoxDays.CheckedItems[i] + "\t");
			//}
			//Console.WriteLine();
			//Console.Write($"Days:\t");
			//for (int i = 0; i < checkedListBoxDays.CheckedIndices.Count; i++)
			//{
			//	Console.Write(checkedListBoxDays.CheckedIndices[i] + "\t");
			//}

			//Console.WriteLine("\n------------------------\n");
			labelBitset.Text = $"Bitset:{Convert.ToString(GetBitSet(), 2)}";
		}

		private void buttonPlay_Click(object sender, EventArgs e)
		{
			SoundPlayer soundPlayer = new SoundPlayer(Alarm.Filename);
			soundPlayer.Play();
		}
		private void AddAlarm_Closing(object sender, FormClosingEventArgs e)
		{
			axWindowsMediaPlayer1.Ctlcontrols.stop();
			//buttonAdd.DialogResult = DialogResult.None;
			//MessageBox.Show(this, "Buy", "Buy", MessageBoxButtons.OK);
		}

		private void buttonCancel_Click(object sender, EventArgs e)
		{
			this.Close();
		}

		private void buttonAdd_Click(object sender, EventArgs e)
		{
			if (buttonAdd.Text == "Apply")
			{
				Alarm.Date = dateTimePickerDate.Value;
				Alarm.Time = dateTimePickerTime.Value;
				Alarm[] alarms = this.alarms.ToArray();
				alarms[index] = Alarm;
				this.alarms = new HashSet<Alarm>(alarms);
				this.Close();
				return;
			}
			//buttonAdd.DialogResult = DialogResult.None;
			IntervalOK = true;
			if (alarms != null && Alarm != null)
			{
				Alarm.Time = dateTimePickerTime.Value;
				TimeSpan interval = new TimeSpan(0, 0, 3, 0);
				for (int i = 0; i < alarms.Count; i++)
				{
					DateTime old_time = alarms.ToArray()[i].Time;
					TimeSpan current_interval = Alarm.Time - old_time;
					string message = $@"
Too short interval:
Interval:		{interval.ToString()}
CurrentInterval:{current_interval.ToString()}

";
					if (current_interval < interval)
					{
						MessageBox.Show(this, message, "Info", MessageBoxButtons.OK, MessageBoxIcon.Information);
						IntervalOK = false;
						return;
					}
				}
			}
			//buttonAdd.DialogResult = DialogResult.OK;
			this.Close();
		}
	}
}
