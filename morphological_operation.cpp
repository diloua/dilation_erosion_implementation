#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <array>
#include <algorithm>
#include <iterator>
#include <cstring>
using namespace std;

// The 2 functions used for getting min and max from an array

int min_finder(int array[], int size){
    int min;
    min = array[0];
    for(int i=0; i<size; i++){
        if(min>array[i]){
            min=array[i];
        }
    }
    return min;
}
 
int max_finder(int array[], int size){
    int max;
    max = array[0];
    for(int i=0; i<size; i++){
        if(max<array[i]){
            max=array[i];
        }
    }
    return max;
 }

/*  The function used for processing the image, it takes the operation as an argument, it can do both erosion and dilation on both grayscale and binary images. It returns a 2D array.
*/
int** process_image(int** data, int** SE, int size, int se_size, const char* operation){
    int** result = 0;
    result = new int*[size-1]; // allocating memory for the array we are returning

    int data_s[1000]; //this will contain the data that we will be getting min / max from
    int flag;

    int counter=0;
    int counter_saver=0;

/*   The functions takes the whole input data, then on each cell it's going too look for the max or min value on the cells around it that correspond to the structuring element */

    for( int row= 0; row<size; row++) {
        flag = 0;
        result[row] = new int[size+1];

        for (int col= 0; col<size; col++){
            counter=0;
            for (int i= 0; i<se_size; i++){
                if(flag == 1){
                        break;
                }
                for(int j=0; j<se_size; j++){
                    if(row-1+i < 0 || row-1+i > size-1 || col-1+j > size-1 || col-1+j < 0) { //this is used to skip checking the border
                        continue;
                    }

                    else if ( SE[i][j] == 1){ //checking if the cell corresponds to the structuring element
                        data_s[counter] = data[row-1+i][col-1+j]; // writing all the cells that we are processing on an array
                        counter++;
                        counter_saver=counter;
                    }
                }
            }
                if(strcmp(operation, "e") == 0){    
                    result[row][col] = min_finder(data_s, counter_saver); //getting the minimum value from the array and replacing the current cell with that value
                }

                else if(strcmp(operation, "d") == 0){
                    result[row][col] = max_finder(data_s, counter_saver);
                }

         }
     }

    return result;
}

int main(int argc, char** argv){
    
    string line;
    string file_name;
    stringstream data_file_path;
    stringstream se_file_path;
    stringstream output_file_path;
    ifstream data_file;
    ifstream se_file;
    if( argc < 5 ){
        cout << "Not enough arguments"<<endl;
        return -1;
    }
 //File processing
    data_file_path << "/home/user/Desktop/IPHW/input/" << argv[3];
    file_name = data_file_path.str(); 
    data_file.open(file_name);
    if(data_file.is_open() && data_file.good()){
        cout<<file_name<<" opened successfully "<<endl;
    }
    else{
        cout<<"Error with "<< file_name <<endl;
        return 0;
    }
 
    se_file_path << "/home/user/Desktop/IPHW/input/" << argv[2];
    file_name = se_file_path.str();
    se_file.open(file_name);
    if(se_file.is_open() && se_file.good()){
        cout<<file_name<<" opened successfully"<<endl;
    }
    else{
        cout<<"Error with "<< file_name <<endl;
        return 0;
    }
    
    output_file_path << "/home/user/Desktop/IPHW/output/" << argv[4];
    file_name = output_file_path.str();
    ofstream output_file(file_name);
        
    int** se_data;
    int** input_data;

    int** result;
    int** pre_result; //This will be used in case we have an opening operation
    int total_size = 0;
    int total_se_size = 0;
    int flag=0;

    se_data = new int*[2000];
    input_data = new int*[2000];
     for(int row = 0; row < 2000; row++) { // Reading data
        if(flag==1){
            break;
        }
        
        total_size++;
        input_data[row] = new int[2000];
        getline(data_file,line);
        stringstream iss(line);
        for ( int col = 0; col < 2000; col++){
            string val;
            getline(iss, val, ',');
            stringstream convertor(val);
            convertor >> input_data[row][col];
            if( data_file.eof() ){
                flag=1;
                break;
            }
        }

    }

    flag = 0;

    for(int row = 0; row < 2000; row++) {
        if(flag==1){
            break;
        }
        
        total_se_size++;
        se_data[row] = new int[2000];
        getline(se_file,line);
        stringstream iss(line);
        for ( int col = 0; col < 2000; col++){
            string val;
            getline(iss, val, ',');
            stringstream convertor(val);
            convertor >> se_data[row][col];
            if( se_file.eof() ){
                flag=1;
                break;
            }
        }
    }
    if(strcmp(argv[1],"opening")== 0){//if the user inputs "opening" the data will go through an erosion and the result of that will go through the dialation
        pre_result = process_image(input_data, se_data, total_size-1, total_se_size-1, "e");
        result = process_image(pre_result, se_data, total_size-1, total_se_size-1, "d");
    }
    else
        result = process_image(input_data, se_data, total_size-1, total_se_size-1, argv[1]);
    
    for(int row = 0; row<total_size-1; row++){
        for(int col= 0; col<total_size-1; col++){
            if(col == total_size-2)
                output_file << result[row][col];
            else
            output_file << result[row][col]<< ", ";
            }
        output_file<<endl;
        }

    data_file.close();
    se_file.close();
    output_file.close();
    //Freeing allocated space
    for (int i=0; i< total_size-1; i++) {
        delete[] input_data[i];
    }
    delete[] input_data;

    for (int i=0; i< total_se_size-1; i++) {
        delete[] se_data[i];
    }
    delete[] se_data;

	return 0;
}
