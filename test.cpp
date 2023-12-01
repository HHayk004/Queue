#include "queue.h"

int main()
{
    Hayk::Queue<int> obj;
    
    for (int i = 0; i < 100; ++i)
    {
        obj.push(i);
    }
 
    std::cout << obj.size() << ' ' << obj.front() << ' ' << obj.rear() << std::endl;
    std::cout << obj << std::endl;
    return 0;
}
