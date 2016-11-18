#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int *argc, char **argv)
{
    void    *fHandle;
    void     (*func)(); // 注意傳入參數和回傳參數的型態

    fHandle = dlopen("./jasonLIB.so",RTLD_LAZY);
    if (!fHandle) {
        fprintf (stderr, "%s\n", dlerror());
        exit(1);
    }
    dlerror();
    func = dlsym(fHandle, "jasonAdd");

    
    if (func) {        
        //printf("Result = %d\n",func(10,20));
    }
    func();
    dlclose(fHandle);
    return 0;
}