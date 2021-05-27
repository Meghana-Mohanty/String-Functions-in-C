#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 50

//function declarations
int StringLength(char word[]);
void CopyString(char word[], char word2[]);
void ReverseString(char word[], char word2[]);
void ChangeCase(char word[], char word2[]);
int CheckPalimdrome(char word[], char word2[]);
int CompareString(char word[], char word2[]);
void ConcatString(char word[], char word2[], char final[]);
int Substring(char word[], char word2[]);

int main(void)
{
    int choice = -1;
    char word[MAXSIZE] = {'\0'};
    char word2[MAXSIZE] = {'\0'};
    char final[100] = "\0";//to store concatenated string, hence double size
    int length = -1;
    int succ = -1;
    int result = 0;
    
    printf("\nEnter a word: ");
    scanf("%49s", word);//accepting word for all future functions
    
    while(choice != 0)
    {
        printf("\n\tEnter 1 to find length of string");
        printf("\n\tEnter 2 to copy a string");
        printf("\n\tEnter 3 to reverse a string");
        printf("\n\tEnter 4 to change case of string");
        printf("\n\tEnter 5 to check for palindrome strings");
        printf("\n\tEnter 6 to compare strings");
        printf("\n\tEnter 7 to concatenate strings");
        printf("\n\tEnter 8 to find if substring exists");
        printf("\n\tEnter 0 to Exit");
        printf("\n\tEnter your choice : ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 0:
            break;//exit case
            
            case 1:
            length = StringLength(word);
            printf("\nString length is: %d", length);
            break;
            
            case 2:
            if(sizeof(word2) < sizeof(word))//checking if second string is big enough to 
            {//hold first
                printf("\nword cannot be copied as there is not enough space.");
            }
            else
            {
                CopyString(word, word2);//calling copy string
                printf("\nWord copied.");
            }
            break;
            
            case 3:
            ReverseString(word, word2);//calling reverse string func
            printf("\nReverse is : %s", word2);
            break;
            
            case 4:
            ChangeCase(word, word2);//calling change case function
            printf("\nword after case change is : %s", word2);
            break;
            
            case 5:
            succ = CheckPalimdrome(word, word2);
            if(succ == 0)//checking for success of func
            {
                printf("Word is not palindrome");
            }
            else
            {
                printf("Word is palindrome");
            }
            break;
            
            case 6:
            printf("\nEnter second string: ");//accepting second string to compare
            scanf("%49s", word2);
            result = CompareString(word, word2);
            if(result == 0)//checking result
            {
                printf("\nStrings are equal.");
            }
            else
            {
                if(result > 0)
                {
                    printf("\nString 2 is greater");
                }
                else
                {
                    printf("\nString 1 is greater");
                }
            }
            break;
            
            case 7:
            printf("\nEnter second string: ");
            scanf("%49s", word2);//accepting second string to concatenate
            ConcatString(word, word2, final);
            printf("%s", final);
            break;
            
            case 8:
            printf("\nEnter substring to check: ");
            scanf("%49s", word2);//accepting second string to check
            result = Substring(word, word2);
            if(result == 0)//checking results
            {
                printf("\nNot a substring.");
            }
            else
            {
                printf("\nWord is a substring");
            }
            break;
        }
      
    }
    return 0;
}

int StringLength(char word[])
{
    int i = 0;
    char ch = word[i];
    while(ch != '\0')
    {
        ch = word[i];
        i++;//taking i as counter variable to calculate length
    }
    return (i-1);
}

void CopyString(char word[], char word2[])
{
    int i = 0;
    int len = StringLength(word);
    
    for(i = 0; word[i] != '\0'; ++i)
    {
        word2[i] = word[i];//copying character from first to second
        word2[i+1] = '\0';//making next character as \0 to avoid illegal string
    }
}

void ReverseString(char word[], char word2[])
{
    int len = StringLength(word);
    int i = 0;
    int j = 0;
    
    for(i = len-1; i>= 0; i--)
    {
        word2[j] = word[i];//assigning character from word to word2 in reverse order
        j++;
    }
    word2[j] = '\0';
}

void ChangeCase(char word[], char word2[])
{
    int len = StringLength(word);
    int i = 0;
    char ch = word[i];
    
    for(i = 0; i< len; i++)
    {
        ch = word[i];
        if(ch >= 'A' && ch <= 'Z')//checking if character is uppercase
        {
            ch = ch + 32;
        }
        else if(ch >= 'a' && ch <= 'z')//checking if character is lowercase
        {
            ch = ch - 32;
        }
        word2[i] = ch;//assigning character to the word
        word2[i+1] = '\0';
    }
    
}

int CheckPalimdrome(char word[], char word2[])
{
    ReverseString(word, word2);//reversing string 
    int len = StringLength(word2);
    int i = 0;
    int succ = -1;
    char ch1 = word[i];
    char ch2 = word2[i];
    
    //following is code for converting to lowercase and then comparing words.
    for(i = 0; i< len; i++)
    {
        if(ch1 >= 'A' && ch1 <= 'Z')
        {
            ch1 = ch1 + 32;
        }
        if(ch2 >= 'A' && ch2 <= 'Z')
        {
            ch2 = ch2 + 32;
        }
        
    }
    if(CompareString(word, word2) == 0)
    {
        succ = 1;
    }
    else
    {
        succ = 0;
    }
    return succ;
}

int CompareString(char word[], char word2[])
{
    int diff = 0;
    int i = 0;
    int l1 = StringLength(word);
    int l2 = StringLength(word2);
    int min = l2;
    char ch1 = word[i];
    char ch2 = word2[i];
    int flag = 0;
  
    
    if(l2 > l1)
    {
        min = l1;//checking for larger string
    }
    
    for(i = 0; i < min; i++)
    {
        ch1 = word[i];
        ch2 = word2[i];
        if(ch1 == ch2)//if character is same, then diff is zero
        {
            diff = 0;
        }
        else//if characters are different, then save difference between characters
        {
            if(ch1 > ch2)
            {
                diff = (ch1 - ch2);
                flag = 1;
                i = min;//if different characters are found, come out of loop and return difference
            }
            else
            {
                diff = (ch2 - ch1); 
                flag = 1;
                i = min;
            }
        }
    }
    
    return diff;
    
}

void ConcatString(char word[], char word2[], char final[])
{
    int l1 = StringLength(word);
    int l2 = StringLength(word2);
    int i = 0;
    int j = 0;
    
    for(i = 0; i< l1; i++)//adding first word to final word
    {
        final[i] = word[i];
        final[i+1] = '\0';
    }
    for(j = 0; j< l2; j++)//adding second word to final word
    {
        final[i] = word2[j];
        final[i+1] = '\0';
        i++;
    }
    
}

int Substring(char word[], char word2[])
{
    int i = 0;
    int j = 0;
    int count1 = StringLength(word);
    int count2 = StringLength(word2);
    int flag = 0;
    
    for (i = 0; i <= count1 - count2; i++)//looping only till where we can have first character
    {
        for (j = i; j < i + count2; j++)//checking the characters upto length of substring
        {
            flag = 1;
            if (word[j] != word2[j - i])
            {
                flag = 0;
                j = i+count2;
            }
        }
        if (flag == 1)
        {
            i = (count1 - count2) + 1;
        }
    }
    
}