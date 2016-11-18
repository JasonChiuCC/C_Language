int i = 0;
for (i=0;i<1000;i++){
    printf("\rValue of i is: %d", i);
    fflush(stdout);
    Sleep(1000);
}


int bootdelay   = 15;
printf(" Default will run xxxxx_xxxxx OS after %2d sec.", bootdelay);
while( bootdelay > 0 )
{
    int i;
    --bootdelay;
    Sleep(1000);
    printf("\b\b\b\b\b\b\b%2d sec.", bootdelay);
}
