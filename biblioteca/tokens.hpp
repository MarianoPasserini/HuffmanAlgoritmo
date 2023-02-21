#include <iostream>
using namespace std;
#include "arrays.hpp"
#include "strings.hpp"
#include "coll.hpp"

int tokenCount(string s,char sep){
   int cont = 1;
   if (length(s)>0){
      for(int i = 0; i<length(s); i++){
         if (s[i]==sep){
            cont++;
         }
      }
   } else {
      cont = 0;
   }
   return cont;
}

void addToken(string& s,char sep,string t){
   if (length(s)==0){
      s = t;
   } else {
      s = s + sep + t;
   }
}

string getTokenAt(string s,char sep,int pos){
   string x = "";
   int cont = 0;
   for(int i=0;i<length(s);i++){
      if (s[i] == sep){
         cont++;
         continue;
      }
      if(pos == cont){
         x += s[i];
      }
   }
   return x;
}

void removeTokenAt(string& s,char sep,int i){
    string subcadena = "";
    int cont = 0;
    for(int j=0;j<length(s);j++){
        if (s[j] == sep){
            cont++;
        }
        if(i != cont){
            subcadena += s[j];
        }
    }
    s = subcadena;
}

void setTokenAt(string& s,char sep,string t,int i){
   string subcadena = "";
         bool replaced = false;
         int cont = 0;
         for(int j=0;j<length(s);j++){
            if (s[j] == sep){
               cont++;
            }
            if(i == cont && replaced == false){
               addToken(subcadena,sep,t);
               replaced = true;
               removeTokenAt(s,sep,i);
               subcadena += sep;
               continue;
            } else {
               subcadena += s[j];
            }

            }
         s="";
         s=subcadena;
}
