#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_th
{
    int mails;
    pthread_mutex_t my_mut;
    pthread_t   th[4];
}   t_th;

void    *increment(void * st)
{
    int i;
    t_th    *tt;

    tt = (t_th *)st;
    i = 0;
    while (i < 1000000)
    {
        pthread_mutex_lock(&tt->my_mut);
        tt->mails++;
        pthread_mutex_unlock(&tt->my_mut);
        i++;
    }
    return (NULL);
}

int main(void)
{
    t_th *tt;
    int     i;

    tt = malloc(sizeof(t_th));
    i = 0;
    tt->mails = 0;
    pthread_mutex_init(&tt->my_mut, NULL);
    while (i < 4)
    {
        pthread_create(tt->th + i, NULL, &increment, (void *)tt);
        printf("Thread %d has started\n", i);
        i++;
    }
    i = 0;
    while (i < 4)
    {
        pthread_join(tt->th[i], NULL);
        printf("Thread %d finished\n", i);
        i++;
    }
    pthread_mutex_destroy(&tt->my_mut);
    printf("Number of mails: %d\n", tt->mails);
    return (0);
}