#include <cstdio>
template<class Num>
Num moder(Num head){
    return head;
}

template<class Num, typename... Args, typename Mod>
Num moder(Mod mod, Num head, Args... args){
    Num num = moder<Num>(mod, args...);
    return (1ll * head + 1ll * num) % (1ll * mod);
}