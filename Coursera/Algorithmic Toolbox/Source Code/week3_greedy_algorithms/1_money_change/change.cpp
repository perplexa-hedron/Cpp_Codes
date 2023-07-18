#include <iostream>
using namespace std;
int change(int n)
{
  int num;
  while(n>=0){
    if(n>5 && n<10)
    {
      n=n-5;
      num = 5;
    }
    else if(n>10)
    {
      int i = 0;
      while(n>=0){
        if(i ==0){
          n=n-10;
          num = 6;
          i++;
        }
        else{
          num = n/10;
          n= n%10;
        }
      }
    } 

    else{
      n=n-n;
      num = n;
    }

  }

}
int main()
{
  int n;
  cin>>n;
  cout<<change(n);
  return 0;
} 