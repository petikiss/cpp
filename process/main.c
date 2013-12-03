#include <stdio.h>
#include <unistd.h>

int
main(int ac, char **av)
{
        pid_t sid, mypid, pgid, gid;

        mypid = getpid();
        sid = getsid(0);
        pgid = getpgid(0);
        gid = getpgrp();

        printf("PID %d\n", mypid);
        printf("process group ID of session leader: %d\n", sid);
        printf("process group ID: %d\n", pgid);
        printf("process group ID: %d\n", gid);

        if (!fork())
        {
                mypid = getpid();
                sid = getsid(0);
                pgid = getpgid(0);
                gid = getpgrp();

                printf("child PID %d\n", mypid);
                printf("process group ID of session leader: %d\n", sid);
                printf("process group ID: %d\n", pgid);
                printf("process group ID: %d\n", gid);

                _exit(0);
        }

        return 0;
}

