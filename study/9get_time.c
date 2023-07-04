#include <stdio.h>
#include <sys/time.h>
#include <stdint.h>
#include <unistd.h>

/*
int gettimeofday(struct timeval *tv, struct timezone *tz);
The tv argument is a struct timeval (as specified in <sys/time.h>):

           struct timeval {
               time_t      tv_sec;      seconds 
               suseconds_t tv_usec;     microseconds
           };
Gives the number of seconds and microseconds since the Epoch
Remember:
    1 sec = 1 000 000 microseconds or 1 000 milliseconds

The tz argument is a struct timezone:

           struct timezone {
               int tz_minuteswest;      minutes west of Greenwich
               int tz_dsttime;          type of DST correction 
           };
If either tv or tz is NULL, the corresponding structure is not set or returned.
(However, compilation warnings will result if tv is NULL.)
The use of the timezone structure is obsolete; the tz argument should normally be 
specified as NULL.
*/
int     main(void)
{   
    //1st step - declare a variable of timeval type to be used as argument 
    struct timeval  t1;

    //2nd step - call the function passing the address os the variable
    gettimeofday(&t1, NULL);

    //3rd  step - acess the struct in order to get the time 
    long int my_time_in_secs = t1.tv_sec; 
    printf("seconds since the epoch: %ld\n", my_time_in_secs);
    long int my_time_in_usec = t1.tv_usec;
    printf("microseconds since the epoch: %ld\n", my_time_in_usec);

    /* To get the time in milliseconds (1sec = 1000 millisecs and
    1 millisec == 1000 microsseconds */
    long int nowtime = ((t1.tv_sec * (uint64_t)1000) + t1.tv_usec / 1000);
    printf("time in milliseconds since the epoch %ld\n", nowtime);

    /* To get the number of hours */
    long int minutes = my_time_in_secs / 60;
    printf ("Minutes since the epoch: %ld\n", minutes);
    long int hours = minutes / 60;
    printf ("Hours since the epoch: %ld\n", hours);
    long int days = hours / 24;
    printf ("Days since the epoch: %ld\n", days);
    long int years = days / 365;
    printf ("Years since the epoch: %ld\n", years);
    return (0);
}

