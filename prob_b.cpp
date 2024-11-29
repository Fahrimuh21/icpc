#include<bits/stdc++.h>
using namespace std;

int fx2(int a, int b){
	if(b==0){
		return 1;
	}
	else{
		return a*fx2(a, b-1);
	}
}
int main(){
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i) {
		int hasil=0;
        string input;
        cin>>input;
        if (input == "+0" || input == "0") {
            cout << "Inf" << endl;
        } else if (input == "-0") {
        	cout << "-Inf" <<endl;
        } else if (input == "Inf" || input == "inf") {
            cout << "0.000000" << endl;
        } else if (input == "-Inf") {
            cout << "0.000000" <<endl;
        } else if (input == "nan" || input == "NaN") {
            cout << "NaN" << endl;
        }else{
        	for(int j=0; j<input.length(); j++){
        		hasil=hasil+input[input.length()-j-1]*fx2(10, j);
        		
			}
			cout<<hasil*0.0000001;
		}
	}
}
