//
// Created by Maxim on 03.12.2021.
//

#ifndef ALL_SORTINGS_KUCHA_H
#define ALL_SORTINGS_KUCHA_H
template<typename T>
class Kucha
{
public:
    std::vector <T> src;
    int size;
    Kucha(std::vector<T> a;
    int sift_down(int i);
    void extract_max();
};

template<typename T>
Kucha<T>::Kucha(std::vector<T> a) {
    src = a;
    size = a.size();
    for(int i = size-1; i >= 0; i--)
        sift_down(i);
}

template<typename T>
int Kucha<T>::sift_down(int i) {
    int next1 = i*2 +1, next2 = i*2 +2, now = i;
    while(next1 < size)
    {
        //std::cout << "ok";//infinitive problem!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        if(next2 < size)
        {
            if(src[next1] >= src[next2] && src[next1] > src[now])
            {
                std::swap(src[next1] , src[now]);
                now = next1;
            }
            else if(src[next2] > src[next1] && src[next2] > src[now])
            {
                std::swap(src[next2] , src[now]);
                now = next2;
            }
            else
                return now;
        }
        else
        {
            if(src[next1] > src[now])
            {
                std::swap(src[next1] , src[now]);
                now = next1;
            }
            else
                return now;
        }
        next1 = 2*now+1;
        next2 = 2*now+2;
    }
    return now;
}

template<typename T>
void Kucha<T>::extract_max() {
    std::swap(src[0], src[size-1]);
    size--;
    if(size > 1) sift_down(0);
}
#endif //ALL_SORTINGS_KUCHA_H
