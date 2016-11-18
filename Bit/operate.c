#define MASK_BIT2  (1 << 2)
#define MASK_BIT1  (1 << 1)
#define MASK_BIT0  (1 << 0)
int main()
{
    unsigned short data = 0x0;
    data |= MASK_BIT2;           /* Data Bit 2 set 1 */
    
    printf("0x%04x\n",data);

    if( data & MASK_BIT2 )      /* Check bit 2 is 1 or 0 */
    {
        printf("BIT2 is 1 \n");
    }
    else
    {
        printf("BIT2 is 0 \n");
    }

    data &= ~(MASK_BIT2);        /* Data Bit 2 set 0 */
    printf("0x%04x\n",data);
}
