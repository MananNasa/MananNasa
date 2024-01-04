#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void*thread_function(void*argument)
{
    printf("CHild thread starts\n");
    sleep(2);
    printf("child thread completes\n");
    return NULL;
}

int main()
{
    pthread_t id;
    pthread_create(&id, NULL, thread_function, NULL);
    pthread_detach(id);
    sleep(3);
    printf("Main thread completes\n");
    return 0;
}
