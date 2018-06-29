using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;
using System.Runtime.InteropServices;


namespace zlaser_cs
{
	class Program
	{
		[DllImport("zlaser.dll")]
		static extern bool zl_device_open(string port, ref int hComm);		

		static void Main(string[] args)
		{
			int comm = 0;
			zl_device_open("1234", ref comm);
		}
	}
}
