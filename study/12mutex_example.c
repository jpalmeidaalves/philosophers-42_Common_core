#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_data
{
    int num;
    pthread_mutex_t mutex;

}   t_data;

void    free_data(t_data *data)
{
    pthread_mutex_destroy(&data->mutex);
    free(data);
}

t_data    *init_data()
{
    t_data *data;

    data = malloc(sizeof(t_data));
    data->num = 0;
    pthread_mutex_init(&data->mutex, NULL);
    return (data);
}

void    *funct(void *arg)
{
    int     i;
    t_data  *data;

    data = (t_data *)arg;
    i = 0;
    while (i < 10000000)
    {
        //printf("1");
        pthread_mutex_lock(&data->mutex);
        //printf("2");
        (data->num)++;
        //printf("3");
        pthread_mutex_unlock(&data->mutex);
        //printf("4");
        i++;
    }
    return (NULL);
}

int     main(void)
{
    pthread_t   t1;
    pthread_t   t2;
    t_data  *data;  

    data = init_data();   
    pthread_create(&t1, NULL, funct, data);
    pthread_create(&t2, NULL, funct, data);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("NUM: %d\n", data->num);
    free_data(data);
    return (0);
}