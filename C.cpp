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
	cout << "1.��¼ѧ���ɼ�" << endl;
	cout << "2.��ѯѧ���ɼ�" << endl;
	cout << "3.ͳ�ƿγ̳ɼ�" << endl;
	cout << "4.�˳�ϵͳ" << endl;
	cout << "������ѡ����ţ�";	cin >> choose;
	cout << endl;

	return choose;
}

void init()
{
	student s1;
	string na, num, c_n;
	int ma;
	cout << "������ѧ��������";
	cin >> na;
	s1.name = na;
	cout << "������ѧ��ѧ�ţ�";
	cin >> num;
	s1.number = num;
	cout << "������ѧ���Ŀγ����ƣ�";
	cin >> c_n;
	s1.class_name = c_n;
	cout << "������ѧ���ĳɼ���";
	cin >> ma;
	s1.mark = ma;
	v1.push_back(s1);
	cout << "�ɼ��Ѿ��ɹ�¼��!";
	cout << endl;
}

void find()
{
	int choose;
	cout << "1.��ѧ��������ѯ" << endl;
	cout << "2.��ѧ��ѧ�Ų�ѯ" << endl;
	cout << "3.���γ����Ʋ�ѯ" << endl;
	cout << "������ѡ����ţ�"; cin >> choose;
	if (choose == 1)
	{
		string name;
		cout << "������ѧ��������"; cin >> name;
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i].name == name)
			{
				cout << "������" << v1[i].name << endl;
				cout << "ѧ�ţ�" << v1[i].number << endl;
				cout << "�γ̣�" << v1[i].class_name << endl;
				cout << "�ɼ���" << v1[i].mark << endl;
				break;
			}
		}
	}
	else if (choose == 2)
	{
		string number;
		cout << "������ѧ��ѧ�ţ�"; cin >> number;
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i].number == number)
			{
				cout << "������" << v1[i].name << endl;
				cout << "ѧ�ţ�" << v1[i].number << endl;
				cout << "�γ̣�" << v1[i].class_name << endl;
				cout << "�ɼ���" << v1[i].mark << endl;
				break;
			}
		}
	}
	else
	{
		string c_n;
		cout << "������ѧ���Ŀγ����ƣ�"; cin >> c_n;
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i].class_name == c_n)
			{
				cout << "������" << v1[i].name << endl;
				cout << "ѧ�ţ�" << v1[i].number << endl;
				cout << "�γ̣�" << v1[i].class_name << endl;
				cout << "�ɼ���" << v1[i].mark << endl;
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
	cout << "������γ����ƣ�"; cin >> c_n;
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
	cout << "�γ̣�" << c_n << endl;
	average = average / count;
	printf("ƽ���֣�%3.2f\n", average);
	cout << "��߷֣�" << highest << endl;
	cout << "��ͷ֣�" << lowest << endl;
}

void exit_Bar()
{
	cout << "��лʹ��ѧ���ɼ�����ϵͳ���ټ���";
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