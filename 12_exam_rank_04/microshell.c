#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STDIN	0
#define STDOUT	1
#define STDERR	2

int	ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return(i);
}

void	ft_putstr(char *s)
{
	write(STDERR, s, ft_strlen(s));
}

void	ft_error(int err, char *s)
{
	if (err == 1)
		ft_putstr("error: cd: bad arguments\n");
	else if (err == 2)
	{
		ft_putstr("error: cd: cannot change directory to ");
		ft_putstr(s);
		ft_putstr("\n");
	}
	else if (err == 3)
	{
		ft_putstr("error: cannot execute ");
		ft_putstr(s);
		ft_putstr("\n");
	}
	else
		ft_putstr("error: fatal\n");
}

void	ft_cd(char *s, int idx)
{
	if (idx != 2)
		ft_error(1, "");
	else if (chdir(s) == -1)
		ft_error(2, s);
}

void	ft_microshell(int argc, char **argv, char **env)
{
	int i = 0, j = 0;
	int pid = 0;
	int prev = 0;
	int temp = 0;
	int fd[2];

	while (i < argc)
	{
		j = i;
		while (argv[j] && strcmp(argv[j], "|") && strcmp(argv[j], ";"))
			j++;
		if (argv[j] && !strcmp(argv[j], "|"))
		{
			if (pipe(fd) == -1)
				ft_error(4, "");
		}
		if ((argv[i] && i == j) || argv[i] == NULL)
		{
			if (argv[i] == NULL)
				break ;
		}
		else if (!strcmp(argv[i], "cd"))
			ft_cd(argv[i + 1], j - i);
		else
		{
			pid = fork();
			if (pid == 0)
			{
				if (prev)
				{
					if(dup2(temp, 0) == -1)
						ft_error(4, "");
				}
				if (argv[j] && !strcmp(argv[j], "|"))
				{
					if (dup2(fd[1], 1) == -1)
						ft_error(4, "");
					close(fd[0]);
					close(fd[1]);
				}
				argv[j] = NULL;
				if(execve(argv[i], &argv[i], env) == -1)
					ft_error(3, "");
			}
			waitpid(pid, NULL, 0);
		}
		if (argv[j] && !strcmp(argv[j], "|"))
		{
			prev = 1;
			if (dup2(fd[0], temp) == -1)
				ft_error(4, "");
			close(fd[0]);
			close(fd[1]);
		}
		else
			prev = 0;
		i = j;
		i++;
	}
	close(temp);
}

int main(int argc, char **argv, char **env)
{
	if (argc != 1)
		ft_microshell(argc, &argv[1], env);
}
