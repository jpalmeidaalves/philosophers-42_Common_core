#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void* roll_dice() {
    int value = (rand() % 6) + 1;
    int* result = malloc(sizeof(int));
    *result = value;
    sleep(1);
    return ((void*) result);
}

// int main(int argc, char* argv[]) {
//     int* res;
//     srand(time(NULL));
//     pthread_t th;
//     if (pthread_create(&th, NULL, &roll_dice, NULL) != 0) {
//         return 1;
//     }
//     /*the second argument of pthread_join is a pointer to the adress of the return of
//       the function executed by the thread*/
//     if (pthread_join(th, (void**) &res) != 0) {
//         return 2;
//     }
//     printf("Main res: %p\n", res);
//     printf("Result: %d\n", *res);
//     free(res);
//     return 0;
// }

int main(int argc, char* argv[]) {
    int* res;
    (void)  argc;
    (void)  argv;
    srand(time(NULL));
    pthread_t th[4];
    int i = 0;
    while(i < 4)
    {
        if (pthread_create(&th[i], NULL, &roll_dice, NULL) != 0)
            return 1;
        printf("Rolling the dice: %d\n", i);
        i++;
    }
    i = 0;
    while(i < 4)
    {
        if (pthread_join(th[i], (void**) &res) != 0)
            return 2;
        printf("The dice %d has been thrown\n", i);
        printf("Result: %d\n", *res);
        free(res);
        i++;
    }
    return 0;
}