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

namespace WindowsForms
{
	public partial class AddAlarm : Form
	{
		public Alarm Alarm { get; set; }
		public AddAlarm()
		{
			InitializeComponent();
			dateTimePickerTime.CustomFormat = "hh:mm:ss";
			dateTimePickerTime.ShowUpDown = true;
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

		private void buttonAdd_Click(object sender, EventArgs e)
		{
			string filename = "";
			OpenFileDialog openFileDialog = new OpenFileDialog();
			openFileDialog.Multiselect = false;
			DialogResult result = openFileDialog.ShowDialog();
			if (result == DialogResult.OK)
			{
				filename = openFileDialog.SafeFileName;
				Alarm = new Alarm(dateTimePickerTime.Value, filename);
			}
			labelFilename.Text = Alarm.ToString();
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
			labelBitset.Text = $"Bitset:{Convert.ToString(GetBitSet(), 2).Reverse()}";
		}
	}
}
