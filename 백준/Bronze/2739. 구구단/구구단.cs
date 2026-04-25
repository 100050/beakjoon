using System;

class Sample
{
    public static void Main()
    {
        string a = Console.ReadLine();
        int b = Int32.Parse(a);
        for (int i = 1; i < 10; i++)
        {
            Console.WriteLine(b + " * " + i + " = " + b * i);
        }
    }
}