#include <iostream>
#include "BinaryHeap.h"

void line() {
    for (int i = 0; i < 144; ++i) {
        cout << "-";
    } cout << endl;
}

int main() {

    vector<int> keys = { 17,21,23,44,32,65,38,56,46,69,33,77,67,56,39,61,60,62,50,71 };

    // Build Heap
    cout << "Build Heap" << endl;
    line();
    BinaryHeap<int> heap(7);
    for (auto key : keys) {
        heap.insert(key);
    }

    heap.print(true, true);
    line();

    // IncreaseKey
    //cout << "IncreaseKey" << endl;
    //heap.increaseKey(3, 8);

    //heap.print(true, true);
    //line();

    // DecreaseKey
    //cout << "DecreaseKey" << endl;
    //heap.decreaseKey(3, 12);

    //heap.print(true, true);
    //line();


    /*while (true) {
        int p;
        int delta;
        cout << "p = ";
        cin >> p;
        cout << "∆ = ";
        cin >> delta;
        heap.changeKey(p, delta);
        heap.print(true, true);
        line();
    }*/
    return 0;
}
