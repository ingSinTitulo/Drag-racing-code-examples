import time

start = time.time()

line_count = 0
with open("../bigfile.txt", "r", encoding="utf-8") as file:
    for _ in file:
        line_count += 1

end = time.time()

print(f"Total lines: {line_count}")
print(f"Execution time: {(end - start) * 1000:.2f} ms")
