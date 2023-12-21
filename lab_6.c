NUM 1
#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<double>> data; // двумерный вектор для хранения данных матрицы

public:
    // Конструктор для создания матрицы заданного размера с нулевыми значениями
    Matrix(int rows, int cols) : data(rows, std::vector<double>(cols, 0.0)) {}

    // Метод для получения количества строк
    int getRows() const {
        return data.size();
    }

    // Метод для получения количества столбцов
    int getCols() const {
        return data[0].size();
    }

    // Метод для установки значения элемента матрицы
    void setElement(int row, int col, double value) {
        data[row][col] = value;
    }

    // Метод для получения значения элемента матрицы
    double getElement(int row, int col) const {
        return data[row][col];
    }

    // Метод для сложения двух матриц
    Matrix add(const Matrix& other) const {
        if (getRows() != other.getRows() || getCols() != other.getCols()) {
            throw std::invalid_argument("Matrices must have the same dimensions for addition.");
        }

        Matrix result(getRows(), getCols());
        for (int i = 0; i < getRows(); ++i) {
            for (int j = 0; j < getCols(); ++j) {
                result.setElement(i, j, getElement(i, j) + other.getElement(i, j));
            }
        }

        return result;
    }

    // Метод для вычитания одной матрицы из другой
    Matrix subtract(const Matrix& other) const {
        if (getRows() != other.getRows() || getCols() != other.getCols()) {
            throw std::invalid_argument("Matrices must have the same dimensions for subtraction.");
        }

        Matrix result(getRows(), getCols());
        for (int i = 0; i < getRows(); ++i) {
            for (int j = 0; j < getCols(); ++j) {
                result.setElement(i, j, getElement(i, j) - other.getElement(i, j));
            }
        }

        return result;
    }

    // Метод для умножения матрицы на число
    Matrix multiplyByScalar(double scalar) const {
        Matrix result(getRows(), getCols());
        for (int i = 0; i < getRows(); ++i) {
            for (int j = 0; j < getCols(); ++j) {
                result.setElement(i, j, getElement(i, j) * scalar);
            }
        }

        return result;
    }

    // Метод для умножения двух матриц
    Matrix multiply(const Matrix& other) const {
        if (getCols() != other.getRows()) {
            throw std::invalid_argument("Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication.");
        }

        Matrix result(getRows(), other.getCols());
        for (int i = 0; i < getRows(); ++i) {
            for (int j = 0; j < other.getCols(); ++j) {
                double sum = 0.0;
                for (int k = 0; k < getCols(); ++k) {
                    sum += getElement(i, k) * other.getElement(k, j);
                }
                result.setElement(i, j, sum);
            }
        }

        return result;
    }

    // Метод для получения транспонированной матрицы
    Matrix transpose() const {
        Matrix result(getCols(), getRows());
        for (int i = 0; i < getRows(); ++i) {
            for (int j = 0; j < getCols(); ++j) {
                result.setElement(j, i, getElement(i, j));
            }
        }

        return result;
    }

    // Метод для возведения матрицы в степень (для целых положительных степеней)
    Matrix power(int exponent) const {
        if (exponent < 0) {
            throw std::invalid_argument("Exponent must be a non-negative integer.");
        }

        if (exponent == 0) {
            // Возвести в нулевую степень возвращает единичную матрицу
            Matrix result(getRows(), getCols());
            for (int i = 0; i < getRows(); ++i) {
                for (int j = 0; j < getCols(); ++j) {
                    result.setElement(i, j, (i == j) ? 1.0 : 0.0);
                }
            }
            return result;
        }

        Matrix result = *this;
        for (int i = 1; i < exponent; ++i) {
            result = result.multiply(*this);
        }

        return result;
    }
};

int main() {
    // Пример использования
    Matrix A(2, 3);
    Matrix B(3, 2);

    // Заполнение матриц A и B данными (по вашему желанию)

    // a. Сложение матриц
    Matrix C = A.add(B);

    // b. Вычитание матриц
    Matrix D = A.subtract(B);

    // c. Умножение матрицы на число
    Matrix E = A.multiplyByScalar(2.0);

    // d. Умножение матриц
    Matrix F = A.multiply(B);

    // e. Транспонированная матрица
    Matrix G = A.transpose();

    // f. Возведение матрицы в степень
    Matrix H = A.power(2);

    return 0;
}

NUM 2
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Vector3D {
private:
    double x, y, z;

public:
    // a. Конструктор с параметрами в виде списка координат x, y, z
    Vector3D(double xCoord, double yCoord, double zCoord) : x(xCoord), y(yCoord), z(zCoord) {}

    // b. Метод, вычисляющий длину вектора
    double calculateLength() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // c. Метод, вычисляющий скалярное произведение
    double dotProduct(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // d. Метод, вычисляющий векторное произведение
    Vector3D crossProduct(const Vector3D& other) const {
        double resultX = y * other.z - z * other.y;
        double resultY = z * other.x - x * other.z;
        double resultZ = x * other.y - y * other.x;
        return Vector3D(resultX, resultY, resultZ);
    }

    // e. Метод, вычисляющий угол между векторами (в радианах)
    double calculateAngle(const Vector3D& other) const {
        double dotProd = dotProduct(other);
        double lengthProduct = calculateLength() * other.calculateLength();
        return std::acos(dotProd / lengthProduct);
    }

    // f. Методы для суммы и разности
    Vector3D add(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D subtract(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    // g. Статический метод, который возвращает массив случайных векторов размером N
    static std::vector<Vector3D> generateRandomVectors(int N) {
        std::vector<Vector3D> result;
        std::srand(static_cast<unsigned>(std::time(0))); // инициализация генератора случайных чисел

        for (int i = 0; i < N; ++i) {
            double xRand = static_cast<double>(std::rand()) / RAND_MAX;
            double yRand = static_cast<double>(std::rand()) / RAND_MAX;
            double zRand = static_cast<double>(std::rand()) / RAND_MAX;
            result.push_back(Vector3D(xRand, yRand, zRand));
        }

        return result;
    }
};

int main() {
    // Пример использования
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);

    // Вызов методов
    double length = v1.calculateLength();
    double dotProd = v1.dotProduct(v2);
    Vector3D crossProd = v1.crossProduct(v2);
    double angleRad = v1.calculateAngle(v2);

    Vector3D sum = v1.add(v2);
    Vector3D diff = v1.subtract(v2);

    // Статический метод для генерации массива случайных векторов
    std::vector<Vector3D> randomVectors = Vector3D::generateRandomVectors(5);

    return 0;
}

NUM 3
#include <iostream>
#include <vector>

// Базовый класс для трехмерных фигур
class Shape {
public:
    virtual double getVolume() const = 0; // Виртуальный метод для получения объема
    virtual ~Shape() {}
};

// Класс для представления куба
class Cube : public Shape {
private:
    double side; // Длина стороны куба

public:
    Cube(double side) : side(side) {}

    double getVolume() const override {
        return side * side * side;
    }
};

// Класс для представления сферы
class Sphere : public Shape {
private:
    double radius; // Радиус сферы

public:
    Sphere(double radius) : radius(radius) {}

    double getVolume() const override {
        return (4.0 / 3.0) * 3.141592653589793 * radius * radius * radius;
    }
};

// Класс для представления цилиндра
class Cylinder : public Shape {
private:
    double radius; // Радиус цилиндра
    double height; // Высота цилиндра

public:
    Cylinder(double radius, double height) : radius(radius), height(height) {}

    double getVolume() const override {
        return 3.141592653589793 * radius * radius * height;
    }
};

// Класс Box, контейнер для трехмерных фигур
class Box {
private:
    double availableVolume; // Доступный объем в коробке
    std::vector<Shape*> shapes; // Вектор для хранения фигур в коробке

public:
    Box(double volume) : availableVolume(volume) {}

    // Метод для добавления фигуры в коробку
    bool add(Shape* shape) {
        double shapeVolume = shape->getVolume();

        if (shapeVolume <= availableVolume) {
            shapes.push_back(shape);
            availableVolume -= shapeVolume;
            return true;
        } else {
            return false; // Недостаточно места для добавления новой фигуры
        }
    }

    // Метод для вывода информации о фигурах в коробке
    void displayContents() const {
        std::cout << "Box contents:" << std::endl;
        for (const auto& shape : shapes) {
            std::cout << "- Shape volume: " << shape->getVolume() << std::endl;
        }
    }
};

int main() {
    // Пример использования
    Box box(100.0); // Создаем коробку с объемом 100.0

    // Создаем фигуры
    Cube cube(5.0);
    Sphere sphere(4.0);
    Cylinder cylinder(3.0, 6.0);

    // Добавляем фигуры в коробку
    if (box.add(&cube)) {
        std::cout << "Cube added to the box." << std::endl;
    } else {
        std::cout << "Not enough space for the cube in the box." << std::endl;
    }

    if (box.add(&sphere)) {
        std::cout << "Sphere added to the box." << std::endl;
    } else {
        std::cout << "Not enough space for the sphere in the box." << std::endl;
    }

    if (box.add(&cylinder)) {
        std::cout << "Cylinder added to the box." << std::endl;
    } else {
        std::cout << "Not enough space for the cylinder in the box." << std::endl;
    }

    // Выводим содержимое коробки
    box.displayContents();

    return 0;
}

NUM 4
#include <iostream>
#include <vector>

// Абстрактный базовый класс для трехмерных фигур
class Shape {
public:
    virtual double getVolume() const = 0; // Чисто виртуальная функция для получения объема
    virtual void displayInfo() const = 0; // Чисто виртуальная функция для вывода информации
    virtual ~Shape() {} // Виртуальный деструктор
};

// Абстрактный класс для представления куба
class Cube : public Shape {
protected:
    double side; // Длина стороны куба

public:
    Cube(double side) : side(side) {}

    double getVolume() const override {
        return side * side * side;
    }

    void displayInfo() const override {
        std::cout << "Cube volume: " << getVolume() << std::endl;
    }
};

// Абстрактный класс для представления сферы
class Sphere : public Shape {
protected:
    double radius; // Радиус сферы

public:
    Sphere(double radius) : radius(radius) {}

    double getVolume() const override {
        return (4.0 / 3.0) * 3.141592653589793 * radius * radius * radius;
    }

    void displayInfo() const override {
        std::cout << "Sphere volume: " << getVolume() << std::endl;
    }
};

// Абстрактный класс для представления цилиндра
class Cylinder : public Shape {
protected:
    double radius; // Радиус цилиндра
    double height; // Высота цилиндра

public:
    Cylinder(double radius, double height) : radius(radius), height(height) {}

    double getVolume() const override {
        return 3.141592653589793 * radius * radius * height;
    }

    void displayInfo() const override {
        std::cout << "Cylinder volume: " << getVolume() << std::endl;
    }
};

// Класс Box, контейнер для трехмерных фигур
class Box {
private:
    double availableVolume; // Доступный объем в коробке
    std::vector<Shape*> shapes; // Вектор для хранения фигур в коробке

public:
    Box(double volume) : availableVolume(volume) {}

    // Метод для добавления фигуры в коробку
    bool add(Shape* shape) {
        double shapeVolume = shape->getVolume();

        if (shapeVolume <= availableVolume) {
            shapes.push_back(shape);
            availableVolume -= shapeVolume;
            return true;
        } else {
            return false; // Недостаточно места для добавления новой фигуры
        }
    }

    // Метод для вывода информации о фигурах в коробке
    void displayContents() const {
        std::cout << "Box contents:" << std::endl;
        for (const auto& shape : shapes) {
            shape->displayInfo();
        }
    }

    // Деструктор для освобождения памяти от фигур
    ~Box() {
        for (const auto& shape : shapes) {
            delete shape;
        }
    }
};

int main() {
    // Пример использования
    Box box(100.0); // Создаем коробку с объемом 100.0

    // Создаем фигуры
    Cube cube(5.0);
    Sphere sphere(4.0);
    Cylinder cylinder(3.0, 6.0);

    // Добавляем фигуры в коробку
    if (box.add(&cube)) {
        std::cout << "Cube added to the box." << std::endl;
    } else {
        std::cout << "Not enough space for the cube in the box." << std::endl;
    }

    if (box.add(&sphere)) {
        std::cout << "Sphere added to the box." << std::endl;
    } else {
        std::cout << "Not enough space for the sphere in the box." << std::endl;
    }

    if (box.add(&cylinder)) {
        std::cout << "Cylinder added to the box." << std::endl;
    } else {
        std::cout << "Not enough space for the cylinder in the box." << std::endl;
    }

    // Выводим содержимое коробки
    box.displayContents();

    return 0;
}

NUM 5
#include <vector>
#include <random>
#include <ctime>

class WeightedRandomPicker {
private:
    std::vector<int> values;
    std::vector<int> weights;
    std::mt19937 generator; // Mersenne Twister 19937 generator

public:
    // Конструктор, принимающий два массива: массив значений и массив весов значений
    WeightedRandomPicker(const std::vector<int>& inputValues, const std::vector<int>& inputWeights)
        : values(inputValues), weights(inputWeights), generator(std::time(0)) {}

    // Метод для возврата элемента из первого массива случайным образом, с учетом его веса
    int pickRandomValue() const {
        if (values.empty() || weights.empty() || values.size() != weights.size()) {
            throw std::invalid_argument("Invalid input arrays.");
        }

        std::discrete_distribution<int> distribution(weights.begin(), weights.end());
        return values[ distribution(generator) ];
    }
};

int main() {
    // Пример использования
    std::vector<int> arrayValues = {1, 2, 3};
    std::vector<int> arrayWeights = {1, 2, 10};

    WeightedRandomPicker picker(arrayValues, arrayWeights);

    // Выбираем случайные значения с учетом весов
    for (int i = 0; i < 10; ++i) {
        int randomValue = picker.pickRandomValue();
        std::cout << "Random Value: " << randomValue << std::endl;
    }

    return 0;
}

NUM 6
#include <iostream>
#include <string>

class Tiles {
public:
    // Поля с открытым доступом
    std::string brand;
    double size_h;
    double size_w;
    double price;

    // Метод для получения данных
    void getData() const {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Size (Height x Width): " << size_h << " x " << size_w << std::endl;
        std::cout << "Price: " << price << std::endl;
    }
};

int main() {
    // Создаем объекты класса Tiles
    Tiles tile1, tile2;

    // Внесение данных в поля объектов
    tile1.brand = "ExampleBrand1";
    tile1.size_h = 10.0;
    tile1.size_w = 5.0;
    tile1.price = 20.0;

    tile2.brand = "ExampleBrand2";
    tile2.size_h = 8.0;
    tile2.size_w = 6.0;
    tile2.price = 25.0;

    // Выводим данные, вызывая метод getData()
    std::cout << "Tile 1:" << std::endl;
    tile1.getData();
    std::cout << std::endl;

    std::cout << "Tile 2:" << std::endl;
    tile2.getData();

    return 0;
}

NUM 7
#include <iostream>
#include <string>

class Children {
private:
    std::string firstName;
    std::string lastName;
    int age;

public:
    // Метод для ввода данных
    void inputData() {
        std::cout << "Enter first name: ";
        std::cin >> firstName;

        std::cout << "Enter last name: ";
        std::cin >> lastName;

        std::cout << "Enter age: ";
        std::cin >> age;
    }

    // Метод для отображения данных на экран
    void displayData() const {
        std::cout << "Name: " << firstName << " " << lastName << std::endl;
        std::cout << "Age: " << age << std::endl;
    }
};

int main() {
    // Создаем объекты класса Children
    Children child1, child2;

    // Внесение данных в поля объектов
    std::cout << "Enter data for child 1:" << std::endl;
    child1.inputData();

    std::cout << std::endl;

    std::cout << "Enter data for child 2:" << std::endl;
    child2.inputData();

    // Выводим данные, вызывая метод displayData()
    std::cout << std::endl;
    std::cout << "Data for child 1:" << std::endl;
    child1.displayData();

    std::cout << std::endl;

    std::cout << "Data for child 2:" << std::endl;
    child2.displayData();

    return 0;
}

NUM 8
#include <iostream>
#include <vector>

class ArrayConverter {
private:
    std::vector<std::vector<int>> array;

public:
    // Метод для заполнения массива значениями
    void fillArray() {
        int rows, cols;
        std::cout << "Enter the number of rows: ";
        std::cin >> rows;

        std::cout << "Enter the number of columns: ";
        std::cin >> cols;

        array.resize(rows, std::vector<int>(cols, 0));

        std::cout << "Enter values for the array:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Enter value for array[" << i << "][" << j << "]: ";
                std::cin >> array[i][j];
            }
        }
    }

    // Метод для замены значений строк на значения столбцов
    void convertRowsToColumns() {
        int rows = array.size();
        int cols = (rows > 0) ? array[0].size() : 0;

        std::vector<std::vector<int>> result(cols, std::vector<int>(rows, 0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[j][i] = array[i][j];
            }
        }

        array = result;
    }

    // Метод для отображения массива
    void displayArray() const {
        int rows = array.size();
        int cols = (rows > 0) ? array[0].size() : 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << array[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Пример использования
    ArrayConverter arrayConverter;

    // Заполнение массива значениями
    arrayConverter.fillArray();

    // Отображение исходного массива
    std::cout << "Original array:" << std::endl;
    arrayConverter.displayArray();

    // Произведение замены значений строк на значения столбцов
    arrayConverter.convertRowsToColumns();

    // Отображение массива после замены
    std::cout << "\nArray after converting rows to columns:" << std::endl;
    arrayConverter.displayArray();

    return 0;
}

NUM 9
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>

class Worker {
protected:
    int id;
    std::string name;

public:
    Worker(int id, const std::string& name) : id(id), name(name) {}

    // Абстрактный метод для расчета среднемесячной зарплаты
    virtual double calculateMonthlySalary() const = 0;

    // Геттер для получения идентификатора работника
    int getId() const {
        return id;
    }

    // Геттер для получения имени работника
    const std::string& getName() const {
        return name;
    }

    // Виртуальный деструктор
    virtual ~Worker() {}
};

class HourlyWorker : public Worker {
private:
    double hourlyRate;

public:
    HourlyWorker(int id, const std::string& name, double hourlyRate)
        : Worker(id, name), hourlyRate(hourlyRate) {}

    // Реализация метода для расчета среднемесячной зарплаты
    double calculateMonthlySalary() const override {
        return 20.8 * 8 * hourlyRate;
    }
};

class FixedWorker : public Worker {
private:
    double fixedSalary;

public:
    FixedWorker(int id, const std::string& name, double fixedSalary)
        : Worker(id, name), fixedSalary(fixedSalary) {}

    // Реализация метода для расчета среднемесячной зарплаты
    double calculateMonthlySalary() const override {
        return fixedSalary;
    }
};

// Функция для упорядочивания списка работников
bool compareWorkers(const Worker* a, const Worker* b) {
    if (a->calculateMonthlySalary() == b->calculateMonthlySalary()) {
        return a->getName() < b->getName();
    }
    return a->calculateMonthlySalary() > b->calculateMonthlySalary();
}

// Функция для вывода информации о работниках
void displayWorkers(const std::vector<Worker*>& workers) {
    std::cout << std::setw(15) << "ID" << std::setw(15) << "Name" << std::setw(25) << "Monthly Salary" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    for (const auto& worker : workers) {
        std::cout << std::setw(15) << worker->getId() << std::setw(15) << worker->getName()
                  << std::setw(25) << worker->calculateMonthlySalary() << std::endl;
    }
}

int main() {
    // Создаем объекты работников
    HourlyWorker worker1(1, "John", 15.0);
    FixedWorker worker2(2, "Alice", 2000.0);
    HourlyWorker worker3(3, "Bob", 20.0);

    // Заполняем вектор указателями на объекты работников
    std::vector<Worker*> workers = {&worker1, &worker2, &worker3};

    // Сортируем список работников
    std::sort(workers.begin(), workers.end(), compareWorkers);

    // a) Выводим информацию о работниках
    std::cout << "a) Ordered list of workers by monthly salary:" << std::endl;
    displayWorkers(workers);

    // b) Выводим первые 5 имен работников
    std::cout << "\nb) First 5 names of workers:" << std::endl;
    for (int i = 0; i < 5 && i < workers.size(); ++i) {
        std::cout << workers[i]->getName() << std::endl;
    }

    // c) Выводим последние 3 идентификатора работников
    std::cout << "\nc) Last 3 IDs of workers:" << std::endl;
    for (int i = workers.size() - 3; i < workers.size(); ++i) {
        if (i >= 0) {
            std::cout << workers[i]->getId() << std::endl;
        }
    }

    // d) Записываем коллекцию в файл
    std::ofstream outFile("workers.txt");
    if (outFile.is_open()) {
        for (const auto& worker : workers) {
            outFile << worker->getId() << " " << worker->getName() << " "
                    << worker->calculateMonthlySalary() << std::endl;
        }
        outFile.close();
        std::cout << "\nd) Collection has been written to 'workers.txt'." << std::endl;
    } else {
        std::cerr << "Unable to open the output file." << std::endl;
    }

    // e) Читаем коллекцию из файла
    std::vector<Worker*> readWorkers;
    std::ifstream inFile("workers.txt");
    if (inFile.is_open()) {
        int id;
        std::string name;
        double salary;
        while (inFile >> id >> name >> salary) {
            Worker* newWorker = (salary == 2000.0) ? static_cast<Worker*>(new FixedWorker(id, name, salary))
                                                  : static_cast<Worker*>(new HourlyWorker(id, name, salary));
            readWorkers.push_back(newWorker);
        }
        inFile.close();

        // Выводим информацию о считанных работниках
        std::cout << "\ne) List of workers read from 'workers.txt':" << std::endl;
        displayWorkers(readWorkers);

        // Освобождаем память, выделенную для считанных работников
        for (const auto& worker : readWorkers) {
            delete worker;
        }
    } else {
        std::cerr << "Unable to open the input file." << std::endl;
    }

    return 0;
}

NUM 10
#include <iostream>
#include <vector>
#include <string>

// Структура для представления статистики терминала оплаты
struct TerminalStatistics {
    int trips;
    int singleRideTickets;
    double revenue;

    TerminalStatistics() : trips(0), singleRideTickets(0), revenue(0.0) {}
};

// Базовый класс транспортной карты
class TransportCard {
protected:
    double balance;

public:
    TransportCard() : balance(0.0) {}

    double getBalance() const {
        return balance;
    }

    // Метод для пополнения карты через банкомат
    virtual void rechargeAtATM(double amount) {
        balance += amount;
    }

    // Метод для пополнения карты через мобильное приложение
    virtual void rechargeViaMobileApp(double amount) {
        balance += amount;
    }

    // Метод для оплаты поездки
    virtual void payForRide() = 0;

    virtual ~TransportCard() {}
};

// Класс для транспортной карты с фиксированной оплатой в месяц
class MonthlySubscriptionCard : public TransportCard {
private:
    std::string cardType;
    double monthlyFee;

public:
    MonthlySubscriptionCard(const std::string& type, double fee)
        : cardType(type), monthlyFee(fee) {}

    void rechargeAtATM(double amount) override {
        std::cout << "Monthly subscription cards cannot be recharged at ATMs." << std::endl;
    }

    void rechargeViaMobileApp(double amount) override {
        std::cout << "Monthly subscription cards cannot be recharged via mobile app." << std::endl;
    }

    // Реализация метода оплаты поездки
    void payForRide() override {
        if (balance >= monthlyFee) {
            balance -= monthlyFee;
            std::cout << "Ride successfully paid with a monthly subscription card." << std::endl;
        } else {
            std::cout << "Insufficient funds. Please recharge your card." << std::endl;
        }
    }
};

// Класс для транспортной карты с разовой оплатой
class SingleRideCard : public TransportCard {
private:
    int singleRideTickets;

public:
    SingleRideCard() : singleRideTickets(0) {}

    // Реализация метода оплаты поездки
    void payForRide() override {
        if (singleRideTickets > 0) {
            --singleRideTickets;
            std::cout << "Ride successfully paid with a single ride ticket." << std::endl;
        } else if (balance >= 2.0) {
            balance -= 2.0; // Стоимость разовой поездки
            std::cout << "Ride successfully paid with balance." << std::endl;
        } else {
            std::cout << "Insufficient funds. Please recharge your card." << std::endl;
        }
    }

    // Метод для пополнения карты через банкомат
    void rechargeAtATM(double amount) override {
        balance += amount;
    }

    // Метод для пополнения карты через мобильное приложение
    void rechargeViaMobileApp(double amount) override {
        balance += amount;
    }

    // Метод для покупки поштучных билетов
    void buySingleRideTickets(int count) {
        singleRideTickets += count;
    }
};

// Класс банкомата
class ATM {
public:
    // Метод для пополнения карты через банкомат
    void rechargeCardAtATM(TransportCard& card, double amount) {
        card.rechargeAtATM(amount);
    }
};

// Класс мобильного приложения
class MobileApp {
public:
    // Метод для пополнения карты через мобильное приложение
    void rechargeCardViaMobileApp(TransportCard& card, double amount) {
        card.rechargeViaMobileApp(amount);
    }
};

// Класс терминала оплаты
class PaymentTerminal {
private:
    TerminalStatistics statistics;

public:
    // Метод для проверки оплаты поездки
    void checkRidePayment(TransportCard& card) {
        card.payForRide();
        ++statistics.trips;
    }

    // Метод для вывода статистики терминала оплаты
    void displayStatistics() const {
        std::cout << "Terminal Statistics:" << std::endl;
        std::cout << "Trips: " << statistics.trips << std::endl;
        std::cout << "Single Ride Tickets Used: " << statistics.singleRideTickets << std::endl;
        std::cout << "Total Revenue: " << statistics.revenue << std::endl;
    }
};

int main() {
    // Пример использования
    MonthlySubscriptionCard studentCard("Student", 30.0);
    SingleRideCard singleRideCard;

    ATM atm;
    MobileApp mobileApp;
    PaymentTerminal paymentTerminal;

    // Пополнение карт через банкомат и мобильное приложение
    atm.rechargeCardAtATM(studentCard, 50.0);
    mobileApp.rechargeCardViaMobileApp(singleRideCard, 20.0);

    // Покупка поштучных билетов
    singleRideCard.buySingleRideTickets(5);

    // Проверка оплаты поездки через терминал
    paymentTerminal.checkRidePayment(studentCard);
    paymentTerminal.checkRidePayment(singleRideCard);
    paymentTerminal.checkRidePayment(singleRideCard);

    // Вывод статистики терминала оплаты
    paymentTerminal.displayStatistics();
