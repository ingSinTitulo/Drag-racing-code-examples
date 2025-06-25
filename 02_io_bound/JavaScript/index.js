const fs = require('fs');
const readline = require('readline');
const { performance } = require('perf_hooks');

const start = performance.now();

let lineCount = 0;
const rl = readline.createInterface({
  input: fs.createReadStream('../bigfile.txt'),
  crlfDelay: Infinity
});

rl.on('line', () => {
  lineCount++;
});

rl.on('close', () => {
  const end = performance.now();
  console.log(`Total lines: ${lineCount}`);
  console.log(`Execution time: ${(end - start).toFixed(2)} ms`);
});
