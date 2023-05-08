#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

// typedef struct s_th
// {
//     pthread_t  philo1;
//     int     time_to_die;
//     int     time_to_eat;
//     int     time_to_sleep;
// }   t_th;


void *funct1(void * arg)
{
    printf("Philo 1 eating\n");
}

void *funct2(void * arg)
{
    
    printf("Philo 2 eating\n");
}

int main(void)
{
    pthread_t philo1;
    pthread_t philo2;
    pthread_mutex_t mutex1;
    pthread_mutex_t mutex2;

    int     time_to_die = 600;
    int     time_to_eat = 200;
    int     time_to_sleep = 200;
    
    // pthread_mutex_init(&mutex1, NULL);
    // pthread_mutex_init(&mutex2, NULL);

    pthread_create(&philo1, NULL, &funct1, NULL);
    pthread_create(&philo2, NULL, &funct2, NULL);

    pthread_join(philo1, NULL);
    pthread_join(philo2, NULL);


}