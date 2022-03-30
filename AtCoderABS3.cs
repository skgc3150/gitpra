using System;
namespace ABC085C
{
    static class Program
    {
        static void Main(string[] args)
        {
 
		string s = Console.ReadLine();
    	int num = 0;
      
      	foreach(var b in s)
        {
        	if(b == '1')
            {
            num++;
        	}
         
      	}
		 Console.WriteLine($"{num}");
		}
    }
}