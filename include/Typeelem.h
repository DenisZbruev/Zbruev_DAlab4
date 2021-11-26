#include "string"
using namespace std;
class Typeelem
{
	string name;
	int time;       //����� ����������
	int count;      //��������� ����� �����������
	int is;        //is=1-� ������ ������� �� ����
public:
	Typeelem(string name_ = "", int time_ = 1, int count_ = 1);
	Typeelem& operator=(const Typeelem& tmp);
	Typeelem(const Typeelem& tmp);
	string Getname()
	{
		return name;
	}
	int Gettime()
	{
		return time;
	}
	int Getcount()
	{
		return count;
	}
	int Get_is()
	{
		return is;
	}
	void Change_is()
	{
		is = -is;
	}
};
