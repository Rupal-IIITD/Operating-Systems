#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#define sz 200
void sigintHandler(int sig_num)
{
    signal(SIGINT, sigintHandler);
    fflush(stdout);
}
int main() {
	int i;
	char arr_history[100][200];
	while(1)
	{
		signal(SIGINT, sigintHandler);
		char cwd[1024];
	    getcwd(cwd, sizeof(cwd));
		static int count=0;
		printf("rupal@rupal-MyOwnShell:");
		printf(cwd);
		printf(" $");
		char *search = " ";
		char *token;
		char arr[100]="";
		char arr1[100]="";
		char *p = fgets (arr, sz, stdin);
		if(p == NULL)
		{
			printf("\n");
			continue;
		}
strcpy(arr_history[count],arr);
		++count;
		if(strcmp(arr, "exit\n")==0)
			exit(0);
		strcpy(arr1, arr);
		token = strtok(arr1, search);
		if(strcmp(token, "cd")==0)
		{
			search = "\n";
			token = strtok(NULL, search);
			chdir(token);
		}
		if(strcmp(arr, "history\n")==0)
		{
		    FILE * fp;
		    char * line = NULL;
		    size_t len = 0;
		    ssize_t read;

		    fp = fopen("/home/rupal/Desktop/history.txt", "r");
		    if (fp == NULL)
		        exit(EXIT_FAILURE);
		    i=0;
		    while ((read = getline(&line, &len, fp)) != -1) {
		        i++;
		        printf("%s", line);
		    }

		    fclose(fp);
			int j;
			for(j=0;j<count-1;j++)
			{
				printf("%d %s",j+i+1, arr_history[j]);
			}
		}
	    char *name[] = {
	        "/bin/bash",
	        "-c",
	        arr,
	        NULL
	    };
	    int pid= fork();
    	if(pid==0)
    	{
	        execvp(name[0], name);
	        exit(0);
   		}
   		else
   			wait(NULL);
	}
	return 0;
}
