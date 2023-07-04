#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void    *computation(void *add)
{
    long sum = 0;
    long i = 0;
    long    *add_num = (long *) (add);

    while (i < 2000000000)
    {
        sum += *add_num;
        i++;
    }
    printf("Sum: %ld\n", sum);
    return (NULL);
}

int     main(void)
{
//    pthread_t   t1;
//    pthread_t   t2;


    long    value1 = 1;
    long    value2 = 2;
//uncoment this part to see the execution time in a single thread

    computation((void *)&value1);
    computation((void *)&value2);

//uncoment this part to see the execution time with two threads

    // pthread_create(&t1, NULL, computation, (void *)&value1);
    // pthread_create(&t2, NULL, computation, (void *)&value2);

    // pthread_join(t1, NULL);
    // pthread_join(t2, NULL);

    return (0);
}