#include <iostream>
using namespace std;
int main()
{
    char c;
    cout<<"Enter the character: ";
    cin>>c;
    if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U'){
        cout<<"Entered character is vowel"<<endl;
    }
    else{
        cout<<"Entered Character is consonant"<<endl;
    }
    
}