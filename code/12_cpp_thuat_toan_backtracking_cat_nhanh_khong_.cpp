#include <iostream>
using namespace std;

int total_configurations = 0;
int limit; // Gioi han bitmask ung voi N cot

// Ham de quy cat nhanh khong gian tim kiem bang dai so boolean
void solve(int col, int diag1, int diag2) {
    if (col == limit) {
        total_configurations++; // Da xep du N quan hau
        return;
    }
    
    // Xac dinh tat ca cac vi tri hop le tren hang hien tai (bits == 1)
    int pos = limit & (~(col | diag1 | diag2));
    
    while (pos) {
        // Trich xuat bit hop le ngoai cung ben phai (2's complement)
        int p = pos & (-pos);
        pos -= p; // Xoa bit nay de tiep tuc duyet
        
        // De quy den hang tiep theo. Dich bit tuong duong voi invariant r+c va r-c
        solve(col | p, (diag1 | p) << 1, (diag2 | p) >> 1);
    }
}

int countNQueens(int n) {
    limit = (1 << n) - 1;
    total_configurations = 0;
    solve(0, 0, 0);
    return total_configurations;
}


int main() {
    for (int i = 4; i <= 8; i++) {
        cout << "N = " << i << ", Solutions: " << countNQueens(i) << endl;
    }
    return 0;
}
