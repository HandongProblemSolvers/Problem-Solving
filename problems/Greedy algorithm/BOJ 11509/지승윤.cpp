#include<iostream>
int N,a[1000001],h,z;
int main(){
    std::cin>>N;
    while(N--){
        std::cin>>h;
        a[h]++;
        (a[h+1])?a[h+1]--:z++;
    }
    std::cout<<z;
}
