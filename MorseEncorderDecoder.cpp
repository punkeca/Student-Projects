/*
DEVELOPER: Patricia Brenny Ribeiro
Engenharia de Computação - IESTI
UNIVERSIDADE FEDERAL DE ITAJUBÁ - Itajubá, MG.
*/
#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

int find(string,  array<string,36>);

int main() {
    // Write C++ code here
    string alphabet {"abcdefghijklmnopqrstuvwxyz123456789?"};
    array<string,36> morseCode{  
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
        "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
        "..-","...-",".--","-..-","-.--","--..","-----",".----",
        "..---","...--","....-",".....","-....","--...","---..","----."
    };//Ideal structure would be a map, however array was chosen as initial solutior to encode due to back-and-fourth decryption.
	
    string original{};
    string encrypted{};
    string decrypted{};
    
    cout << "Type original message: ";
    getline(cin,original);
    
    cout << "Morse code message: ";
    for(auto &x : original){ //refence to change the actual variables in the vector.
        x = tolower(x); //Guarantees there wont be any capitals to be treated and simpifies solution.
        if(x == ' ')
            encrypted += " ";
        else if (alphabet.find(x)!= string::npos){
            encrypted += morseCode[alphabet.find(x)];
        }else{encrypted += "?" ;}
        encrypted += " " ;
    }//end for
    cout << encrypted << endl;
    
    string word{};
    for( unsigned int i=0; i <= encrypted.length() ; i++) {
        if( encrypted[i] == '.' ){
            word += "." ;
        }//end if
        else if( encrypted[i] == '-' ){
            word += "-";
        }//end if
        else if(encrypted[i] == ' ' && encrypted[i+1]== ' ' && encrypted[i+2]== ' '){ // its a new word
            decrypted += alphabet[find(word, morseCode)]; //find function was implemented.
            decrypted += " " ;
            word.clear();
            continue;
            }//end if
        else if(encrypted[i] == ' ' && encrypted[i-1]!=' '){ // its a new morse char
            decrypted += alphabet[find(word, morseCode)];
            word.clear();
        }//end else
    }//end for
    //decrypted += alphabet[find(word, morseCode)];
    cout << "Decrypted message: " << decrypted << endl;
    return 0;
}//end main

int find(string element,  array<string,36> arr) {
	for(int i=0;i<arr.size();i++){
	    //cout << element <<endl;
		if(arr[i] == element)
			return i;
	}//end for
return 35; //equals ?
}//end find
