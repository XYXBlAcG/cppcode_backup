#include <cstdio>
#include <algorithm>
const int STL_MAXN = 1e5 + 5;
namespace xyx{
    template <typename T, size_t _Size>
    struct Heap{
        T data[_Size]; int pdata = 0;
        void push(T b){
            data[++pdata] = b;
            std::push_heap(data + 1, data + 1 + pdata);
        }
        void pop(){std::pop_heap(data + 1, data + 1 + pdata--);}
        T top(){return data[1];}
        int size(){return pdata;}
        bool empty(){return pdata;}
        T* begin(){return &data[1];}
        T* end(){return &data[pdata + 1];}
    };
    template <typename T, size_t _Size>
    struct Stack{
        T data[_Size]; int pdata = 0;
        void push(T b){data[++pdata] = b;}
        void pop(){if(pdata) pdata--;}
        T operator[](int x){return data[x];}
        T top(){return data[pdata];}
        int size(){return pdata;}
        bool empty(){return pdata;}
        int* begin(){return &data[1];}
        int* end(){return &data[pdata + 1];}
    };
    template <typename T, size_t _Size>
    struct Queue{
        T data[_Size]; int l = 0, r = 0;
        void push(T b){data[++r] = b;}
        void pop(){l++;}
        T tail(){return data[l + 1];}
        T head(){return data[r];}
        int size(){return r - l;}
        bool empty(){return r - l;}
        int* begin(){return &data[l + 1];}
        int* end(){return &data[r + 1];}
    };
    // wait to write a queue which can recycle space
    template<typename T>
    class QueueBase{
    public:
        QueueBase(){}
        ~QueueBase(){}
        virtual bool enque(const T&)=0;
        virtual bool deque(T&)=0;
        virtual bool front(T&)=0;
        virtual bool rear(T&)=0;
        virtual bool empty()const=0;
        virtual bool full()const=0;
        virtual int size() =0;
        virtual int maxSzie()=0;
    };
    template <typename T>
    class CQueue : public QueueBase<T>
    {
        public:
            //默认构造函数
            CQueue();
            //自定义构造函数
            CQueue(size_t);
            //析构函数
            ~CQueue();
            //出队操作
            virtual bool deque(T&);
            //入队操作
            virtual bool enque(const T&);
            //查看队列首端元素
            virtual bool front(T&);
            //查看队列末端元素
            virtual bool rear(T&);
            //队列是否非空
            virtual bool empty() const;
            //队列是否已满
            virtual bool full() const;
            //返回队列已有数量
            virtual int size();
            //返回队列maxsize
            virtual int maxSzie();
            //缓存
            const T *buffer();

        private:
            //内部元素队列指针
            int d_rear;
            int d_front;
            int d_size;
            int d_maxsize;
            T *d_arr;
    };

    ////////////////////////////////////定义///////////////////////////////////
    /*模板类申明和定义放在.h文件中
    否则定义该派生模板类对象时，会报错：构造和析构函数未定义
    */
    #define DEFAULT_SIZE 1e5 + 5

    template <typename T>
    CQueue<T>::CQueue()
    {
        d_front = -1;
        d_rear = -1;
        d_maxsize = DEFAULT_SIZE;
        d_size = 0;
        d_arr = new T[d_maxsize];
    }


    //构造函数
    template <typename T>
    CQueue<T>::CQueue(size_t size)
    {
        d_size = 0;
        d_maxsize = size;
        d_front = -1;
        d_rear = -1;
        d_arr = new T[d_maxsize];
    }


    //析构函数
    template <typename T>
    CQueue<T>::~CQueue()
    {
        delete[] d_arr;
        //d_arr = nullptr;
    }


    //检查环形队列是否为满载
    template <typename T>
    bool CQueue<T>::full() const
    {
        return d_front == (d_rear + 1) % d_maxsize;
    }


    //返回队列已有数量
    template <typename T>
    int CQueue<T>::size()
    {
        return d_size;
    }


    //判断环形队列是否为空
    template <typename T>
    bool CQueue<T>::empty() const
    {
        return d_front == d_rear;
    }

    //入队操作
    template <typename T>
    bool CQueue<T>::enque(const T &value)
    {
        if (full())
        {
            // std::cout << "环形队列已满" << std::endl;
            return false;
        }
        else if (d_front == -1)
        {
            d_rear = d_front = 0;
        }
        else if (d_rear == d_maxsize - 1 && d_front != 0)
        {
            d_rear = 0;
        }
        else
        {
            d_rear++;
        }
        d_arr[d_rear] = value;
        d_size++;
        return true;
    }


    //出队操作
    template <typename T>
    bool CQueue<T>::deque(T & value)
    {
        if (empty())
        {
            // std::cout << "环形队列为空" << std::endl;
            return false;
        }
        value = d_arr[d_front];

        if (d_front == d_rear)
        {
            d_front = -1;
            d_rear = -1;
        }
        else if (d_front == d_size - 1)
        {
            d_front = 0;
        }
        else
        {
            d_front++;
        }
        d_size--;
        return true;
    }

    //获取队头部元素
    template <typename T>
    bool CQueue<T>::front(T& value)
    {
        if (empty())
        {
            // std::cout << "环形队列为空" << std::endl;
            return false;
        }
        value = d_arr[d_front];
        return true;
    }

    //获取队尾元素
    template <typename T>
    bool CQueue<T>::rear(T& value)
    {
        if (empty())
        {
            // std::cout << "环形队列为空" << std::endl;
            return false;
        }
        value = d_arr[d_rear];
        return true;
    }


    //获取队列尺寸
    template <typename T>
    int CQueue<T>::maxSzie()
    {
        return d_maxsize;
    }


    //获取队列内部的缓存指针
    template <typename T>
    const T *CQueue<T>::buffer()
    {
        return d_arr;
    }


    template <typename T>
    void swapINT(T& a, T& b){
        a ^= b ^= a ^= b;
    }
};