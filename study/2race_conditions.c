#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;

//race condition happens when different threads try to read/write to the memory in an asychronous way
void    *my_routine()
{
    //in this case a thread would read, increment and write
    for (int i = 0; i < 1000000; i++)
    mails++;
}

int main(void)
{
    //declare a variable of 'pthread_t' type
    pthread_t   t1;
    pthread_t   t2;
    //initialize and start a thread passing the function to be executed by the thread
    if (pthread_create(&t1, NULL, &my_routine, NULL) != 0)
        return (1);
    if (pthread_create(&t2, NULL, &my_routine, NULL) != 0)
        return (2);

    //make the processs wait till the thread is finished to finish
    if (pthread_join(t1, NULL) != 0)
        return (3);
    if (pthread_join(t2, NULL) != 0)
        return (4);
    printf("Number of mails: %d\n", mails);
    return (0);
}