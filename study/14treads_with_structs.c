#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_th
{
    int nb_of_threads;
    int mails;
    int var;
    pthread_mutex_t *my_mut;
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
        pthread_mutex_lock(&tt->my_mut[0]);
        tt->mails++;
        pthread_mutex_unlock(&tt->my_mut[0]);
        pthread_mutex_lock(&tt->my_mut[1]);
        tt->var++;
        pthread_mutex_unlock(&tt->my_mut[1]);
        
        i++;
    }
    return (NULL);
}

void    init_tt(t_th *tt, int nb)
{
    tt->nb_of_threads = nb;
    tt->mails = 0;
    tt->var = 0;
    tt->th = malloc(sizeof(pthread_t) * tt->nb_of_threads);
    tt->my_mut = malloc(sizeof(pthread_mutex_t) * tt->nb_of_threads);
}

void	mut_init(t_th *tt)
{
    int i =0;
    while (i < 2)
    {
        pthread_mutex_init(&tt->my_mut[i], NULL);
        i++;
    }
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
    mut_init(tt);
    //pthread_mutex_init(&tt->my_mut, NULL);
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
   //pthread_mutex_destroy(&tt->my_mut);
    printf("Number of mails: %d\n", tt->mails);
    printf("Number of var: %d\n", tt->var);
    pthread_mutex_destroy(&tt->my_mut[0]);
    pthread_mutex_destroy(&tt->my_mut[1]);
    free(tt->th);
    free(tt->my_mut);
    free(tt);
    return (0);
}
