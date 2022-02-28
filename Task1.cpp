#include <iostream>

using namespace std;

struct student
{
	string name;
	string reg_no;
	string degree_program;
	double SGPA;
}; student s[3];
int main(int argc, char const *argv[])
{
	int n_courses;
	int n_students=3;
	for (int i=0; i<n_students;i++)
	{
		cout<<"Enter the record of student "<<i+1<<" "<<endl;
		cout<<"Enter the name:"<<endl;
		cin>>s[i].name;
		cout<<"Enter the reg_no:"<<endl;
		cin>>s[i].reg_no;
		cout<<"Enter the Degree Program:"<<endl;
		cin>>s[i].degree_program;
		cout<<"Enter the number of courses enrolled"<<endl;
		cin>>n_courses;
		float grade_point[n_courses];
		float sum=0;
		for (int j=0; j<n_courses;j++)
		{
			double marks;
			cout<<"Enter the marks of course "<<j+1<<" "<<endl;
			cin>> marks;
			if (marks>86 && marks<=100){
				grade_point[j]=4*3;
			}
			else if (marks<=86 && marks>82){
				grade_point[j]=3.67*3;
			}
			else if (marks<=82 && marks>78){
				grade_point[j]=3.33*3;
			}
			else if (marks<=78 && marks>74){
				grade_point[j]=3*3;
			}
			else if (marks<=74 && marks>70){
				grade_point[j]=2.67*3;
			}
			else if (marks<=70 && marks>66){
				grade_point[j]=2.33*3;
			}
			else if (marks<=66 && marks>62){
				grade_point[j]=2*3;
			}
			else if (marks<=62 && marks>58){
				grade_point[j]=1.67*3;
			}
			else if (marks<=58 && marks>54){
				grade_point[j]=1.33*3;
			}
			else if (marks<=54 && marks>50){
				grade_point[j]=1*3;
			}
			else {
				grade_point[j]=0*3;
			}
			cout<<grade_point[j]<<endl;
			sum=sum+grade_point[j];
		}
		cout<<sum<<endl;
		s[i].SGPA=sum/(float(n_courses)*3);
	}


	for (int k=0; k<n_students;k++)
	{
		cout<<"S.No.\t"<<"Name\t"<<"Reg_No.\t"<<"Degree_program\t"<<"SGPA"<<endl;
		cout<<k+1<<"\t"<<s[k].name<<"\t"<<s[k].reg_no<<"\t"<<s[k].degree_program<<"\t\t"<<s[k].SGPA<<"\t"<<endl;

	}

	for (int i=1;i<n_students;i++)
	{
		student key;
		key.name=s[i].name;
		key.reg_no=s[i].reg_no;
		key.degree_program=s[i].degree_program;
		key.SGPA=s[i].SGPA;
		int j=i-1;
		while (j>-1 && s[j].SGPA<key.SGPA)
		{
			s[j+1].SGPA=s[j].SGPA;
			j=j-1;
		}
		s[j+1].name=key.name;
		s[j+1].reg_no=key.reg_no;
		s[j+1].degree_program=key.degree_program;
		s[j+1].SGPA=key.SGPA;
	}
	for (int k=0; k<n_students;k++)
	{
		cout<<"S.No.\t"<<"Name\t"<<"Reg_No.\t"<<"Degree_program\t"<<"SGPA"<<endl;
		cout<<k+1<<"\t"<<s[k].name<<"\t"<<s[k].reg_no<<"\t"<<s[k].degree_program<<"\t\t"<<s[k].SGPA<<"\t"<<endl;

	}
	return 0;
}