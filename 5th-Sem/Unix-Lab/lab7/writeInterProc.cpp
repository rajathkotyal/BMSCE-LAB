#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>

using namespace std;
#define BUFFER_SIZE PIPE_BUF
int main(int argc,char *argv[])
{
    int pipe_fd;
    char buffer[BUFFER_SIZE+1];
    if(argc!=2)
    {
        cout<<"usage:./a.out pipe_name\n";
        return 1;
    }
    if(access(argv[1],F_OK)==-1)
    {
        if(mkfifo(argv[1],0777))
        {
            perror("\nmkfifo error\n");
            exit(0);
        }
    }

    cout<<"Process "<<getpid()<<"opening fifo in write mode"<<endl;
    pipe_fd=open(argv[1],O_WRONLY);
    cout<<"FD of fifo in write mode:"<<pipe_fd<<endl;
    if(pipe_fd!=-1)
    {
        cout<<"enter data\n";
        cin>>buffer;
        int res= write(pipe_fd,buffer,BUFFER_SIZE);
        if(res==-1)
        {
            perror("write error\n");
            exit(0);
        }
        close(pipe_fd);
    }
    else
        perror("fifo write");

    cout<<"\nprocess "<<getpid()<<" finished writing\n"<<endl;
    unlink(argv[1]);
    return 0;
}
