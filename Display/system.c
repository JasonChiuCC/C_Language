#include <sys/utsname.h>
// http://linux.die.net/man/2/uname
//Then, define a utsname structure:

struct utsname unameData;

//Then, call uname() with a pointer to the struct:

uname(&unameData); // Might check return value here (non-0 = failure)

//After this, the struct will contain the info you want:

printf("%s", unameData.sysname);
