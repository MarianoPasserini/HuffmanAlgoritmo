using namespace std;
#include <iostream>
#include <string>

int length(string s){
   int i = 0;
   while(s[i] != '\0'){
      i++;
   }
   return i;
}

int charCount(string s,char c){
   int n = length(s);
   int cont = 0;
   for (int i = 0; i<n; i++){
      if (s[i] == c){
         cont++;
      }
   }
   return cont;
}

string substring(string s,int d,int h){
   string subcadena = "";
   for(;d<h;d++){
      subcadena = subcadena + s[d];
   }
   return subcadena;
}

string substring(string s,int d){
   string subcadena = "";
   while(s[d]!= '\0'){
      subcadena = subcadena + s[d];
      d++;
   }
   return subcadena;
}

int indexOf(string s,char c){
   int i = 0;
   while(s[i] != c){
      i++;
      if(i>length(s)){
         i=-1;
         break;
      }
   }

   return i;
}

int indexOf(string s,char c,int offset){
   bool flag = true;
   int i = offset;
   for(;i<length(s);i++){
      if(s[i]==c){
         flag = true;
         break;
      }
      else {
         flag = false;
      }
   }
   if(flag == false){
      i = -1;
   }
   return i;
}
int indexOf(string s,string toSearch){
   int index = -1;
   for(int i = 0;i<length(s);i++){
      if(toSearch[0]==s[i]){
         int k = i;
         int j = 0;
         while ((s[k]==toSearch[j]) && (j<length(toSearch))){
            j++;
            k++;
         }
         if (j==length(toSearch)){
            index = i;
            break;
         }
      }
   }
   return index;
}

int indexOf(string s,string toSearch,int offset){
   int index = -1;
   for(int i = offset;i<length(s);i++){
      if(toSearch[0]==s[i]){
         int k = i;
         int j = 0;
         while ((s[k]==toSearch[j]) && (j<length(toSearch))){
            j++;
            k++;
         }
         if (j==length(toSearch)){
            index = i;
            break;
         }
      }
   }
   return index;
}

int lastIndexOf(string s,char c){
   int index = -1;
   for (int i = 0; i<length(s); i++){
      if (s[i]==c){
         index = i;
      }
   }
   return index;
}

int indexOfN(string s,char c,int n){
   int index;
   int cont = 0;
   bool flag = false;
   for(int i=0; i<length(s);i++){
       if(s[i]==c){
          index = i;
          cont++;
       }
       if(cont==n){
          flag = true;
          break;
       }
    }
   if (flag == false){
      index = length(s);
   }

   return index;
}

int charToInt(char c){return (int(c)- 48);}

string stringToString(string s) { return s; }
