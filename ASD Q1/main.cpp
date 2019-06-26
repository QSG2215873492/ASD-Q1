
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream stu("/Users/s20181105882ASN/Desktop/选手信息.txt");
ifstream jud("/Users/s20181105882ASN/Desktop/裁判打分.txt");
ofstream gra("/Users/s20181105882ASN/Desktop/grade.txt");

class Game
{
private:
    double grade[7]={0};
    string number,name,college,judge[7];
public:
    double average;
    double sum=0;
    Game(string num,string nam,string col);
    void play()
    {
        gra<<number<<"  "<<name<<"  "<<college<<endl;
        for(int i=0;i<7;i++)
        {
            gra<<judge[i]<<" "<<grade[i];
            if(i!=6)
                gra<<" ";
        }
        gra<<endl;
        gra<<"average="<<average<<endl;
    }
};

Game::Game(string num,string nam,string col):number(num),name(nam),college(col)
{
    for(int i=0;i<7;i++)
    {
        jud>>judge[i];
        jud>>grade[i];
    }
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6-i;j++)
        {
            if(grade[j]>grade[j+1])
            {
                double m=grade[j];
                grade[j]=grade[j+1];
                grade[j+1]=m;
            }
        }
    }
    cout<<endl;
    for(int i=1;i<6;i++)
    {
        sum+=grade[i];
    }
    average=sum/5.0;
}

int main()
{
    string name,number,college;
    Game *avg[8];
    for(int i=0;i<8;i++)
    {
        stu>>number>>name>>college;
        avg[i]=new Game(number,name,college);
    }
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7-i;j++)
        {
            if(avg[j]->average<avg[j+1]->average)
            {
                Game *t=avg[j+1];
                avg[j+1]=avg[j];
                avg[j]=t;
            }
        }
    }
    for(int m=0;m<8;m++)
    {
        avg[m]->play();
    }
    return 0;
}
