#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


class grid
{
    int arr[20][20];
    int arr2[20][20];


public:


    grid()
    {
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {

                arr[i][j]=0;
                arr2[i][j]=0;
            }
        }
        arr[10][11]=1;
        arr[11][12]=1;
        arr[12][10]=1;
        arr[12][11]=1;
        arr[12][12]=1;

    }
    pair<int,int> smallestI ()
    {
        vector<int>vec1;

        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {

                if(arr[i][j]==1)
                {
                    vec1.push_back(i);
                }


            }
        }
        sort(vec1.begin(),vec1.end());
        return make_pair((vec1[0]-1),(vec1[vec1.size()-1]+1));
    }

    pair<int,int> smallestJ ()
    {
        vector<int>vec2;

        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {

                if(arr[i][j]==1)
                {
                    vec2.push_back(j);
                }

            }
        }
        sort(vec2.begin(),vec2.end());
        return make_pair((vec2[0]-1),(vec2[vec2.size()-1]+1));
    }


    void display()
    {
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                cout<<arr2[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    void equalize()
    {
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {

                arr[i][j]=arr2[i][j];

            }
        }
    }

    int neighbours ()
    {
        int sum=0;
        int firstI = smallestI().first;
        int lastI = smallestI().second;
        int firstJ = smallestJ().first;
        int lastJ = smallestJ().second;
        cout<<firstI<<' '<<lastI<<' '<<firstJ<<' '<<lastI<<endl;

        for(int i=firstI;i<=lastI;i++)
        {
            for(int j=firstJ;j<=lastJ;j++)
            {
                cout<<endl<<i<<"    "<<j<<endl;
                sum=0;
                sum=arr[i+1][j]+arr[i-1][j]+arr[i][j+1]+arr[i][j-1]+arr[i+1][j+1]+arr[i+1][j-1]+arr[i-1][j+1]+arr[i-1][j-1];

                if(arr[i][j]==0)
                {
                    if(sum==3)
                    {
                        arr2[i][j]=1;
                    }
                }
                else if(arr[i][j]==1)
                {
                    if(sum==2 || sum==3)
                    {
                        arr2[i][j]=1;
                    }

                    if(sum<=1)
                    {
                        arr2[i][j]=0;
                    }
                    if(sum>=4)
                    {
                        arr2[i][j]=0;
                    }
                }


            }
        }
        return 0;
    }


};




int main()
{
    grid one;
    for(int i=0;i<10;i++)
    {
        one.neighbours();
        cout<<endl<<"==========================="<<endl;
        one.display();
        one.equalize();
    }



}
