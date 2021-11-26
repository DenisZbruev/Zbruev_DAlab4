
#include <iostream>
#include "Claster.h"
#include "locale.h"
//---------------------------------------------------------------------------

void main()
{
  
    setlocale(0, "");
    Claster Y(4,2);
    cout << "¬ведите количество тактов: " << endl;
    int s;
    cin >> s;
    Y.model_start(s);
    for (int i = 0; i < Y.Getsize(); i++)
    {
        cout<<"процессору "<<i<<" осталось работать "<<Y.Getwork()[i]<< " тактов " <<" , пустовал "<< Y.Getstop()[i]<<" тактов "<< endl;
    }
    cout << " „исло отказов " << Y.Getfailure() << endl; 
}
//---------------------------------------------------------------------------
