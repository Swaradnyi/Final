struct student{
	char ID[15];
	char name[20];
	char add[20];
	char parname[20];
	char dob[20];
	int age;
	char gender[16];
	int Class;
	long unsigned int phone_no;
};
struct employee{
	char id[15];
	char name[20];
	char add[20];
	char sub[15];
	char dob[20];
	char gender[16];
	char qualifn[20];
	int salary;
	long unsigned int phone_no;
};
struct marks{
	int ds, dsgt, math, dsa;
	char ID[15];
	float avg;
};
struct test{
	char exam_id[16];
	char date[20];
	char sub[20];
	char dept[20];
	float duration;
	char type[16];
	char year[16];
};
void gotoxy(int, int);
void verification();
void print_heading(const char st[]);
void add_student();
void searchid_student();
void mod_student();
void delete_student();
void display_std();
void add_exam();
void mod_exam();
void del_exam();
void dis_exam();
void add_employee();
void searchid_employee();
void mod_employee();
void delete_emp();
void display_emp();
void add_marks();
void display_marks();
void main_window();
void std_window();
void e_window();
