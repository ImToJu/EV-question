#include<iostream>
#include <time.h>
using namespace std;
int main(){
    srand(time(NULL));

    double rate[6];
    rate[0]=0.02;
    rate[1]=0.11;
    rate[2]=0.11;
    rate[3]=0.25333;
    rate[4]=0.25333;
    rate[5]=0.25333;

    int pot=1;
    int priceCount[6]={0};
    int repTimes=10000000;
    double ev=0;
    for(int c=0;c<repTimes;c++){
        int t=1000,cmpltTime=0;
        for(int i=0;i<6;i++){
            priceCount[i]=0;
        }
        while(t--){
            double x = (double) rand() / (RAND_MAX + 1.0);
            double y=rate[0];
            if(x<y)
                priceCount[0]++;
            else if(x<y+rate[1])
                priceCount[1]++;
            else if(x<y+rate[1]+rate[2])
                priceCount[2]++;
            else if(x<y+rate[1]+rate[2]+rate[3])
                priceCount[3]++;
            else if(x<y+rate[1]+rate[2]+rate[3]+rate[4])
                priceCount[4]++;
            else
                priceCount[5]++;

            int check=1;
            for(int i=0;i<6;i++){
                check*=priceCount[i];
            }
            cmpltTime++;
            if(check!=0){
                ev+=cmpltTime;
                t=0;
            }
        }
    }
    cout<<"Ev:"<<ev/repTimes;
    return 0;
}
