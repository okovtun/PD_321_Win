﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsForms
{
	public class WeekDays
	{
		string[] names = new string[] { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
		byte days;
		public byte Days
		{
			get => days;
			set
			{
				if (value > 128) value -= 128;
				days = value;
			}
		}
		public WeekDays(byte bitset)
		{
			Days = bitset;
		}
		public WeekDays(CheckedListBox checkedListBoxDays)
		{
			GetBitSet(checkedListBoxDays);
		}
		public byte GetBitSet(CheckedListBox checkedListBoxDays)
		{
			days = 0;
			for (int i = 0; i < checkedListBoxDays.CheckedIndices.Count; i++)
			{
				byte day = (byte)Math.Pow(2, checkedListBoxDays.CheckedIndices[i]);
				days += day;
			}
			return days;
		}
		public override string ToString()
		{
			string week = "";
			for (int i = 0; i < 7; i++)
			{
				byte day = 1;
				day <<= i;	//2^i
				if ((days & day) != 0)
					week += names[i]+",";
			}
			return week;
		}
		public bool CheckDay(DayOfWeek dayOfWeek)
		{
			byte day = 1;
			day <<= (int)dayOfWeek - 1;
			return (days & day) != 0 ? true : false;
		}
	}
}
