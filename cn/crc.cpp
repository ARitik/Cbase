#include<iostream>
#include<string>

using namespace std;

int n;
string quotient,rem;

string performxor(string x,string y) {
    string result = "";
    for(int j=0;j<4;j++) {
        if(x[j] == y[j])
            result+="0";
        else
            result+="1";
    }
    if(result[0] == '0')
        result = result.substr(1,3);
    return result;
}

void performdivision(string a,string b) {
    if(a[0] == '0')
        quotient+="0";
    else
        quotient+="1";
    string t = a.substr(0,4);
    t = performxor(t,b);

    for(int i=4;i<n;i++) {
        t+=a[i];
        if(t[0]=='0'){
            quotient+="0";
            t = performxor(t,"0000");
        }
        else {
            quotient+="1";
            t = performxor(t,b);
            
        }
          
    }
    rem+=t;
}

int main() {
  
    string perm,a;
    string b; 
    cout << "Enter key to be used: " << endl;
    cin >> b;
    cout << "Enter Number of Bits to be sent: " << endl;
    cin >> n;
    cout << "Enter Data to be Sent: " << endl;
    cin >> a;
    perm = a;
    a+="000";
    n+=3;
    performdivision(a,b);
    string todecrypt = perm + rem;
    cout << "Encrypted String is: " << todecrypt << endl;
    rem = "";
    quotient = "";
    performdivision(todecrypt,b);
    cout << "No Errors Encountered -> Remainder: " << rem << endl;


    return 0;

}
