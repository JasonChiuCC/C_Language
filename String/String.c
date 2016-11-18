// char porinter -> char array
char *pDateStr;
char au8DataStr[MAX_STR_LEN+1];
strcpy(pDateStr,au8DataStr,MAX_STR_LEN);
au8DataStr[MAX_STR_LEN] = '\0';

// char array -> short array
short au8Data[LEN];
for(i=0;i<LEN;i++)
{
 au8Data[i] = au8DataStr[i]; 
}
