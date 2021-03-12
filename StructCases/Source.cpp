/* 
case1:
学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下

设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员

学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值

最终打印出老师数据以及老师所带的学生数据。


case2:
设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。

通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。

五名英雄信息如下：

		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
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
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
	};

	bubbleSort(shero, numberHero);
	for (int i = 0; i < numberHero; i++)
		cout << shero[i].name << "\t" << shero[i].age << "\t" << shero[i].gender << endl;


	system("pause");
	return 0;
}