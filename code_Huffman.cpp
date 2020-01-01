/*---------------------------------------------------------
 *  name       : Make Binery Compress with Huffman Algoritm(Coded)
 *  date       : th,Dec,26,2019
 *  write by : Reza Tanaki zade
 *---------------------------------------------------------*/

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <fstream>

using namespace std;

//Redefine Functions;
void findNumberOfEachLetter();
int returnNumberOfLetter(string test,const char letter);



//Global Variables;
      string text = "";                                         //Text that we must to Compress it;
      char letter[] = {'a','b','c','d'};                        //All the english letter;
      int n_letter[4];                                          //number of each letter;
      string bin[4] = {"00","01","10","111"};                   //the binery code for most and least repeated words;
      string bin_letter[4] = {"110","110","110","110"};     //binery Code with its defualt;
      string tobineryletter = "";                               //binery code of text fine;

//main Function;
int main(){ 

      //read TEXT fine that we need to compressed
      fstream myfile1;
      myfile1.open ("text.txt");
      myfile1 >> text;
      myfile1.close();


      //find number of each letter by this function that defined after main function ;
      findNumberOfEachLetter();    
   
      //this variable and loop seved max repeated letter;
      int max[2] = {n_letter[0],0};
       for (int i = 1; i < 4; i++){
         if (n_letter[i] > max[0]){
            max[0] = n_letter[i];
            max[1] = i;
       }}
      
      //print max
      cout << "MAX OF ARRAY is : " << max[0] << "  and ID is : " << max[1] << endl;

      //find best binery code for each letter;
      int b = 0;
      for(int c = 0; c < max[0]; c++){
         for(int i = 0; i < 4; i++){
              if(n_letter[i] == (max[0]-c)){
                 bin_letter[i] = bin[b];
                 b++;
                 cout << i <<"     " << letter[i] << " " << bin_letter[i] << endl;
      }}}


      //last binery code with decode Help
      for(int i = 0; i < 4; i++){
         tobineryletter += bin_letter[i];
      }
      
      //fine binery code for the text;
      for(int i = 0; i < text.length(); i++){
      char l = text[i];
      for(int b = 0; b < 4; b++){
         if(l == letter[b]){
            tobineryletter += bin_letter[b];
            
      }}}

      
      
      tobineryletter += "10000000";
      cout << tobineryletter << endl;
      cout << text <<endl;

      //make programm for save to Huffman.bin
      fstream myfile;
    
      string data = tobineryletter;
      stringstream sstream(data);
      string output;
      
      while(sstream.good()){
         bitset<8> bits;
         sstream >> bits;
         char c = char(bits.to_ulong());
         output += c;
      }
      
      myfile.open ("Huffman.bin",ios::out | ios::binary);
      myfile << output;
      myfile.close();


return 0;
}


//this Function find repreated number of each letter ;
int returnNumberOfLetter(string test,const char letter){
    int count = 0;
    int l_number =  test.length();
    for (int i = 0; i < l_number; i++)
    {
       if (test[i] == letter)
        count++;
    }
   
   return count;
}

//this function  saved repeated number of each letter in n_letter array;
void findNumberOfEachLetter(){
   for (int i = 0; i < sizeof(letter); i++){
         n_letter[i] = returnNumberOfLetter(text,letter[i]);
         cout << n_letter[i] << endl;
      }
}
