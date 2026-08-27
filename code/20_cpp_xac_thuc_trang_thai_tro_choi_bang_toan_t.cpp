#include <iostream>
#include <vector>
using namespace std;

// Kiem chung trang thai tat thang cua he thong N tro choi doc lap
// Su dung Dang cau XOR cua Dinh ly Sprague-Grundy
bool isWinningState(const vector<int>& grundy_values) {
    int nim_sum = 0;
    
    // Khai thac toan tu thao tac bit XOR de mo phong Tich chap cua khong gian trang thai
    for (int g : grundy_values) {
        nim_sum ^= g; 
    }
    
    // Trang thai hien tai la Winning neu tong Nim khac 0
    return nim_sum != 0;
}


int main() {
    vector<int> game_states = {4, 5, 6};
    // Expected nim sum: 4^5^6 = 7 != 0 => Winning
    cout << "Is Winning State? " << (isWinningState(game_states) ? "Yes" : "No") << endl;
    return 0;
}
