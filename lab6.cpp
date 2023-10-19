#include <iostream>
#include <fstream>

using namespace std;

//Globals
const int maxSize = 100;

void print_matrix(int A[maxSize][maxSize], int size){
    for (int i =0; i<size;i++){
        for (int j = 0;j<size;j++){
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void add_matrix(int A[maxSize][maxSize], int B[maxSize][maxSize], int size){
    int C[maxSize][maxSize];
    for (int i =0; i<size;i++){
        for (int j = 0;j<size;j++){
            C[i][j] = A[i][j]+B[i][j];
        }
    }
    print_matrix(C, size);
}

void subtract_matrix(int A[maxSize][maxSize], int B[maxSize][maxSize], int size){
    int C[maxSize][maxSize];
    for (int i =0; i<size;i++){
        for (int j = 0;j<size;j++){
            C[i][j] = A[i][j]-B[i][j];
        }
    }
    print_matrix(C, size);
}

void multiply_matrix(int A[maxSize][maxSize], int B[maxSize][maxSize], int size){
    int C[maxSize][maxSize];
    for (int i =0; i<size;i++){
        for (int j = 0;j<size;j++){
            C[i][j] = 0;
            for (int k = 0; k<size;k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    print_matrix(C, size);
}

int main(){
    string line;
    int size;
    int A[maxSize][maxSize], B[maxSize][maxSize];
    

    ifstream inFile("matrix_input.txt");
    if (inFile.is_open()){
        int num;
        getline(inFile, line);
        size = stoi(line);
        size = (size>maxSize) ? maxSize : size;
    

        for (int i = 0;i<size*size; i++) {
            inFile >> num;
            A[i/size][i%size] = num;
        }
        for (int j=0; j<(size*size); j++){
            inFile >> num;
            B[j/size][j%size] = num;
        }
    }else{
        cout << "File did not open" << endl;
        return 0;
    }
    inFile.close();

    print_matrix(A, size);
    add_matrix(A,B,size);
    multiply_matrix(A,B,size);
    subtract_matrix(A,B,size);
    
    return 0;
}