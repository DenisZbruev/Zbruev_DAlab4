
#include <iostream>
#include "Claster.h"
#include "locale.h"
//---------------------------------------------------------------------------

void main()
{
  
    setlocale(0, "");
    Claster Y(4,2);
    cout << "������� ���������� ������: " << endl;
    int s;
    cin >> s;
    Y.model_start(s);
    for (int i = 0; i < Y.Getsize(); i++)
    {
        cout<<"���������� "<<i<<" �������� �������� "<<Y.Getwork()[i]<< " ������ " <<" , �������� "<< Y.Getstop()[i]<<" ������ "<< endl;
    }
    cout << " ����� ������� " << Y.Getfailure() << endl; 
}
//---------------------------------------------------------------------------
