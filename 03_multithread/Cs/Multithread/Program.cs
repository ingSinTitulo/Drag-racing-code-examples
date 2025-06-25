using System;
using System.Net.Http;
using System.Threading.Tasks;
using System.Diagnostics;

class Program
{
    static async Task Main()
    {
        var httpClient = new HttpClient();
        string url = "https://httpbin.org/delay/1";

        var stopwatch = Stopwatch.StartNew();

        var tasks = new Task[10];
        for (int i = 0; i < 10; i++)
        {
            tasks[i] = httpClient.GetStringAsync(url);
        }

        await Task.WhenAll(tasks);

        stopwatch.Stop();
        Console.WriteLine($"All requests completed in {stopwatch.ElapsedMilliseconds} ms");
    }
}
