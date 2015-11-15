/*College Management System*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"miniproject.h"
struct student stu;
struct employee emp;
struct marks mark;
struct test t;
int main() {
	char user_name[64];
	char password[8];
	system("clear");
	gotoxy(5, 5);
	printf("\t\t-----------------------------------\n");
	printf("\t\t***********************************\n");	
	printf("\t\tWelcome to College Of Engg Pune\n");
	printf("\t\t***********************************\n");
	printf("\t\t-----------------------------------\n");	
	verification();
	return 0;
}
void gotoxy(int x,int y){
	printf("%c[%d;%df",0x1B,y,x);
}
void verification(){
	char s_pass[8] = {"student"};
	char a_pass[8] = {"admin"};
	char u_pass[8] = {"user"};
	char e_pass[16] = {"employee"};
	char student[16];
	char admin[16];
	char user[16];
	char employee[16];
	int vchoice;
	printf("1.Enter 1 if you are an admin\n");
	printf("2.Enter 2 if you are a student\n");
	printf("3.Enter 3 if you are an employee\n");
	printf("4.Enter 4 to exit\n");
	scanf("%d",&vchoice);
	while(1){
		
		switch (vchoice){
			case 1:/*Admin*/
				printf("Enter the password\n");
				scanf("%s", admin);
				/* Password for admin is "admin"*/
				if (strcmp(admin, "admin") == 0){
					system("clear");
					gotoxy(18, 18);
					printf("\t\tWelcome\n");
					gotoxy(18, 19);
					printf("\t\t********\n");
					main_window();
				}
				else{
					printf("Wrong password.Please try again.\n");
					verification();
				}
				break;
			
			case 2:/*Student*/
				printf("Enter the password\n");
				scanf("%s", student);
				/* Password for student is "student"*/
				if (strcmp(student, "student") == 0){
					system("clear");
					gotoxy(18, 18);
					printf("\t\tWelcome\n");
					gotoxy(18, 19);
					printf("\t\t********\n");
					std_window();
				}
				else{ 
					printf("Wrong password.Please try again.\n");
					verification();
				}
				
				break;
			case 3:/*Employee*/
				printf("Enter the password\n");
				scanf("%s", employee);
				/* Password for employee is "employee"*/
				if (strcmp(employee, "employee") == 0){
					system("clear");
					gotoxy(18, 18);
					printf("\t\tWelcome\n");
					gotoxy(18, 19);
					printf("\t\t********\n");
					e_window();
				}
				else{
					printf("Wrong password.Please try again.\n");
					verification();
				}
				break;
			case 4:/*exit*/
				exit(0);
				break;
		}
	}
}
void print_heading(const char st[]){
	printf("SRS : %s",st);
}
void main_window(){
	int choice;
	while(1){
	printf("1. Add Student:\n");
	printf("2. Search Student:\n");
	printf("3. Modify Student Record:\n");
	printf("4. Delete Student Record:\n");
	printf("5. Display the record:\n");
	printf("6. Add Test Schedule:\n");
	printf("7. Modify Test Schedule:\n");
	printf("8. Delete Test Schedule:\n");
	printf("9. Display Test Schedule:\n");
	printf("10.Add Marks:\n");
	printf("11.Display Marks:\n");
	printf("12.Log out:\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
		switch(choice){
			case 1:
			add_student();
			break;
			case 2:
			searchid_student();
			break;
			case 3:
			mod_student();
			break;     
			case 4:
			delete_student();
			break;
			case 5:
			display_std();
			break;
			case 6:
			add_exam();
			break;
			case 7:
			mod_exam();
			break;
			case 8:
			del_exam();
			break;
			case 9:
			dis_exam();
			break;
			case 10:
			add_marks();
			break;
			case 11:
			display_marks();
			break;
			case 12:
			verification();
			break;
			default:
			break;
		}
	}
}
void std_window(){
	int choice;
	while(1){
	printf("1. Search Student By ID:\n");
	printf("2. Modify Student Record:\n");
	printf("3. Display the record\n");
	printf("4. Display Marks:\n");
	printf("5. Log out:\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
		switch(choice){
			case 1:
			searchid_student();
			break;
			case 2:
			mod_student();
			break;
			case 3:
			display_std();
			break;
			case 4:
			display_marks();
			break;
			case 5:
			verification();
			break;
			default:
			break;
		}
	}
}
void e_window(){
	int choice;
	while(1){
	printf("1. Add employee\n");
	printf("2. Search employee:\n");
	printf("3. Modify employee Record:\n");
	printf("4. Delete employee Record:\n");
	printf("5. Display the record\n");
	printf("6. Log out:\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
		switch(choice){
			case 1:
			add_employee();
			break;
			case 2:
			searchid_employee();
			break;
			case 3:
			mod_employee();
			break;     
			case 4:
			delete_emp();
			break;
			case 5:
			display_emp();
			break;
			case 6:
			verification();
			break;
			default:
			break;
		}
	}
}
void add_student(){
	print_heading("Add Record");
	FILE *fp;
	fp = fopen("record.txt","a");
	if(fp == NULL)
		printf("Error in Opening file\n");
	else{
		printf("ID: ");
		scanf("%s", stu.ID);
		printf("Name: ");
		scanf("%s", stu.name);
		printf("Address: ");
		scanf("%s", stu.add);
		printf("Parent's name: ");
		scanf("%s", stu.parname);
		printf("Date Of Birth:");
		scanf("%s", stu.dob);
		printf("Age:");	
		scanf("%d", &stu.age);
		printf("Gender:");
		scanf("%s", stu.gender);
		printf("Class: ");
		scanf("%d",&stu.Class);
		printf("Phone Number: ");
		scanf("%ld",&stu.phone_no);
		fwrite(&stu, sizeof(stu), 1, fp);
		printf("The record is sucessfully added\n");
	}
	fclose(fp);
	return;
}
void add_exam(){
	print_heading("Add Record");
	FILE *fp;
	fp = fopen("record2.txt","a");
	if(fp == NULL)
		printf("Error in Opening file\n");
	else{
		printf("Exam ID: ");
		scanf("%s", t.exam_id);
		printf("Date: ");
		scanf("%s", t.date);
		printf("Sub: ");
		scanf("%s", t.sub);
		printf("Department: ");
		scanf("%s", t.dept);
		printf("Duration: ");
		scanf("%f", &t.duration);
		printf("Type Of Exam:");
		scanf("%s", t.type);
		printf("Year:");	
		scanf("%s", t.year);
		fwrite(&t, sizeof(t), 1, fp);
		printf("The record is sucessfully added\n");
	}
	fclose(fp);
	return;
}
void searchid_student(){
	print_heading("Search Record By ID\n");
	char s_id[15];
	int isFound = 0;
	FILE *fp;
	fp = fopen("record.txt","r");
	printf("Enter ID to Search: ");
	scanf("%s",s_id);
	if(fp == NULL)
		printf("Empty\n");
	else{
		while(fread(&stu,sizeof(stu),1,fp) == 1){
			if(strcmp(stu.ID,s_id) == 0){
			isFound = 1;
			break;
			}
		}
		if(isFound == 1){
		printf("The record is Found\n");
		printf("ID: %s\n",stu.ID);
		printf("Name: %s\n",stu.name);
		printf("Address: %s\n",stu.add);
		printf("Parent's Name: %s\n",stu.parname);
		printf("Date Of Birth: %s\n", stu.dob);
		printf("Age:%d\n", stu.age);
		printf("Gender:%s\n", stu.gender);
		printf("Class: %d\n",stu.Class);
		printf("Phone No: %ld\n",stu.phone_no);
		}
		else{
		printf("Sorry, No record found in the database\n");
		fclose(fp);
		}
	}
	return;
}
void mod_exam(){
	print_heading("Modify Record");
	char s_id[15];
	int isFound = 0, print = 37;
	printf("Enter ID to Modify: ");
	scanf("%s",s_id);
	FILE *fp;
	fp = fopen("record2.txt","rb+");
	if(fp == NULL)
		printf("Empty\n");
	else{
		while(fread(&t, sizeof(t),1,fp) == 1){
        		if(strcmp(t.exam_id,s_id) == 0){
        			printf("Exam id: ");
				scanf("%s",t.exam_id);
				fgets(t.exam_id,sizeof(t.exam_id), fp);
            			printf("Date: ");
				scanf("%s", t.date);
				fgets(t.date,sizeof(t.date),fp);
            			printf("Subject: ");
				scanf("%s", t.sub);
				fgets(t.sub,sizeof(t.sub),fp);
            			printf("Department: ");
				scanf("%s", t.dept);
				fgets(t.dept,sizeof(t.dept),fp);
				printf("Duration:");
				scanf("%f", &t.duration);
				printf("Type:");	
				scanf("%s", t.type);
				printf("Year:");
				scanf("%s", t.year);
				fgets(t.year,sizeof(t.year),fp);
                		fseek(fp,-sizeof(t), SEEK_CUR);
                		fwrite(&t,sizeof(t), 1, fp);
                		isFound = 1;
       	         		break;
				}
		}
		if(!isFound)
			printf("No Record Found");
		fclose(fp);
	}
	return;
}
void mod_student(){
	print_heading("Modify Record");
	char s_id[15];
	int isFound = 0, print = 37;
	printf("Enter ID to Modify: ");
	scanf("%s",s_id);
	FILE *fp;
	fp = fopen("record.txt","rb+");
	if(fp == NULL)
		printf("Empty\n");
	else{
		while(fread(&stu, sizeof(stu),1,fp) == 1){
        		if(strcmp(stu.ID,s_id) == 0){
        			printf("ID: ");
				scanf("%s",stu.ID);
				fgets(stu.ID,sizeof(stu.ID), fp);
            			printf("Name: ");
				scanf("%s", stu.name);
				fgets(stu.name,sizeof(stu.name),fp);
            			printf("Address: ");
				scanf("%s", stu.add);
				fgets(stu.add,sizeof(stu.add),fp);
            			printf("Parent's name: ");
				scanf("%s", stu.parname);
				fgets(stu.parname,sizeof(stu.parname),fp);
				printf("Date Of Birth:");
				scanf("%s", stu.dob);
				fgets(stu.dob,sizeof(stu.dob),fp);
				printf("Age:");	
				scanf("%d", &stu.age);
				printf("Gender:");
				scanf("%s", stu.gender);
				fgets(stu.gender,sizeof(stu.gender),fp);
                		printf("Class: ");
				scanf("%d",&stu.Class);
                		printf("Phone Number: ");
				scanf("%ld",&stu.phone_no);
                		fseek(fp,-sizeof(stu), SEEK_CUR);
                		fwrite(&stu,sizeof(stu), 1, fp);
                		isFound = 1;
       	         		break;
				}
		}
		if(!isFound)
			printf("No Record Found");
		fclose(fp);
	}
	return;
}
void delete_student(){
	print_heading("Delete Record");
	char s_id[15];
	int isFound = 0;
	printf("Enter ID to Modify: ");
	scanf("%s",s_id);
	FILE *fp, *temp;
	fp = fopen("record.txt","rb");
	temp = fopen("temp.txt", "wb");
	if(fp == NULL)
		printf("Empty\n");
	else{
		while(fread(&stu, sizeof(stu),1,fp) == 1){
			if(strcmp(s_id, stu.ID) != 0){
				fwrite(&stu,sizeof(stu),1,temp);
			}
			else
				printf("The record has been successfully deletd\n");
		}
		fclose(fp);
		fclose(temp);
		remove("record.txt");
		rename("temp.txt","record.txt");
	}
	return;
}
void del_exam(){
	print_heading("Delete Record");
	char s_id[15];
	int isFound = 0;
	printf("Enter ID to Modify: ");
	scanf("%s",s_id);
	FILE *fp, *temp;
	fp = fopen("record2.txt","rb");
	temp = fopen("temp2.txt", "wb");
	if(fp == NULL)
		printf("Empty\n");
	else{
		while(fread(&t, sizeof(t),1,fp) == 1){
			if(strcmp(s_id, t.exam_id) != 0){
				fwrite(&t,sizeof(t),1,temp);
			}
			else
				printf("The record has been successfully deletd\n");
		}
		fclose(fp);
		fclose(temp);
		remove("record2.txt");
		rename("temp2.txt","record2.txt");
	}
	return;
}
void display_std(){
	FILE *fp;
	fp = fopen("record.txt", "r");
	if(fp == NULL)
		printf("Empty\n");
	else{
		fseek(fp, 0, SEEK_SET);
		while(fread(&stu, sizeof(stu), 1, fp) == 1){ 
			printf("ID:%s\n", stu.ID); 
			printf("Name:%s\n", stu.name);
			printf("Add:%s\n", stu.add);
			printf("Parname:%s\n",stu.parname);
			printf("Date Of Birth: %s\n", stu.dob);
			printf("Age:%d\n", stu.age);
			printf("Gender:%s\n", stu.gender);
			printf("Class:%d\n",stu.Class);
			printf("Phone_no.:%ld\n",stu.phone_no);	
		}
	}
}
void dis_exam(){
	FILE *fp;
	fp = fopen("record2.txt", "r");
	if(fp == NULL)
		printf("Empty\n");
	else{
		fseek(fp, 0, SEEK_SET);
		while(fread(&t, sizeof(t), 1, fp) == 1){ 
			printf("Exam id:%s\n", t.exam_id); 
			printf("Date:%s\n", t.date);
			printf("Subject:%s\n", t.sub);
			printf("Department:%s\n",t.dept);
			printf("Duration: %f\n", t.duration);
			printf("Exam Type:%s\n", t.type);
			printf("Year:%s\n",t.year);
		}
	}
}
void add_marks(){
	FILE *fp, *ft;
	ft = fopen("record.txt", "r");
	fp = fopen("marks.txt", "a");
	printf("Enter ID\n");
	scanf("%s",mark.ID);
	if((strcmp(mark.ID,stu.ID) == 0)){
	printf("Enter marks in DSA\n");
	scanf("%d", &mark.dsa);
	printf("Enter marks in DS\n");
	scanf("%d", &mark.ds);
	printf("Enter marks in DSGT\n");
	scanf("%d", &mark.dsgt);
	printf("Enter marks in MATHS\n");
	scanf("%d", &mark.math);
	fwrite(&mark,sizeof(mark),1,fp);
	}
	else
		printf("ID does not exit\n");
	fclose(fp);
}
void display_marks(){
	FILE *fp;
	fp = fopen("marks.txt", "r");
	if(fp == NULL)
		printf("Empty\n");
	else{
		fseek(fp, 0, SEEK_SET);
		printf("\n\tID\tDSA\tDS\tDSGT\tMATHS\tAVERAGE\n"); 
		while(fread(&mark, sizeof(mark), 1,fp) == 1){ 
			printf("\t%s\t", mark.ID); 
			printf("%d\t",mark.dsa );
			printf("%d\t", mark.ds);
			printf("%d\t", mark.dsgt);
			printf("%d\t",mark.math);
			(mark.avg) = (mark.dsa + mark.ds + mark.dsgt + mark.math) / 4;
			printf("%f\n", mark.avg);
		}
		fclose(fp);
	}
}
void add_employee(){
	print_heading("Add Record");
	FILE *fp;
	fp = fopen("record1.txt","a");
	if(fp == NULL)
		printf("Error in Opening file\n");
	else{
		printf("ID: ");
		scanf("%s", emp.id);
		printf("Name: ");
		scanf("%s", emp.name);
		printf("Address: ");
		scanf("%s", emp.add);
		printf("Department: ");
		scanf("%s", emp.sub);
		printf("Gender:");
		scanf("%s", emp.gender);
		printf("Date Of Birth:");
		scanf("%s", emp.dob);
		printf("Qualification: ");
		scanf("%s", emp.qualifn);
		printf("Salary: ");
		scanf("%d",&emp.salary);
		printf("Phone Number: ");
		scanf("%ld",&emp.phone_no);
		fwrite(&emp, sizeof(emp), 1, fp);
		printf("The record is sucessfully added\n");
	}
	fclose(fp);
	return;
}
void searchid_employee(){
	print_heading("Search Record\n");
	char s_id[15];
	int isFound = 0;
	FILE *fp;
	fp = fopen("record1.txt","r");
	printf("Enter ID to Search: ");
	scanf("%s",s_id);
	if(fp == NULL)
		printf("Empty\n");
	else{
		while(fread(&emp,sizeof(emp),1,fp) == 1){
			if(strcmp(emp.id,s_id) == 0){
			isFound = 1;
			break;
			}
		}
		if(isFound == 1){
		printf("The record is Found\n");
		printf("id: %s\n",emp.id);
		printf("Name: %s\n",emp.name);
		printf("Add:%s\n", emp.add);
		printf("Department: %s\n",emp.sub);
		printf("Date Of Birth: %s\n", emp.dob);
		printf("Gender:%s\n", emp.gender);
		printf("Qualification: %s\n",emp.qualifn);
		printf("Salary: %d\n",emp.salary);
		printf("Phone No: %ld\n",emp.phone_no);
		}
		else{
		printf("Sory, No record found in the database\n");
		fclose(fp);
		}
	}
	return;
}
void mod_employee(){
	print_heading("Modify Record");
	char s_id[15];
	int isFound = 0, print = 37;
	printf("Enter ID to Modify: ");
	scanf("%s",s_id);
	FILE *fp;
	fp = fopen("record1.txt","rb+");
	if(fp == NULL)
		printf("Empty\n");
	else{
		while(fread(&emp, sizeof(emp),1,fp) == 1){
        		if(strcmp(emp.id,s_id) == 0){
        			printf("ID: ");
				scanf("%s",emp.id);
				fgets(emp.id,sizeof(emp.id), fp);
            			printf("Name: ");
				scanf("%s", emp.name);
				fgets(emp.name,sizeof(emp.name),fp);
				printf("Address: ");
				scanf("%s", emp.add);
				fgets(emp.add,sizeof(emp.add),fp);
            			printf("Department: ");
				scanf("%s", emp.sub);
				fgets(emp.sub,sizeof(emp.sub),fp);
				printf("Date Of Birth:");
				scanf("%s", emp.dob);
				fgets(emp.dob,sizeof(emp.dob),fp);
				printf("Gender:");
				scanf("%s", emp.gender);
				fgets(emp.gender,sizeof(emp.gender),fp);
            			printf("Qualification: ");
				scanf("%s", emp.qualifn);
				fgets(emp.qualifn,sizeof(emp.qualifn),fp);
               		 	printf("Salary: ");
				scanf("%d",&emp.salary);
                		printf("Phone Number: ");
				scanf("%ld",&emp.phone_no);
                		fseek(fp,-sizeof(emp), SEEK_CUR);
               		 	fwrite(&emp,sizeof(emp), 1, fp);
                		isFound = 1;
       	         		break;
			}	
		}	
		if(!isFound)
			printf("No Record Found");
		fclose(fp);
	}
	return;
}
void delete_emp(){
	print_heading("Delete Record");
	char s_id[15];
	int isFound = 0;
	printf("Enter ID to Modify: ");
	scanf("%s",s_id);
	FILE *fp, *temp;
	fp = fopen("record1.txt","rb");
	temp = fopen("temp1.txt", "wb");
	if(fp == NULL)
		printf("Empty\n");
	else{
		while(fread(&emp, sizeof(emp),1,fp) == 1){
			if(strcmp(s_id, emp.id) != 0){
				fwrite(&emp,sizeof(emp),1,temp);
			}
			else
				printf("The record has been successfully deletd\n");
		}
		fclose(fp);
		fclose(temp);
		remove("record1.txt");
		rename("temp1.txt","record1.txt");
	}
	return;
}
void display_emp(){
	FILE *fp;
	fp = fopen("record1.txt", "r");
	if(fp == NULL)
		printf("Empty\n");
	else{
		fseek(fp, 0, SEEK_SET); 
		while(fread(&emp, sizeof(emp), 1, fp) == 1){ 
			printf("ID:%s\n", emp.id); 
			printf("Name:%s\n", emp.name);
			printf("Add:%s\n", emp.add);
			printf("Department:%s\n", emp.sub);
			printf("Date Of Birth: %s\n", emp.dob);
			printf("Gender:%s\n", emp.gender);
			printf("Qualification:%s\n",emp.qualifn);
			printf("Salary:%d\n",emp.salary);
			printf("Phone_no.:%ld\n",emp.phone_no);	
		}
	}
}
