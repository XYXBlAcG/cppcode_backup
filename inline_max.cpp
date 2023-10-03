#include <cstdio>
namespace xyx{
    template<class T>
    T max(T head) {
        return head;
    }

    template<class T, typename... Args>
    T max(T head, Args... args) {
        T t = max<T>(args...);
        return (head > t) ? head : t;
    }
};
