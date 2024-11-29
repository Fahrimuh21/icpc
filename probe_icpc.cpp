#include<bits/stdc++.h>
using namespace std;

bool is_divisible_by_3(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum % 3 == 0;
}

string remove_digit(string N, int index) {
    return N.substr(0, index) + N.substr(index + 1);
}

string play_game(string N) {
    bool anda_turn = true;

    while (N.length() >= 3) {
        bool found_move = false;
        for (int i = 0; i < N.length() - 2; i++) {
            int num = stoi(N.substr(i, 3));
            if (is_divisible_by_3(num)) {
                N = remove_digit(N, i + 1);
                found_move = true;
                anda_turn = !anda_turn;
                break;
            }
        }

        if (!found_move) {
            break;
        }
    }

    return anda_turn ? "Kamu" : "Anda";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string N;
        cin >> N;
        string winner = play_game(N);
        cout << winner << endl;
    }

    return 0;
}
