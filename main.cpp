#include <iostream>
#include <vector>
#include "time.h"

using namespace std;

vector<int> sort_massive_size_3;
vector<int> sort_massive_size_5;
vector<int> sort_massive_size_7;
vector<int> rand_massive_size_3;
vector<int> rand_massive_size_5;
vector<int> rand_massive_size_7;
vector<int> resort_massive_size_3;
vector<int> resort_massive_size_5;
vector<int> resort_massive_size_7;
vector<int> sort90_massive_size_3;
vector<int> sort90_massive_size_5;
vector<int> sort90_massive_size_7;


void bubble_sort(vector<int> m)
{
    bool f = true;
    for(int i = 1; i < m.size() && f; i++)
    {
        f = false;
        for(int g = 0; g < m.size() - i; g++)
        {
            if(m[g] > m[g+1])
            {
                swap(m[g], m[g+1]);
                f = true;
            }
        }
    }
}


//

int main() {
    for(int i = 1; i <= 10000000; ++i)
    {
        int x = rand()*rand();
        if(i <= 100000)
        {
            sort_massive_size_5.push_back(i);
            rand_massive_size_5.push_back(x);
            resort_massive_size_5.push_back(100001 - i);
        }
        if(i <= 1000)
        {
            sort_massive_size_3.push_back(i);
            rand_massive_size_3.push_back(x);
            resort_massive_size_3.push_back(1001 - i);
        }
        sort_massive_size_7.push_back(i);
        rand_massive_size_7.push_back(x);
        resort_massive_size_7.push_back(10000001 - i);
        //cout << x << " ";//???
    }
    sort90_massive_size_3 = sort_massive_size_3;
    sort90_massive_size_5 = sort_massive_size_5;
    sort90_massive_size_7 = sort_massive_size_7;
    //generate sort90




    //
    cout << endl << endl;
    cout << "   Bubble sort: " << endl;
    double ticksStart = clock();
    bubble_sort(sort_massive_size_3);
    double timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sort sorting mass with size 10^3: " << timeUsed << endl;
    ticksStart = clock();
    bubble_sort(sort_massive_size_5);
    timeUsed = (clock() - ticksStart) / (double)CLOCKS_PER_SEC;
    cout << "sort sorting mass with size 10^5: " << timeUsed << endl;



    return 0;
}
