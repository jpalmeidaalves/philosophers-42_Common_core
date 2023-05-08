#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
*/


void *func1(void *arg)
{
    (void)arg;
    for (int i = 0; i < 100; i++)
    {
        printf("\033[95m%s\033[0m\n", (char *)arg);
    }
    pthread_exit(arg);
}

void *func2(void *arg)
{
    (void)arg;
    for (int i = 0; i < 100; i++)
    {
        printf("\033[91m%s\033[0m\n", (char *)arg);
    }
    pthread_exit(arg);
}

int main(void)
{
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, func1, "hello 1");
    pthread_create(&t2, NULL, func2, "hello 2");
    char *s1, *s2;
    pthread_join(t1, (void **)&s1);
    pthread_join(t2, (void **)&s2);
    printf ("%s %s\n", s1, s2);
   
    return (0);
}