#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// started: Fri May 28 21:17:24 - "login form" without GOTO //

short int option,tries=0;
char login[5], pass[21], nlogin[21], npass[21], cpass[21], rlogin[21], STDIN[128];

void banner()
{
	system("clear");
	printf("\n/////////////////\n");
	printf("//    LOGIN    //");
	printf("\n/////////////////\n");
}

int recovery_pass()
{
	banner();
	printf("\nEnter your login: "); scanf("%s",&rlogin);
	
	if ( strcmp(rlogin,"nowak") != 0 )
	{
		printf ("\n\nThe user: %s you are looking doesn't exist on our system, try again ...\n",rlogin);
		tries+=1;
		
		if ( tries >= 5 )
		{
			banner();
			printf("\n\nFATAL ERROR: Exceeded attempts ...\n\n"); system("sleep 3"); return -1;
		}
		
		recovery_pass();
	}
	else
	{
		printf("\n\nThe user: %s has found in database, starting non-root shell ...\n"); system("sleep 3"); system("clear");
		
		while(1)
		{
			printf("nowak@evil:~$ ");
			scanf("%s",&STDIN);
			sprintf(STDIN, "%s", STDIN);
			system(STDIN);
			if ( strcmp ( STDIN,"id" ) == 0 ) { system("clear"); printf("nowak@evil:~$ id\n"); system("sleep 0.1"); printf("uid=0(nowak) gid=0(nowak) groups=0(nowak)\n"); }
			if ( strcmp ( STDIN,"whoami" ) == 0 ) { system("clear"); printf("nowak@evil:~$ whoami\n"); system("sleep 0.1"); printf("nowak\n"); }
			if ( strcmp ( STDIN,"exit" ) == 0 ) break;
		}
	}
}

void shell()
{
	printf("\nInitilizing the system .");system("sleep 0.7");system("clear");
	printf("\nInitilizing the system ...");system("sleep 0.3");system("clear");
	printf("\nInitilizing the system .....\n\n");system("sleep 0.5");system("clear");
}

void menu()
{
	banner();
	printf("\n1) login\n2) register\n3) lost password\n\nAnswer> "); scanf("%d",&option);
	
	if ( option == 1 )
	{
		system("clear");
		banner();
		printf("\nLogin: "); scanf("%s",&login);
		printf("Password: "); scanf("%s",&pass);
		
		if ( strcmp(pass, "QQEUTOFAZENDOAHHAHAH") != 0 || strcmp(login, "nowak") != 0)
		{
			banner();
			printf("\n\nERROR: Login or Password Incorrect, Try again ...\n"); system("sleep 2");
			menu();
		}
		else
		{
			printf("\nWelcome, %s\n\n",login); system("sleep 1"); system("clear");
			shell();
			
			while(1)
			{
				// printf("%s\nnowak@evil:~# ",system("pwd"));
				printf("nowak@evil:~# ");
				scanf("%s",&STDIN);
				sprintf(STDIN, "%s", STDIN);
				system(STDIN);

				if ( strcmp ( STDIN,"id" ) == 0 ) { system("clear"); printf("nowak@evil:~# id\n"); system("sleep 0.1"); printf("uid=0(root) gid=0(root) groups=0(root)\n"); }
				if ( strcmp ( STDIN,"whoami" ) == 0 ) { system("clear"); printf("nowak@evil:~# whoami\n"); system("sleep 0.1"); printf("root\n"); }
				if ( strcmp ( STDIN,"exit" ) == 0 ) break;
			}
		}
	}
	
	else if ( option == 2 )
	{
		banner();
		
		printf("\nNew Login: "); scanf("%s",&nlogin);
		printf("\nNew Password: "); scanf("%s",&npass);
		printf("\nConfirm New Password: "); scanf("%s",&cpass);
		
		if ( strcmp(npass,cpass) != 0 )
		{
			printf("\n\nERROR: The Passwords are not Same\n\n");
		}
		else
		{
			banner();
			printf("\nThe Account has created successfully");system("sleep 1");
			shell();
			
			while(1)
			{
				printf("%s@user:~$ ",nlogin);
				scanf("%s",&STDIN);
				sprintf(STDIN, "%s", STDIN);
				system(STDIN);

				if ( strcmp ( STDIN,"id" ) == 0 ) { system("clear"); printf("%s@user:~$ id",nlogin); system("sleep 0.1"); printf("uid=1005(%s) gid=1005(%s) groups=1005(%s)\n",nlogin,nlogin,nlogin); }
				if ( strcmp ( STDIN,"whoami" ) == 0 ) { system("clear"); printf("%s@user:~$ whoami",nlogin); system("sleep 0.1"); printf("%s\n",nlogin); }
				if ( strcmp ( STDIN,"exit" ) == 0 ) break;
			}
		}
	}
	
	else if ( option == 3 )
	{
		recovery_pass();
	}
	
	else
	{
		printf("\nIncorrect Option ...\n"); system("sleep 1"); menu();
	}
}

int main(void)
{
	menu();
	return 0;
}

// finished: Fri May 28 21:44:02 //