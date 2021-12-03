#include "my_sortings.h"

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

void test(void (*sort_function)(vector<int>), int dif, string name)
{
    cout << endl << endl;
    cout << "   " + name + ": " << endl;
    double ticksStart, timeUsed;
    if(dif == 1) {
        ticksStart = clock();
        sort_function(sort_massive_size_3);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort sort mass with size 10^3: " << timeUsed << endl;
        ticksStart = clock();
        sort_function(sort_massive_size_5);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort sort mass with size 10^5: " << timeUsed << endl;

        ticksStart = clock();
        sort_function(rand_massive_size_3);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort rand mass with size 10^3: " << timeUsed << endl;
        ticksStart = clock();
        sort_function(rand_massive_size_5);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort rand mass with size 10^5: " << timeUsed << endl;

        ticksStart = clock();
        sort_function(resort_massive_size_3);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort reverse mass with size 10^3: " << timeUsed << endl;
        ticksStart = clock();
        sort_function(resort_massive_size_5);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort reverse mass with size 10^5: " << timeUsed << endl;

        ticksStart = clock();
        sort_function(sort90_massive_size_3);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort 90 percent sort mass with size 10^3: " << timeUsed << endl;
        ticksStart = clock();
        sort_function(sort90_massive_size_5);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort 90 percent sort mass with size 10^5: " << timeUsed << endl;
    }
    else
    {
        ticksStart = clock();
        sort_function(sort_massive_size_5);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort sort mass with size 10^5: " << timeUsed << endl;
        ticksStart = clock();
        sort_function(sort_massive_size_7);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort sort mass with size 10^7: " << timeUsed << endl;

        ticksStart = clock();
        sort_function(rand_massive_size_5);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort rand mass with size 10^5: " << timeUsed << endl;
        ticksStart = clock();
        sort_function(rand_massive_size_7);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort rand mass with size 10^7: " << timeUsed << endl;

        ticksStart = clock();
        sort_function(resort_massive_size_5);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort reverse mass with size 10^5: " << timeUsed << endl;
        ticksStart = clock();
        sort_function(resort_massive_size_7);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort reverse mass with size 10^7: " << timeUsed << endl;

        ticksStart = clock();
        sort_function(sort90_massive_size_5);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort 90 percent sort mass with size 10^5: " << timeUsed << endl;
        ticksStart = clock();
        sort_function(sort90_massive_size_7);
        timeUsed = (clock() - ticksStart) / (double) CLOCKS_PER_SEC;
        cout << "sort 90 percent sort mass with size 10^7: " << timeUsed << endl;
    }
}
//sort90
void generate_sort90(vector<int> &m)
{
    for(int i = 0; i < m.size()/10; ++i)
    {
        swap(m[(rand()*rand())%m.size()], m[(rand()*rand())%m.size()]);
    }
}

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




    //tests:
    test(bubble_sort, 1, "Bubble sort");
    test(bubble_sort_exit, 1, "Bubble sort with exit");
    test(selection_sort, 1, "Selection sort");
    test(insertion_sort, 1, "Insertion sort");
    test(kucha_sort, 2, "Kucha sort");
    test(my_sort, 2, "'std::sort()' from c++");
    test(my_stable_sort, 2, "'std::stable_sort()' from c++");
    test(final_merge_sort, 2, "Merge sort");


    return 0;
}
