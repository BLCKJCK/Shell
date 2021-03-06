#include <stdio.h>	
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <wait.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include "run.h"

int unset(char **args, int num)
{
	if (args[1]==NULL || num>2)
	{perror("Inappropriate number of arguments for setenv");}
	else
	{
		args[1][strlen(args[1])-1] = 0;
		if (getenv(args[1])==NULL)
		{perror("This environment variable has not been created.");}
		else
		{unsetenv(args[1]);}
	}
	return 1;
}