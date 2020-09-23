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
    print("Two Choices", binsTwoChoices);

    // With 10007 balls. The maximum bin size is usually seven. I've seen 8 once.
    // With 32749 balls. The maximum bin size is usually seven. I've seen 8 once.

    std::cout << "Ordinay:\t\t" << log(32749) / log(log(32749)) << std::endl;
    std::cout << "Two Choices:\t" << log(log(32749)) << std::endl;
    // No this is wrong.
    

    
    
    /*int yada = 0;
    std::cout << bins[count].size() << std::endl;
    for (int i = 0; i < bins[count].size();i++) 
    {
        std::cout << bins[count][i] << std::endl;
    }*/

    

   /* for (std::vector<int> &bin : bins)
    {
        if (bin.size() > max)
        {
            max = bin.;
        }
    }

    std::cout << bins[0].size() << std::endl;
    for (int i = 0; i < bins[0].size();i++) {
        std::cout << bins[0][i] << std::endl;
        count++;
    }*/
}