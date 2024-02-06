using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DateTimeComparison
{
	class Program
	{
		static void Main(string[] args)
		{
			DateTime dateTime = new DateTime(2024, 2, 1, 16, 4, 4);
			Console.WriteLine(dateTime.CompareTo(DateTime.Now));
			Console.WriteLine(dateTime - DateTime.Now);
			TimeSpan interval1 = new TimeSpan(0, 0, 3, 0);
			TimeSpan interval2 = new TimeSpan(0, 0, 5, 0);
			Console.WriteLine(interval1);
			Console.WriteLine(interval2);
			Console.WriteLine(interval1 < interval2);
			Console.WriteLine(interval1 > interval2);
			Console.WriteLine("\n---------------------------------\n");
			Console.WriteLine((int)DateTime.Now.DayOfWeek);
			DateTime day = new DateTime(2024, 2, 4);
			Console.WriteLine((int)day.DayOfWeek);
		}
	}
}
