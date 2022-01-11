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
    case 1: cout << "Сложение двух матриц:" << endl; break;
    case 2: cout << "Вычитание двух матриц:" << endl;
    }
    unsigned int n, m, i, j;

    cout << "Введите кол-во строк:" << endl << "n=";
    cin >> n;

    cout << "Введите кол-во столбцов:" << endl << "m=";
    cin >> m;

    signed int** matrix_1 = new signed int* [n];
    signed int** matrix_2 = new signed int* [n];
    signed int** finalMatrix = new signed int* [n];

    for (i = 0; i < n; i++) {
        matrix_1[i] = new signed int [m];
        matrix_2[i] = new signed int [m];
        finalMatrix[i] = new signed int [m];
    }

    cout << "Введите первую матрицу:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> matrix_1[i][j];
        }
    }

    cout << "Введите вторую матрицу:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> matrix_2[i][j];
        }
    }

    switch (choice) {
    case 1: addition(matrix_1, matrix_2, finalMatrix, n, m); break;
    case 2: subtraction(matrix_1, matrix_2, finalMatrix, n, m);
    }

    cout << endl << "Ваша матрица:" << endl;

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
    cout << endl << "Умножение матрицы на число:" << endl;
    unsigned int n, m, i, j;
    signed int multiplier;

    cout << "Введите кол-во строк матрицы:" << endl << "n=";
    cin >> n;

    cout << "Введите кол-во столбцов матрицы" << endl << "m=";
    cin >> m;

    cout << "Введие матрицу:" << endl;

    signed int** matrix = new signed int*[n];
    signed int** finalMatrix = new signed int*[n];

    for (i = 0; i < n; i++) {
        matrix[i] = new signed int [m];
        finalMatrix[i] = new signed int [m];
        for (j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Введите число, на которое надо умножить матрицу:" << endl;
    cin >> multiplier;

    cout << endl << "Ваша матрица:" << endl;

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
    cout << endl << "Транспонирование матрицы:" << endl;
    unsigned int n, m, i, j;

    cout << "Введите кол-во строк матрицы:" << endl << "n=";
    cin >> n;

    cout << "Введите кол-во столбцов матрицы" << endl << "m=";
    cin >> m;

    signed int** matrix = new signed int* [n];

    signed int** finalMatrix = new signed int* [m];
    for (i = 0; i < m; i++) {
        finalMatrix[i] = new signed int [n];
    }

    cout << "Введите матрицу:" << endl;

    for (i = 0; i < n; i++) {
        matrix[i] = new signed int [m];
        for (j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    tranposition(matrix, n, m, finalMatrix);

    cout << "Ваша матрица:" << endl;
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
    cout << endl << "Умножение двух матриц:" << endl;

    unsigned int n, k, m, i, j;

    cout << "Введите кол-во строк первой матрицы:" << endl << "n=";
    cin >> n;

    cout << "Введите кол-во столбцов первой и строк второй матриц:" << endl << "k=";
    cin >> k;

    cout << "Введите кол-во столбцов второй матрицы:" << endl << "m=";
    cin >> m;

    signed int** matrix_1 = new signed int* [n];
    signed int** matrix_2 = new signed int* [k];
    signed int** finalMatrix = new signed int* [n];

    for (i = 0; i < n; i++) {
        finalMatrix[i] = new signed int [m];
    }


    cout << "Введите первую матрицу:" << endl;
    for (i = 0; i < n; i++) {
        matrix_1[i] = new signed int [k];
        for (j = 0; j < k; j++) {
            cin >> matrix_1[i][j];
        }
    }


    cout << "Введите вторую матрицу:" << endl;
    for (i = 0; i < k; i++) {
        matrix_2[i] = new signed int [m];
        for (j = 0; j < m; j++) {
            cin >> matrix_2[i][j];
        }
    }


    multiplication(matrix_1, matrix_2, finalMatrix, n, k, m);

    cout << "Ваша матрица:" << endl;
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
    cout << endl << "Вычисление определителя:" << endl;
    unsigned int i, j;
    unsigned int n;

    cout << "Введите кол-во строк столбцов матрицы:" << endl << "n=";
    cin >> n;

    signed int** matrix = new signed int* [n];

    cout << "Введите матрицу:" << endl;

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
    cout << endl << "Вычисление корней системы линейных уравнений:" << endl;
    unsigned int n;
    unsigned int i, j;


    cout << "Введите кол-во переменных:" << endl << "n=";
    cin >> n;

    signed int** matrix = new signed int* [n];

    cout << "Введите матрицу:" << endl;
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

    for (i = 0; i < n; i++) { ///Объявление матрицы без последнего столбца
        matrixWithoutB[i] = new int[n];
    }

    for (i = 0; i < n; i++) { ///"Ввод" матрицы без последнего столбца
        for (j = 0; j < n; j++) {
            matrixWithoutB[i][j] = matrix[i][j];
        }
    }

    signed int determinantOfBigMatrix  =  determinant(matrixWithoutB, n);
    if (determinantOfBigMatrix == 0) {///Проверка на то, что детерминант равен нулю
        int flag_1 = 0;
    }

    for (i = 0; i < n; i++) { ///Удаление матрицы без последнего столбца
        delete[] matrixWithoutB[i];
    }
    delete[] matrixWithoutB;


    int** temporaryMatrix = new signed int*[n];
    for (i = 0; i < n; i++) {
        temporaryMatrix[i] = new signed int[n];
    }

    for (I = 0; I < n; I++) { ///Считаем детерминанты для каждой перемонной
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

    if (determinantOfBigMatrix  !=  0) {///Проверяем условия и выводим
        for (i = 0; i < n; i++) {
            cout << "X_" <<  i + 1 << "= " << determinants[i] / determinantOfBigMatrix << endl;
        }
    }
    else {
        if (nullInMassiv(determinants, n) == 0    &&    determinantOfBigMatrix  ==  0) {
            cout << "Пустое множество" << endl;
        }
        else {
            if (nullInMassiv(determinants, n)  == n    &&    determinantOfBigMatrix  ==  0) {
                cout << "Бесконечно много решений" << endl;
            }
        }
    }

}

int nullInMassiv(signed int* array, unsigned int n) {///Вычисляет, сколько элементов в данном массиве с данным размером равны нулю
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
    cout << "1. Сложение двух матриц" << endl;
    cout << "2. Вычитание двух матриц" << endl;
    cout << "3. Умножение матрицы на число" << endl;
    cout << "4. Транспонирование матрицы" << endl;
    cout << "5. Умножение двух матриц" << endl;
    cout << "6. Определитель матрицы" << endl;
    cout << "7. Корни системы линейных уравнений" << endl << endl;
    cout << "Выберите номер операции:";
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
    cout << "Вы ошиблись" << endl;
}

void printDeterminant(signed int** matrix, unsigned int n){
    cout << "Детерминант матрицы = " << determinant(matrix, n);
}



