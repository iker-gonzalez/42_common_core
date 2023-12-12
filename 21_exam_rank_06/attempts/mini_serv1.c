#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define WRONG_ARG_MSG "Wrong number of arguments\n"
#define FATAL_ERROR_MSG "Fatal error\n"
#define IP_ADDRESS 2130706433 // 127.0.0.1
#define BACKLOG_SIZE 128

fd_set  fds, rfds, wfds;
int     fdmax = 0;

int main (int argc, char** argv)
{
    if (argc != 2)
    {
        write(2, WRONG_ARG_MSG, strlen(WRONG_ARG_MSG));
        exit(1);
    }

    FD_ZERO(&fds);
    fdmax = socket(AF_INET, SOCK_STREAM, 0);
    if (fdmax < 0)
    {
        write(2, FATAL_ERROR_MSG, strlen(FATAL_ERROR_MSG));
        exit(1);
    }
    FD_SET(fdmax, &fds);
    int sockfd = fdmax;

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(IP_ADDRESS); // 127.0.0.1
    servaddr.sin_port = htons(atoi(argv[1])); // port to bind to in the IP address specified

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) || listen(sockfd, BACKLOG_SIZE))
    {
        write(2, FATAL_ERROR_MSG, strlen(FATAL_ERROR_MSG));
        exit(1);
    }

    while(1)
    {
        rfds = wfds = fds;
        if (select(fdmax + 1, &rfds, &wfds, NULL, NULL) < 0)
        {
            write(2, FATAL_ERROR_MSG, strlen(FATAL_ERROR_MSG));
            exit(1);
        }

        if

    
    }
}