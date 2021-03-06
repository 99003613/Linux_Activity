#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define BufferSize 10

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[size];
int max;

void *producer(void *pno)
{   
    int item;
    for(int i = 0; i < max; i++) {
        item = rand(); 
        sem_wait(&empty);
        while (((in + 1) % size) == out)
        {
           buffer[in] = item;
           printf("producer no. %d: insert item %d at %d\n", *((int *)pno),buffer[in],in);
           in = (in + 1) % size;     
        }
        sem_post(&full);
    }
}
void *consumer(void *cno)
{
    int item=0;
    for(int i = 0; i < max; i++) {
        sem_wait(&full);
        while (in == out) 
        {
           item = buffer[out];
           printf("comsumer %d: remove item  %d from %d\n",*((int *)cno),item, out); 
           out = (out + 1) % size; 
        }
        sem_post(&empty);
    }
}

int main()
{

    pthread_t pro[5],con[5];
    sem_init(&empty,0,size);
    sem_init(&full,0,0);

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

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}