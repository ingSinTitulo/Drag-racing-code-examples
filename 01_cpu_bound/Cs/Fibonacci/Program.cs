using System;
using System.Diagnostics;

class Program
{
    static long Fibonacci(int n)
    {
        if (n <= 1) return n;
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }

    static void Main()
    {
        var stopwatch = new Stopwatch();
        stopwatch.Start();

        long result = Fibonacci(40);

        stopwatch.Stop();
        Console.WriteLine($"Fibonacci(40) = {result}");
        Console.WriteLine($"Execution time: {stopwatch.ElapsedMilliseconds} ms");
    }
}