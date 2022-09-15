#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int dim;

typedef struct psw{
	int alb;
	int nbr;
	int car;
	int maj;
	int min;
	
}psw;

typedef struct user{
	double id;
	char firstname[30];
	char lastname[30];
	//char *login;
	char pasword[30];
	char mail[30];
	
}user;

// aaaAAA111@@@
psw Pasword (char p[])
{
	struct psw Is={0,0,0,0,0};
	int i;
	FILE *F;	
	for (i=0; i<strlen(p) ;i++)
	{
		if (  	isalpha( p[i]  )    ) Is.alb=1;
		if (  	isdigit( p[i]  )    ) Is.nbr=1;
		if (  	islower( p[i]  )    ) Is.min=1;
		if (  	isupper( p[i]  )    ) Is.maj=1;
		if (   !isalpha(p[i]) && !isdigit(p[i]) && !islower(p[i]) &&  !isupper(p[i])  )Is.car=1;
	}
	return Is;
}


int Choix()
{
	int choix;
    char op[5];
    int i,choixtest;
	do
	{	   	
      	choixtest=1;
	    system("cls");  
	    printf("\n\n\n\t  %c * * * * * * * * * * * * * * * %c",17,16);
	    printf("\n\t %c                                %c",30,30);
	    printf("\n\t  *                              *");
	    printf("\n\t   *                            *");
	    printf("\n\t    *\t  FOR LOG-IN  (1)      *");
	    printf("\n\t     *                        *");
	    printf("\n\t    *\t  FOR SIGN-UP  (2)     *");
	    printf("\n\t   *\t                        *");
	    printf("\n\t  *\t  FOR EXIT     (3)       *");
	    printf("\n\t %c                                %c",31,31);
	    printf("\n\t  %c * * * * * * * * * * * * * * * %c\n",17,16);
	   	printf("\n\t     %c ENTRER VOTRE CHOIX : ",254);
		gets(op);
	    fflush(stdin);
	    sscanf(op, "%d", &choix);
	    fflush(stdin);
	    
	    for(i=0; i<strlen(op) ; i++) if( !isdigit(*(op+i)) ) choixtest=0;
	    
		if(choix<0 || choix>3 || choixtest==0 )
		{
		    system("cls");
			printf("\n\t\t\aVEUILLER ENTRER UN CHOIX VALABLE !!!");
	    }
				
	}while(choix<0 || choix>3 || choixtest==0 ) ;

}

void signup(int *id)
{
	struct psw Is; struct user USER;
	int tmp1=0,tmp2=0,tmp3=0,tmp4=0;
	FILE *P;
	
    printf("\n\n\tENTER YOUR FIRST NAME:\n");
	printf("\n\t*****************************************************************\n");
	printf("\t***                                                           ***");
	printf("\n\t                    ");
	fflush(stdin);
	gets(USER.firstname);
	tmp1=strlen(USER.firstname)+1;
	printf("\t***                                                           ***");
	printf("\n\t*****************************************************************\n");	
	printf("\n\n\tENTER YOUR LASTE NAME:\n");
	printf("\n\t*****************************************************************\n");
	printf("\t***                                                           ***\n");
	printf("\n\t                    ");
	fflush(stdin);
	gets(USER.lastname);
	tmp2=strlen(USER.lastname)+1;
	printf("\t***                                                           ***");
	printf("\n\t*****************************************************************\n");
	printf("\n\n\tENTER YOUR MAIL OR YOUR NUMBER PHONE:\n");
	printf("\n\t*****************************************************************\n");
	printf("\t***                                                           ***\n");
	printf("\t                    ");
	fflush(stdin);
	gets(USER.mail);
	tmp3=strlen(USER.mail)+1;
	printf("\t***                                                           ***");
	printf("\n\t*****************************************************************\n");
	
	again: 
	printf("\n\n\tENTER YOUR PASWORD:(more than 8, uppercase, number and character)\n");
	printf("\n\t*****************************************************************\n");
	printf("\t***                                                           ***\n");
	printf("\t     ");
	fflush(stdin);               
	gets(USER.pasword);
	tmp4=strlen(USER.pasword)+1;
	
	printf("\t***                                                           ***");
	printf("\n\t*****************************************************************\n");
	
        Is=Pasword(USER.pasword);

	    if (     tmp4<8     ) { system("cls"); printf("\n\tVEUILER ENTRER UN MOT DE PASSE PLUS GRAND >8"); 	}
	    if (    Is.car!=1   ) { system("cls"); printf("\n\tVEUILER ENTRER AU MOIN UN CARACTER !"); }
	    if (  	Is.alb!=1   ) { system("cls"); printf("\n\tVEUILER ENTRER AU MOIN UNE ALPHABET !"); }
		if (  	Is.nbr!=1   ) { system("cls"); printf("\n\tVEUILER ENTRER AU MOIN UN NOMBRE !"); }
		if (  	Is.min!=1   ) { system("cls"); printf("\n\tVEUILER ENTRER AU MOIN UNE LETTRE NINISCUL !"); }
		if (  	Is.maj!=1   ) { system("cls"); printf("\n\tVEUILER ENTRER AU MOIN UNE LETTRE MAJUSCUL !"); }
	    	
	    if ( tmp4<8 ) {
			printf("\n\tTRY AGAIN !");
			printf("\n\t*****************************************************************\n");
			goto again;
		} 
	    else if(  Is.car!=1 )  {
			printf("\n\tTRY AGAIN !");
			printf("\n\t*****************************************************************\n");
			goto again;
		}      
		else if (  	Is.alb!=1   ) { 
			printf("\n\tTRY AGAIN !");
			printf("\n\t*****************************************************************\n");
			goto again;
		}
		else if (  	Is.nbr!=1   ){
			printf("TRY AGAIN !");
			printf("\n\t*****************************************************************\n");
			goto again;
		} 
		else if (  	Is.min!=1   ) {
			printf("\n\tTRY AGAIN !");
			printf("\n\t*****************************************************************\n");
			goto again;
		}
		else if (  	Is.maj!=1 ) { 
			printf("\n\tTRY AGAIN !");
			printf("\n\t*****************************************************************\n");
			goto again;
		}else
		{
			printf("\n\n\tVOTRE MOT DE PASSE EST BIEN ");
			
			(USER).id=*id;
			(*id)++;
			strcat(USER.firstname,"\0");
			strcat(USER.lastname,"\0");
			strcat(USER.mail,"\0");
			strcat(USER.pasword,"\0");
			
			
			P=fopen("users.bin","ab");	
			fwrite(&tmp1,sizeof(int),1,P);
			fwrite(&tmp2,sizeof(int),1,P);
			fwrite(&tmp3,sizeof(int),1,P);
			fwrite(&tmp4,sizeof(int),1,P);
			
//			printf("\n\t%d  %d   %d   %d",tmp1,tmp2,tmp3,tmp4);	
//			sleep(3);
					
			fwrite((USER).mail,1,tmp3,P);	
			fwrite((USER).pasword,1,tmp4,P);	
			fwrite(&(USER.id),sizeof(double),1,P);
			fwrite((USER).firstname,1,tmp1,P);
			fwrite((USER).lastname,1,tmp2,P);
			
//			fwrite(&USER,sizeof(USER),1,P);
			
			fclose(P);
		}	
}

user signin()
{
	char userTest[30],usertest[30];
	int tmp1=0,tmp2=0,tmp3=0,tmp4=0;
	int isgood;
	FILE *D;
	struct user USER;
	
    system("cls");
	again:
	D = fopen("users.bin","rb");
			//rewind(D);	
    if ( D == NULL)
	{
    printf("\n\t\tError 404!"); // Program exits if the file pointer returns NULL.
    exit(1);
            }	
            isgood=0;
            printf("\n\n\tENTER YOUR MAIL OR YOUR NUMBER PHONE:\n");
        	printf("\n\t*****************************************************************\n");
        	printf("\t***                                                           ***\n");
        	printf("\t                    ");
        	fflush(stdin);
        	gets(userTest);
        	printf("\t***                                                           ***");
        	printf("\n\t*****************************************************************\n");  
			 	
	    do
	    {        
            fflush(stdin);
            
            fread(&tmp1,sizeof(int),1,D);
			fread(&tmp2,sizeof(int),1,D);
			fread(&tmp3,sizeof(int),1,D);
			fread(&tmp4,sizeof(int),1,D);
			
//			printf("\n\t%d  %d   %d   %d",tmp1,tmp2,tmp3,tmp4);		
					
			fread(usertest,1,tmp3,D);	
			strncpy((USER).mail,usertest,tmp3);
			
			fread(usertest,1,tmp4,D);
			strncpy((USER).pasword,usertest,tmp4);	
			
			fread(&(USER.id),sizeof(double),1,D);

			fread(usertest,1,tmp1,D);
			strncpy((USER).firstname,usertest,tmp1);

			fread(usertest,1,tmp2,D);
            strncpy((USER).lastname,usertest,tmp2);
            
//            printf("\n\t%lf  %s  %s   %s   %s/n",USER.id,USER.firstname,USER.lastname,USER.mail,USER.pasword,(USER).id);

//             fread(&USER,sizeof(USER),1,D);
            
            puts(USER.pasword);
            printf("%d",tmp4);
            
	        if( !strcmp((USER).mail,userTest) )
	        {
	        	again2:
	        	printf("\tENTER YOUR PASWORD:");
            	printf("\n\t*****************************************************************\n");
            	printf("\t***                                                           ***\n");
            	printf("\t                    ");
            	fflush(stdin);               
            	gets(userTest);
            	printf("\t***                                                           ***");
            	printf("\n\t*****************************************************************\n");
	        	if( strcmp(USER.pasword,userTest)==0)
	        	{
	        		fclose(D);
	        		return USER;
				}else
				{   
				    system("cls");
					printf("\n\tYOUR PASWORD IS NOT INVALID !!(try again)\n");
					printf("%d",strcmp(USER.pasword,userTest));
					puts(USER.pasword);
					goto again2;
				} 
	        	isgood==1;
			}		
	    }while(!feof(D) && isgood==0);
			if(isgood==0)
			{
				    system("cls");
                	printf("\n\tYOUR MAIL OR YOUR NUMBER PHONE IS NOT INVALID !!(try again)");
                	fclose(D);
                 	goto again;
			}	
}

void tete(struct user users)
{
	system("CLS");
	puts(users.firstname);
	//printf("\n");
	puts(users.lastname); 
	//printf("\n"); 
	puts(users.mail);
	//printf("\n");
	printf("%lf",users.id);
}
int main ()
{	
	struct user users;
	int choix1=Choix();
	FILE *F;
	
    while(choix1!=3)
    {
	
		if(choix1==2)
		{
		
			F = fopen("dim.txt","r");
			fscanf(F,"%d",&dim);
			fclose(F);
	
			system("cls");
			signup(&dim);
				
			F = fopen("dim.txt","w");
			fprintf(F,"%d",dim);
			fclose(F);
				
		}else if(choix1==1)
		{
		
		users=signin();
		tete(users);
		sleep(4);
	
		}
		choix1=Choix();
		
		}
	}
		
			
	
	
	

	


