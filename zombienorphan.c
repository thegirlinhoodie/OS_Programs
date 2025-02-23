//zombie process
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
    pid_t child_pid,parent_pid,my_pid;
    child_pid=fork();
    if(child_pid<0)
    {
        printf("Fork failed..exiting\n");
        exit(0);
    }
    if(child_pid==0)
    {
        printf("[CHILD] This is the child process\n");
        my_pid=getpid();
        parent_pid=getppid();
        printf("[CHILD] My ID is %d\n",my_pid);
        printf("[CHILD] My parent ID is %d\n",parent_pid);
        printf("[CHILD] Exiting\n");
        exit(0);
    }
    else
    {
        printf("[PARENT] This is the parent process\n");
        my_pid=getpid();
        parent_pid=getppid();
        printf("[PARENT] My ID is %d\n",my_pid);
        printf("[PARENT] My parent ID is %d\n",parent_pid);
        printf("[PARENT] Sleeping for 10 sec\n");
        sleep(10);
        printf("[PARENT] The child process %d has exited but it still has an entry in the process table. Hence it is a zombie process\n");
    }
}

//Orphan Process
/*#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
    pid_t child_pid,parent_pid,my_pid;
    child_pid=fork();
    if(child_pid<0)
    {
        printf("Fork failed..exiting\n");
        exit(0);
    }
    if(child_pid==0)
    {
        printf("[CHILD] This is the child process\n");
        my_pid=getpid();
        parent_pid=getppid();
        printf("[CHILD] My ID is %d\n",my_pid);
        printf("[CHILD] My parent ID is %d\n",parent_pid);
        printf("[CHILD] Sleeping for 10 sec\n");
        sleep(10);
        printf("[CHILD] My parent has exited and I have nowhere to return, So I am an Orphan process\n");
    }
    else
    {
        printf("[PARENT] This is the parent process\n");
        my_pid=getpid();
        parent_pid=getppid();
        printf("[PARENT] My ID is %d\n",my_pid);
        printf("[PARENT] My parent ID is %d\n",parent_pid);
        printf("[PARENT] Exiting\n");
        exit(0);
    }
}*/