#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//Substitution simple
//Substitución para encriptar
unordered_map<char, char> substitutionABox = {
  {'A', 'R'},
  {'B', 'X'},
  {'C', 'M'},
  {'D', 'O'},
  {'E', 'T'},
  {'F', 'P'},
  {'G', 'Q'},
  {'H', 'Y'},
  {'I', 'N'},
  {'J', 'U'},
  {'K', 'V'},
  {'L', 'W'},
  {'M', 'A'},
  {'N', 'C'},
  {'O', 'D'},
  {'P', 'F'},
  {'Q', 'G'},
  {'R', 'H'},
  {'S', 'Z'},
  {'T', 'E'},
  {'U', 'J'},
  {'V', 'K'},
  {'W', 'L'},
  {'X', 'B'},
  {'Y', 'I'},
  {'Z', 'S'},

  {'r', 'a'}, 
  {'x', 'b'}, 
  {'m', 'c'}, 
  {'o', 'd'}, 
  {'t', 'e'}, 
  {'p', 'f'},
  {'q', 'g'}, 
  {'y', 'h'}, 
  {'n', 'i'}, 
  {'u', 'j'}, 
  {'v', 'k'}, 
  {'w', 'l'}, 
  {'a', 'm'}, 
  {'c', 'n'}, 
  {'d', 'o'}, 
  {'f', 'p'},
  {'g', 'q'},
  {'h', 'r'}, 
  {'s', 'z'}, 
  {'e', 't'},
  {'j', 'u'}, 
  {'k', 'v'},
  {'l', 'w'}, 
  {'b', 'x'}, 
  {'i', 'y'}, 
  {'s', 'z'},

  {'0', '7'},
  {'1', '3'},
  {'2', '9'},
  {'3', '6'},
  {'4', '8'},
  {'5', '0'},
  {'6', '4'},
  {'7', '5'},
  {'8', '2'},
  {'9', '1'}
};
//Substitución para desencriptar
unordered_map<char, char> substitutionBBox = {
  {'R', 'A'}, 
  {'X', 'B'}, 
  {'M', 'C'}, 
  {'O', 'D'}, 
  {'T', 'E'}, 
  {'P', 'F'}, 
  {'Q', 'G'}, 
  {'Y', 'H'}, 
  {'N', 'I'}, 
  {'U', 'J'}, 
  {'V', 'K'}, 
  {'W', 'L'}, 
  {'A', 'M'}, 
  {'C', 'N'}, 
  {'D', 'O'}, 
  {'F', 'P'}, 
  {'G', 'Q'}, 
  {'H', 'R'}, 
  {'Z', 'S'}, 
  {'E', 'T'}, 
  {'J', 'U'}, 
  {'K', 'V'}, 
  {'L', 'W'}, 
  {'B', 'X'}, 
  {'I', 'Y'}, 
  {'S', 'Z'},

  {'a', 'r'},
  {'b', 'x'},
  {'c', 'm'},
  {'d', 'o'},
  {'e', 't'},
  {'f', 'p'},
  {'g', 'q'},
  {'h', 'y'},
  {'i', 'n'},
  {'j', 'u'},
  {'k', 'v'},
  {'l', 'w'},
  {'m', 'a'},
  {'n', 'c'},
  {'o', 'd'},
  {'p', 'f'},
  {'q', 'g'},
  {'r', 'h'},
  {'s', 'z'},
  {'t', 'e'},
  {'u', 'j'},
  {'v', 'k'},
  {'w', 'l'},
  {'x', 'b'},
  {'y', 'i'},
  {'z', 's'},

  {'7', '0'},
  {'3', '1'},
  {'9', '2'},
  {'6', '3'},
  {'8', '4'},
  {'0', '5'},
  {'4', '6'},
  {'5', '7'},
  {'2', '8'},
  {'1', '9'}

};

// Function to perform substitution, 0 encriptar 1 desencriptar
string substitute(const string& plaintext, int num) {
  string ciphertext = "";

  if(num == 0){//Num 0 = cypher, else decypher
    for (char ch : plaintext) {
        // Check if the character is in the substitution S-box
        if (substitutionABox.find(ch) != substitutionABox.end()) {
            // Character exists in the S-box, perform substitution
            char substituted_char = substitutionABox[ch];
            ciphertext += substituted_char;
        } else {
            // Character not found in the S-box, leave it unchanged
            ciphertext += ch;
        }
    }
  }else{
    for (char ch : plaintext) {
        // Check if the character is in the substitution S-box
        if (substitutionBBox.find(ch) != substitutionBBox.end()) {
            // Character exists in the S-box, perform substitution
            char substituted_char = substitutionBBox[ch];
            ciphertext += substituted_char;
        } else {
            // Character not found in the S-box, leave it unchanged
            ciphertext += ch;
        }
    }
  }

    return ciphertext;
}

//Permutation
//Rotar a la izquierda
string leftRotate(const string& input, int shiftAmount) {
    string rotated = input;
    for (int i = 0; i < shiftAmount; ++i) {
        char temp = rotated[0];
        for (int j = 0; j < rotated.length() - 1; ++j) {
            rotated[j] = rotated[j + 1];
        }
        rotated[rotated.length() - 1] = temp;
    }
    return rotated;
}

// Rotar a la derecha
string rightRotate(const string& input, int shiftAmount) {
    string rotated = input;
    for (int i = 0; i < shiftAmount; ++i) {
        char temp = rotated[rotated.length() - 1];
        for (int j = rotated.length() - 1; j > 0; --j) {
            rotated[j] = rotated[j - 1];
        }
        rotated[0] = temp;
    }
    return rotated;
}

//XOR, funcinoa para encriptar y desencriptar
string encrypt(string plaintext, string key) {
    string ciphertext = "";
    
    // Asegurarse de que la clave tenga la misma longitud que el texto en claro
    while (key.length() < plaintext.length()) {
        key += key; // Repetir la clave si es más corta
    }

    // Aplicar la operación XOR y filtrar caracteres no deseados
    for (size_t i = 0; i < plaintext.length(); ++i) {
        char encrypted_char = plaintext[i] ^ key[i];
        
        // Filtrar caracteres no deseados (solo letras y números)
        if (isalnum(encrypted_char)) {
            ciphertext += encrypted_char;
        }else{
          ciphertext += plaintext[i];
        }
    }
    
    return ciphertext;
}

//Rotation
string caesarCipherEncrypt(const string& message, int key) {
    string encryptedMessage = "";

    for (char character : message) {
        if (isalpha(character)) {
            char base = islower(character) ? 'a' : 'A';
            char encryptedChar = static_cast<char>((character - base + key + 26) % 26 + base);
            encryptedMessage += encryptedChar;
        } else if (isdigit(character)) {
            // For numbers, shift them by the key positions
            char encryptedChar = static_cast<char>((character - '0' + key + 10) % 10 + '0');
            encryptedMessage += encryptedChar;
        } else {
            // If the character is not a letter or a number, keep it unchanged
            encryptedMessage += character;
        }
    }

    return encryptedMessage;
}

// Function to decrypt a Caesar cipher message
string caesarCipherDecrypt(const string& ciphertext, int key) {
    // Decryption is the same as encryption but with a negative key
    return caesarCipherEncrypt(ciphertext, -key);
}


//Funcion para cambiar de hexadecimal a decimal
string Hadecimal(string hexadecimal){
  int decimal = 0;
  int base = 16;

  for (int i = 0; i < hexadecimal.length(); i++) {
    char c = hexadecimal[i];
    int digit;

    if (isdigit(c)) {
      digit = c - '0'; // Si es un dígito, convertirlo a entero
      } else {
        // Si es una letra (A-F), convertirla a entero
        c = toupper(c);
        digit = 10 + (c - 'A');
      }

        decimal += digit * pow(base, hexadecimal.length() - i - 1);
  }

  //hacerlo string para que funcione
    return to_string(decimal);
}

//0 para encriptar, 1 para desencriptar
string algorithm(string message, string key, bool operation, bool decimal){
  
  //cout<<"Mensaje : "<<message<<"."<<endl;
  if(!decimal){
    key = Hadecimal(key); 
   // cout<<"No decimal : "<<key<<endl;
  }
  string ans ="";
//  cout<<key[0]<<endl;
  int intkey = key[0]-48;
  
//  cout<<"Int key:"<<intkey<<endl;
    
    for(int i = 0; i<2;i++){
      //cout<<i<<endl;
      if(operation == true){   

       string ceasar = caesarCipherEncrypt(message,intkey);
       // cout<<"Ceasar :"<<ceasar<<"."<<endl;
          
  
        string leftShifted = leftRotate(ceasar, key[0]);
        //  cout<<"Left : "<<leftShifted<<"."<<endl;
        
    
      string ciphertext = substitute(leftShifted,0);
       // cout<<"Cypher : "<<ciphertext<<"."<<endl;
  
    
      string xors = encrypt(ciphertext, key);
        //  cout<<"XORS : "<<xors<<"."<<endl;
        
      string rightShifted = rightRotate(xors, key[-1]);
        //  cout<<"Right :"<<rightShifted<<endl;

               message = rightShifted;

    }else{
   string leftShifted = leftRotate(message, key[-1]);
       // cout<<"Left : "<<leftShifted<<endl;
        
      string xors = encrypt(leftShifted, key);
       //  cout<<"XORS : "<<xors<<"."<<endl;
              
      string plainText = substitute(xors,1);
     // cout<<"Answer : "<<plainText<<"."<<endl;
  
      string rightShifted = rightRotate(plainText, key[0]);
       // cout<<"Right :"<<rightShifted<<endl;

      string ceasar =  caesarCipherDecrypt(rightShifted, intkey);
    // cout<<"Ceasar :"<<ceasar<<endl;
        
       message = ceasar;
    }
  }
  return message;
}

int main() {
  string message = "Hace mucho tiempo siento la soledad 12 dias 3 meses o 84 años talves";
  string messageA ="MzVS 27 akSG 9 yaGMf I 14 Vñuj STCyMfLTlP wbbNu gdyaKI GkazQy RS jyF";
  string key ="FA";
  
  bool decimal = false;

  //mensaje, key, encriptar/desencriptar, si es decimal la key
  string ans = algorithm(message, key,true,decimal);
  cout<<"Ciphertext:"<<endl;
  cout<<ans<<endl;
  cout<<endl;
  
  string ans2 = algorithm(ans, key,false,decimal);
  cout<<"Encrypted and decrypted input text:"<<endl;
  cout<<ans2<<endl;
  cout<<endl;
  
  string ans3 = algorithm(messageA, key,false,decimal);
  cout<<"Texto decifrado:"<<endl;
  cout<<ans3<<endl;
  
  return 0;

  //Outputs:
  /*
  Ciphertext:
  MzVS 27 akSG 9 yaGMf I 14 Vñuj STCyMfLTlP wbbNu gdMwKI GkazQy RS jyF

  Encrypted and decrypted input text:
  Hace mucho tiempo siento la soledad 12 dias 3 meses o 84 años talves

  Texto decifrado:
  Hace mucho timepo siento la soledad 12 dias 3 meses o 84 años talves
  */
}