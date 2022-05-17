#include <iostream>

class Creaker
{
private:
    int flour;
    int salt;
    int sugar;
    int water;
    int rainbowFlour;
    int total_weight;
    const char* creaker_name;

public:
    Creaker(int flour, int salt, int sugar, int water,
        int rainbowFlour, const char * creaker_name)
    {
        this->flour = flour;
        this->salt = salt;
        this->water = water;
        this->rainbowFlour = rainbowFlour;
        this->creaker_name = creaker_name;
    }

    void mixer(void)
    {
        total_weight = flour + salt + sugar + water + rainbowFlour;
    }

    void print_Creaker(void)
    {
        printf("완성 ! 총 용량 = %d\n", total_weight);
        printf("과자 이름 : %c\n", creaker_name);
    }
};

int main(void)
{                   // 객체 부분( 인스턴스 부분 )
    Creaker* Dieje = new Creaker(100, 20, 10, 100, 10, "Dideje");
    Creaker* pokacip = new Creaker(100, 20, 10, 100, 10, "pokacip");
    Creaker* Homenumboll = new Creaker(100, 20, 10, 100, 10, "Homenumboll");

    return 0;
}