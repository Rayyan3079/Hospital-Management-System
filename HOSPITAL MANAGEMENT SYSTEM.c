#include <stdio.h> // for input output
#include <stdlib.h>
#include <string.h> // strcpy,strcmp etc
#include <ctype.h> // toupper
#include <conio.h> //getch()
#include <windows.h> // for gotoxy
#include <time.h> // for time
void loading(int N);
void gotoxy(int x,int y);
void welcome_screen();
void login_screen();
void title();
void get_time();
void add_pat();
void list_pat();
void menu();
void search_rec();
void edit_rec();
void dlt_rec();
void ex_it();
void get_string(char n[20]);
struct Doctor {
    char name[30];
    float fee;
    int age;
    char days[40];
    char day[10];
}d1_opd,d2_opd,d3_gp,d4_gp,d5_derm,d6_neuro,d7_physio,d8_gyno,d9_cardio,d10_dentist;
struct address
{
    int hno;
    char street[40];
    char city[40];
    char state[40];
};  
struct patient
{
    char name[40];
    char lname[40];
    char fname[40];
    int age;
    char bg[3];
    char gender;
    char regn[10];
    struct address a;
    char ph[12];
    char disease[60];
    struct Doctor d;
};

int main(){
	welcome_screen();
	login_screen();
}
void get_string(char n[20])
	{
		int i;
		int valid=0;
		int count =0;
		while(1)
		{
		while(count!=0)
		{
			printf("Enter name again");
			scanf("%s",n);
			break;
			}	
		for(i=0;i<strlen(n);i++)
		{
			if(isalpha(n[i])==0)
			{
				valid = 0;
			}
			else{
				valid = 1;
			}
		}
		if(valid==0)
		{
			printf("Your name contains invalid characters\n");
			count++;
			continue;
		}
		
		else{
			n[0] = toupper(n[0]);
			break;
		}
	}
}

void title(){
	printf("========================================================================================================================");
	printf("\n\t\t\t\t\t\tHOSPITAL MANAGEMENT SYSTEM\n");
	printf("========================================================================================================================");
}
void get_time(){
	time_t t;
	time(&t);
	printf("\n\t\t\t\t\t\t%s",ctime(&t));
}

void loading(int N) //function for loading screen
{	
	int i,j; 
	gotoxy(25,12);
	printf("Loading....");
	gotoxy(23,14);
	for(i=1;i<=15;i++)
	{
		for(j=0; j<=N;j++); //determine speed of loading screen
		{
			printf("%c", 219); //219 is ASCII code for Character which is to be printed
		}
	}
}
void gotoxy(int x,int y) //function to print anything at desired position...
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


void welcome_screen(){
	int i;
	system("COLOR 30");
	time_t t;
	time(&t);
	printf("\n\t\t\t\t\t\t%s",ctime(&t));
	gotoxy(15,8);
	for(i=0;i<30;i++)
    	printf("%c",219);
    gotoxy(15,9);
    printf("%c%cHospital Management System%c%c",219,219,219,219);
    gotoxy(15,10);
	for(i=0;i<30;i++)
    	printf("%c",219);	
    loading(10000000);
    gotoxy(19,15);
    printf("Press any key to continue.");
    getch();
	
}

void login_screen(){
	system("cls");	
	system("COLOR 30");
	char usern[20];
	char passn[20];
	char o_un[20];
	char o_upw[20];
	int count=0;
	get_time();
	title();
	strcpy(o_un,"admin");
	strcpy(o_upw,"admin");
	system("COLOR 30");
	printf("\n\n\n\n\t\t\t\t\t^^^Enter your username and password^^^\n");
	printf("\t\t\t\t\t======================================");
	do{
	printf("\n\n\n\n\t\t\t\t\t\tUSERNAME :");
	scanf("%s", &usern);
	printf("\t\t\t\t\t\tPASSWORD :");
	scanf("%s", &passn);
	if(strcmp(usern,o_un)==0 && strcmp(passn,o_upw)==0){
	printf("\t\t\t\t\t\tLOGIN SUCCESSFUL\n");
	printf("\t\t\t\t\t\tEnter any key to continue");	
	getch();
	menu();
	break;	
	}
	else{
	printf("\t\t\t\t\t\tLOGIN UNSUCCESSFUL TRY AGAIN\n");
	count++;
	}
	}while(count<=2);
	if(count>2){
		printf("You have enter wrong id too many times..");
	}
	
}

void menu(){
	system("cls");
	get_time();
	title();
	int choice;
	printf("\n\n\n\n\n\t\t\t\t1) Add patient records\n");
	printf("\n\t\t\t\t2) List patient records\n");
	printf("\n\t\t\t\t3) Search patient records\n");
	printf("\n\t\t\t\t4) Edit patient records\n");
	printf("\n\t\t\t\t5) Delete patient records\n");
	printf("\n\t\t\t\t6) Exit\n");
	printf("\n\n\t\t\t\tCHOOSE FROM 1 TO 6: ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
			add_pat();
			break;
		case 2:
			list_pat();
			break;
		case 3:
			search_rec();
			break;
		case 4:
			edit_rec();
		case 5:
			dlt_rec();
			break;
		case 6:
			ex_it();
			break;
		default:
		printf("Please!choose the right option");	
		break;		
	}
}

void add_pat(){
	char pat_choice='y';
	int i;
	int valid=0;
	system("cls");
	get_time();
    title();
	FILE *fe;
	fe = fopen("Record.dat", "a");
	printf("\n\n\t\t\t\t\t\tADD PATIENT RECORDS\n");
	printf("\t\t\t\t\t\t===================");
	struct patient p;
    char z;	
     fflush(stdin);                  
    printf("\nEnter the first name of the patient: ");
	gets(p.name);
	get_string(p.name);                     
    printf("\nEnter the last name of the patient: ");
	gets(p.lname);
	get_string(p.lname);
	
    printf("\nEnter the name of the guardian: ");
    gets(p.fname);
	get_string(p.fname);		
    while(1){
    fflush(stdin);                    
    printf("\nEnter the gender of the patient(M for male or F for female): ");
    scanf(" %c",&p.gender);
    p.gender = toupper(p.gender);
    if(p.gender == 'M' || p.gender == 'F'){
        break;
    }else{
    	printf("You have entered invalid character, please select M for male or F for female\n");
    }
}
    fflush(stdin);
    while(1){
    char A[4],B[4],C[3],D[3],E[3],F[3],G[3],H[3];
    strcpy(A,"AB+");
	strcpy(B,"AB-");
    strcpy(C,"B+");
    strcpy(D,"B-");
    strcpy(E,"A+");
    strcpy(F,"A-");
    strcpy(G,"O+");
    strcpy(H,"O-");
    printf("\nEnter the Blood group of the patient: ");
    scanf("%s",&p.bg);
    for(i=0;i<strlen(p.bg);i++){
    p.bg[i] = toupper(p.bg[i]);
    }
    if(strcmp(p.bg,A)==0 || strcmp(p.bg,B)==0 || strcmp(p.bg,C)==0 || strcmp(p.bg,D)==0 || strcmp(p.bg,E)==0 || strcmp(p.bg,F)==0 || strcmp(p.bg,G)==0 || strcmp(p.bg,H)==0){
    break;
    }else{
       printf("Please enter correct blood group");
   	   continue;
   }
}
    while(1){
    fflush(stdin);
    printf("\nEnter the age of the patient: ");
    scanf("%d",&p.age);
    if(p.age>160 || p.age<1){
    	printf("You have entered invalid age,Try again");
    	continue;
   }else{
		break;
	}
}
    printf("\nEnter the address of the patient:\n");
    printf("\n\tEnter the house number: ");
    scanf("%d",&p.a.hno);
    fflush(stdin);
    printf("\n\tEnter the street/colony: ");
    scanf("%s",&p.a.street);
      fflush(stdin);                      
    printf("\n\tEnter the city: ");
    scanf("%s",&p.a.city);
	get_string(p.a.city);
    while(1){ 	
    fflush(stdin);
    printf("\nEnter the phone number of the patient(Start with 92...): ");
    gets(p.ph);
    if(strlen(p.ph)>12 || strlen(p.ph)!=12){
        printf("You have entered phone number of invalid length,please try again");
        continue;
	}
    for(i=0;i<strlen(p.ph);i++){
		if(isalpha(p.ph[i])==0){				
			valid = 1;
		}else{
			valid = 0;
		}
	}
	if(valid == 0){
		printf("Phone number contains invalid character,please enter again");
		continue;
	}else{
		break;
	}
 }
    printf("\nEnter the history, if any, related to treatment of the patient(If yes then write 'Y' if NO then write 'N'): ");
    scanf(" %c",&z);
    fflush(stdin);
    printf("\nEnter the Disease or problem for which he/she wants treatment: ");
    gets(p.disease);
    printf("Choose the doctor\n");
    int k;
    float m,pay,n;
    struct Doctor d1_opd,d2_opd,d3_gp,d4_gp,d5_derm,d6_neuro,d7_physio,d8_gyno,d9_cardio,d10_dentist;
    char day[10];
    d1_opd.fee= 500;
    strcpy(d1_opd.name,"Dr_Arif_Ahmed");
    d1_opd.age = 25;
    strcpy(d1_opd.days,"All days");
  
    d2_opd.fee = 500;
    strcpy(d2_opd.name,"Dr_Muniba_Naz");
    d2_opd.age = 27;
    strcpy(d2_opd.days,"All days");
  
    d3_gp.fee = 400;
    strcpy(d3_gp.name,"Dr_Shaista");
    d3_gp.age = 30;
    strcpy(d3_gp.days,"Monday to Wednesday");
  
    d4_gp.fee = 400;
    strcpy(d4_gp.name,"Dr_Khalid_Bruhi");
    d4_gp.age = 34;
    strcpy(d4_gp.days,"Thursday to Saturday,Sunday");
  
    d5_derm.fee = 800;
    strcpy(d5_derm.name,"Dr_Tariq_Warsi");
    d5_derm.age = 31;
    strcpy(d5_derm.days,"Monday,Wednesday,Friday");
    
    d6_neuro.fee = 1500;
    strcpy(d6_neuro.name,"Dr_Shahid_Masood");
    d6_neuro.age = 40;
    strcpy(d6_neuro.days,"Saturday");
    
    d7_physio.fee = 600;
    strcpy(d7_physio.name,"Dr_Zubia_Afreen");
    d7_physio.age = 26;
    strcpy(d7_physio.days,"Monday to Saturday");
    
    d8_gyno.fee = 1200;
    strcpy(d8_gyno.name,"Dr_Shumaila");
    d8_gyno.age = 35;
    strcpy(d8_gyno.days,"Monday to Friday");
      
    d9_cardio.fee = 1800;
    strcpy(d9_cardio.name,"Dr_Rozina_Faisal");
    d9_cardio.age = 38;
    strcpy(d9_cardio.days,"Monday to Friday,Sunday");
    
    d10_dentist.fee = 1000;
    strcpy(d10_dentist.name,"Dr_Zaid_Ghani");
    d10_dentist.age = 25;
    strcpy(d10_dentist.days,"Thursday to Saturday");
    
    printf("1)OPD(Dr Arif Ahmed)\n2)OPD(Dr Muniba Naz)\n3)Gerneral physician(Dr Shaista)\n4)Gerneral physician(Dr Khalid Bruhi)\n5)Dermotoligist(Dr Tari Warsi)\n6)Neurologist(Dr Shahid Masood)\n7)Physiotherapist(Dr Zubia Afreen)\n8)Gynecologist(Dr Shumaila)\n9)Cardiologist(Dr Rozina Faisal)\n10)Dentist(Dr Zaid Ghani)\n");
    scanf("%d",&k);
    switch(k){
         case 1:
         	printf("\nOPD");
       		printf("\nDoctor is available..");
         	printf("\nName:%s",d1_opd.name);
         	printf("\nAge:%d",d1_opd.age);
         	printf("\nDays:%s",d1_opd.days);
         	printf("\nFee:%.2f",d1_opd.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d1_opd.name);
         	if(pay<500){
         		m = d1_opd.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d1_opd.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         	break;
         case 2:
         	printf("\nOPD");
         	printf("\nDoctor is available..");
         	printf("\nName:%s",d2_opd.name);
         	printf("\nAge:%d",d2_opd.age);
         	printf("\nDays:%s",d2_opd.days);
         	printf("\nFee:%.2f",d2_opd.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d2_opd.name);
         	if(pay<500){
         		m = d2_opd.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d2_opd.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         	break;	
         case 3:
         	printf("\nGeneral physician");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d3_gp.day);
         	d3_gp.day[0] = toupper(d3_gp.day[0]); 
         	if(strcmp(d3_gp.day,"Monday")==0||strcmp(d3_gp.day,"Tuesday")==0||strcmp(d3_gp.day,"Wednesday")==0){
         	printf("\nDoctor is available today..");
         	printf("\nName:%s",d3_gp.name);
         	printf("\nAge:%d",d3_gp.age);
         	printf("\nDays:%s",d3_gp.days);
         	printf("\nFee:%.2f",d3_gp.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d3_gp.name);
         	if(pay<400){
         		m = d3_gp.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d3_gp.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
         	printf("\nSorry!Doctor is not available on this day..");
         	printf("\nChoose the day again:");
         	scanf("%s",&d3_gp.day);
		 }
         	break;
		 case 4:
         	printf("\nGeneral physician");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d4_gp.day);
         	d4_gp.day[0] = toupper(d4_gp.day[0]); 
         	if(strcmp(d4_gp.day,"Thursday")==0||strcmp(d4_gp.day,"Friday")==0||strcmp(d4_gp.day,"Saturday")==0||strcmp(d4_gp.day,"Sunday")==0){
         	printf("\nDoctor is available today..");
         	printf("\nName:%s",d4_gp.name);
         	printf("\nAge:%d",d4_gp.age);
         	printf("\nDays:%s",d4_gp.days);
         	printf("\nFee:%.2f",d4_gp.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d4_gp.name);
         	if(pay<400){
         		m = d4_gp.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d4_gp.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
         	printf("\nSorry!Doctor is not available on this day..");
         	printf("\nChoose the day again:");
         	scanf("%s",&d4_gp.day);
		 }
         	break;
		case 5:
         	printf("\nDermotologist");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d5_derm.day);
         	d5_derm.day[0] = toupper(d5_derm.day[0]); 
         	if(strcmp(d5_derm.day,"Monday")==0||strcmp(d5_derm.day,"Friday")==0||strcmp(d5_derm.day,"Wednesday")==0){
         	printf("\nDoctor is available today..");
         	printf("\nName:%s",d5_derm.name);
         	printf("\nAge:%d",d5_derm.age);
         	printf("\nDays:%s",d5_derm.days);
         	printf("\nFee:%.2f",d5_derm.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d5_derm.name);
         	if(pay<800){
         		m = d5_derm.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d5_derm.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
          	printf("\nSorry!Doctor is not available on this day..");
		 	printf("\nChoose the day again:");
         	scanf("%s",&d5_derm.day);	
		 }
         	break;
		case 6:
         	printf("\nNeurologist");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d6_neuro.day);
         	d6_neuro.day[0] = toupper(d6_neuro.day[0]); 
         	if(strcmp(d6_neuro.day,"Saturday")==0){
         	printf("\nName:%s",d6_neuro.name);
         	printf("\nAge:%d",d6_neuro.age);
         	printf("\nDays:%s",d6_neuro.days);
         	printf("\nFee:%.2f",d6_neuro.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d6_neuro.name);
         	if(pay<1500){
         		m = d6_neuro.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d6_neuro.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
          	printf("\nSorry!Doctor is not available on this day\nDoctor will only available on Saturday ..");
			printf("\nChoose the day again:");
         	scanf("%s",&d6_neuro.day);  	
		 }
         	break;
         case 7:
         	printf("\nPhysiotherapist");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d7_physio.day);
       		d7_physio.day[0] = toupper(d7_physio.day[0]); 
         	if(strcmp(d7_physio.day,"Monday")==0||strcmp(d7_physio.day,"Tuesday")==0||strcmp(d7_physio.day,"Wednesday")==0||strcmp(d7_physio.day,"Thursday")==0||strcmp(d7_physio.day,"Friday")==0||strcmp(d7_physio.day,"Saturday")==0){
         	printf("\nDoctor is available today..");
		 	printf("\nName:%s",d7_physio.name);
         	printf("\nAge:%d",d7_physio.age);
         	printf("\nDays:%s",d7_physio.days);
         	printf("\nFee:%.2f",d7_physio.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d7_physio.name);
         	if(pay<600){
         		m = d7_physio.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d7_physio.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
         	printf("\nSorry!Doctor is not available on this day..");
         	printf("\nChoose the day again:");
         	scanf("%s",&d7_physio.day);
		 }
         	break;	
		case 8:
         	printf("\nGynecologist");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d8_gyno.day);
       		d8_gyno.day[0] = toupper(d8_gyno.day[0]); 
         	if(strcmp(d8_gyno.day,"Monday")==0||strcmp(d8_gyno.day,"Tuesday")==0||strcmp(d8_gyno.day,"Wednesday")==0||strcmp(d8_gyno.day,"Thursday")==0||strcmp(d8_gyno.day,"Friday")==0){
         	printf("\nDoctor is available today..");
		 	printf("\nName:%s",d8_gyno.name);
         	printf("\nAge:%d",d8_gyno.age);
         	printf("\nDays:%s",d8_gyno.days);
         	printf("\nFee:%.2f",d8_gyno.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d8_gyno.name);
         	if(pay<1200){
         		m = d8_gyno.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d8_gyno.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
         	printf("\nSorry!Doctor is not available on this day..");
         	printf("\nChoose the day again:");
         	scanf("%s",&d8_gyno.day);
		 }
         	break;	 
		case 9:
         	printf("\nCardiologist");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d9_cardio.day);
       		d9_cardio.day[0] = toupper(d9_cardio.day[0]); 
         	if(strcmp(d9_cardio.day,"Monday")==0||strcmp(d9_cardio.day,"Tuesday")==0||strcmp(d9_cardio.day,"Wednesday")==0||strcmp(d9_cardio.day,"Thursday")==0||strcmp(d9_cardio.day,"Friday")==0||strcmp(d9_cardio.day,"Saturday")==0||strcmp(d9_cardio.day,"Sunday")==0){
         	printf("\nDoctor is available today..");
	     	printf("\nName:%s",d9_cardio.name);
         	printf("\nAge:%d",d9_cardio.age);
         	printf("\nDays:%s",d9_cardio.days);
         	printf("\nFee:%.2f",d9_cardio.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d9_cardio.name);
         	if(pay<1800){
         		m = d9_cardio.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d9_cardio.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
         	printf("\nSorry!Doctor is not available on this day..");
         	printf("\nChoose the day again:");
         	scanf("%s",&d9_cardio.day);
		 }
         	break;
		case 10:
         	printf("\nDentist");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d10_dentist.day);
         	d10_dentist.day[0] = toupper(d10_dentist.day[0]); 
         	if(strcmp(d10_dentist.day,"Thursday")==0||strcmp(d10_dentist.day,"Friday")==0||strcmp(d10_dentist.day,"Saturday")==0){
         	printf("\nDoctor is available today..");
         	printf("\nName:%s",d10_dentist.name);
         	printf("\nAge:%d",d10_dentist.age);
         	printf("\nDays:%s",d10_dentist.days);
         	printf("\nFee:%.2f",d10_dentist.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d10_dentist.name);
         	if(pay<1000){
         		m = d10_dentist.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d10_dentist.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
         	printf("\nSorry!Doctor is not available on this day..");
         	printf("\nChoose the day again:");
         	scanf("%s",&d10_dentist.day);
		 }
         	break;	 
		default:
   	        printf("Invalid Input");	 		 	 	 	 	
	}
	fprintf(fe," %s %s %c %d %s %s %s %s\n", p.name, p.lname, p.gender, p.age, p.ph, p.a.city, p.disease, p.d.name);	 
    printf("\n\n\t\t\t Information stored successfully");
    fclose(fe);

    while(1){
    printf("\nDo you want to add more records if yes press Y else press N");
    scanf(" %c", &pat_choice);
    if(pat_choice == 'Y' || pat_choice=='y'){
        add_pat();
        break;
	 }else if(pat_choice == 'N' || pat_choice == 'n'){
		printf("/t/tThank you");
    	menu();
		break;
		getch();	
	 }else{
	 	printf("Invalid input");
	 }
}
    
}

void list_pat(){
	int row;
	system("cls");
	title();
	struct patient p;
	FILE *fe;
	fe = fopen("Record.dat", "r");
	printf("\n\n\t\t !!!! List patient records !!!!\n");
	printf("\t\t===============================");
	gotoxy(1,15);
	printf("Full name");
	gotoxy(20,15);
	printf("Gender");
	gotoxy(32,15);
	printf("Age");
	gotoxy(37,15);
	printf("Contact no");
	gotoxy(49,15);
	printf("City");
	gotoxy(64,15);
	printf("Problem");
	gotoxy(75,15);
	printf("Doctor name\n");
	printf("------------------------------------------------------------------------------------------------------------------------");
	row = 17;
	while(fscanf(fe," %s %s %c %d %s %s %s %s\n", p.name, p.lname, &p.gender, &p.age, p.ph, p.a.city, p.disease, p.d.name)!=EOF)
	{
		gotoxy(1,row);
		printf("%s %s",p.name, p.lname);
		gotoxy(20,row);
		printf(" %c",p.gender);
		gotoxy(32,row);
		printf("%d",p.age);
		gotoxy(37,row);
		printf("%s",p.ph);
		gotoxy(49,row);
		printf("%s",p.a.city);
		gotoxy(64,row);
		printf("%s",p.disease);
		gotoxy(75,row);
		printf("%s",p.d.name);
		row++;
	}
	fclose(fe);
	getch();
	menu();
}
void search_rec(){
	char name[30];
	char choice;
	system("cls");
	title();
	struct patient p;
	FILE *fe;
	fe = fopen("Record.dat","r");
	printf("\n\n\t\t\t !!!! Search patient records !!!!\n");
	printf("\t\t\t================================");
	gotoxy(12,8);
	printf("\n Enter the patient name you want to viewed: ");
	scanf("%s", &name);
	fflush(stdin);
	name[0] = toupper(name[0]);
	while(fscanf(fe," %s %s %c %d %s %s %s %s\n", p.name, p.lname, &p.gender, &p.age, p.ph, p.a.city, p.disease, p.d.name)!=EOF){
	if(strcmp(p.name,name)==0){
	gotoxy(1,15);
	printf("Full name");
	gotoxy(20,15);
	printf("Gender");
	gotoxy(32,15);
	printf("Age");
	gotoxy(37,15);
	printf("Contact no.");
	gotoxy(49,15);
	printf("City");
	gotoxy(64,15);
	printf("Problem");
	gotoxy(75,15);
	printf("Doctor name\n");
	printf("------------------------------------------------------------------------------------------------------------------------");
	int row=18;
	gotoxy(1,row);
	printf("%s %s",p.name, p.lname);
	gotoxy(20,row);
	printf(" %c",p.gender);
	gotoxy(32,row);
	printf("%d",p.age);
	gotoxy(37,row);
	printf("%s",p.ph);
	gotoxy(49,row);
	printf("%s",p.a.city);
	gotoxy(64,row);
	printf("%s",p.disease);
	gotoxy(75,row);
	printf("%s",p.d.name);
	break;
	}
}
	if(strcmp(p.name,name)!=0){
		gotoxy(5,10);
		printf("Record not found");
		getch();
	}
	fclose(fe);
	while(1){	
	getch();
	printf("\nDo you want to view more [Y/N] ??");
	scanf(" %c", &choice);
	if(toupper(choice) == 'Y'){
		search_rec();
		break;
	}
	else if(toupper(choice) == 'N'){
		printf("\n\t\tThank you");
		getch();
		menu();
		break;
	}else{
		printf("Invalid input,try again");
		continue;			
}	
	
}

}

void edit_rec(){
	FILE *fe, *ft;
	int i,b,valid=0;
	char ch;
	char name[20];
	system("cls");
	title();
	struct patient p;
	ft = fopen("temp.dat", "w+");
	fe = fopen("Record.dat", "r");
	if(fe==NULL){
		printf("\n\t Cannot open file");
		getch();
		menu();		
	}
	printf("\n\n\t\t\t\t\t!!!! Edit patient records !!!!\n");
	printf("\t\t\t\t\t==============================");
	gotoxy(12,13);
	printf("Enter the name of the patient: ");
	scanf(" %s", name);
	fflush(stdin);
	name[0] = toupper(name[0]);
	gotoxy(12,15);
	if(ft == NULL){
		printf("\n\tCannot open file");
		getch();
		menu();
	}
	while(fscanf(fe," %s %s %c %d %s %s %s %s\n", p.name, p.lname, &p.gender, &p.age, p.ph, p.a.city, p.disease, p.d.name)!=EOF){
	if(strcmp(p.name,name)==0){
    	valid =1;
    	gotoxy(25,17);
    	printf("\t\t\t\tExisting record\n");
    	printf("\t\t\t\t\t\t\t===============");
    	gotoxy(10,19);
	    printf(" %s \t%s \t%c \t%d \t%s \t%s \t%s \t%s\n", p.name, p.lname, p.gender, p.age, p.ph, p.a.city, p.disease, p.d.name);
    	gotoxy(12,22);
  
    fflush(stdin);                        
    printf("\nEnter the first name of the patient: ");
	gets(p.name);
	get_string(p.name);
	gotoxy(12,24);
                             
    printf("\nEnter the last name of the patient: ");
	gets(p.lname);
   get_string(p.lname);
	gotoxy(12,26);
                        
    printf("\nEnter the name of the guardian: ");
    gets(p.fname);
	get_string(p.fname);
	gotoxy(12,28);
	printf("Enter city: ");
	scanf("%s",p.a.city);
	gotoxy(12,30);
    while(1){ 	
    fflush(stdin);
	printf("\nEnter the phone number of the patient: ");
    scanf("%s",p.ph);
    if(strlen(p.ph)<12 || strlen(p.ph)>12){
    	printf("You have entered phone number of invalid length,please try again");
    	continue;
	}
    for(i=0;i<strlen(p.ph);i++){
		if(isalpha(p.ph[i])==0){			
			valid = 1;			
		}else{
			valid = 0;
		}
	}
	if(valid == 0){
		printf("Phone number contains invalid character,please enter again");
		continue;
	}
	else{
		break;
	}
 }
	gotoxy(12,32);
	printf("Enter disease: ");
	scanf("%s", &p.disease);
	gotoxy(12,34);
    printf("Choose the doctor\n");
    int k;
    float m,pay,n;
    struct Doctor d1_opd,d2_opd,d3_gp,d4_gp,d5_derm,d6_neuro,d7_physio,d8_gyno,d9_cardio,d10_dentist;
    char day[10];
    d1_opd.fee= 500;
    strcpy(d1_opd.name,"Dr_Arif_Ahmed");
    d1_opd.age = 25;
    strcpy(d1_opd.days,"All days");
  
    d2_opd.fee = 500;
    strcpy(d2_opd.name,"Dr_Muniba_Naz");
    d2_opd.age = 27;
    strcpy(d2_opd.days,"All days");
  
    d3_gp.fee = 400;
    strcpy(d3_gp.name,"Dr_Shaista");
    d3_gp.age = 30;
    strcpy(d3_gp.days,"Monday to Wednesday");
  
    d4_gp.fee = 400;
    strcpy(d4_gp.name,"Dr_Khalid_Bruhi");
    d4_gp.age = 34;
    strcpy(d4_gp.days,"Thursday to Saturday,Sunday");
  
    d5_derm.fee = 800;
    strcpy(d5_derm.name,"Dr_Tariq_Warsi");
    d5_derm.age = 31;
    strcpy(d5_derm.days,"Monday,Wednesday,Friday");
    
    d6_neuro.fee = 1500;
    strcpy(d6_neuro.name,"Dr_Shahid_Masood");
    d6_neuro.age = 40;
    strcpy(d6_neuro.days,"Saturday");
    
    d7_physio.fee = 600;
    strcpy(d7_physio.name,"Dr_Zubia_Afreen");
    d7_physio.age = 26;
    strcpy(d7_physio.days,"Monday to Saturday");
    
    d8_gyno.fee = 1200;
    strcpy(d8_gyno.name,"Dr_Shumaila");
    d8_gyno.age = 35;
    strcpy(d8_gyno.days,"Monday to Friday");
      
    d9_cardio.fee = 1800;
    strcpy(d9_cardio.name,"Dr_Rozina_Faisal");
    d9_cardio.age = 38;
    strcpy(d9_cardio.days,"Monday to Friday,Sunday");
    
    d10_dentist.fee = 1000;
    strcpy(d10_dentist.name,"Dr_Zaid_Ghani");
    d10_dentist.age = 25;
    strcpy(d10_dentist.days,"Thursday to Saturday");
    
    printf("1)OPD(Dr Arif Ahmed)\n2)OPD(Dr Muniba Naz)\n3)Gerneral physician(Dr Shaista)\n4)Gerneral physician(Dr Khalid Bruhi)\n5)Dermotoligist(Dr Tari Warsi)\n6)Neurologist(Dr Shahid Masood)\n7)Physiotherapist(Dr Zubia Afreen)\n8)Gynecologist(Dr Shumaila)\n9)Cardiologist(Dr Rozina Faisal)\n10)Dentist(Dr Zaid Ghani)\n");
    scanf("%d",&k);
    switch(k){
         case 1:
         	printf("\nOPD");
       		printf("\nDoctor is available..");
         	printf("\nName:%s",d1_opd.name);
         	printf("\nAge:%d",d1_opd.age);
         	printf("\nDays:%s",d1_opd.days);
         	printf("\nFee:%.2f",d1_opd.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d1_opd.name);
         	if(pay<500){
         		m = d1_opd.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d1_opd.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         	break;
         case 2:
         	printf("\nOPD");
         	printf("\nDoctor is available..");
         	printf("\nName:%s",d2_opd.name);
         	printf("\nAge:%d",d2_opd.age);
         	printf("\nDays:%s",d2_opd.days);
         	printf("\nFee:%.2f",d2_opd.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d2_opd.name);
         	if(pay<500){
         		m = d2_opd.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d2_opd.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         	break;	
         case 3:
         	printf("\nGeneral physician");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d3_gp.day);
         	d3_gp.day[0] = toupper(d3_gp.day[0]); 
         	if(strcmp(d3_gp.day,"Monday")==0||strcmp(d3_gp.day,"Tuesday")==0||strcmp(d3_gp.day,"Wednesday")==0){
         	printf("\nDoctor is available today..");
         	printf("\nName:%s",d3_gp.name);
         	printf("\nAge:%d",d3_gp.age);
         	printf("\nDays:%s",d3_gp.days);
         	printf("\nFee:%.2f",d3_gp.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d3_gp.name);
         	if(pay<400){
         		m = d3_gp.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d3_gp.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
         	printf("\nSorry!Doctor is not available on this day..");
         	printf("\nChoose the day again:");
         	scanf("%s",&d3_gp.day);
		 }
         	break;
		 case 4:
         	printf("\nGeneral physician");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d4_gp.day);
         	d4_gp.day[0] = toupper(d4_gp.day[0]); 
         	if(strcmp(d4_gp.day,"Thursday")==0||strcmp(d4_gp.day,"Friday")==0||strcmp(d4_gp.day,"Saturday")==0||strcmp(d4_gp.day,"Sunday")==0){
         	printf("\nDoctor is available today..");
         	printf("\nName:%s",d4_gp.name);
         	printf("\nAge:%d",d4_gp.age);
         	printf("\nDays:%s",d4_gp.days);
         	printf("\nFee:%.2f",d4_gp.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d4_gp.name);
         	if(pay<400){
         		m = d4_gp.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d4_gp.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
         	printf("\nSorry!Doctor is not available on this day..");
         	printf("\nChoose the day again:");
         	scanf("%s",&d4_gp.day);
		 }
         	break;
		case 5:
         	printf("\nDermotologist");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d5_derm.day);
         	d5_derm.day[0] = toupper(d5_derm.day[0]); 
         	if(strcmp(d5_derm.day,"Monday")==0||strcmp(d5_derm.day,"Friday")==0||strcmp(d5_derm.day,"Wednesday")==0){
         	printf("\nDoctor is available today..");
         	printf("\nName:%s",d5_derm.name);
         	printf("\nAge:%d",d5_derm.age);
         	printf("\nDays:%s",d5_derm.days);
         	printf("\nFee:%.2f",d5_derm.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d5_derm.name);
         	if(pay<800){
         		m = d5_derm.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d5_derm.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
          	printf("\nSorry!Doctor is not available on this day..");
		 	printf("\nChoose the day again:");
         	scanf("%s",&d5_derm.day);	
		 }
         	break;
		case 6:
         	printf("\nNeurologist");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d6_neuro.day);
         	d6_neuro.day[0] = toupper(d6_neuro.day[0]); 
         	if(strcmp(d6_neuro.day,"Saturday")==0){
         	printf("\nName:%s",d6_neuro.name);
         	printf("\nAge:%d",d6_neuro.age);
         	printf("\nDays:%s",d6_neuro.days);
         	printf("\nFee:%.2f",d6_neuro.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d6_neuro.name);
         	if(pay<1500){
         		m = d6_neuro.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d6_neuro.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
          	printf("\nSorry!Doctor is not available on this day\nDoctor will only available on Saturday ..");
			printf("\nChoose the day again:");
         	scanf("%s",&d6_neuro.day);  	
		 }
         	break;
         case 7:
         	printf("\nPhysiotherapist");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d7_physio.day);
       		d7_physio.day[0] = toupper(d7_physio.day[0]); 
         	if(strcmp(d7_physio.day,"Monday")==0||strcmp(d7_physio.day,"Tuesday")==0||strcmp(d7_physio.day,"Wednesday")==0||strcmp(d7_physio.day,"Thursday")==0||strcmp(d7_physio.day,"Friday")==0||strcmp(d7_physio.day,"Saturday")==0){
         	printf("\nDoctor is available today..");
		 	printf("\nName:%s",d7_physio.name);
         	printf("\nAge:%d",d7_physio.age);
         	printf("\nDays:%s",d7_physio.days);
         	printf("\nFee:%.2f",d7_physio.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d7_physio.name);
         	if(pay<600){
         		m = d7_physio.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d7_physio.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
         	printf("\nSorry!Doctor is not available on this day..");
         	printf("\nChoose the day again:");
         	scanf("%s",&d7_physio.day);
		 }
         	break;	
		case 8:
         	printf("\nGynecologist");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d8_gyno.day);
       		d8_gyno.day[0] = toupper(d8_gyno.day[0]); 
         	if(strcmp(d8_gyno.day,"Monday")==0||strcmp(d8_gyno.day,"Tuesday")==0||strcmp(d8_gyno.day,"Wednesday")==0||strcmp(d8_gyno.day,"Thursday")==0||strcmp(d8_gyno.day,"Friday")==0){
         	printf("\nDoctor is available today..");
		 	printf("\nName:%s",d8_gyno.name);
         	printf("\nAge:%d",d8_gyno.age);
         	printf("\nDays:%s",d8_gyno.days);
         	printf("\nFee:%.2f",d8_gyno.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d8_gyno.name);
         	if(pay<1200){
         		m = d8_gyno.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d8_gyno.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
         	printf("\nSorry!Doctor is not available on this day..");
         	printf("\nChoose the day again:");
         	scanf("%s",&d8_gyno.day);
		 }
         	break;	 
		case 9:
         	printf("\nCardiologist");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d9_cardio.day);
       		d9_cardio.day[0] = toupper(d9_cardio.day[0]); 
         	if(strcmp(d9_cardio.day,"Monday")==0||strcmp(d9_cardio.day,"Tuesday")==0||strcmp(d9_cardio.day,"Wednesday")==0||strcmp(d9_cardio.day,"Thursday")==0||strcmp(d9_cardio.day,"Friday")==0||strcmp(d9_cardio.day,"Sunday")==0){
         	printf("\nDoctor is available today..");
	     	printf("\nName:%s",d9_cardio.name);
         	printf("\nAge:%d",d9_cardio.age);
         	printf("\nDays:%s",d9_cardio.days);
         	printf("\nFee:%.2f",d9_cardio.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d9_cardio.name);
         	if(pay<1800){
         		m = d9_cardio.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d9_cardio.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
         	printf("\nSorry!Doctor is not available on this day..");
         	printf("\nChoose the day again:");
         	scanf("%s",&d9_cardio.day);
		 }
         	break;
		case 10:
         	printf("\nDentist");
         	printf("\nwhats the day today?\n");
         	scanf("%s",d10_dentist.day);
         	d10_dentist.day[0] = toupper(d10_dentist.day[0]); 
         	if(strcmp(d10_dentist.day,"Thursday")==0||strcmp(d10_dentist.day,"Friday")==0||strcmp(d10_dentist.day,"Saturday")==0){
         	printf("\nDoctor is available today..");
         	printf("\nName:%s",d10_dentist.name);
         	printf("\nAge:%d",d10_dentist.age);
         	printf("\nDays:%s",d10_dentist.days);
         	printf("\nFee:%.2f",d10_dentist.fee);
         	printf("\nAmount given by Patient\n");
         	scanf("%f",&pay);
         	strcpy(p.d.name,d10_dentist.name);
         	if(pay<1000){
         		m = d10_dentist.fee - pay;
         		printf("\nYou need to pay %.2f more",m);
			 }else{
			 	m = pay - d10_dentist.fee;
			 	printf("\nreturn amount = %.2f",m);
			 }
         }else{
         	printf("\nSorry!Doctor is not available on this day..");
         	printf("\nChoose the day again:");
         	scanf("%s",&d10_dentist.day);
		 }
         	break;	 
		default:
   	        printf("Invalid Input..");	 		 	 	 	 	
	}
	printf("Press U character to update.");
	scanf(" %c", &ch);
	if(ch=='u' || ch=='U'){
		fprintf(ft,"%s %s %c %d %s %s %s %s\n", p.name, p.lname, p.gender, p.age, p.ph, p.a.city, p.disease, p.d.name);
		printf("\n\n\t\t\tPatient record edited successfully\n");
		printf("\t\t\t==================================");
	}else{
		fprintf(ft,"%s %s %c %d %s %s %s %s\n", p.name, p.lname, p.gender, p.age, p.ph, p.a.city, p.disease, p.d.name);
	}
}
    if(!valid){
	    printf("\n\t\tNo record found");
}
     fclose(fe);
     fclose(ft);
     remove("Record.dat");
     rename("temp.dat","Record.dat");
     getch();
     menu();
}
}

void dlt_rec(){
	char name[20];
	int found=0;
	system("cls");
	struct patient p;
	title();
	FILE *fe,*ft;
	ft=fopen("temp.dat","w+");
	fe=fopen("Record.dat","r");
	printf("\n\n\t\t\tDelete Patient record\n");
	printf("\t\t\t=====================");
	gotoxy(12,8);
	printf("Enter patient first name to delete:");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	while(fscanf(fe," %s %s %c %d %s %s %s %s\n", p.name, p.lname, &p.gender, &p.age, p.ph, p.a.city, p.disease, p.d.name)!=EOF){
	if(strcmp(p.name,name)!=0){
		fprintf(ft," %s %s %c %d %s %s %s %s\n", p.name, p.lname, p.gender, p.age, p.ph, p.a.city, p.disease, p.d.name);
	}else{
		printf(" %s %s %c %d %s %s %s %s\n", p.name, p.lname, p.gender, p.age, p.ph, p.a.city, p.disease, p.d.name);
		found = 1;
	}
}
    if(found==0){
    	printf("\n\n\t\t\tRecord not found");
    	getch();
	    menu();
    }else{
    	fclose(fe);
	    fclose(ft);
	    remove("Record.dat");
	    rename("temp.dat","Record.dat");
	    printf("\n\n\t\t\t Record deleted successfully");
	    getch();
	    menu();
    }
}

void ex_it()
{
	system("cls");
	title();
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t----------------------------");
	printf("\n\t\t\t\t\t\tThanks :) Closing the system\n");
	printf("\t\t\t\t\t\t----------------------------");
	getch();
}




