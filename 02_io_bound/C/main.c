#include <stdio.h>
#include <time.h>

int main() {
    FILE *file = fopen("../bigfile.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    clock_t start = clock();

    int lineCount = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file)) {
        lineCount++;
    }

    clock_t end = clock();
    fclose(file);

    double timeTaken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    printf("Total lines: %d\n", lineCount);
    printf("Execution time: %.2f ms\n", timeTaken);

    return 0;
}
