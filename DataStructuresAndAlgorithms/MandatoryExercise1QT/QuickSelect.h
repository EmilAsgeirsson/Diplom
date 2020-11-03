#ifndef QUICKSELECT_H
#define QUICKSELECT_H
#include <vector>

class QuickSelect
{
public:
    QuickSelect(std::vector<int> & a);

    void quickselect(std::vector<int>& a, int left, int right, int k);
    unsigned median3(std::vector<int>& a, int left, int right);
    void insertionSort(std::vector<int>& a, int begin, int end);

private:
    int mComplexity;
    std::vector<int> mArray;
};

#endif // QUICKSELECT_H
