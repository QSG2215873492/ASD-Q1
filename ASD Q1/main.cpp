//
//  main.cpp
//  ASD Q1
//
//  Created by s20181105882ASN on 2019/6/19.
//  Copyright © 2019 s20181105882ASN. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int a[8];
    for (int i=0; i<8; i++)
    {
        cin>>a[i];
    }

    for(int i=0; i<8; i++)
    {
        int x;
        for(int j=0; j<7-i; j++)
        {
            if(a[j]>a[j+1])
            {
                x=a[j];
                a[j]=a[j+1];
                a[j+1]=x;
            }
        }
    }
    int s=0;
    int avg;
    for(int i=1; i<7; i++)
    {
        s+=a[i];
        cout<<a[i]<<endl;
    }
    avg=s/6;
    cout<<avg<<endl;
    return 0;
}
