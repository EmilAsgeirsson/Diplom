#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>


int main()
{
    // Place ball randomly in bins.
    std::vector<std::vector<int>> bins(32749);
    srand(time(NULL));
    int ball = 3;
    for (int i = 0; i < bins.size();i++) {
        int randIndex = rand() % bins.size();
        bins[randIndex].push_back(ball);
    }

    // Search the bins
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

    // With 10007 balls. The maximum bin size is usually seven. I've seen 8 once.
    // With 32749 balls. The maximum bin size is usually seven. I've seen 8 once.


    std::cout << "max = " << max << " and bin number = " << count << " and the number of big bins is " << numberOfBigBins << std::endl;
    
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