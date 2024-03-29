﻿#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ////////////////////////////////////////////////
    //int형 벡터생성
    vector<int> v1;   
    ////////////////////////////////////////////////
    //int형 벡터생성 후 크기 4
    vector<int>v2(4);    
    ////////////////////////////////////////////////
    //int형 벡터 생성 후 1,2,3,으로 초기화    
    vector<int>v3 = { 1,2,3 };    
    ////////////////////////////////////////////////
    //int형 벡터 배열 생성(행은 가변이지만 열은 고정)
    vector<int>v4[] = { {1,2},{3,4} }; 
    ////////////////////////////////////////////////
    // 2차원 벡터 생성(행과 열 모두 가변)
    vector<vector<int>> v5;        
    ////////////////////////////////////////////////
    //벡터 범위를 5로 지정하고 정수 10으로 초기화
    vector<int> v6 = { 1,2,3,4,5 };         
    v6.assign(5, 10);  

    ////////////////////////////////////////////////
    vector<int> v = { 1,2,3,4 };
    for_each(v.begin(), v.end(), [&](int& n)
        {
            printf("%d ", n);
        });
    printf("\n");
    for_each(v.rbegin(), v.rend(), [&](int& n)
        {
            printf("%d ", n);
        });
    printf("\n");
    ////////////////////////////////////////////////
    ////////////////////////////////////////////////
    ////////////////////////////////////////////////
    ////////////////////////////////////////////////
    vector<int>::iterator itor = v.begin();
    for (; itor != v.end(); itor++)
        printf("%d ", *itor);
    printf("\n");
    vector<int>::reverse_iterator itor2 = v.rbegin();
    for (; itor2 != v.rend(); itor2++)
        printf("%d ", *itor2);
    printf("\n");

    ////////////////////////////////////////////////
    ////////////////////////////////////////////////
    ////////////////////////////////////////////////
    ////////////////////////////////////////////////
    printf("%d\n", v.front());
    printf("%d\n", v.back());
    printf("%d\n", v.at(1));
    printf("%d\n", v[2]);

    ////////////////////////////////////////////////
    ////////////////////////////////////////////////
    ////////////////////////////////////////////////
    ////////////////////////////////////////////////

    vector<int> temp;
    temp.push_back(10);
    temp.push_back(20);
    // temp = {10 ,20}
    temp.insert(temp.begin() + 1, 100);
    // temp = {10 ,100 ,20}
    temp.pop_back();
    // temp = {10, 100}
    temp.emplace_back(1); // temp = {10, 100, 1}
    temp.emplace_back(2); // temp = {10, 100, 1, 2}
    // temp = {1, 100, -50, 1 ,2}
    temp.emplace(temp.begin() + 2, -50); 

    temp.erase(temp.begin() + 1); // temp = {1, -50, 1, 2}
    temp.resize(6); // v = {1, - 50, 1, 2, 0, 0}
    temp.clear();   // v = empty()
}
