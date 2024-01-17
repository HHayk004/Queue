#include "queue.h"

int main()
{
    Queue<int> obj {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Queue<int> obj1 = obj;

    Queue<int> obj2 = std::move(obj);
  
    std::cout << obj << std::endl;

    obj1.push(11);

    std::cout << obj1 << std::endl;
    std::cout << obj2 << std::endl;

    return 0;
}
