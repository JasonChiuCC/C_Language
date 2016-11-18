    struct {
        char    *str;
        int     val1;
        int     val2;
    }   stTest [] = {
            { str: "t1", val1: 1 },
            { str: "t2", val1: 2 },
        };
    printf("%d \n",stTest[0].val1);


struct i2c_msg {
         __u16 addr;            /* slave address                        */
         __u16 flags;
#define I2C_M_TEN               0x0010  /* this is a ten bit chip address */
#define I2C_M_RD                0x0001  /* read data, from slave to master */
#define I2C_M_STOP              0x8000  /* if I2C_FUNC_PROTOCOL_MANGLING */
#define I2C_M_NOSTART           0x4000  /* if I2C_FUNC_NOSTART */
#define I2C_M_REV_DIR_ADDR      0x2000  /* if I2C_FUNC_PROTOCOL_MANGLING */
#define I2C_M_IGNORE_NAK        0x1000  /* if I2C_FUNC_PROTOCOL_MANGLING */
#define I2C_M_NO_RD_ACK         0x0800  /* if I2C_FUNC_PROTOCOL_MANGLING */
#define I2C_M_RECV_LEN          0x0400  /* length will be first received byte */
         __u16 len;              /* msg length                           */
         __u8 *buf;              /* pointer to msg data                  */
};

static int i2c_read_byte (u8 devaddr, u16 regoffset, u8 * value)
{
    struct i2c_msg i2c_msgs[] = {
        { .addr     = devaddr,
          .flags    = 0x0,
          .len      = 0x1,
          .buf      = (u8 *)&regoffset,
        },
        { .addr     = devaddr,
          .flags    = 0x1,
          .len      = 0x1,
          .buf      = value,
        },                
    };  
}
