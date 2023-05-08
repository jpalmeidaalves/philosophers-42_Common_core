#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void    *my_routine()
{
    printf("Testing threads\n");
    sleep(3);
    printf("ending threads\n");
}
/* int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
   The  pthread_create()  function  starts  a  new  thread  in the calling
   process.  The new thread starts execution by invoking routine() - 3rd argument.
   arg (4th argument) is passed as the sole argument of start_routine().
   The 2nd argument is a pointer to a structure  whose  contents are
   used  at thread creation time to determine attributes for the new thread,
   If its NULL, the thread is created with default attributes.
*/

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
    
    return (0);
}