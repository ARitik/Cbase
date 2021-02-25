#include<iostream>

using namespace std;

int main() {
    char c_frame[40],frame[20];
    int size;
    cout << "Enter size of Frame :" << endl;
    cin >> size; 
    cout << "Enter character string:" << endl;
    cin >> frame;
    int n=5,flag=0;
    c_frame[0] = 'd';
    c_frame[1] = 'l';
    c_frame[2] = 'e';
    c_frame[3] = 's';
    c_frame[4] = 't';
    c_frame[5] = 'x';
    for(int i=0;i<size;i++) {
        c_frame[++n] = frame[i];
        if(i<=size-3) { 
        if(frame[i] == 'd' && frame[i+1] == 'l' && frame[i+2] == 'e') {
            c_frame[++n] = 'l';
            c_frame[++n] = 'e';
            c_frame[++n] = 'd';
            c_frame[++n] = 'l';
            c_frame[++n] = 'e';
            i+=2;
        }
        }
    }
    c_frame[++n] = 'd';
    c_frame[++n] = 'l';
    c_frame[++n] = 'e';
    c_frame[++n] = 'e';
    c_frame[++n] = 't';
    c_frame[++n] = 'x';

    for(int i=0;i<=n;i++) {
        cout << c_frame[i];
    }
    return 0;
}