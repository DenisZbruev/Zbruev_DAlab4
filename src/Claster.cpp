#include "Claster.h"
#include<iostream>
using namespace std;
Claster::Claster(int size_, int size_q)
{
	if ((size_ < 0)||(size_>Maxcount))throw "uncorrect_claster_size";
	size = size_;
	work = new int[size];
	stop = new int[size];
	for (int i = 0; i < size; i++)
	{
		work[i] = 0;
		stop[i] = 0;
	}
	failure = 0;
	turn = Queue(size_q);
}
Claster::Claster(const Claster& tmp)
{
	size = tmp.size;
	failure = tmp.failure;
	turn = tmp.turn;
	work = new int[size];
	stop = new int[size];
	for (int i = 0; i < size; i++)
	{
		work[i] = tmp.work[i];
		stop[i] = tmp.stop[i];
	}
}
Claster& Claster::operator=(const Claster& tmp)
{
	if (size != 0)
	{
		delete[]work;
		delete[]stop;
	}
	size = tmp.size;
	failure = tmp.failure;
	turn = tmp.turn;
	work = new int[size];
	stop = new int[size];
	for (int i = 0; i < size; i++)
	{
		work[i] = tmp.work[i];
		stop[i] = tmp.stop[i];
	}
	return *this;
}
Claster::~Claster()
{
	delete[]work;
	delete[]stop;
}
void Claster::model_start(int tact)
{
	srand(time(NULL));
	Typeelem cur;
	for (int i = 0; i < tact; i++)
	{
		int count_free = 0;
		do
		{
			if (cur.Get_is() == 1)       //если задание еще не в работе
			{
				if (!(turn.IsEmpty()))
				{
					cur = turn.Get();
					cur.Change_is();
					count_free = 0;
					for (int j = 0; j < size; j++)
					{
						if (work[j] == 0)
						{
							count_free++;
						}
					}
					if (count_free >= cur.Getcount())
					{
						int l = cur.Getcount();
						for (int j = 0; (j < size) && (l > 0); j++)
						{
							if (work[j] == 0)
							{
								work[j] = cur.Gettime();
								l--;
							}
						}
						count_free -= cur.Getcount();
					}
					else
					{
						turn.Put(cur);
						count_free = -1;
					}
					cur.Change_is();
				}
			}
		} while ((count_free > 0)&&(!(turn.IsEmpty())));
		int count_problem = rand() % Maxcount;
		for (int j = 0; j < count_problem; j++)
		{
			string name = to_string(111233233 % (rand() % 1000));
			int time = rand() % 50 +  1;
			int count = rand() % size;
			Typeelem newproblem(name, time, count);
			if (!turn.IsFull())
			{
				turn.Put(newproblem);
			}
			else
			{
				failure++;
			}
		}
		for (int j = 0; j < size; j++)
		{
			if (work[j] > 0)
			{
				work[j]--;
			}
			else
			{
				stop[j]++;
			}
		}
	}
}
