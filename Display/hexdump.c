#include<stdio.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
/*-----------------------------------------------------------------------
 * Typedef
 *----------------------------------------------------------------------*/
typedef long                I64_T;
typedef unsigned long       UI64_T;
typedef int                 I32_T;
typedef unsigned int        UI32_T;
typedef short int           I16_T;     
typedef unsigned short int  UI16_T;    
typedef char                I8_T;
typedef unsigned char       UI8_T;
typedef unsigned short int  BOOLEAN;
typedef unsigned char       u_char;
typedef unsigned short      u_short;
typedef unsigned long       u_long;
typedef unsigned char       unchar;
typedef unsigned short      ushort;
typedef unsigned int        uint;
typedef unsigned long       ulong;

/*-----------------------------------------------------------------------
 * Color
 *----------------------------------------------------------------------*/
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


/*-----------------------------------------------------------------------
 * Size
 *----------------------------------------------------------------------*/
#define SIZE_2G     0x80000000 
#define SIZE_1G     0x40000000
#define SIZE_512M   0x20000000
#define SIZE_200M   0x0C800000
#define SIZE_20M    0x01400000
#define SIZE_10M    0x00A00000
#define SIZE_1M     0x00100000

#define RAM_BASE    0x60000000

/*========================================*/
/* hexdump                                */
/*    desc : 描述                         */
/*    mem  : 起始位址                     */
/*    len  : 長度 (Byte)                  */
/*    type : 0 = 一般顯示,1 = 詳細顯示    */
/*========================================*/
void hexdump(char *desc, void *map_base,unsigned long startAddr, unsigned long dumpByteSize, unsigned int infoType)
{

    unsigned int i          = 0;
    unsigned int j          = 0;
    unsigned int dumpCols   = 16;

    /* Start */    
    /*
    if (desc != NULL)
        printf ("[ %s : Start]\n\n", desc);
    */

    /* 顯示上方索引 */
    if( infoType == 1 )
    {
        printf("\t\t  ");
        for(i = 0; i <  dumpCols ; i++)
        {
            printf("%2d ", i);
        }
        printf(" ");
        for(i = 0; i <  dumpCols ; i++)
        {
            printf("%2d ", i);
        }
        printf("\n  ");
        for(i = 0; i <  113 ; i++)
        {
            printf("-");
        }
        printf("\n");
    }


    for(i = 0; i < dumpByteSize + ((dumpByteSize % dumpCols) ? (dumpCols - dumpByteSize % dumpCols) : 0); i++)
    {
            /* 列開頭 */
            if(i % dumpCols == 0)
            {
                if( infoType == 1 ) { printf("0x%08x (%04d) : ", (i+startAddr), i); } 
                else                { printf("0x%08x: ", (i+startAddr));            }
            }

            /* 輸出 Hex Data */
            if(i < dumpByteSize)
            {
                printf("%02x ", 0xFF & ((char*)map_base)[i]);
            }

            /* 輸出 ASCII */
            if(i % dumpCols == (dumpCols - 1))
            {
                /* Hex Data 和 ASCII 間距*/
                printf("  ");
                for( j = i - (dumpCols - 1); j <= i; j++)
                {
                        if(isprint(((char*)map_base)[j])) /* printable char */
                        {
                            printf("%c", 0xFF & ((char*)map_base)[j]);
                            if( infoType == 1 ) printf("  ");
                        }
                        else
                        {
                            printf(".");
                            if( infoType == 1 ) printf("  ");
                        }
                }
                printf("\n");
            }
    }

    /* End */
    /*
    if (desc != NULL)
        printf ("\n[ %s : End]\n\n", desc);
    */
}

/* Example
$ ./Ram_Dump 0x60000000 0x100 0
$ ./Ram_Dump 0x60000000 0x100
*/
int main(int argc, char *argv[])
{
 
    unsigned long   startAddr       = 0;
    unsigned long   dumpByteSize    = 0;
    unsigned long   infoType        = 0;
    unsigned char   *map_base;
    FILE            *f;
    int             n;
    int             fd;
    
    
    startAddr           = strtoul(argv[1], NULL, 0);
    dumpByteSize        = strtoul(argv[2], NULL, 0);
    infoType            = (argc==4) ? 1 : 0;   
    
    printf("%s================================================================================%s\n", KCYN, KNRM);
    printf("%s Ram Dump StartAddr : 0x%08x  Size : 0x%08x byte                                %s\n", KCYN, startAddr, dumpByteSize,KNRM);
    printf("%s================================================================================%s\n", KCYN, KNRM);    
    

    fd = open("/dev/mem", O_RDWR|O_SYNC);
    if (fd == -1){
        printf("%sERROR : Can't open /dev/mem!%s\n", KRED, KNRM);
        return (-1);
    }

    map_base = mmap(NULL, dumpByteSize, PROT_READ|PROT_WRITE, MAP_SHARED, fd, startAddr );
    if (map_base == 0){
        printf("NULL pointer!\n");
        close(fd);        
        return (1);        
    }
    
    hexdump("Test", map_base, startAddr, dumpByteSize, infoType);  
    close(fd);
    munmap(map_base, dumpByteSize);    
    return (1);    
}
