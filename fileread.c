#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#define BUFFER_SIZE 30
void main()
{
    int fd,n;
    char buf[BUFFER_SIZE];
    fd=open("trial.txt",O_RDWR);
    if(fd==-1)
    {
        printf("Cannot open file, exiting\n");
        exit(0);
    }
    printf("Reading first 10 characters\n");
    n=read(fd,buf,10);
    write(1,buf,n);
    printf("Skipping 5 cchar from current position\n");
    lseek(fd,5,SEEK_CUR);
    n=read(fd,buf,5);
    write(1,buf,n);
    printf("Reverting 5 char from current position\n");
    lseek(fd,-5,SEEK_CUR);
    n=read(fd,buf,5);
    write(1,buf,n);
    printf("Going to 5th last char\n");
    lseek(fd,-5,SEEK_END);
    n=read(fd,buf,5);
    write(1,buf,n);
    printf("Going to 3rd char in file\n");
    lseek(fd,3,SEEK_SET);
    n=read(fd,buf,5);
    write(1,buf,n);
}