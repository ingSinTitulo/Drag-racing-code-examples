using System;
using System.Diagnostics;
using System.IO;

class Program
{
    static void Main()
    {
        var stopwatch = new Stopwatch();
        stopwatch.Start();

        int lineCount = 0;
        using (var reader = new StreamReader("../../bigfile.txt"))
        {
            while (reader.ReadLine() != null)
            {
                lineCount++;
            }
        }

        stopwatch.Stop();
        Console.WriteLine($"Total lines: {lineCount}");
        Console.WriteLine($"Execution time: {stopwatch.ElapsedMilliseconds} ms");
    }
}
