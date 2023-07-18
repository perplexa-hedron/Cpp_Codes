#include <iostream>
#include <vector>
using namespace std;
long long mpp(const vector<int> vec)
{
    long long mpp = 0;
    long long n = vec.size();
    for (int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((long long)vec[i]* vec[j] > mpp){
            mpp=(long long)vec[i]*vec[j];
            }
        }
    }
    return mpp;
}

long long mpf(const vector<int> vec)
{
    int n = vec.size();
    int mi1 = -1;
    for (int i = 0; i < n; i++)
    {
        if ((mi1 == -1 || vec[i] > vec[mi1]))
        {
            mi1 = i;
        }
    }
    int mi2 = -1;
    for (int j = 0; j < n;j++)
    {
        if ((j != mi1) && (mi2 == -1 ||vec[j] > vec[mi2]))
        {
            mi2 = j;
        }
    }

    long long prod;
    prod = (long long) vec[mi1]*vec[mi2];

    return prod;
}

int main(){
    /*while(true){
        int n = rand() % 4 +3;
        cout<<n<<endl;
        vector<int> vec;
        for(int i = 0; i<n;i++){
            vec.push_back(rand() % 10);
        }
        for(int i=0; i<n;i++){
            cout<<vec[i]<<' ';
        }
        long long res1=mpp(vec);
        long long res2 = mpf(vec);

        if(res1 != res2){
            cout<<"Wrong answer"<<endl;
            break;
        }
        else
            cout<<"OK"<<endl;
    }*/
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }
    cout<<mpf(v)<<endl;
    return 0;
}