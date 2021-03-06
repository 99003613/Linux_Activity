#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#define max 6
#define size 6

int in = 0;
int out= 0;
int buffer[size];
pthread_mutex_t mutex;
void *producer(void *pno)
{
    int item;
    for(int i = 0; i < max; i++) {
        itm = rand();
        pthread_mutex_lock(&mutex);
         while (((in + 1) % size) == out)
        {
           buffer[in] = item;
           printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
           in= (in + 1) % size;
        }
        pthread_mutex_unlock(&mutex);
    }
}
void *consumer(void *cno)
{
    int item=0;
    for(int i = 0; i < max; i++) {
        pthread_mutex_lock(&mutex);
        while (in== out)
        {
           item = buffer[out];
           printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out);
           out = (out + 1) % size;
        }
        pthread_mutex_unlock(&mutex);
    }
}
int main()
{
    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex, NULL);
    int arr[6] = {1,2,3,4,5,6}; 
    for(int i = 0; i < 6; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&arr[i]);
    }
    for(int i = 0; i < 6; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&arr[i]);
    }
    for(int i = 0; i < 6; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 6; i++) {
        pthread_join(con[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}