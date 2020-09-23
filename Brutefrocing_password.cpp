/**
    @author
 
    Alias: daktari
 
    Name: Tolga Ay
 
    E-Mail: tolga-ay@outlook.com
 
    Contact :
        facebook : https://www.facebook.com/daktarism/
        steam : http://steamcommunity.com/id/daktar1/
 
    @file
    Project name : daktari's brute force key cracker
 
    Cracking the password "d4Kt4R" with %13 CPU use of i7 3770k
    took 82.6348 mins... -> http://puu.sh/7zfeo.png
 
 
    ->How it works?
 
    Actually, it finds easy password  easier but harder password will be harder because it increases the difficulity level one by one to get the easy password easier.
 
    It starts with one character passwords, tries a simple number charset at first, then if it can't find it, it switches charset until it finds it.
 
    Charset switches like,
 
    1-only numbers (10 characters)
    2-only lowercase characters (26 characters)
    3-only uppercase characters (26 characters)
    4-numbers and lowercase characters (36 characters)
    5-numbers and uppercase characters (36 characters)
    6-uppercase and lowercase characters (52 characters)
    7-numbers, uppercase and lowercase characters (62 characters)
 
    (it wont test the 4/5/6/7 with one char length, and also wont test the 7 with two char length passwords.)
 
    If it still can't find it, the password length increases to 2. and it loops like this, until it finds the password.
 
 EXAMPLES
    ---- some easy ones (probably faster than many brute force password crackers):
    Z : http://puu.sh/7zfpW.png
    i7 : http://puu.sh/7zfmR.png
    123 : http://puu.sh/7zewE.png
    asdf : http://puu.sh/7zeYP.png
    v4Af : http://puu.sh/7zeSG.png   -   http://puu.sh/7zePF.png
    dktri : http://puu.sh/7zf3V.png
 
 
    ---HARD ONE:
    some screenshots of it while cracking the d4Kt4R: (Every dot equals 2,500,000 attempts)
    http://puu.sh/7z8SI.png
    http://puu.sh/7z92e.png
    http://puu.sh/7z94q.png
    http://puu.sh/7z96P.png
    http://puu.sh/7z9KL.png
    *couple pages with full of dots here*
    *happy ending after 82.6348 mins*
    http://puu.sh/7zdsB.png
*/
 
#include <iostream>
#include <ctime>
using namespace std;
string crackPassword(string pass);
long long int attempt;
clock_t start_t, end_t;
 
int main(){
    string password;
 
    cout << "Enter the password to crack : ";
    cin >> password;
 
    cout << endl << endl << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>\n>> CRACKED THE PASSWORD! >>\n>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl <<  endl <<"The password : " << crackPassword(password) << endl;
    cout << "The number of attempts : " << attempt << endl;
    cout << "The time duration  passed : " << (double)(end_t - start_t)/1000 << " seconds" << endl << endl;
    return 0;
}
 
string crackPassword(string pass){
    int digit[7],alphabetSet=1,passwordLength=1;
    start_t = clock();
 
    string test,alphabet = "1337 also daktari is pro";
    while(1){
 
 
            switch(passwordLength){
                case 1:
                    while(alphabetSet<4){
                    switch(alphabetSet){
                        case 1 : alphabet = "-0123456789";
                                 cout << endl << endl <<"Testing only digits(0123456789) - 10 Characters, please wait";  break;
                        case 2 : alphabet = "-abcdefghijklmnopqrstuvwxyz";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only lowercase characters(abcdefghijklmnopqrstuvwxyz) - 26 Characters, please wait";  break;
                        case 3 : alphabet = "-ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only uppercase characters(ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 26 Characters, please wait";  break;
                        }
 
                    for(digit[0]=1;digit[0]<alphabet.length();digit[0]++){
                                                    attempt++;
                                                    if(attempt%2500000==0) cout << ".";
                                                    test=alphabet[digit[0]];
                                                    for(int i=1;i<passwordLength;i++)
                                                        if(alphabet[digit[i]]!='-')test+=alphabet[digit[i]];
                                                    if(pass.compare(test)==0){end_t = clock(); return test;}
                                                    }
                                                    alphabetSet++;
                    }
                    break;
                case 2:
                    alphabetSet=1;
                    while(alphabetSet<6){
                    switch(alphabetSet){
                        case 1 : alphabet = "-0123456789";
                                 cout << endl << endl <<"Testing only digits(0123456789) - 10 Characters, please wait";  break;
                        case 2 : alphabet = "-abcdefghijklmnopqrstuvwxyz";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only lowercase characters(abcdefghijklmnopqrstuvwxyz) - 26 Characters, please wait";  break;
                        case 3 : alphabet = "-ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only uppercase characters(ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 26 Characters, please wait";  break;
                        case 4 : alphabet = "-0123456789abcdefghijklmnopqrstuvwxyz";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyz) - 36 Characters, please wait";  break;
                        case 5 : alphabet = "-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                        }
 
 
                         for(digit[1]=0;digit[1]<alphabet.length();digit[1]++)
                             for(digit[0]=1;digit[0]<alphabet.length();digit[0]++){
                                                    attempt++;
                                                    if(attempt%2500000==0) cout << ".";
                                                    test=alphabet[digit[0]];
                                                    for(int i=1;i<passwordLength;i++)
                                                        if(alphabet[digit[i]]!='-')test+=alphabet[digit[i]];
                                                    if(pass.compare(test)==0){end_t = clock(); return test;}
                                                    }
                                                    alphabetSet++;
                    }
                    break;
                case 3:
                    alphabetSet=1;
                    while(alphabetSet<8){
                    switch(alphabetSet){
                        case 1 : alphabet = "-0123456789";
                                 cout << endl << endl <<"Testing only digits(0123456789) - 10 Characters, please wait";  break;
                        case 2 : alphabet = "-abcdefghijklmnopqrstuvwxyz";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only lowercase characters(abcdefghijklmnopqrstuvwxyz) - 26 Characters, please wait";  break;
                        case 3 : alphabet = "-ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only uppercase characters(ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 26 Characters, please wait";  break;
                        case 4 : alphabet = "-0123456789abcdefghijklmnopqrstuvwxyz";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyz) - 36 Characters, please wait";  break;
                        case 5 : alphabet = "-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing uppercase characters and numbers(0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 36 Characters, please wait";  break;
                        case 6 : alphabet = "-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase, uppercase characters(abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 52 Characters, please wait";  break;
                        case 7 : alphabet = "-0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase, uppercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 62 Characters, please wait";  break;
                    }
                                        for(digit[2]=0;digit[2]<alphabet.length();digit[2]++)
                                            for(digit[1]=0;digit[1]<alphabet.length();digit[1]++)
                                                for(digit[0]=1;digit[0]<alphabet.length();digit[0]++){
                                                    attempt++;
                                                    if(attempt%2500000==0) cout << ".";
                                                    test=alphabet[digit[0]];
                                                    for(int i=1;i<passwordLength;i++)
                                                        if(alphabet[digit[i]]!='-')test+=alphabet[digit[i]];
                                                    if(pass.compare(test)==0){end_t = clock(); return test;}
                                                    }
                                                    alphabetSet++;
                    }
                    break;
                case 4:
                    alphabetSet=1;
                    while(alphabetSet<8){
                    switch(alphabetSet){
                        case 1 : alphabet = "-0123456789";
                                 cout << endl << endl <<"Testing only digits(0123456789) - 10 Characters, please wait";  break;
                        case 2 : alphabet = "-abcdefghijklmnopqrstuvwxyz";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only lowercase characters(abcdefghijklmnopqrstuvwxyz) - 26 Characters, please wait";  break;
                        case 3 : alphabet = "-ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only uppercase characters(ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 26 Characters, please wait";  break;
                        case 4 : alphabet = "-0123456789abcdefghijklmnopqrstuvwxyz";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyz) - 36 Characters, please wait";  break;
                        case 5 : alphabet = "-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing uppercase characters and numbers(0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 36 Characters, please wait";  break;
                        case 6 : alphabet = "-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase, uppercase characters(abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 52 Characters, please wait";  break;
                        case 7 : alphabet = "-0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase, uppercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 62 Characters, please wait";  break;
                    }
 
                                    for(digit[3]=0;digit[3]<alphabet.length();digit[3]++)
                                        for(digit[2]=0;digit[2]<alphabet.length();digit[2]++)
                                            for(digit[1]=0;digit[1]<alphabet.length();digit[1]++)
                                                for(digit[0]=1;digit[0]<alphabet.length();digit[0]++){
                                                    attempt++;
                                                    if(attempt%2500000==0) cout << ".";
                                                    test=alphabet[digit[0]];
                                                    for(int i=1;i<passwordLength;i++)
                                                        if(alphabet[digit[i]]!='-')test+=alphabet[digit[i]];
                                                    if(pass.compare(test)==0){end_t = clock(); return test;}
                                                    }
                                                    alphabetSet++;
                    }
                    break;
                case 5:
                    alphabetSet=1;
                    while(alphabetSet<8){
                    switch(alphabetSet){
                        case 1 : alphabet = "-0123456789";
                                 cout << endl << endl <<"Testing only digits(0123456789) - 10 Characters, please wait";  break;
                        case 2 : alphabet = "-abcdefghijklmnopqrstuvwxyz";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only lowercase characters(abcdefghijklmnopqrstuvwxyz) - 26 Characters, please wait";  break;
                        case 3 : alphabet = "-ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only uppercase characters(ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 26 Characters, please wait";  break;
                        case 4 : alphabet = "-0123456789abcdefghijklmnopqrstuvwxyz";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyz) - 36 Characters, please wait";  break;
                        case 5 : alphabet = "-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing uppercase characters and numbers(0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 36 Characters, please wait";  break;
                        case 6 : alphabet = "-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase, uppercase characters(abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 52 Characters, please wait";  break;
                        case 7 : alphabet = "-0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase, uppercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 62 Characters, please wait";  break;
                    }
                                for(digit[4]=0;digit[4]<alphabet.length();digit[4]++)
                                    for(digit[3]=0;digit[3]<alphabet.length();digit[3]++)
                                        for(digit[2]=0;digit[2]<alphabet.length();digit[2]++)
                                            for(digit[1]=0;digit[1]<alphabet.length();digit[1]++)
                                                for(digit[0]=1;digit[0]<alphabet.length();digit[0]++){
                                                    attempt++;
                                                    if(attempt%2500000==0) cout << ".";
                                                    test=alphabet[digit[0]];
                                                    for(int i=1;i<passwordLength;i++)
                                                        if(alphabet[digit[i]]!='-')test+=alphabet[digit[i]];
                                                    if(pass.compare(test)==0){end_t = clock(); return test;}
                                                    }
                                                    alphabetSet++;
                    }
                    break;
                case 6:
                    alphabetSet=1;
                    while(alphabetSet<8){
                    switch(alphabetSet){
                        case 1 : alphabet = "-0123456789";
                                 cout << endl << endl <<"Testing only digits(0123456789) - 10 Characters, please wait";  break;
                        case 2 : alphabet = "-abcdefghijklmnopqrstuvwxyz";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only lowercase characters(abcdefghijklmnopqrstuvwxyz) - 26 Characters, please wait";  break;
                        case 3 : alphabet = "-ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only uppercase characters(ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 26 Characters, please wait";  break;
                        case 4 : alphabet = "-0123456789abcdefghijklmnopqrstuvwxyz";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyz) - 36 Characters, please wait";  break;
                        case 5 : alphabet = "-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing uppercase characters and numbers(0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 36 Characters, please wait";  break;
                        case 6 : alphabet = "-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase, uppercase characters(abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 52 Characters, please wait";  break;
                        case 7 : alphabet = "-0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase, uppercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 62 Characters, please wait";  break;
                    }
                            for(digit[5]=0;digit[5]<alphabet.length();digit[5]++)
                                for(digit[4]=0;digit[4]<alphabet.length();digit[4]++)
                                    for(digit[3]=0;digit[3]<alphabet.length();digit[3]++)
                                        for(digit[2]=0;digit[2]<alphabet.length();digit[2]++)
                                            for(digit[1]=0;digit[1]<alphabet.length();digit[1]++)
                                                for(digit[0]=1;digit[0]<alphabet.length();digit[0]++){
                                                    attempt++;
                                                    if(attempt%2500000==0) cout << ".";
                                                    test=alphabet[digit[0]];
                                                    for(int i=1;i<passwordLength;i++)
                                                        if(alphabet[digit[i]]!='-')test+=alphabet[digit[i]];
                                                    if(pass.compare(test)==0){end_t = clock(); return test;}
                                                    }
                                                    alphabetSet++;
                    }
                    break;
                case 7:
                    alphabetSet=1;
                    while(alphabetSet<8){
                    switch(alphabetSet){
                        case 1 : alphabet = "-0123456789";
                                 cout << endl << endl <<"Testing only digits(0123456789) - 10 Characters, please wait";  break;
                        case 2 : alphabet = "-abcdefghijklmnopqrstuvwxyz";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only lowercase characters(abcdefghijklmnopqrstuvwxyz) - 26 Characters, please wait";  break;
                        case 3 : alphabet = "-ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only uppercase characters(ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 26 Characters, please wait";  break;
                        case 4 : alphabet = "-0123456789abcdefghijklmnopqrstuvwxyz";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyz) - 36 Characters, please wait";  break;
                        case 5 : alphabet = "-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing uppercase characters and numbers(0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 36 Characters, please wait";  break;
                        case 6 : alphabet = "-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase, uppercase characters(abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 52 Characters, please wait";  break;
                        case 7 : alphabet = "-0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase, uppercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 62 Characters, please wait";  break;
                    }
                        for(digit[6]=0;digit[6]<alphabet.length();digit[6]++)
                            for(digit[5]=0;digit[5]<alphabet.length();digit[5]++)
                                for(digit[4]=0;digit[4]<alphabet.length();digit[4]++)
                                    for(digit[3]=0;digit[3]<alphabet.length();digit[3]++)
                                        for(digit[2]=0;digit[2]<alphabet.length();digit[2]++)
                                            for(digit[1]=0;digit[1]<alphabet.length();digit[1]++)
                                                for(digit[0]=1;digit[0]<alphabet.length();digit[0]++){
                                                    attempt++;
                                                    if(attempt%2500000==0) cout << ".";
                                                    test=alphabet[digit[0]];
                                                    for(int i=1;i<passwordLength;i++)
                                                        if(alphabet[digit[i]]!='-')test+=alphabet[digit[i]];
                                                    if(pass.compare(test)==0){end_t = clock(); return test;}
                                                    }
                                                    alphabetSet++;
                    }
                    break;
                case 8:
                    alphabetSet=1;
                    while(alphabetSet<8){
                    switch(alphabetSet){
                        case 1 : alphabet = "-0123456789";
                                 cout << endl << endl <<"Testing only digits(0123456789) - 10 Characters, please wait";  break;
                        case 2 : alphabet = "-abcdefghijklmnopqrstuvwxyz";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only lowercase characters(abcdefghijklmnopqrstuvwxyz) - 26 Characters, please wait";  break;
                        case 3 : alphabet = "-ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing only uppercase characters(ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 26 Characters, please wait";  break;
                        case 4 : alphabet = "-0123456789abcdefghijklmnopqrstuvwxyz";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyz) - 36 Characters, please wait";  break;
                        case 5 : alphabet = "-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing uppercase characters and numbers(0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ) - 36 Characters, please wait";  break;
                        case 6 : alphabet = "-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase, uppercase characters(abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 52 Characters, please wait";  break;
                        case 7 : alphabet = "-0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                                 cout << endl << endl << "Couldn't find the password, increasing the searching level."<< endl << endl << "Testing lowercase, uppercase characters and numbers(0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ) - 62 Characters, please wait";  break;
                    }
                    for(digit[7]=0;digit[7]<alphabet.length();digit[7]++)
                        for(digit[6]=0;digit[6]<alphabet.length();digit[6]++)
                            for(digit[5]=0;digit[5]<alphabet.length();digit[5]++)
                                for(digit[4]=0;digit[4]<alphabet.length();digit[4]++)
                                    for(digit[3]=0;digit[3]<alphabet.length();digit[3]++)
                                        for(digit[2]=0;digit[2]<alphabet.length();digit[2]++)
                                            for(digit[1]=0;digit[1]<alphabet.length();digit[1]++)
                                                for(digit[0]=1;digit[0]<alphabet.length();digit[0]++){
                                                    attempt++;
                                                    if(attempt%2500000==0) cout << ".";
                                                    test=alphabet[digit[0]];
                                                    for(int i=1;i<passwordLength;i++)
                                                        if(alphabet[digit[i]]!='-')test+=alphabet[digit[i]];
                                                    if(pass.compare(test)==0){end_t = clock(); return test;}
                                                    }
                                                    alphabetSet++;
                    }
                    break;
            }
            cout  << endl << endl << endl << endl << "*************************************************************" << endl;
            cout  << "*** Password length is not " << passwordLength <<  ". Increasing password length! ***";
            cout  << endl << "*************************************************************" << endl << endl;
            passwordLength++;
    }
 }