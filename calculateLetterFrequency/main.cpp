#include "calculateLettterFrequency.h"
using namespace std;

int main()
{
    char aa[] = "aaaaaaaaaaaa";
    int letterHash[27] = {0};
    bool result;
    printf("please input string: ");
    scanf("%s",aa);
    result = calculateLetterFrequency(aa,letterHash);
    if(result)
    {
        for(int i=0;i<26;i++)
        {
            printf("%c : %d \n", 'a'+i, letterHash[i]);
        }
        printf("others : %d \n", letterHash[26]);
    }
    else
    {printf("input string error!!");}
    return 0;
}
