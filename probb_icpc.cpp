#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Fungsi untuk memeriksa apakah kata ada dalam vector
bool existsInDictionary(const string& word, const vector<string>& dictionary) {
    for (size_t i = 0; i < dictionary.size(); ++i) {
        if (dictionary[i] == word) {
            return true;
        }
    }
    return false;
}

int card_game(int D, const vector<string>& dictionary_words, int N, const vector<string>& anda_cards, int M, vector<string>& my_cards) {
    int successful_matches = 0;

    for (size_t i = 0; i < anda_cards.size(); ++i) {
        const string& ai = anda_cards[i];
        for (size_t j = 0; j < my_cards.size(); ++j) {
            const string& bj = my_cards[j];
            // Periksa apakah kartu ini sudah digunakan
            if (bj.empty()) continue; // Kartu yang sudah digunakan akan menjadi empty string

            // Periksa kedua concatenation
            if (existsInDictionary(ai + bj, dictionary_words) || existsInDictionary(bj + ai, dictionary_words)) {
                successful_matches++;
                my_cards[j].clear(); // Tandai kartu ini sebagai digunakan
                break; // Tidak perlu memeriksa lebih lanjut jika sudah cocok
            }
        }
    }

    return successful_matches;
}

int main() {
    int D;
    cin >> D;
    vector<string> dictionary_words(D);
    for (int i = 0; i < D; ++i) {
        cin >> dictionary_words[i];
    }

    int N;
    cin >> N;
    vector<string> anda_cards(N);
    for (int i = 0; i < N; ++i) {
        cin >> anda_cards[i];
    }

    int M;
    cin >> M;
    vector<string> my_cards(M);
    for (int i = 0; i < M; ++i) {
        cin >> my_cards[i];
    }

    int result = card_game(D, dictionary_words, N, anda_cards, M, my_cards);
    cout << result << endl;

    return 0;
}

