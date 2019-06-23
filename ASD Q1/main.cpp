
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

ifstream stu("Users/s20181105882ASN/Desktop/选手信息.txt");
ifstream jud("/Users/s20181105882ASN/Desktop/裁判打分.txt");
ofstream gra("/Users/s20181105882ASN/Desktop/grade.txt");

class DF
{
private:
    double grade[7]={0};
    string number,name,college,judge[7];
public:
    double average;
    DF(string num,string nam,string col);
    void cout();
};

DF::DF(string num,string nam,string col):number(num),name(nam),college(col)
{
    double sum=0;
    for(int i=0; i<7;i++)
    {
        jud>>judge[i];
        jud>>grade[i];
        for(int i=0;i<7;i++)
        {
            for(int k=0;k<6-i;k++)
            {
                if(grade[k]>grade[k+1])
                {
                    double s=grade[k];
                    grade[k]=grade[k+1];
                    grade[k+1]=s;
                }
            }
        }
        for(i=1;i<6;i++)
        {
            sum+=grade[i];
        }
        average=sum/5.0;
    }
}

void DF::cout()
{
    gra<<number <<"  "<<name <<"  "<<college<<endl;
    for(int i=0;i<7;i++)
    {
        gra<<judge[i]<<"  "<<grade[i]<<"  ";
    }
    gra<<"average="<<average<<endl;
}

int main(int argc, const char * argv[]) {
    DF *avg[8];
    string number,name,college;
    for(int i=0;i<8;i++)
    {
        stu>>number>>name>>college;
        avg[i]=new DF(number,name,college);
    }
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7-i;j++)
        {
            if(avg[j]>avg[j+1])
            {
                DF *k= avg[j];
                avg[j]= avg[j+1];
                avg[j+1]=k;
            }
        }
    }
    for(int i=0;i<8;i++)
    {
        avg[i]->cout();
    }
    return 0;
}
