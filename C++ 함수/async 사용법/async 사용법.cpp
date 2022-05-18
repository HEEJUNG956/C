#include <iostream>
#include <future>
using namespace std;
void for_print(char c)
{
    for (int i = 0; i < 10; i++)
        printf("%c번 Thread : %d\n", c, i);
}
int main()
{
    auto c = async(for_print, 'c');
    future<int> d;

    try
    {
        c.get();
        d.get();
    }
    catch (const future_error& e)
    {
        printf("\nCaught a future_error with code %d\n", e.code());
        printf("Message : %s\n", e.what());
    }

    return 0;
}
