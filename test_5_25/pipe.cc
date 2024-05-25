#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdio>
#include <sys/wait.h>
using namespace std;
int main()
{
    int pipefd[2] = {0};
    int n = pipe(pipefd);
    assert(n == 0);
    (void)n;
    pid_t id = fork();
    if (id < 0)
        perror("fork");
    if (id == 0)
    {
        // 子
        close(pipefd[1]);

        int cnt = 10;
        while (cnt)
        {
            char buf[1024];
            ssize_t sz = read(pipefd[0], buf, sizeof(buf) - 1);
            if (sz > 0)
            {
                buf[sz] = '\0';
                puts(buf);
                cnt--;
            }
            else
                break;

            sleep(1);
        }

        exit(1);
    }
    // 父
    close(pipefd[0]);
    const char *buf = "i am father";
    int cnt = 10;
    while (cnt)
    {
        ssize_t sz = write(pipefd[1], buf, strlen(buf));
        if (sz < 0)
        {
            break;
        }
        sleep(1);
        cnt--;
    }
    close(pipefd[1]);
    int rid = waitpid(-1, nullptr, 0);
    if (rid == id)
        cout << "wait successful" << endl;

    return 0;
}