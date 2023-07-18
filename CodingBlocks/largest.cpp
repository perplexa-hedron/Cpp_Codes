#include<iostream>
#include<climits>
using namespace std;
int main() {
	int num;
	int largest = INT_MIN;
	for(int i = 0;i<3;i++){
		cin>>num;
		if(num>largest){
			largest = num;
		}
	}
	cout<<largest;
}