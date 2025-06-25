const { performance } = require('perf_hooks');
const fetch = require('node-fetch'); // npm install node-fetch@2

const URL = 'https://httpbin.org/delay/1';

async function main() {
  const start = performance.now();

  const requests = Array.from({ length: 10 }, () => fetch(URL));
  await Promise.all(requests);

  const end = performance.now();
  console.log(`All requests completed in ${(end - start).toFixed(2)} ms`);
}

main();
