#include "string"
using namespace std;
class Typeelem
{
	string name;
	int time;       //время выполнения
	int count;      //требуемое число процессоров
	int is;        //is=1-в работу ставить не надо
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
