function fibonacci(n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

const start = process.hrtime.bigint(); // tiempo en nanosegundos
const result = fibonacci(40); // número lo suficientemente grande para que tarde
const end = process.hrtime.bigint();

console.log(`Fibonacci(40) = ${result}`);
console.log(`Execution time: ${(end - start) / 1000000n} ms`);