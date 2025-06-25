#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <curl/curl.h>
#include <sys/time.h>

#define NUM_THREADS 10
#define URL "https://httpbin.org/delay/1"

void *perform_request(void *arg) {
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL); // Ignore response body
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    curl_global_init(CURL_GLOBAL_ALL);

    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Crear hilos
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, perform_request, NULL);
    }

    // Esperar que todos terminen
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    gettimeofday(&end, NULL);

    curl_global_cleanup();

    double elapsed = (end.tv_sec - start.tv_sec) * 1000.0;
    elapsed += (end.tv_usec - start.tv_usec) / 1000.0;
    printf("All requests completed in %.2f ms\n", elapsed);

    return 0;
}
