#include "Sort.h"
Sort::Sort(int nr, int mini, int maxi) {
    cnt = nr;
    while (nr > 0)
    {
        v[nr - 1] = rand()%mini+(maxi+1);
        nr--;
    }
}
Sort::Sort(std::initializer_list<int> x) {
    cnt = 0;
    v[1000] = {0};
    for(int num:x)
        this->v[cnt++] = num;
}
Sort::Sort(int nr, ...) {
    cnt = nr;
    va_list args;
    va_start(args, nr);
    for (int i = 0; i < cnt; i++)
        v[i] = va_arg(args, int);
    va_end(args);
}
Sort::Sort(int x[], int nr) {
    for (int i = 0; i < nr; i++)
        v[i] = x[i];
    cnt = nr;
}
Sort::Sort(char s[]) {
    cnt = 0;
    char* p = strtok(s, ",");
    while (p)
    {
        int pt = 1;
        int nr = strlen(p);
        while (nr >= 0)
        {
            v[cnt] +=((int)p[nr]-(int)('0')) * pt;
            pt *= 10;
            nr--;
        }
        cnt++;
        p = strtok(NULL, ",");
    }

}
void Sort::InsertSort(bool ascendent)
{
    if (ascendent == false)
    {
        for (int i = 1; i < cnt; i++)
        {
            int p = i;
            while (p > 0 && v[p] < v[p - 1])
            {
                int aux = v[p];
                v[p] = v[p - 1];
                v[p - 1] = aux;
                p--;
            }
        }
    }
}
int partitioneaza(int x[], int a,int q) {
    int p = x[a];
    int i = a + 1;
    int j = q;
    while (i <= j)
    {
        if (x[i] <=p) i++;
        if (x[j] >= p) j--;
        if (x[i] > p && x[j] < p) {
            int aux = x[i];
            x[i] = x[j];
            x[j] =aux;
        }
    }
    int k = i - 1;
    x[a] = x[k];
    x[k] = p;
    return k;
}
void qs(int x[], int i, int j)
{
    int k = partitioneaza(x, i, j);
    while (i < j)

    {
        partitioneaza(x, k + 1, j);
        partitioneaza(x, i, k - 1);
    }
}
void Sort::QuickSort(bool ascendent)
{
    qs(v, 1, cnt);
}
void Sort::BubbleSort(bool ascendent)
{
    bool s = false;
    do
    {
       for(int i=0;i<cnt;i++)
           if (v[i] > v[i + 1] && ascendent)
           {
               s = false;
               int aux = v[i];
               v[i] = v[i + 1];
               v[i + 1] = aux;
           }
           else if (!ascendent && v[i] < v[i + 1])
           {
               s = false;
               int aux = v[i];
               v[i] = v[i + 1];
               v[i + 1] = aux;
           }
    }while (!s);
}
void Sort::Print()
{
    for (int i = 0; i < cnt; i++)
        std::cout << v[i] << " ";
}
int Sort::GetElementsCount()
{
    return cnt;
}
int Sort::GetElementFromIndex(int index)
{
    return v[index];
}
