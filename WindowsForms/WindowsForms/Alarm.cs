using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsForms
{
	public class Alarm
	{
		public DateTime Date { get; set; }
		public DateTime Time { get; set; }
		public WeekDays WeekDays { get; set; }
		public string Filename { get; set; }
		public Alarm(DateTime time, string filename)
		{
			this.Time = time;
			this.Filename = filename;
		}
		public Alarm(DateTime time, string filename, byte weekdays):this(time, filename)
		{
			this.WeekDays = new WeekDays(weekdays);
		}
		public Alarm(DateTime time, string filename, CheckedListBox weekdays):this(time, filename)
		{
			this.WeekDays = new WeekDays(weekdays);
		}


		//public static bool operator ==(Alarm left, Alarm right)
		//{
		//	return left?.ToString() == right?.ToString();
		//}
		//public static bool operator !=(Alarm left, Alarm right)
		//{
		//	return left?.ToString() == right?.ToString();
		//}

		public override string ToString()
		{
			return $"Date:\t{Date.ToShortDateString()}\nTime:\t{Time.ToString("hh:mm:ss tt")}\nWeekDays:\t{WeekDays.ToString()}\nFile:\t{Filename.Split('\\').Last()}";
		}
	}
}
