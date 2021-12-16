#include<stdio.h>
#include <string.h>
char str[100];

//Function for finding digit.
int is_digit(char ch){
    if(ch>='0'&&ch<='9') return 1;
    return 0;
}
//FUnction for finding char.
int is_char(char ch){
    if(ch>='A'&&ch<='Z') return 1;
    if(ch>='a'&&ch<='z') return 1;
    return 0;
}
//Function for finding vowel.
int is_vowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') return 1;
    return 0;
}


char letters[100],digits[100],others[100], vowels[10], consonants[50];
int inl=0,ind=0,ino=0,inv=0,inc=0;
int markl[300],markd[300],marko[300];
// For counting word, digit, other character and seperate characters, digits, and other characters.
void count_word_letter_digit_other_and_seperate_view(){

    int cnt=1,letter_cnt=0,digit_count=0, other = 0,i, x, consonants_cnt=0, vowels_count=0;
    //If nothing is given as the input.
    if (strlen(str)==0){
        cnt=0;
    }
    //Looping in the input untill terminating character comes.
    for(i=0;str[i];i++){
        if(str[i]==' '&&(is_char(str[i+1])||is_digit(str[i+1]))){
            //Counting number of words by detechting spaces and 
            //after the space untill another character or digit comes.
           cnt++;
        }
        //Converting the char value to integer.
        x = (int)str[i];
        if(is_char(str[i])){
            //Counting number of letters.
            letter_cnt++;
            //Counting number of vowels and consonants in the input.
            if(is_vowel(str[i])){
                vowels_count++;
                
            }
            else{
                consonants_cnt++;
            }
            // Checking for char and if the character is already marked if not
            // then mark them by putting 1 in their crosponding x value.
            if(!markl[x]){
                // Differencing each voewls.
                if(is_vowel(str[i])){
                    vowels[inv++] = str[i];
                    vowels[inv++] = ' ';

                }
                // Differencing each Consonents.
                else{
                    consonants[inc++] = str[i];
                    consonants[inc++] = ' ';
                }

                // Getting each letters.
                letters[inl++] = str[i];
                letters[inl++] = ' ';

                

                markl[x] = 1;
            }
            
        }
        
        if(is_digit(str[i])){
            // Counting digit.
            digit_count++;
            // Differencing each digits.
            if(!markd[x]){
                digits[ind++] = str[i];
                digits[ind++] = ' ';
                markd[x] = 1;
            }
            
            
        }
        
        if(!is_digit(str[i])&&!is_char(str[i])){
            //Counting others
            other++;
            //Differencing each others.
            if(!marko[x]){
                others[ino++] = str[i];
                others[ino++] = ' ';
                marko[x] = 1;
            }
        }
    }
    printf("\n\nProblem1-a:\n");
    printf("------------\n");
    printf("Numbers of words : %d\n",cnt);
    printf("Numbers of letters : %d\n",letter_cnt);
    printf("Numbers of digit : %d\n",digit_count);
    printf("Numbers of Other char : %d\n",other);
    letters[inl] = '\0';
    digits[ind] = '\0';
    others[ino] = '\0';
    vowels[inv] = '\0';
    consonants[inc] = '\0';

    printf("\n\nProblem1-b:\n");
    printf("------------\n");

    printf("Separated letters : %s\n",letters);
    printf("Separated digits : %s\n",digits);
    printf("Separated others : %s\n",others);

    printf("\n\nProblem1-c:\n");
    printf("------------\n");
    printf("Number of Consonants:%d\n", consonants_cnt);
    printf("Number of vowel:%d\n", vowels_count);

    printf("\n\nProblem1-d:\n");
    printf("------------\n");
    printf("Vowels used:%s\n", vowels);
    printf("consonnts used: %s\n", consonants);
}
char vowel_words[500], vw=0, consonant_words[500],cw = 0;
//For separating words starting with vowel and consonents.
void seperate_by_starting_char(){
    for(int i = 0; str[i]; i++){
        //printf("i");
        //Cheack if it is character.
        if(is_char(str[i])){
            //Cheacking first character vowel of consonent.
            if(is_vowel(str[i])){
                //printf("i");
                
                vowel_words[vw++] = str[i];
                i++;
                //Going untill next others or number comes.
                while(is_char(str[i])){
                    vowel_words[vw++] = str[i++];
                }
                vowel_words[vw++] = ' ';
            }
            else{
                //printf("y");
                consonant_words[cw++] = str[i];
                i++;
                while(is_char(str[i])){
                    consonant_words[cw++] = str[i++];
                }
                consonant_words[cw++] = ' ';
            }

            
            
        }
    }
    vowel_words[vw] = '\0';
    consonant_words[cw] = '\0';

    printf("\n\nProblem1-e:\n");
    printf("------------\n");
    printf("Vowel words: %s\n", vowel_words);
    printf("Consonent words: %s\n", consonant_words);
}



int main(){

    freopen("input.txt","r",stdin);
    

    scanf(" %[^\n]",str);
    printf("Input is: %s", str);

    count_word_letter_digit_other_and_seperate_view();
    seperate_by_starting_char();
    
    return 0;
}