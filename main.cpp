#include <iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
string full_string;

class grid
{


    vector<vector<int>> arr ;
    vector<vector<int>> arr2 ;

public:



    grid()
    {
        arr = vector<vector<int>>(20, vector<int>(20,0));
        arr2 = vector<vector<int>>(20, vector<int>(20,0));

        int count2=0;
        cout<<endl<<"        The Initial Grid"<<endl;

        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {




                if(arr[i][j]==0)
                {
                    cout<<'-'<<' ';
                }
                else
                {
                    cout<<arr[i][j]<<' ';
                }
                count2++;

            }
            cout<<endl;
        }


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

    void setter()
    {
        int count2=0;
        cout<<"     The New Grid is "<<endl;
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {

                arr[i][j] = full_string[count2]-'0';


                if(arr[i][j]==0)
                {
                    cout<<'-'<<' ';
                }
                else
                {
                    cout<<arr[i][j]<<' ';
                }
                count2++;

            }
            cout<<endl;
        }
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
                else if(arr2[i][j]==1)
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

    void initialize_playing_grid()
    {
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                arr2[i][j]=arr[i][j];
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

        firstI = max(0,firstI);
        lastI = min(19,lastI);
        firstJ = max(0,firstJ);
        lastJ = min(19,lastJ);



        for(int i=firstI;i<=lastI;i++)
        {
            for(int j=firstJ;j<=lastJ;j++)
            {
                sum=0;

                if(i==0 && j==0)
                {
                    sum=arr[i+1][j]+arr[i][j+1]+arr[i+1][j+1];
                }
                else if(i==0 && j==19)
                {
                    sum=arr[i+1][j]+arr[i][j-1]+arr[i+1][j-1];
                }
                else if(i==19 && j==0)
                {
                    sum=arr[i-1][j]+arr[i][j+1]+arr[i-1][j+1];
                }
                else if(i==19 && j==19)
                {
                    sum=arr[i-1][j]+arr[i][j-1]+arr[i-1][j-1];
                }
                else if(i==0)
                {
                    sum=arr[i+1][j]+arr[i][j+1]+arr[i][j-1]+arr[i+1][j+1]+arr[i+1][j-1];
                }
                else if(i==19)
                {
                    sum=arr[i-1][j]+arr[i][j+1]+arr[i][j-1]+arr[i-1][j+1]+arr[i-1][j-1];
                }
                else if(j==0)
                {
                    sum=arr[i+1][j]+arr[i-1][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i-1][j+1];
                }
                else if(j==19)
                {
                    sum=arr[i+1][j]+arr[i-1][j]+arr[i][j-1]+arr[i+1][j-1]+arr[i-1][j-1];
                }
                else
                {
                    sum=arr[i+1][j]+arr[i-1][j]+arr[i][j+1]+arr[i][j-1]+arr[i+1][j+1]+arr[i+1][j-1]+arr[i-1][j+1]+arr[i-1][j-1];
                }


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
    cout<<"===== Welcome to the Game of Life ======"<<endl;
    bool flag =true;
    grid example;
    while (true)
    {
        cout<<"1)Reset"<<endl<<"2)load a new grid from a file"<<endl<<"3)count neighbours"<<endl<<"4)Next generation"<<endl<<"5)Display"<<endl<<"6)Run several turns"<<endl<<"7)Exit"<<endl;
        string choice;
        cout<<"choose a number from 1 to 7: ";
        cin>>choice;


        if(choice=="1")
        {
            example.reset1();
            example.reset2();
        }
        else if(choice =="2")
        {
            cout<<"Enter the file's name: "<<endl;
            string name;
            cin>>name;
            ifstream file(name);
            if(!file)
            {
                cout<<"Error in opening the file"<<endl;

            }
            else
            {
                string t;
                full_string="";
                while(file>>t)
                {
                    full_string+=t;
                }
                if(full_string.size()!=400)
                {
                    cout<<"the file must contain 400 character"<<endl;
                    continue;
                }
                else
                {
                    example.setter();
                }
            }
        }
        else if (choice=="3")
        {
            int ans = example.countNeighbours();
            cout<<"The Number of living cells are: "<<ans<<endl;
        }
        else if(choice=="4")
        {
            flag=false;
            if(example.countNeighbours()==0)
            {
                cout<<"All the grid is dead"<<endl;
                continue;

            }
            example.neighbours();
            example.equalize();
        }
        else if(choice =="5")
        {
            if(flag)
            {
                example.initialize_playing_grid();
            }
            example.display();
        }
        else if(choice =="6")
        {
            flag=false;

            if(example.countNeighbours()==0)
            {
                cout<<"All the grid is dead"<<endl;
                continue;

            }
            cout<<"please the number of turns that you want to play at once: "<<endl;
            int num;
            cin>>num;
            for(int i=0;i<num;i++)
            {
                example.neighbours();
                example.equalize();
            }

        }
        else if(choice=="7")
        {
            cout<<"Exiting the program"<<endl<<"Bye Bye"<<endl;
            break;
        }
    }







}
