#include <iostream>
using namespace std;
void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}

void reverseWords(char *s)
{
  char *word_begin = s;
  char *temp = s; /* temp is for word boundry */
 
  /*STEP 1 of the above algorithm */
  while( *temp )
  {
    temp++;
    if (*temp == '\0')
    {
      reverse(word_begin, temp-1);
    }
    else if(*temp == ' ')
    {
      reverse(word_begin, temp-1);
      word_begin = temp+1;
    }
  } /* End of while */
 
   /*STEP 2 of the above algorithm */
  reverse(s, temp-1);
}

int main(){
    char s[] = "in my room, there are 3 people right now.";
    char * temp = s;
    cout<<s;
    reverseWords(s);
    cout << s;
    cout << endl;
    return 1;
}

// #include <iostream>
// using namespace std;
// int main(){
//     int a[] = {1,1,2,2,3,3,4,4,5};
//     int c = a[0];
//     for(int i = 1; i < sizeof(a)/sizeof(a[0]); i++){
//         c = c ^ a[i];
//     }
//     cout << "Single number is   : #" << c;
//     return c;
// }
