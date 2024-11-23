#include <iostream>
#include<vector>
using namespace std;


class grid
{
    char arr[20][20];


public:


    grid()
    {
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                arr[i][j]='0';
            }
        }
    }


    void display()
    {
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                cout<<arr[i][j]<<' ';
            }
            cout<<endl;
        }
    }


};




int main()
{
    grid one;
    one.display();

}
