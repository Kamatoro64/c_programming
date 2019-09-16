#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 

/*  stdio.h is required to use the printf function
 *  stdlib.h is included so that we can use the EXIT_SUCCESS macro
 *  pthread.h is the header file that give us access to the pthread functions
 *  When compiling, link the pthread library:
 *  gcc -o understanding_threads understanding_threads.c -lpthread
*/

void *entry_point(void *value){
    printf("Hello from the second thread :) \n");
    
    int *num = (int *) value;

    printf("The value of value is %d \n", *num);

    return NULL;
}

int main(int argc, char **argv){
    pthread_t thread;
    
    printf("Hello from the first thread :D \n");

    int num = 123;

    pthread_create(&thread, NULL, entry_point, &num);

    pthread_join(thread, NULL);

    return EXIT_SUCCESS;
}





