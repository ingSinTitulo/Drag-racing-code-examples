import time

def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)

start = time.time()
result = fibonacci(40)
end = time.time()

print(f"Fibonacci(40) = {result}")
print(f"Execution time: {(end - start) * 1000:.2f} ms")