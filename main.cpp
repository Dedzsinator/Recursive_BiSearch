#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("in.in");
ofstream g("out.out");

int n, arr[100],r,res;

int biSearch(int arr[], int l, int y, int x) {
    if (y >= l) {
        int mid = l + (y - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return biSearch(arr, l, mid - 1, x);

        return biSearch(arr, mid + 1, y, x);
    }

    return -1;
}

int main() {
    f>>r;
    for(int i = 0; i < 20; i++) {
        f>>arr[i];
        n++;
    }
    sort(arr, arr+n);

    res = biSearch(arr, 0 , n-1,r);

    if (res == -1) {
        g<< "A szam nem letezik!";
    } else {
        g << res;
    }

    return 0;
}
