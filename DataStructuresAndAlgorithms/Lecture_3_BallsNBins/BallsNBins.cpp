#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>


std::vector<std::vector<int>> fillRandomly(std::vector<std::vector<int>> bins)
{
    // Place ball randomly in bins.
    int ball = 3;
    for (int i = 0; i < bins.size();i++) {
        int randIndex = rand() % bins.size();
        bins[randIndex].push_back(ball);
    }
    return bins;
}


std::vector<std::vector<int>> twoChoices(std::vector<std::vector<int>> bins)
{
    // Pick two bins randomly and fill up the lowest of the two.
    int ball = 3;
    for (int i = 0; i < bins.size();i++) {
        int randIndex1 = rand() % bins.size();
        int randIndex2 = rand() % bins.size();
        if (bins[randIndex1].size() > bins[randIndex2].size())
        {
            bins[randIndex2].push_back(ball);
        }
        else
        {
            bins[randIndex1].push_back(ball);
        }
        
    }
    return bins;
}


void print(std::string title, std::vector<std::vector<int>> bins)
{
    std::cout << title << std::endl;

    int count = 0;
    int max = 0;

    for (int i = 0; i < bins.size(); i++)
    {
        if (bins[i].size() > max)
        {
            max = bins[i].size();
            count = i;
        }
    }

    int numberOfBigBins = 0;
    for (size_t i = 0; i < bins.size(); i++)
    {
        if (bins[i].size() == max)
            numberOfBigBins++;
    }

    std::cout << "max = " << max << " and bin number = " << count << " and the number of big bins is " << numberOfBigBins << std::endl;
}

int main()
{
    srand(time(NULL));

    std::vector<std::vector<int>> bins(32749);    

    std::vector<std::vector<int>> binsRandom = fillRandomly(bins);
    std::vector<std::vector<int>> binsTwoChoices = twoChoices(bins);
    
    print("Randomly filled", binsRandom);
    //print("Two Choices", binsTwoChoices);

    // With 10007 balls. The maximum bin size is usually seven. I've seen 8 once.
    // With 32749 balls. The maximum bin size is usually seven. I've seen 8 once.

    // We must use log2 in computer science and not log10.
    std::cout << "Ordinay:\t\t" << log2(32749 / log2(log2(32749)))  << std::endl;
    std::cout << "Two Choices:\t" << log2(log2(32749)) << std::endl;
    // No this is wrong.
    std::cout << "Ordinay:\t\t" << log2(10007) / log2(log2(10007)) << std::endl;
    std::cout << "Two Choices:\t" << log2(log2(10007)) << std::endl;

}