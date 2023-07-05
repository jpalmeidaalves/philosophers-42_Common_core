#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;

pthread_mutex_t mutex;

void    *my_routine()
{
    for (int i = 0; i < 100000000; i++)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
    return (NULL);
}

int main(void)
{
    pthread_t   th[4];
        
    pthread_mutex_init(&mutex, NULL);
    //The first loop initializes 4 threads to be executed simultaneously
    int i = 0;
    while (i < 4)
    {
        if (pthread_create(th + i, NULL, &my_routine, NULL) != 0)
        {
            perror("Failed to create thread");
            return(1);
        }
        printf("Thread %d has started\n", i);
        i++;
    }
    //The second loop makes the process wait the threads to finish to continue
    i = 0;
    while (i < 4)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread");
            return(1);
        }
        printf("Thread %d has finished its execution\n", i);
        i++;
    
    }

    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
    return (0);
}