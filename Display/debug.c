#define __toStr(x...) #x
#define __str(x...)  __toStr(x)
#define DEBUG_STR "TEST:" __str(__LINE__)

printf("%s\n",DEBUG_STR);
