// parse mac address from char array
char   *delim = ":";
char   *pChar;  
    
/* Parse mac address */
pChar = strtok(au8DataStr,delim);
for( i=0; i<LEN && pChar != NULL ; i++)
{
  shortArray[i] = strtol(pChar,NULL,16);
  pChar = strtok(NULL,delim);        
}  
