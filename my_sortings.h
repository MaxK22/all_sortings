//
// Created by Maxim on 03.12.2021.
//
#include <iostream>
#include <vector>
#include "time.h"
#include "kucha.h"
#include <algorithm>

using namespace std;

#ifndef ALL_SORTINGS_MY_SORTINGS_H
#define ALL_SORTINGS_MY_SORTINGS_H

void bubble_sort_exit(vector<int> m)
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

void bubble_sort(vector<int> m)
{
    for(int i = 1; i < m.size(); i++)
    {
        for(int g = 0; g < m.size() - i; g++)
        {
            if(m[g] > m[g+1])
            {
                swap(m[g], m[g+1]);
            }
        }
    }
}

void selection_sort(vector<int> m)
{
    for (int idx_i = 0; idx_i < m.size() - 1; idx_i++)
    {
        int min = idx_i;

        for (int idx_j = idx_i + 1; idx_j < m.size(); idx_j++)
        {
            if (m[idx_j] < m[min])
            {
                min = idx_j;
            }
        }

        if (min != idx_i)
        {
            swap(m[idx_i], m[min]);
        }
    }
}

void insertion_sort(vector<int> m)
{
    for(int i = 1; i < m.size(); ++i)
    {
        int j = i;
        while(j > 0 && m[j] < m[j-1])
        {
            swap(m[j], m[--j]);
        }
    }
}

void kucha_sort(vector<int> m)
{
    Kucha<int> kucha(m);
    for(int j = 0; j < m.size(); ++j)
    {
        kucha.extract_max();
    }
}

void my_sort(vector<int> m)
{
    sort(m.begin(), m.end());
}

void my_stable_sort(vector<int> m)
{
    stable_sort(m.begin(), m.end());
}

///////merge

vector<int> merge_massive(vector<int> a, vector<int> b)
{
    int n1 = a.size(), n2 = b.size();
    vector<int>c(n1+n2);
    int a_now = 0, b_now = 0;
    for(int i = 0; i < n1+n2; i++)
    {
        if(a[a_now] <= a[n1-1] && (b[b_now] > b[n2-1] || a[a_now] < b[b_now]))
        {
            c[i] = a[a_now];
            a_now++;
        }
        else
        {
            c[i] = b[b_now];
            b_now++;
        }
    }
    return c;
}

void merge_sort(vector<int> &m, int x,  int n)
{
    if(n == 1)
        return;
    merge_sort(m, x, n/2);
    merge_sort(m, x + n/2, (n+1)/2);
    vector<int> b;

    b.insert(b.begin(), m.begin() + x, m.begin() + x + n);
    for(int i = 0, j = n/2; i < n/2 || j < n;)
    {
        if(i < n/2 && j < n)
        {
            if(b[i] <= b[j])
            {
                m[x+i+j-n/2] = b[i];
                i++;
            }
            else
            {
                m[x+i+j-n/2] = b[j];
                j++;
            }
        }
        else if(i < n/2)
        {
            m[x+i+j-n/2] = b[i];
            i++;
        }
        else
        {
            m[x+i+j-n/2] = b[j];
            j++;
        }
    }
}

void final_merge_sort(vector<int> m)
{
    merge_sort(m, 0, m.size());
}
#endif //ALL_SORTINGS_MY_SORTINGS_H
