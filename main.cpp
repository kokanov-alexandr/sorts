#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

void insertion_sort(vector<int> &a) {
    for (int i = 1; i < a.size(); ++i) {
        int t = a[i];
        int j = 0;
        for (; j < i && a[j] < t; ++j) {}
        for (int k = i; k > j; --k)
            a[k] = a[k - 1];
        a[j] = t;
    }
}

void bubble_sort(vector<int> &a) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size() - 1; ++j) {
            if (a[j + 1] < a[j])
                swap(a[j], a[j + 1]);
        }
    }
}

int partition(vector <int> &a, int i, int j) {
    int pivot = a[i];
    while(true) {
        while (a[i] < pivot) ++i;
        while (j > i && a[j] >= pivot) --j;
        if (i >= j)
            return j;
        swap(a[i], a[j]);
        cout << i << ' ' << j <<  ' ' << pivot << endl;
    }
}

void quick_sort(vector <int> &a, int i, int j) {
    if (i < j) {
        int m = partition(a, i, j);
        quick_sort(a, i, m - 1);
        quick_sort(a, m + (i == m), j);
    }
}

void Shuttle_Sort(vector<int>& arr) {
    int tmp = arr.size() - 1;
    int L  = 0;
    int R = arr.size() - 1;
    while (L < R) {
        for (int i = L; i < R; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                tmp = i;
            }
        }
        R = tmp;
        for (int i = R; i > L; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                tmp = i;
            }
        }
        L = tmp;
    }
}


void CenterInsert(vector<int> &a) {
    auto tmp = vector<int>(a.size());
    int middle = a.size() / 2;
    int L = middle - 1;
    int R = middle + 1;
    tmp[middle] = a[0];

    for (int i = 1; i < a.size(); i++) {
        bool flag = true;
        int x = a[i];
        if (x > tmp[middle]) {
            if (R == tmp.size()) {
                for (int j = L + 1; j < R - 1; j++)
                    tmp[j - 1] = tmp[j];
                L = L - 1;
                R = R - 1;
                tmp[tmp.size() - 1] = 0;
            }

            for (int j = R - 1; j > middle - 1 && flag; j--) {
                if (x > tmp[j]) {
                    tmp[j + 1] = x;
                    flag = false;
                }
                else tmp[j + 1] = tmp[j];
            }
            R++;
        } else {
            if (L == -1) {
                for (int j = R - 1; j > L + 1; j--)
                    tmp[j + 1] = tmp[j];
                L += 1;
                R += 1;
                tmp[0] = 0;
            }
            for (int j = L + 1; j < middle + 1 && flag; j++)
                if (tmp[j] < x) tmp[j - 1] = tmp[j];
                else {
                    tmp[j - 1] = x;
                    flag = false;
                }
            L--;
        }
    }
    for (int i = 0; i < tmp.size(); i++) {
        a[i] = tmp[i];
    }
}

void Shell(vector<int> &arr) {
    int d = arr.size() / 2;
    while (d > 0) {
        int i = 0;
        while (i < arr.size() - d) {
            int j = i;
            while (j >= 0) {
                if (arr[j] > arr[j + d])
                    swap(arr[j], arr[j + d]);
                j--;
            }
            i++;
        }
        d /= 2;
    }
}

void merge( const vector<int> &a, const vector<int> &b, vector<int> &c) {
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j])  { c[i + j] = a[i]; ++i; }
        else { c[i + j] = b[j]; ++j; }
    }
    for (; i < a.size(); ++i) c[i + j] = a[i];
    for (; j < b.size(); ++j) c[i + j] = b[j];
}

void merge_sort(vector<int> &a) {
    if (a.size() <= 1) return;
    vector<int> b(a.size() / 2);
    vector<int> c(a.size()- a.size() / 2);
    int i = 0;
    for (; i < b.size(); ++i)  b[i] = a[i];
    for (; i < a.size(); ++i)  c[i - b.size()] = a[i];
    merge_sort(b);
    merge_sort(c);
    merge(c, b, a);
}

void count_sort(vector<int> &a) {
    int m = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > m) m = a[i];
    }

    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < a.size(); ++i) {
        cnt[a[i]]++;
    }

    int k = 0;
    for (int i = 0; i < cnt.size(); ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            a[k++] = i;
        }
    }
}


void bucket_sort(vector<int> &a) {

    int maxValue = a[0];
    int minValue = a[0];

    for (int i = 1; i < a.size(); i++) {
        if (a[i] > maxValue)
            maxValue = a[i];

        if (a[i] < minValue)
            minValue = a[i];
    }

    int n = 5;
    int k = (maxValue - minValue) / (n - 1);
    vector<vector<int>> b(n);
    for (int i = 0; i < a.size(); ++i) {
        b[((a[i] - minValue) / k)].push_back(a[i]);
    }

    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            a[index++] = b[i][j];
        }
    }
}

int main() 