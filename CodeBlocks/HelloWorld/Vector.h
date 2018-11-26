#include <iostream>

class Vector
{
private:
    int* m_arr;
    int m_size;
    int m_capacity;
public:
    Vector()
        : m_size(0), m_capacity(4) 
    {
        m_arr = new int[m_capacity];
    }
    
    ~Vector()
    {
        delete[] m_arr;
    }
    void append(int data)
    {
        m_size++;
        if(m_size == m_capacity)
        {
            m_capacity *= 2;
            int *b = new int[m_capacity];
            for(int i=0; i < m_size-1; i++)
                b[i] = m_arr[i];
            delete[] m_arr;
            m_arr = b;
        }
        m_arr[m_size-1] = data;
    }
    
    void insert(int index, int data)
    {
        m_size++;
        if(m_size == m_capacity)
            m_capacity *= 2;
            
        int *b = new int[m_capacity];
        for(int i=0; i < index; i++)
            b[i] = m_arr[i];
        b[index] = data;
        for(int i=index+1; i<m_size; i++)
            b[i] = m_arr[i-1];
        delete[] m_arr;
        m_arr = b;    
    }
    
    int& operator[](int index) const
    {
        return m_arr[index];
    }

    int capacity() const
    {
        return m_capacity;
    }
    
    int size() const
    {
        return m_size;
    }
};

std::ostream& operator<<(std::ostream& stream, const Vector& v)
{
    for(int i=0; i<v.size(); i++)
        stream << v[i] << " ";
    return stream;
}

