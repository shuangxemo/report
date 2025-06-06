#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

class student
{
public:
	string name;
	string number;
	string class_name;
	int mark;
};

vector<student> v1;

int Menu_Bar()
{
	int choose;
	cout << "1.记录学生成绩" << endl;
	cout << "2.查询学生成绩" << endl;
	cout << "3.统计课程成绩" << endl;
	cout << "4.退出系统" << endl;
	cout << "请输入选项序号：";	cin >> choose;
	cout << endl;

	return choose;
}

void init()
{
	student s1;
	string na, num, c_n;
	int ma;
	cout << "请输入学生姓名：";
	cin >> na;
	s1.name = na;
	cout << "请输入学生学号：";
	cin >> num;
	s1.number = num;
	cout << "请输入学生的课程名称：";
	cin >> c_n;
	s1.class_name = c_n;
	cout << "请输入学生的成绩：";
	cin >> ma;
	s1.mark = ma;
	v1.push_back(s1);
	cout << "成绩已经成功录入!";
	cout << endl;
}

void find()
{
	int choose;
	cout << "1.按学生姓名查询" << endl;
	cout << "2.按学生学号查询" << endl;
	cout << "3.按课程名称查询" << endl;
	cout << "请输入选项序号："; cin >> choose;
	if (choose == 1)
	{
		string name;
		cout << "请输入学生姓名："; cin >> name;
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i].name == name)
			{
				cout << "姓名：" << v1[i].name << endl;
				cout << "学号：" << v1[i].number << endl;
				cout << "课程：" << v1[i].class_name << endl;
				cout << "成绩：" << v1[i].mark << endl;
				break;
			}
		}
	}
	else if (choose == 2)
	{
		string number;
		cout << "请输入学生学号："; cin >> number;
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i].number == number)
			{
				cout << "姓名：" << v1[i].name << endl;
				cout << "学号：" << v1[i].number << endl;
				cout << "课程：" << v1[i].class_name << endl;
				cout << "成绩：" << v1[i].mark << endl;
				break;
			}
		}
	}
	else
	{
		string c_n;
		cout << "请输入学生的课程名称："; cin >> c_n;
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i].class_name == c_n)
			{
				cout << "姓名：" << v1[i].name << endl;
				cout << "学号：" << v1[i].number << endl;
				cout << "课程：" << v1[i].class_name << endl;
				cout << "成绩：" << v1[i].mark << endl;
				break;
			}
		}
	}
}

void search_mark()
{
	string c_n;
	int highest = 0, lowest = 100, count = 0;
	double average = 0;
	cout << "请输入课程名称："; cin >> c_n;
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i].class_name == c_n)
		{
			average += v1[i].mark;
			lowest = min(lowest, v1[i].mark);
			highest = max(highest, v1[i].mark);
			count++;
		}
	}
	cout << "课程：" << c_n << endl;
	average = average / count;
	printf("平均分：%3.2f\n", average);
	cout << "最高分：" << highest << endl;
	cout << "最低分：" << lowest << endl;
}

void exit_Bar()
{
	cout << "感谢使用学生成绩管理系统。再见！";
}



int main()
{
	int flag = 1;
	while (flag == 1)
	{
		int choose = Menu_Bar();
		if (choose == 1)
		{
			init();
		}
		else if (choose == 2)
		{
			find();
		}
		else if (choose == 3)
		{
			search_mark();
		}
		else
		{
			exit_Bar();
			break;
		}
	}
	return 0;
}