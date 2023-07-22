#include <emscripten.h>
int main(){
    emscripten_run_script("alert(1)");
    return 0;
}