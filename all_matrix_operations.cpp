#include <iostream>

using namespace std;


void printIntroduction();
void printMatrix(signed int** matrix, unsigned int n, unsigned int m);
void printError();
void printDeterminant(signed int** matrix, unsigned int n);



void mainAddition_Subtraction(signed int choice);
void addition(signed int** matrix_1, signed int** matrix_2, signed int** matrix_3, unsigned int n, unsigned int m);
void subtraction(signed int** matrix_1, signed int** matrix_2, signed int** matrix_3, unsigned int n, unsigned int m);



void mainMultiplyByNumber();
void multiplyByNumber(signed int** matrix, unsigned int n, unsigned int m, signed int multiplier, signed int** finalMatrix);



void mainTransposition();
void tranposition(signed int** matrix, unsigned int n, unsigned int m, signed int** finalMatrix);



void mainMultiplication();
void multiplication(signed int** matrix_1, signed int** matrix_2, signed int** finalMatrix, unsigned int n, unsigned int k, unsigned int m);



void mainDeterminant();
signed int determinant(signed int** matrix, unsigned int n);
void enterSubMatrix(signed int** subMatrix, signed int** matrix, unsigned int n, unsigned int indCol);
void deleteMatrix(signed int** matrix, unsigned int n);



void mainEquations();
void equations(signed int** matrix, unsigned int n);
int nullInMassiv(signed int* massiv, unsigned int n);
















int main() {
    printIntroduction();
    signed int numberOfProgram;
    cin >> numberOfProgram;
    int x;
    switch (numberOfProgram) {
    case 1: mainAddition_Subtraction(numberOfProgram); break;
    case 2: mainAddition_Subtraction(numberOfProgram); break;
    case 3: mainMultiplyByNumber();                    break;
    case 4: mainTransposition();                       break;
    case 5: mainMultiplication();                      break;
    case 6: mainDeterminant();                         break;
    case 7: mainEquations();                           break;
    default : printError();
    }

    cin >> x;

    return 0;
}























void mainAddition_Subtraction(signed int choice){
    cout << endl;
    switch (choice) {
    case 1: cout << "�������� ���� ������:" << endl; break;
    case 2: cout << "��������� ���� ������:" << endl;
    }
    unsigned int n, m, i, j;

    cout << "������� ���-�� �����:" << endl << "n=";
    cin >> n;

    cout << "������� ���-�� ��������:" << endl << "m=";
    cin >> m;

    signed int** matrix_1 = new signed int* [n];
    signed int** matrix_2 = new signed int* [n];
    signed int** finalMatrix = new signed int* [n];

    for (i = 0; i < n; i++) {
        matrix_1[i] = new signed int [m];
        matrix_2[i] = new signed int [m];
        finalMatrix[i] = new signed int [m];
    }

    cout << "������� ������ �������:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> matrix_1[i][j];
        }
    }

    cout << "������� ������ �������:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> matrix_2[i][j];
        }
    }

    switch (choice) {
    case 1: addition(matrix_1, matrix_2, finalMatrix, n, m); break;
    case 2: subtraction(matrix_1, matrix_2, finalMatrix, n, m);
    }

    cout << endl << "���� �������:" << endl;

    printMatrix(finalMatrix, n, m);

    deleteMatrix(matrix_1, n);
    deleteMatrix(matrix_2, n);
    deleteMatrix(finalMatrix, n);
}

void addition(signed int** matrix_1, signed int** matrix_2, signed int** finalMatrix, unsigned int n, unsigned int m) {
    unsigned int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            finalMatrix[i][j]  =  matrix_1[i][j]  +  matrix_2[i][j];
        }
    }
}

void subtraction(signed int** matrix_1, signed int** matrix_2, signed int** finalMatrix, unsigned int n, unsigned int m) {
    unsigned int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            finalMatrix[i][j]  =  matrix_1[i][j]  -  matrix_2[i][j];
        }
    }
}






void mainMultiplyByNumber(){
    cout << endl << "��������� ������� �� �����:" << endl;
    unsigned int n, m, i, j;
    signed int multiplier;

    cout << "������� ���-�� ����� �������:" << endl << "n=";
    cin >> n;

    cout << "������� ���-�� �������� �������" << endl << "m=";
    cin >> m;

    cout << "������ �������:" << endl;

    signed int** matrix = new signed int*[n];
    signed int** finalMatrix = new signed int*[n];

    for (i = 0; i < n; i++) {
        matrix[i] = new signed int [m];
        finalMatrix[i] = new signed int [m];
        for (j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "������� �����, �� ������� ���� �������� �������:" << endl;
    cin >> multiplier;

    cout << endl << "���� �������:" << endl;

    multiplyByNumber(matrix, n, m, multiplier, finalMatrix);

    printMatrix(finalMatrix, n, m);
}

void multiplyByNumber(signed int** matrix, unsigned int n, unsigned int m, signed int multiplier, signed int** finalMatrix) {
    unsigned int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            finalMatrix[i][j] = matrix[i][j] * multiplier;
        }
    }
}






void mainTransposition(){
    cout << endl << "���������������� �������:" << endl;
    unsigned int n, m, i, j;

    cout << "������� ���-�� ����� �������:" << endl << "n=";
    cin >> n;

    cout << "������� ���-�� �������� �������" << endl << "m=";
    cin >> m;

    signed int** matrix = new signed int* [n];

    signed int** finalMatrix = new signed int* [m];
    for (i = 0; i < m; i++) {
        finalMatrix[i] = new signed int [n];
    }

    cout << "������� �������:" << endl;

    for (i = 0; i < n; i++) {
        matrix[i] = new signed int [m];
        for (j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    tranposition(matrix, n, m, finalMatrix);

    cout << "���� �������:" << endl;
    printMatrix(finalMatrix, m, n);
}

void tranposition(signed int** matrix, unsigned int n, unsigned int m, signed int** finalMatrix) {
    unsigned int i, j;

    for (j = 0; j < n; j++) {
        for (i = 0; i < m; i++) {
            finalMatrix[i][j] = matrix[j][i];
        }
    }
}






void mainMultiplication(){
    cout << endl << "��������� ���� ������:" << endl;

    unsigned int n, k, m, i, j;

    cout << "������� ���-�� ����� ������ �������:" << endl << "n=";
    cin >> n;

    cout << "������� ���-�� �������� ������ � ����� ������ ������:" << endl << "k=";
    cin >> k;

    cout << "������� ���-�� �������� ������ �������:" << endl << "m=";
    cin >> m;

    signed int** matrix_1 = new signed int* [n];
    signed int** matrix_2 = new signed int* [k];
    signed int** finalMatrix = new signed int* [n];

    for (i = 0; i < n; i++) {
        finalMatrix[i] = new signed int [m];
    }


    cout << "������� ������ �������:" << endl;
    for (i = 0; i < n; i++) {
        matrix_1[i] = new signed int [k];
        for (j = 0; j < k; j++) {
            cin >> matrix_1[i][j];
        }
    }


    cout << "������� ������ �������:" << endl;
    for (i = 0; i < k; i++) {
        matrix_2[i] = new signed int [m];
        for (j = 0; j < m; j++) {
            cin >> matrix_2[i][j];
        }
    }


    multiplication(matrix_1, matrix_2, finalMatrix, n, k, m);

    cout << "���� �������:" << endl;
    printMatrix(finalMatrix, n, m);

}

void multiplication(signed int** matrix_1, signed int** matrix_2, signed int** finalMatrix, unsigned int n, unsigned int k, unsigned int m) {
    unsigned int i, j;
    unsigned int numberOfElement, totalizer;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            finalMatrix[i][j] = 0;
            for (numberOfElement = 0; numberOfElement < k; numberOfElement++) {
                finalMatrix[i][j]  =  finalMatrix[i][j]  +  (matrix_1[i][numberOfElement] * matrix_2[numberOfElement][j]);
            }
        }
    }
}






void mainDeterminant(){
    cout << endl << "���������� ������������:" << endl;
    unsigned int i, j;
    unsigned int n;

    cout << "������� ���-�� ����� �������� �������:" << endl << "n=";
    cin >> n;

    signed int** matrix = new signed int* [n];

    cout << "������� �������:" << endl;

    for (i = 0; i < n; i++) {
        matrix[i] = new signed int [n];
        for (j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    printDeterminant(matrix, n);
}

signed int determinant(signed int** matrix, unsigned int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    else {
        unsigned int j;
        signed int sign = 1, sum = 0;

        for (j = 0; j < n; j++) {
            signed int** newMatrix = new signed int* [n - 1];
            enterSubMatrix(newMatrix, matrix, n, j);
            sum += sign * matrix[0][j] * determinant(newMatrix, n - 1);
            deleteMatrix(newMatrix, n - 1);
            sign = -sign;
        }
        return sum;
    }
}

void enterSubMatrix(signed int** subMatrix, signed int** matrix, unsigned int n, unsigned int indCol) {
    unsigned int i, j;

    for (i = 1; i < n; i++) {
        subMatrix[i - 1] = new signed int [n - 1];
        for (j = 0; j < indCol; j++) {
            subMatrix[i - 1][j] = matrix[i][j];
        }
        for (j = indCol + 1; j < n; j++) {
            subMatrix[i - 1][j - 1] = matrix[i][j];
        }
    }
}

void deleteMatrix(signed int** matrix, unsigned int n) {
    unsigned int i;

    for (i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}






void mainEquations(){
    cout << endl << "���������� ������ ������� �������� ���������:" << endl;
    unsigned int n;
    unsigned int i, j;


    cout << "������� ���-�� ����������:" << endl << "n=";
    cin >> n;

    signed int** matrix = new signed int* [n];

    cout << "������� �������:" << endl;
    for (i = 0; i < n; i++) {
        matrix[i] = new signed int [n + 1];
        for (j = 0; j < n + 1; j++) {
            cin >> matrix[i][j];
        }
    }
    equations(matrix, n);
}

void equations(signed int** matrix, unsigned int n) {
    unsigned int i, j, I;

    signed int* determinants = new signed int[n];
    signed int** matrixWithoutB = new signed int*[n];

    for (i = 0; i < n; i++) { ///���������� ������� ��� ���������� �������
        matrixWithoutB[i] = new int[n];
    }

    for (i = 0; i < n; i++) { ///"����" ������� ��� ���������� �������
        for (j = 0; j < n; j++) {
            matrixWithoutB[i][j] = matrix[i][j];
        }
    }

    signed int determinantOfBigMatrix  =  determinant(matrixWithoutB, n);
    if (determinantOfBigMatrix == 0) {///�������� �� ��, ��� ����������� ����� ����
        int flag_1 = 0;
    }

    for (i = 0; i < n; i++) { ///�������� ������� ��� ���������� �������
        delete[] matrixWithoutB[i];
    }
    delete[] matrixWithoutB;


    int** temporaryMatrix = new signed int*[n];
    for (i = 0; i < n; i++) {
        temporaryMatrix[i] = new signed int[n];
    }

    for (I = 0; I < n; I++) { ///������� ������������ ��� ������ ����������
        for (j = 0; j < I; j++) {
            for (i = 0; i < n; i++) {
                temporaryMatrix[i][j] = matrix[i][j];
            }
        }
        for (i = 0; i < n; i++) {
            temporaryMatrix[i][j] = matrix[i][n];
        }
        for (j = I + 1; j < n; j++) {
            for (i = 0; i < n; i++) {
                temporaryMatrix[i][j] = matrix[i][j];
            }
        }
        determinants[I] = determinant(temporaryMatrix, n);
    }

    deleteMatrix(temporaryMatrix, n);

    if (determinantOfBigMatrix  !=  0) {///��������� ������� � �������
        for (i = 0; i < n; i++) {
            cout << "X_" <<  i + 1 << "= " << determinants[i] / determinantOfBigMatrix << endl;
        }
    }
    else {
        if (nullInMassiv(determinants, n) == 0    &&    determinantOfBigMatrix  ==  0) {
            cout << "������ ���������" << endl;
        }
        else {
            if (nullInMassiv(determinants, n)  == n    &&    determinantOfBigMatrix  ==  0) {
                cout << "���������� ����� �������" << endl;
            }
        }
    }

}

int nullInMassiv(signed int* array, unsigned int n) {///���������, ������� ��������� � ������ ������� � ������ �������� ����� ����
    unsigned int i, counter = 0;

    for (i = 0; i < n; i++) {
        if (array[i] == 0) {
            counter += 1;
        }
    }
    return counter;
}






void printIntroduction() {
    setlocale(LC_ALL, "Russian");
    cout << "1. �������� ���� ������" << endl;
    cout << "2. ��������� ���� ������" << endl;
    cout << "3. ��������� ������� �� �����" << endl;
    cout << "4. ���������������� �������" << endl;
    cout << "5. ��������� ���� ������" << endl;
    cout << "6. ������������ �������" << endl;
    cout << "7. ����� ������� �������� ���������" << endl << endl;
    cout << "�������� ����� ��������:";
}

void printMatrix(signed int** matrix, unsigned int n, unsigned int m) {
    unsigned int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printError() {
    cout << "�� ��������" << endl;
}

void printDeterminant(signed int** matrix, unsigned int n){
    cout << "����������� ������� = " << determinant(matrix, n);
}



