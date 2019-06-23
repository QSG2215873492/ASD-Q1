//
//  main.cpp
//  ASD Q1
//
//  Created by s20181105882ASN on 2019/6/19.
//  Copyright © 2019 s20181105882ASN. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomainp>

using namespace std;

class DF
{
private:
    int avg;
    string number,name,college;
public:
    void average();
    void cout();
};

void DF::average()
{
    char b[999];
    int a[8];
    ifstream A("/Users/s20181105882ASN/Desktop/裁判打分.txt");
    ofstream C("/Users/s20181105882ASN/Desktop/A.txt");
    if(A.is_open())
    {
        int x;
        int sum=0;
        A.getline(b,999);
        C<<b<<endl;
        for(int i=0; i<7; i++)
        {
            A>>a[i];
        }
        for(int i=0; i<7; i++)
        {
            C<<a[i]<<" ";
        }
        
        for(int i=0; i<7; i++)
        {
            for(int j=0; j<6-i; j++)
            {
                if(a[j]>a[j+1])
                {
                    x=a[j];
                    a[j]=a[j+1];
                    a[j+1]=x;
                }
            }
        }

        for(int i=1; i<6; i++)
        {
            sum +=a[i];
        }
        avg=sum/5;
        C<<avg<<endl;
    }
}

void DF::cout()
{
    ofstream C("/Users/s20181105882ASN/Desktop/A.txt");
    ifstream B("/Users/s20181105882ASN/Desktop/选手信息.txt");
    char c[999];
    if(B.is_open())
    {
        C<<"OK"<<endl;
        B.getline(c,999);
        C<<c<<endl;
    }
}
int main(int argc, const char * argv[]) {
    DF m;
    m.cout();
    m.average();
    return 0;
}
