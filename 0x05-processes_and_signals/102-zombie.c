#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * infinite_while - Infinite loop to keep zombies
 *
 * Return: 0 (never reached)
 */
int infinite_while(void)
{
    while (1)
    {
        sleep(1);
    }
    return (0);
}

/**
 * main - Create 5 zombie processes
 *
 * Return: 0
 */
int main(void)
{
    pid_t zombie_pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        zombie_pid = fork();
        if (zombie_pid > 0)
            printf("Zombie process created, PID: %d\n", zombie_pid);
        else
            exit(0);
    }

    infinite_while();

    return (0);
}

