#include "queue.h"

int main()
{
    Hayk::Queue<int> obj;
    
    for (int i = 0; i < 100; ++i)
    {
        obj.push(i);
    }

    Hayk::Queue<int> obj1 = {1, 2, 3, 4};
    obj1 = obj;
 
    std::cout << obj1 << std::endl;
    return 0;
}
