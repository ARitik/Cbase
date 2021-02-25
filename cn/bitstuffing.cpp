#include<iostream>

using namespace std;

int main() {
    int b_frame[30],frame[20];
    int size;   
    cout << "Enter size of Frame :" << endl;
    cin >> size;
    cout << "Enter array:" << endl;
    for(int i=0;i<size;i++) {
        cin >> frame[i];
    }
    int n = 0,count=0;
    cout << "Performing bit stuffing..." << endl;
    // Perform Bit stuffing
    for(int i=0;i<size;i++) {
        b_frame[n] = frame[i];
        if(frame[i]==1) 
            count++;
        else    
            count=0;
        if(count==5) {
           b_frame[++n] = 0;
           count=0;
        }
            n++;
    }
    cout << "Bit Stuffing :: DONE :: Stuffed Array is: " << endl;
    for(int i=0;i<n;i++)
        cout << b_frame[i];     
    return 1;
}

    
