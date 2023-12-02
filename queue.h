#ifndef QUEUE_H
    #define QUEUE_H
    #include <iostream>
    #include <limits>
    #include <initializer_list>

    namespace Hayk
    {
        template <typename T>
        class Queue
        {
        private:
            T* m_ptr;
            size_t m_start;
            size_t m_end;
            const size_t m_max_size = std::numeric_limits<size_t>::max() / sizeof(T);
            size_t m_capacity;

            void realloc();
        public:
            Queue();
            Queue(std::initializer_list<T>);
            Queue(const Queue<T>&);
            Queue(Queue<T>&&);
            ~Queue();

            std::ostream& operator<<(std::ostream&) const;
            Queue& operator=(std::initializer_list<T>);
            Queue& operator=(const Queue&);
            Queue& operator=(Queue&&);
            
            size_t size() const;
            size_t capacity() const;

            T front() const;
            T rear() const;

            void push(T);
            void pop();

            bool isEmpty() const;
        };
    }

    #include "queue.hpp"
#endif
