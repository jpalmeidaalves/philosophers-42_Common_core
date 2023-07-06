#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_th
{
    int nb_of_threads;
    int mails;
    pthread_mutex_t my_mut;
    pthread_t   *th;
}   t_th;

void    *increment(void *st)
{
    int i;
    t_th    *tt;

    tt = (t_th *)st;
    i = 0;
    while (i < 10000000)
    {
        pthread_mutex_lock(&tt->my_mut);
        tt->mails++;
        pthread_mutex_unlock(&tt->my_mut);
        i++;
    }
    return (NULL);
}

void    init_tt(t_th *tt, int nb)
{
    tt->nb_of_threads = nb;
    tt->mails = 0;
    tt->th = malloc(sizeof(pthread_t) * tt->nb_of_threads);
}

int main(int ac, char **av)
{
    t_th *tt;
    int     i;

    if (ac != 2)
    {
        printf("Usage: ./14run [nb_of_threads]\n");
        return (1);
    }
    tt = malloc(sizeof(t_th));
    init_tt(tt, atoi(av[1]));
    printf("%d\n", tt->nb_of_threads);
    i = 0;
    pthread_mutex_init(&tt->my_mut, NULL);
    while (i < tt->nb_of_threads)
    {
        pthread_create(&tt->th[i], NULL, &increment, (void *)tt);
        printf("Thread %d has started\n", i);
        i++;
    }
    i = 0;
    while (i < tt->nb_of_threads)
    {
        pthread_join(tt->th[i], NULL);
        printf("Thread %d finished\n", i);
        i++;
    }
    pthread_mutex_destroy(&tt->my_mut);
    printf("Number of mails: %d\n", tt->mails);
    free(tt->th);
    free(tt);
    return (0);
}