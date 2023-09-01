#include <iostream>
using namespace std;
#include <vector>


int findOdd(const std::vector<int>& numbers) {
    int s = numbers.size();
    bool hasbeen = 0;
    int s2=1;
    int* a = new int[s2];
    a[0] = numbers[0];
    for (int i = 0; i < s; i++)
    {
        hasbeen = 0;
        for (int j = 0; j < s2; j++)
        {
            if (numbers[i]==a[j])
            {
                hasbeen = 1;
            }
        }
        if (!hasbeen)
        {
            int* c = new int[s2];

            for (int i = 0; i < s2; i++) {
                c[i] = a[i];
            }

            delete[] a;
            s2++;
            a = new int[s2];
            for (int i = 0; i < s2-1; i++) {
                a[i] = c[i];
            }
            delete[] c;
            
            a[s2 - 1] = numbers[i];
        }
    }
    int* b = new int[s2];
    for (int i = 0; i < s2; i++)
    {
        int countcurrent = 0;
        for (int j = 0; j < s; j++)
        {
            if (a[i]==numbers[j])
            {
                countcurrent++;
            }
        }
        b[i] = countcurrent;
    }
    for (int i = 0; i < s2; i++)
    {
        if (b[i] % 2 != 0)
        {
            return a[i];
        }
    }
}

int main()
{
    cout << findOdd({ 1,1,1,1,1,1,10,1,1,1,1 });
}
