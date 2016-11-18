### 編譯 Lib
gcc -fPIC -c jasonLIB.c
gcc -fPIC -shared -o jasonLIB.so jasonLIB.o

### 編譯 main
gcc -o main main.c -ldl