/*---------------------------------------------------------
 *  name       : Make text uncompress with Huffman Algoritm(Decode)
 *  date       : th,Dec,26,2019
 *  write by : Reza Tanaki zade
 *---------------------------------------------------------*/

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <fstream>

using namespace std;

//define functions that they are drfine at the end of file
string TextToBinaryString(string words);
int search(string A[4], string value);

//define bin_letter Global Variable
string bin_letter[4] = {"110","110","110","110"};

int main()
{
    int flag;

    //read .bin file
    fstream myfile;
    string binery_file,binery_file1;
    myfile.open("../Huffman/Huffman.bin",ios::in | ios::binary);
    myfile >> binery_file;
    myfile.close();
    binery_file1 = TextToBinaryString(binery_file);
    cout << binery_file1 << endl;
    cout <<  binery_file1.length() << endl;
    
    //find the end of codec array 0,1
    for (int i = binery_file1.length() -1; i >= 0; i--){
        if(binery_file1[i] == '1'){
            flag = i;
            break;
        }
        
    }
    cout << "flag: " << flag << endl;
    
    
    int counter,num_counter = 0;

    //find decode helper from binery
    for(int i = 0; i < flag; i++){
        num_counter = i;
        int flag1 = 0;
        if(binery_file1[i] == '0' && flag1 == 0){
            i++;
            if (binery_file1[i] == '0'){
                bin_letter[counter] = "00";
                counter++;
                
            }
            else if(binery_file1[i] == '1'){
                bin_letter[counter] = "01";
                counter++;
        }flag1=1;}

        if(binery_file1[i] == '1' && flag1 == 0){
           i++;
           if(binery_file1[i] == '0'){
                bin_letter[counter] = "10";
                counter++;
           }else if(binery_file1[i] == '1'){
               i++;
               if(binery_file1[i] == '1'){
                   bin_letter[counter] = "111";
                   counter++;
               }else if(binery_file1[i] == '0'){
                   bin_letter[counter] = "110";
                   counter++;
        }}flag1=1;}

        if(counter == 4){
            break;
        }
       

    }
    
    
    cout << bin_letter[0] << " "<< bin_letter[1] << " "<< bin_letter[2] << " "<< bin_letter[3] << " i " << num_counter <<endl;


    //find number of decode helper 
    int n_bin_letter = 0;
    int flag2 = 0;
    int c = 0;
    while (flag2 == 0)
    {
      if(flag2 == 0){
          n_bin_letter += bin_letter[c].length();
          c++; 
      }
      if(c == 4){
          flag2 = 1;
      }
    }

    cout << "number of dec help 0,1:  " << n_bin_letter << search(bin_letter,"01")<< endl ;
    string text = "";
    string letter[4] = {"a","b","c","d"};

    //Decode all binery flie
    for (int i = (n_bin_letter); i < flag; i++)
    {
        cout<< "i = " << i << endl;
        int flag1 = 0;
        if(binery_file1[i] == '0' && flag1 == 0){
            i++;
            if (binery_file1[i] == '0'){
                text += letter[search(bin_letter,"00")];
                
            }
            else if(binery_file1[i] == '1'){
                text += letter[search(bin_letter,"01")];
                cout << "01" << endl;
        }flag1=1;}

        if(binery_file1[i] == '1' && flag1 == 0){
           i++;
           if(binery_file1[i] == '0'){
                text += letter[search(bin_letter,"10")];
           }else if(binery_file1[i] == '1'){
               i++;
               if(binery_file1[i] == '1'){
                   text += letter[search(bin_letter,"111")];
               }else if(binery_file1[i] == '0'){
                  text += letter[search(bin_letter,"110")];
        }}flag1=1;}

        
        
        
    }

   
    cout << text;
    
    

    


   return 0;
}

//function : Text to Binary String
string TextToBinaryString(string words) {
    string binaryString = "";
    for (char& _char : words) {
        binaryString +=bitset<8>(_char).to_string();
    }
    return binaryString;
}

//function : search in an array
int search(string A[4], string value)
{
	int index = 0;
	while (index < 4 && A[index] != value)
	{
		++index;
	}
	if (index < 4 && A[index] == value)
		return index;
}
