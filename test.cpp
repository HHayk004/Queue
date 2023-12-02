#include "queue.h"

int main()
{
    Hayk::Queue<int> obj {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << obj.capacity() << std::endl;

    for (int i = 0; i < 6; ++i)
    {
        obj.pop();
    }

    for (int i = 0; i < 2; ++i)
    {
        obj.push(i);
    }
 
    std::cout << obj.size() << ' ' << obj.capacity() << std::endl; 
    std::cout << obj << std::endl;
    return 0;
}
