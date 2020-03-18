#include <stdio.h>
#include "getEmptyPort.h" // github.com/Jochnickel/get_empty_port
int main ( int argc, char **argv, char **envp ) {
        if (argc<=1){
                printf("example usage: %s docker run -it --rm -p %%d:80 alpine\n",argv[0]);
                return -1;
        }
        int port = 0;

        for(int i=50;i>0;i--) if ( (port = getEmptyPort()) > 49152 ) break; // my firewall

        if (port<=49152){
                write(2,"couldn't get a free port\n",25);
                return -1;
        }
        for(int i = argc-1; i>1; i--)
                *(char *)(argv[i]-1)=32;
        char command[255];
        int inp_len = snprintf(command, 255, argv[1], port);
        if (inp_len>255) write(2,"warning: cropped input\n",23);
        printf("executing: %s\n",command);
        FILE* a = popen(command,"r");
        pclose(a);
        return 0;
}
