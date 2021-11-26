#include"Queue.h"
#include <cstdlib>
#include <ctime> 
#include "string"
using namespace std;
#define Maxcount 4
class Claster
{
private:
	int* work;            //массив, содержащий информацию о том, через сколько тактов процессор осводится
	int* stop;            //сколько тактов каждый процессор пустовал
	int size;            //число процессоров
	Queue turn;             //очередь заданий
	int failure;             //число отказов при постановке в очередь
public:
	Claster(int size_ = 1, int size_q = 10);
	Claster(const Claster& tmp);
	Claster& operator=(const Claster& tmp);
	~Claster();
	void model_start(int tact = 0);
	int Getsize()
	{
		return size;
	}
	int Getfailure()
	{
		return failure;
	}
	int* Getwork()
	{
		return work;
	}
	int* Getstop()
	{
		return stop;
	}
};
