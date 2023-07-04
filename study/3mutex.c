#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;
//declare a variable pthread_mutex_t and initializes it
pthread_mutex_t mutex;

void    *my_routine()
{
    for (int i = 0; i < 1000000; i++)
    {
        // control the acess to this memory area. Protect it from being acessed for more than one thread at a time
        pthread_mutex_lock(&mutex); //uncomment this line to see the effect of a mutex
        mails++;
        pthread_mutex_unlock(&mutex);
    }
    return (NULL);
}

int main(void)
{
    pthread_t   t1, t2, t3, t4;
    
    
    pthread_mutex_init(&mutex, NULL);
    
    if (pthread_create(&t1, NULL, &my_routine, NULL) != 0)
        return (1);
    if (pthread_create(&t2, NULL, &my_routine, NULL) != 0)
        return (2);
    if (pthread_create(&t3, NULL, &my_routine, NULL) != 0)
        return (2);
    if (pthread_create(&t4, NULL, &my_routine, NULL) != 0)
        return (2);
    if (pthread_join(t1, NULL) != 0)
        return (3);
    if (pthread_join(t2, NULL) != 0)
        return (4);
    if (pthread_join(t3, NULL) != 0)
        return (4);
    if (pthread_join(t4, NULL) != 0)
        return (4);
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
    return (0);
}