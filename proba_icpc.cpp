#include<bits/stdc++.h>
using namespace std;

string ubah_kata( string kata) {
    string s = "";
    for (int i = 0; i < kata.length(); i++) {
    	if (kata[i] == 'c' && kata[i + 1] == 'h') {
            s += 'c';
            i++;
        }
        else if (kata[i] == 'c') {
            if (i < kata.length() - 1) {
                char next_kata = kata[i + 1];
                if (next_kata == 'a'||next_kata=='o'||next_kata=='u' ||(next_kata!='h' && next_kata!='y' && next_kata!='e' && next_kata!='i')) {
                    s += 'k';
                } else if(next_kata=='e'|| next_kata=='i' || next_kata=='y') {
                    s += 's';
                }
            } else {
                s += 'k';
            }
        }else {
            s += kata[i];
        }
    }
    return s;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        string kata= ubah_kata(s);
        cout << kata << endl;
    }

    return 0;
}
