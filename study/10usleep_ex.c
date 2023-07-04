#include <stdio.h>
#include <sys/time.h>
#include <stdint.h>
#include <unistd.h>

uint64_t    get_time(void)
{
    struct timeval  t1;

    gettimeofday(&t1, NULL);
    return ((t1.tv_sec * (uint64_t)1000) + t1.tv_usec / 1000);

}

int     main(void)
{   
    uint64_t start;
    uint64_t now;

    start = get_time();
    usleep(220000); //usleep take time in microseconds (10000 usecs = 10 millisecs)
    now = get_time();
    printf("passed %ld ms since the start of the program\n", now - start);

    return (0);
}