#include <iostream>
#include <vector>

using namespace std;

void findCoinsRecursive(const vector<int>& v, const vector<int>& m, int N, vector<int>& current, int index) {
    if (N == 0) {
        bool isFirst = true;
        cout << "Nepieciešamās monētas:" << endl;
        for (int i = 0; i < current.size(); ++i) {
            if (current[i] > 0) {
                if (!isFirst) {
                    cout << " + ";
                }
                cout << current[i] << " x " << v[i];
                isFirst = false;
            }
        }
        cout << endl;
        return;
    }

    if (N < 0 || index < 0) {
        return;
    }

    for (int i = m[index]; i >= 0; --i) {
        current[index] = i;
        findCoinsRecursive(v, m, N - i * v[index], current, index - 1);
    }
}

int main() {
    int k = 3;
    vector<int> v = { 1, 45, 50 };
    vector<int> m = { 5, 10, 12 };
    int N = 543;
    cout << "Piemērs 1:" << endl;
    vector<int> current(k, 0);
    findCoinsRecursive(v, m, N, current, k - 1);

    k = 5;
    vector v1 = { 1, 5, 50, 75, 125 };
    vector m1 = { 5, 10, 1, 5, 1 };
    N = 543;

    cout << "Piemērs 2:" << endl;
    vector current1(k, 0);
    findCoinsRecursive(v1, m1, N, current1, k - 1);



    return 0;
}
