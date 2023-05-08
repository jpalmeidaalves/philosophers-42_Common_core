# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

// struct timeval
// {
//     time_t      tv_sec;     /* number of second since the epoch
//     suseconds_t tv_usec;    /* number of microseconds since the epoch*/
// };


int     main (void)
{
    time_t  t = time(NULL); // return the time in SECONDS since the epoch
    struct timeval x;
    gettimeofday(&x, NULL);
    printf ("seconds since the epoch: %ld\n", x.tv_sec);
    printf ("time %ld\n", x.tv_sec * 1000);
    printf ("microseconds since the epoch: %ld\n", x.tv_usec);
    printf ("time %ld\n", x.tv_usec / 1000);
    printf ("Actual time since the epoch: %ld\n", x.tv_sec * 1000 + x.tv_usec / 1000);
    printf ("Actual time since the epoch: %ld\n", t);
}
