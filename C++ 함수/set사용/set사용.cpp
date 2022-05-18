#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(200);
    s.insert(-1);
    s.insert(3);

    int arr[] = { 1,2,3,4,5,6 };
    set<int> s1(s.begin(), s.end());
    // s1 = -1, 1, 3, 200
    set<int> s2(arr, arr + 6);
    // s2 = 1, 2, 3, 4, 5, 6
    set<int> s3(s1);
    // s3 = -1, 1, 3, 200
    set<int> s4 = s2;
    // s4 = 1, 2, 3, 4, 5, 6

    
    for_each(s.begin(), s.end(), [](int n)
        {
            printf("%d ", n);
        });
    printf("\n");
    for_each(s.rbegin(), s.rend(), [](int n) 
        {
            printf("%d ", n);
        });
    printf("\n");

    //////////////////////////////////////////////////
    //////////////////////////////////////////////////
    //////////////////////////////////////////////////
    //////////////////////////////////////////////////

    set<int> a = { 1,2,3,4,5,6,7,8,9,10 };
    pair<set<int>::iterator, set<int>::iterator> itr = s.equal_range(4);
    printf("%d %d", itr.first, itr.second);

    set<int>::iterator low_itr, up_itr;
    low_itr = s.lower_bound(3);
    up_itr = s.upper_bound(7);

    s.erase(low_itr, up_itr);

    for_each(s.begin(), s.end(), [](int n)
        {
            printf("%d ", n);
        });
    printf("\n");
    return 0;
}
