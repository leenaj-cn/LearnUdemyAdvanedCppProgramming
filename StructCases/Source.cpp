/* 
case1:
ѧУ������������Ŀ��ÿ����ʦ����5��ѧ�����ܹ���3����ʦ����������

���ѧ������ʦ�Ľṹ�壬��������ʦ�Ľṹ���У�����ʦ������һ�����5��ѧ����������Ϊ��Ա

ѧ���ĳ�Ա�����������Է���������������3����ʦ��ͨ��������ÿ����ʦ��������ѧ����ֵ

���մ�ӡ����ʦ�����Լ���ʦ������ѧ�����ݡ�


case2:
���һ��Ӣ�۵Ľṹ�壬������Ա���������䣬�Ա�;�����ṹ�����飬�����д��5��Ӣ�ۡ�

ͨ��ð��������㷨���������е�Ӣ�۰���������������������մ�ӡ�����Ľ����

����Ӣ����Ϣ���£�

		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"},
*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int numberTeacher = 3;
const int numberStudent = 5;
const int numberHero = 5;

struct Hero
{
	string name;
	int age;
	string gender;
};

struct Student
{
	string name;
	int score;
};

struct Teacher
{
	string name;
	Student student[numberStudent];
};


void GetStudentsInfo(Teacher* teachers, int numberTeacher, int numberStudent)
{
	string teacherNameSeed = "ABC";
	string studentNameSeed = "abcde";
	for (int i = 0; i < numberTeacher; i++)
	{
		teachers[i].name = "Teacher_";
		teachers[i].name += teacherNameSeed[i];

		for (int j = 0; j < numberStudent; j++)
		{
			teachers[i].student[j].name = "Student_";
			teachers[i].student[j].name += studentNameSeed[j];

			int randomScore = rand() % 61 + 40;
			teachers[i].student[j].score = randomScore;
		}
	}

}

template <typename T>
void SwapHero(T& hero1, T& hero2)
{
	T temp;
	temp = hero1;
	hero1 = hero2;
	hero2 = temp;

}
void bubbleSort(Hero* shero, int numberHero)
{
	for (int i = 0; i < numberHero - 1; i++)
	{
		for (int j = 0; j < numberHero - 1 - i; j++)
		{
			if (shero[j].age > shero[j + 1].age)
			{
				SwapHero(shero[j], shero[j + 1]);
			}
		}
	}
}

int main()
{

	cout << "case 1:" << endl;
	srand((unsigned int)time(NULL));

	Teacher teachers[numberTeacher];
	
	GetStudentsInfo(teachers, numberTeacher, numberStudent);

	for (int i = 0; i < numberTeacher; i++)
	{
		//cout << "Teacher\t\t" << "Student\t\t" << "Score" << endl;
		for (int j = 0; j < numberStudent; j++)
		{
			cout << teachers[i].name << "\t\t" << teachers[i].student[j].name << "\t\t" << teachers[i].student[j].score << endl;
		}
		cout << endl;
	}

	cout << "case 2:" << endl;
	Hero shero[numberHero] = {
		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"},
	};

	bubbleSort(shero, numberHero);
	for (int i = 0; i < numberHero; i++)
		cout << shero[i].name << "\t" << shero[i].age << "\t" << shero[i].gender << endl;


	system("pause");
	return 0;
}