#include <iostream>
#include <vector>
/*
    2022 - 05 - 16
    정희석
*/

using namespace std;
int main()
{
    int c, n, score; // 테스트케이스, 학생 수, 점수
    scanf("%d", &c);
    vector<int> answer; // 점수 배열
    for (int i = 0; i < c; i++)
    {
        int total = 0; // 전체 점수
        double avg; // 평균
        int count = 0; // 평균을 넘은 학생 수
        double student = 0; // 평균을 넘는 학생의 비율
        // 테스트 케이스 입력
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            // 점수 vector에 저장
            scanf("%d", &score);
            answer.push_back(score);
        }

        // 전체 점수 계산
        for (int j = 0; j < n; j++)
        {
            total += answer[j];
        }
        // 평균 점수 계산
        avg = total / n;

        // 평균을 넘는 학생 수 세기
        for (int j = 0; j < n; j++)
        {
            if (answer[j] > avg)
                count++;
        }
        // 비율 계산
        student = count / (double)n * 100;
        // 출력
        printf("%.3f%%\n", student);
        // 다시 초기화
        answer.clear();
    }




}

