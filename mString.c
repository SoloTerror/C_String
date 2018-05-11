#include<stdio.h>

//字符串长度
int StrLength(const char *inStr)
{
        char *strStart = inStr;
         while (*inStr)
         {
          inStr++;
         }
        return inStr - strStart;

}

/*
 *查找字符串
 *返回字符串所在位置
 * **/
int StrIndexOf(const char *inStr,const char *inValue)
{
    int StrIndex =-1;
    char *strStart;
    char *valueTemp;
    for(int index =0 ;*inStr!='\0';inStr++,index++)
    {
        if(*inStr == *inValue)
        {
            StrIndex = index;
            strStart = inStr;
            valueTemp = inValue;
            for(;*valueTemp != '\0';)
            {
                if(*strStart++ != *valueTemp++)
                {
                    StrIndex = -1;
                    break;
                }
            }
        }
        if(StrIndex > 0)
        {
            break;
        }
    }
    return StrIndex;
}
/*
 * 插入字符串
 */
int StrInsert(char *inStr,const char *inInsertStr,const int inIndex)
{
    int strLength = StrLength(inStr);
    int insertStrLength = StrLength(inInsertStr);
    if(inIndex < strLength)
    {
        for(int i = strLength + insertStrLength - 1; i >= inIndex + insertStrLength ; i--)
        {
            inStr[i] = inStr[i - insertStrLength];
        }
        for(int i = 0; i < insertStrLength; i++)
        {
            inStr[inIndex + i] = inInsertStr[i];
        }
        inStr[insertStrLength + strLength] = '\0';
        return 1;
    }else
    {
        return -1;
    }
}

/*
 * 序列删除字符
 */
int StrRemove(char *Originality_Str,int begin,int end)
{

}
/*
 * 替换字符
 */
int StrReplace(char *inStr,const char *inValue,const char *inReplaceStr)
{
    int strIndex = 0;
    int strLength ,
        valueLength = StrLength(inValue),
        replaceStrLength = StrLength(inReplaceStr);
    do
    {
        strIndex = StrIndexOf(inStr,inValue);
        if( strIndex >= 0)
        {
            strLength = StrLength(inStr);
            if(valueLength >= replaceStrLength)
            {
                for(int i = strIndex ,x = 0 ;i < strLength;i++,x++)
                {
                    if(x < replaceStrLength)
                    {      
                        inStr[i] = inReplaceStr[x];
                    }
                    if(x >= valueLength)
                    {
                        inStr[i - (valueLength - replaceStrLength)] = inStr[i];
                    }
                 }
                inStr[strLength -(valueLength-replaceStrLength) ] = '\0';
             }
            else
             {
                for(int i = strLength + (replaceStrLength - valueLength)-1;
                    i >= strIndex+(replaceStrLength-valueLength);
                    i--)
                {
                    inStr[i] = inStr[i-(replaceStrLength - valueLength)];
                }
                for(int i = 0;i < replaceStrLength;i++)
                {
                    inStr[strIndex + i] = inReplaceStr[i];
                }
                inStr[strLength+(replaceStrLength - valueLength)] = '\0';
             }
        }
    }while(strIndex >= 0);

}


int main()
{
    char str[1024] = "间是大12";
    char str1[102] = "间";
    char  str3[100] = "时";

    int s = StrLength(str1);
    int ee =  StrIndexOf(str,str1);
    int xx = StrIndexOf(str,str3); 
    
    printf("%d\n",ee);
    printf("%d\n",xx);
    
    char str5[] = "ssssssssssssssssssss";
    char str6[] = "aaaa";
    printf("STR5 = %s\n",str5);
    printf("Str6 = %s\n",str6);
    StrInsert(str5,str6,5);
    printf("Insert = %s\n",str5);
    printf("str6 = %s\n",str6);
    


    char str8[] ="aaaaaaaddddaaaaaaaaaaaaaaadddddadddaaaddddddaaaaaaa";
    char str9[] = "dddd";
    char str10[] = "123456789";
    printf("str8 length =  %d str8 = %s\n",StrLength(str8),str8);
    StrReplace(str8,str9,str10);
    printf("str8 length = %d Str8 = %s\n",StrLength(str8),str8);
    return 0;;
}
