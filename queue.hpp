#ifndef QUEUE_HPP
    #define QUEUE_HPP
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Hayk::Queue<T>& other)
    {
        return other.operator<<(os);
    }

    namespace Hayk
    {
        template <typename T>
        Queue<T>::Queue()
        {
            m_ptr = nullptr;
            m_start = 0;
            m_end = 0;
            m_capacity = 0;
        }

        template <typename T>
        Queue<T>::Queue(std::initializer_list<T> list)
        {
            m_start = 0;
            m_end = list.size();
            m_capacity = m_end + 10;
            m_ptr = new T [m_capacity]{0};
            int i = 0;
            for (auto& elem : list)
            {
                m_ptr[i] = elem;
                ++i;
            }
        }

        template <typename T>
        Queue<T>::Queue(const Queue<T>& other)
        {
            m_start = other.m_start;
            m_end = other.m_end;
            m_capacity = other.m_capacity;
            
            if (m_capacity == 0)
            {
                m_ptr = nullptr;
            }
            
            else
            {
                m_ptr = new T [m_capacity]{0};
                for (int i = m_start; i < m_end; ++i)
                {
                    m_ptr[i] = other.m_ptr[i];
                }
            }
        }

        template <typename T>
        Queue<T>::Queue(Queue<T>&& other)
        {
            m_start = other.m_start;
            m_end = other.m_end;
            m_capacity = other.m_capacity;
            m_ptr = other.m_ptr;

            other.m_start = 0;
            other.m_end = 0;
            other.m_capacity = 0;
            other.m_ptr = nullptr;
        }

        template <typename T>
        Queue<T>::~Queue()
        {
            delete[] m_ptr;
            m_ptr = nullptr;
            m_start = 0;
            m_end = 0;
            m_capacity = 0;
        }

        template <typename T>
        std::ostream& Queue<T>::operator<<(std::ostream& os) const
        {
            for (int i = m_start; i < m_end; ++i)
            {
                std::cout << m_ptr[i] << ' ';
            }
            return os;
        }

        template <typename T>
        void Queue<T>::realloc()
        {
            if (m_capacity / 2 > size() / 2)
            {
                for (int i = m_start, j = 0; i < m_end; ++i, ++j)
                {
                    m_ptr[j] = m_ptr[i];
                }

                m_end = size();
                m_start = 0;
            }

            else
            {
                m_capacity = size() + 10;
                T* new_ptr = new T [m_capacity];
                for (int i = m_start, j = 0; i < m_end; ++i, ++j)
                {
                    new_ptr[j] = m_ptr[i];
                }
                
                m_end = size();
                m_start = 0;

                delete[] m_ptr;
                m_ptr = new_ptr;
                new_ptr = nullptr;

            }
        }

        template <typename T>
        size_t Queue<T>::size() const
        {
            return m_end - m_start;
        }

        template <typename T>
        T Queue<T>::front() const
        {
            if (isEmpty())
            {
                std::cerr << "Empty for front:\n";
                exit(-1);
            }

            return m_ptr[m_start];
        }

        template <typename T>
        T Queue<T>::rear() const
        {
            if (isEmpty())
            {
                std::cerr << "Empty for rear:\n";
                exit(-1);
            }

            return m_ptr[m_end - 1];
        }

        template <typename T>
        void Queue<T>::push(T val)
        {
            if (m_end == m_capacity)
            {
                realloc();
            }

            m_ptr[m_end] = val;
            ++m_end;
        }

        template <typename T>
        void Queue<T>::pop()
        {
            if (isEmpty())
            {
                std::cerr << "Empty for pop:\n";
                exit(-1);
            }
 
            ++m_start;
        }

        template <typename T>
        bool Queue<T>::isEmpty() const
        {
            return m_start == m_end;
        }
    }   
#endif
