#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


class grid
{


    vector<vector<int>> arr ;
    vector<vector<int>> arr2 ;

public:


    grid()
    {
        arr = vector<vector<int>>(20, vector<int>(20, 0));
        arr2 = vector<vector<int>>(20, vector<int>(20, 0));
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


     void reset1()
    {
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                arr[i][j]=0;
            }
        }

    }
    void reset2()
    {
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                arr2[i][j]=0;
            }
        }

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
                if(arr2[i][j]==0)
                {
                    cout<<'-'<<' ';
                }
                else
                {
                    cout<<arr2[i][j]<<' ';
                }

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
    int countNeighbours()
    {
        int sum=0;
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                if(arr[i][j]==1)
                {
                    sum++;
                }
            }
        }
        return sum;
    }




    int neighbours()
    {
        int sum=0;
        int firstI = smallestI().first;
        int lastI = smallestI().second;
        int firstJ = smallestJ().first;
        int lastJ = smallestJ().second;

        firstI = max(firstI, 1);
        lastI = min(lastI, 18);
        firstJ = max(firstJ, 1);
        lastJ = min(lastJ, 18);

        for(int i=firstI;i<=lastI;i++)
        {
            for(int j=firstJ;j<=lastJ;j++)
            {
//                if(i==18 || i==0 || j==18 ||j==0)
//                {
//                    continue;
//                }

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
    grid example;
    while (true)
    {
        cout<<"1)reset"<<endl<<"2)count neighbours"<<endl<<"3)next generation"<<endl<<"4)display"<<endl<<"5)run"<<endl<<"6)Exit"<<endl;
        string choice;
        cin>>choice;

        if(choice=="1")
        {
            example.reset1();
            example.reset2();
        }
        else if (choice=="2")
        {
            int ans = example.countNeighbours();
            cout<<ans<<endl;
        }
        else if(choice=="3")
        {
            example.neighbours();
            example.equalize();
        }
        else if(choice =="4")
        {
            example.display();
        }
        else if(choice =="5")
        {
            cout<<"please the number of turns that you want to play at once: "<<endl;
            int num;
            cin>>num;
            for(int i=0;i<num;i++)
            {
                example.neighbours();
                example.equalize();
            }

        }
        else if(choice=="6")
        {
            cout<<"Exiting the program"<<endl<<"Bye Bye"<<endl;
            break;
        }
    }







}
