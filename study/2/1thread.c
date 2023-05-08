#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*This example show how the threads are executed at the same time
  Both functions are executed at the same time and their output is mixed
*/


void *func1(void *arg)
{
    (void)arg;
    for (int i = 0; i < 100; i++)
    {
        printf("\033[91mthread 1: %d\n\033[0m", i);
    }
}

void *func2(void *arg)
{
    (void)arg;
    for (int i = 0; i < 100; i++)
    {
        printf("\033[95mthread 2: %d\n\033[0m", i);
    }
}


int main(void)
{
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, func1, NULL);
    pthread_create(&t2, NULL, func2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    
    return (0);
}