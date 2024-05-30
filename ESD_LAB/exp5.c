/*Write a C program to show thread demonstrating the use of a mutex to synchronise access to a shared variable by two threads. One increments the variable, while the other decrements it.*/

#include <stdio.h>
#include <pthread.h>

#define Max 10
int counter = 0;
pthread_mutex_t mutex;

void *up_counter(void *arg) 
{
    for (int i = 0; i < Max; ++i) 
    {
        pthread_mutex_lock(&mutex);
        counter++;
        printf("Upcount:%d\n", counter);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *down_counter(void *arg) 
{
    for (int i = 0; i < Max; ++i) 
    {
        pthread_mutex_lock(&mutex);
        counter--;
        printf("Downcount:%d\n", counter);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t th_up, th_down;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&th_up, NULL, up_counter, NULL);
    pthread_join(th_up, NULL);  // Wait for up_counter to finish

    pthread_create(&th_down, NULL, down_counter, NULL);
    pthread_join(th_down, NULL);  // Wait for down_counter to finish

    pthread_mutex_destroy(&mutex);

    return 0;
}

