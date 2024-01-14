#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n1, n2;
    char ch;
    bool flag = 0;
    //cin >> ch;
    do{
        cin>>ch;
        if(ch == '*'){
            cin>>n1>>n2;
            cout<<(n1*n2)<<endl;
        }
        else if(ch == '%'){
            cin>>n1>>n2;
            cout<<(n1%n2)<<endl;
        }
        else if(ch == '/'){
            cin>>n1>>n2;
            cout<<(n1/n2)<<endl;
        }
        else if(ch == '+'){
            cin>>n1>>n2;
            cout<<(n1+n2)<<endl;
        }
        else if(ch == '-'){
            cin>>n1>>n2;
            cout<<(n1-n2)<<endl;
        }
        else if(ch == 'x'||ch == 'X'){
            flag=1;
        }
        else{
            cout<<"Invalid operation. Try again."<<endl;
        }
    }
    while(flag == 0);
    /*switch (ch)
    {
    case '*':
        cin >> n1 >> n2;
        cout << (n1 * n2);
        break;
    case '%':
        cin >> n1 >> n2;
        cout << (n1 % n2);
        break;
    case '/':
        cin >> n1 >> n2;
        cout << (n1 / n2);
        break;
    case '+':
        cin >> n1 >> n2;
        cout << (n1 + n2);
        break;
    case '-':
        cin >> n1 >> n2;
        cout << (n1 - n2);
        break;
    case 'x' || 'X':
        break;
    default:
        cout << "Invalid Input";
    }*/
}