#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<unistd.h>
#include<limits.h>
#include<fcntl.h>
using namespace std;
#define BUFFER_SIZE PIPE_BUF
int main(int argc,char *argv[])
{
    int pipe_fd,res=0;
    char buffer[BUFFER_SIZE+1];
    if(argc!=2)
    {
        cout<<"usage:./a.out pipe_name\n";
        return -1;
    }
    cout<<"\nFD of fifo in read mode:"<<pipe_fd<<endl;

    if((pipe_fd=open(argv[1],O_RDONLY))!=-1)
    {
        res=read(pipe_fd,buffer,BUFFER_SIZE);
        cout<<"\ndata read..\n";
        cout<<buffer;
        close(pipe_fd);
    }
    else
    {
        perror("\nfifo read\n");
    }

    cout<<"\nprocess "<<getpid()<<" finished reading\n"<<endl;
    return 0;
}
