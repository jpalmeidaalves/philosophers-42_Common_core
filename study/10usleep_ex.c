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
void     ft_usleep(unsigned int nb)
{
    usleep(nb * 1000);
}

int     main(void)
{   
    suseconds_t start;
    suseconds_t now;

    start = get_time();
    ft_usleep(220); //usleep take time in microseconds (10000 usecs = 10 millisecs)
    now = get_time();
    printf("passed %ld ms since the start of the program\n", now - start);

    return (0);
}