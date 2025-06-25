import asyncio
import aiohttp # pip install aiohttp
import time

URL = 'https://httpbin.org/delay/1'

async def fetch(session, url):
    async with session.get(url) as response:
        await response.text()

async def main():
    async with aiohttp.ClientSession() as session:
        tasks = [fetch(session, URL) for _ in range(10)]
        start = time.time()
        await asyncio.gather(*tasks)
        end = time.time()
        print(f"All requests completed in {(end - start) * 1000:.2f} ms")

if __name__ == '__main__':
    asyncio.run(main())
