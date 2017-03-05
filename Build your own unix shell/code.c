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
