using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;
using System.Runtime.InteropServices;


namespace zlaser_cs
{
	class Program
	{
		[DllImport("zlaser.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern bool zl_device_open(string port, ref int hComm);

		[DllImport("zlaser.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern bool zl_device_close(int hComm);

		[DllImport("zlaser.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern bool zl_device_read(int hComm, StringBuilder buff, int maxlen, ref int sizeRead);

		[DllImport("zlaser.dll", CallingConvention = CallingConvention.Cdecl)]
		static extern bool zl_device_convert_buffer(IntPtr inputBuffer, int size);

		static void Main(string[] args)
		{
			//we use handle to keep track of objects in DLL, hObj can simply be an index 
			//to an object entry in an array in C that stores the C++ objects
		
			int hObj = 0;

			//shows how to pass int by reference back to C# from dll
			zl_device_open("1234", ref hObj);

			Console.WriteLine("hObj=" + hObj);

			StringBuilder sb = new StringBuilder(100);
			int len = 0;

			//shows how to pass string back to C# from dll
			zl_device_read(hObj, sb, sb.Capacity, ref len);			
			Console.WriteLine(sb.ToString());

			//shows how to pass C# array to C dll
			byte[] imageData = new byte[100];

			//to access C# array directly from C the array object must be pinned down 
			//in memory or it might get destroyed by the C# garbage collector
			GCHandle handle;
			handle = GCHandle.Alloc(imageData, GCHandleType.Pinned);
			IntPtr outBuffer = handle.AddrOfPinnedObject();
			zl_device_convert_buffer(outBuffer, imageData.Length);							
			handle.Free();

			Console.WriteLine("First 10 bytes of imageData[]");
			for (int i = 0; i < 10; i++) {
				Console.Write(imageData[i] + " ");
			}

			//this should destroy the object associated to hObj
			zl_device_close(hObj);
		}
	}
}
