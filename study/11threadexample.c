#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void    *print_hello(void *arg)
{
    int i;

    i = 0;
    while (i < 100)
    {
        printf("Hello\n");
        i++;
        usleep(10000);
    }
    return (NULL);
}
void    *print_world(void *arg)
{
    int i;

    i = 0;
    while (i < 100)
    {
        printf("\t\tWorld\n");
        i++;
        usleep(10000);
    }
    return (NULL);
}



void    example1()
{
    print_hello(NULL);
    print_world(NULL);    
}
void    example2()
{
    pthread_t   t1;
    pthread_t   t2;

    pthread_create(&t1, NULL, print_hello, NULL);
    pthread_create(&t2, NULL, print_world, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
void    *myfunction(void *arg)
{
    int *num;
    int i;

    num = (int *)arg;
    i = 0;
    while (i < 1000000)
    {
        (*num)++;
        i++;
    }
    return (NULL);
}

void    example3()
{
    int     *num;
    pthread_t   t1;
    pthread_t   t2;

    num = malloc(sizeof(int));
    *num = 0;
    pthread_create(&t1, NULL, myfunction, num);
    pthread_create(&t2, NULL, myfunction, num);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Num: %d\n", *num);

}


int     main(void)
{
    example3();
    return (0);
}