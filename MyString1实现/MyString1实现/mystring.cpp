#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

class String

{

    friend ostream& operator<<(ostream& _cout, const String& s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            cout << s._str[i];
        }
        return _cout;
        
    }

    friend istream& operator>>(istream& _cin, String& s)
    {
        char ch;
        while (ch = getchar() != EOF)
        {
            if (ch == '\n')
                return _cin;
            s += ch;
        }
        return _cin;
    }

public:

    typedef char* iterator;

public:

    String(const char* str = "")
        :_size(0)
        ,_capacity(0)
        ,_str(new char[_capacity+1])
    {
        strcpy(_str, str);
    }

    String(const String& s)
        :_size(strlen(s._str))
        ,_capacity(_size)
        ,_str(nullptr)
    {
        String tmp(s._str);
        swap(tmp._str, _str);
    }

    String& operator=(const String& s)
    {
        if(this!=&s)
        {

            char* tmp = new char[_capacity + 1];
            //拷贝
            strcpy(tmp, s._str);
            //释放原有空间
            delete[] _str;
            //指向新的空间
            _str = tmp;
            //更新
            _size = strlen(s._str);
            _capacity = _size;
        }
    }

    ~String()
    {
        if (_str)
        {
            delete[] _str;
            _str = nullptr;
        }
    }



        //////////////////////////////////////////////////////////////

        // iterator

    iterator begin()
    {
        return _str;
    }

    iterator end()
    {
        return _str + _size;
    }



        /////////////////////////////////////////////////////////////

        // modify

    void PushBack(char c)
    {
        //判断容量是否足够，不够需要增容
        if (_size == _capacity)
        {
            //增容
            size_t newCapacity = _capacity == 0 ? 15 : 2 * _capacity;
            _capacity = newCapacity;
        }
        _str[_size++] = c;
        _str[_size] = '\0';
    }

    String& operator+=(char c)
    {
        PushBack(c);
        return *this;

    }

    void Append(const char* str)
    {
        if (_size + strlen(str) > _capacity)
        {
            reserve(_size + strlen(str));
        }
        strcpy(_str + _size, str);
        _size += strlen(str);

    }

    String& operator+=(const char* str)
    {
        Append(str);

        return *this;
    }

    void clear()
    {
        if (_str)
        {
            delete[] _str;
            _size = 0;
            _capacity = 0;
            _str = nullptr;
        }
    }

    void Swap(String& s)
    {
        swap(_size, s._size);
        swap(_capacity, s._capacity);
        swap(_str, s._str);
    }

    const char* c_str()const
    {
        return _str;
    }



    /////////////////////////////////////////////////////////////

    // capacity

    size_t size()const
    {
        return _size;
    }

    size_t capacity()const
    {
        return _capacity;
    }

    bool empty()const
    {
        return _size == 0;
    }

    void resize(size_t newSize, char c = '\0')
    {
        //n>_capacity
        if (newSize > _capacity)
        {
            reserve(newSize);
        }
        //n>_size&&n<_capacity
        if (newSize > _size)
        {
            memset(_str + _size, c, newSize - _size);
        }
        //n<_size
        _size = newSize;
        _str[_size] = '\0';
    }

    void reserve(size_t newCapacity)
    {
        if (newCapacity > _capacity)
        {
           //开空间
            char* tmp = new char[newCapacity + 1];
            //拷贝
            for (int i = 0; i < _size; i++)
            {
                tmp[i] = _str[i];
            }
            //释放原有空间
            delete[] _str;
            //指向新的空间
            _str = tmp;
            //更新
            _capacity = newCapacity;
            
        }
    }
        



    /////////////////////////////////////////////////////////////

    // access

    char& operator[](size_t index)
    {
        assert(index < _size);
        return _str[index];
    }

    const char& operator[](size_t index)const
    {
        assert(index < _size);
        return _str[index];
    }



    /////////////////////////////////////////////////////////////

    //relational operators

    bool operator<(const String& s)
    {
        int ret=strcmp(_str, s._str);
        if (ret<0)
            return true;
        return false;
    }

    bool operator<=(const String& s)
    {
        return !(*this > s);
    }

    bool operator>(const String& s)
    {
        int ret = strcmp(_str, s._str);
        if (ret > 0)
            return true;
        return false;
    }

    bool operator>=(const String& s)
    {
        return !(*this < s);
    }

    bool operator==(const String& s)
    {
        return (strcmp(_str, s._str) == 0);
    }

    bool operator!=(const String& s)
    {
        return !(*this == s);
    }



    // 返回c在string中第一次出现的位置

    size_t find(char c, size_t pos = 0) const
    {
        for (size_t i = pos; i < _size; i++)
        {
            if (_str[i] == c)
                return i;
        }
        return npose;
    }

    // 返回子串s在string中第一次出现的位置

    size_t find(const char* s, size_t pos = 0) const
    {
        char* start = strstr(_str + pos, s);
        if (start)
        {
            return start - _str;
        }
        return npose;
    }

    // 在pos位置上插入字符c/字符串str，并返回该字符的位置

    String& insert(size_t pos, char c)
    {
        assert(pos <= _size);
        if (pos == _capacity)
        {
            size_t newCapacity = _capacity == 0 ? 15 : 2 * _capacity;
            reserve(newCapacity);
        }
        //移动元素，从后向前移动
        for (int i = _size; i > pos; i--)
        {
            _str[i] = _str[i-1];
        }
        _str[pos] = c;
        _str[_size + 1] = '\0';
        
        return *this;
    }

    String& insert(size_t pos, const char* str)
    {

        assert(pos <= _size);
        if (_size+strlen(str) > _capacity)
        {
            size_t newCapacity = _size + strlen(str);
            reserve(newCapacity);
        }
        int len = strlen(str);
        for (int i = _size; i > pos-1; i--)
        {
            _str[i+len] = _str[i];
        }
        memcpy(_str + pos, str,len*sizeof(char));
        _size += len;
        return *this;
    }



    // 删除pos位置上的元素，并返回该元素的下一个位置

    String& erase(size_t pos, size_t len)
    {
        assert(pos < _size);
        if (pos + len >= _size)
        {
            _size = pos;
            _str[_size] = '\0';
            return;
        }
        size_t start = pos+len;
        while (start < _size)
        {
            _str[pos++] = _str[start++];
        }
        
        _size -= len;
        _str[_size] = '\0';

        return *this;
    }

private:

    char* _str;

    size_t _capacity;

    size_t _size;

    static const size_t npose;

};
  const size_t String::npose = -1;

int main()
{
	return 0;
}