#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	if(N>0 && N<10 && N%2!=0){
		for(int i =0;i<N;i++){
			if(i<=(N-1)/2){
				for(int j=(N)/2-i;j>0;j--)
					cout<<"  ";
				for(int k=0;k<2*i+1;k++)
					cout<<"* ";
			}

			else{
				for(int l=0;l<=(2*i-N)/2;l++)
					cout<<"  ";
				for(int m=2*(N-i)-1;m>=1;m--)
					cout<<"* ";
			}
			cout<<endl;
		}
	}
	return 0;
}