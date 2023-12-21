NUM 1
#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<double>> data; // ��������� ������ ��� �������� ������ �������

public:
    // ����������� ��� �������� ������� ��������� ������� � �������� ����������
    Matrix(int rows, int cols) : data(rows, std::vector<double>(cols, 0.0)) {}

    // ����� ��� ��������� ���������� �����
    int getRows() const {
        return data.size();
    }

    // ����� ��� ��������� ���������� ��������
    int getCols() const {
        return data[0].size();
    }

    // ����� ��� ��������� �������� �������� �������
    void setElement(int row, int col, double value) {
        data[row][col] = value;
    }

    // ����� ��� ��������� �������� �������� �������
    double getElement(int row, int col) const {
        return data[row][col];
    }

    // ����� ��� �������� ���� ������
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

    // ����� ��� ��������� ����� ������� �� ������
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

    // ����� ��� ��������� ������� �� �����
    Matrix multiplyByScalar(double scalar) const {
        Matrix result(getRows(), getCols());
        for (int i = 0; i < getRows(); ++i) {
            for (int j = 0; j < getCols(); ++j) {
                result.setElement(i, j, getElement(i, j) * scalar);
            }
        }

        return result;
    }

    // ����� ��� ��������� ���� ������
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

    // ����� ��� ��������� ����������������� �������
    Matrix transpose() const {
        Matrix result(getCols(), getRows());
        for (int i = 0; i < getRows(); ++i) {
            for (int j = 0; j < getCols(); ++j) {
                result.setElement(j, i, getElement(i, j));
            }
        }

        return result;
    }

    // ����� ��� ���������� ������� � ������� (��� ����� ������������� ��������)
    Matrix power(int exponent) const {
        if (exponent < 0) {
            throw std::invalid_argument("Exponent must be a non-negative integer.");
        }

        if (exponent == 0) {
            // �������� � ������� ������� ���������� ��������� �������
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
    // ������ �������������
    Matrix A(2, 3);
    Matrix B(3, 2);

    // ���������� ������ A � B ������� (�� ������ �������)

    // a. �������� ������
    Matrix C = A.add(B);

    // b. ��������� ������
    Matrix D = A.subtract(B);

    // c. ��������� ������� �� �����
    Matrix E = A.multiplyByScalar(2.0);

    // d. ��������� ������
    Matrix F = A.multiply(B);

    // e. ����������������� �������
    Matrix G = A.transpose();

    // f. ���������� ������� � �������
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
    // a. ����������� � ����������� � ���� ������ ��������� x, y, z
    Vector3D(double xCoord, double yCoord, double zCoord) : x(xCoord), y(yCoord), z(zCoord) {}

    // b. �����, ����������� ����� �������
    double calculateLength() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // c. �����, ����������� ��������� ������������
    double dotProduct(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // d. �����, ����������� ��������� ������������
    Vector3D crossProduct(const Vector3D& other) const {
        double resultX = y * other.z - z * other.y;
        double resultY = z * other.x - x * other.z;
        double resultZ = x * other.y - y * other.x;
        return Vector3D(resultX, resultY, resultZ);
    }

    // e. �����, ����������� ���� ����� ��������� (� ��������)
    double calculateAngle(const Vector3D& other) const {
        double dotProd = dotProduct(other);
        double lengthProduct = calculateLength() * other.calculateLength();
        return std::acos(dotProd / lengthProduct);
    }

    // f. ������ ��� ����� � ��������
    Vector3D add(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D subtract(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    // g. ����������� �����, ������� ���������� ������ ��������� �������� �������� N
    static std::vector<Vector3D> generateRandomVectors(int N) {
        std::vector<Vector3D> result;
        std::srand(static_cast<unsigned>(std::time(0))); // ������������� ���������� ��������� �����

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
    // ������ �������������
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);

    // ����� �������
    double length = v1.calculateLength();
    double dotProd = v1.dotProduct(v2);
    Vector3D crossProd = v1.crossProduct(v2);
    double angleRad = v1.calculateAngle(v2);

    Vector3D sum = v1.add(v2);
    Vector3D diff = v1.subtract(v2);

    // ����������� ����� ��� ��������� ������� ��������� ��������
    std::vector<Vector3D> randomVectors = Vector3D::generateRandomVectors(5);

    return 0;
}

NUM 3
#include <iostream>
#include <vector>

// ������� ����� ��� ���������� �����
class Shape {
public:
    virtual double getVolume() const = 0; // ����������� ����� ��� ��������� ������
    virtual ~Shape() {}
};

// ����� ��� ������������� ����
class Cube : public Shape {
private:
    double side; // ����� ������� ����

public:
    Cube(double side) : side(side) {}

    double getVolume() const override {
        return side * side * side;
    }
};

// ����� ��� ������������� �����
class Sphere : public Shape {
private:
    double radius; // ������ �����

public:
    Sphere(double radius) : radius(radius) {}

    double getVolume() const override {
        return (4.0 / 3.0) * 3.141592653589793 * radius * radius * radius;
    }
};

// ����� ��� ������������� ��������
class Cylinder : public Shape {
private:
    double radius; // ������ ��������
    double height; // ������ ��������

public:
    Cylinder(double radius, double height) : radius(radius), height(height) {}

    double getVolume() const override {
        return 3.141592653589793 * radius * radius * height;
    }
};

// ����� Box, ��������� ��� ���������� �����
class Box {
private:
    double availableVolume; // ��������� ����� � �������
    std::vector<Shape*> shapes; // ������ ��� �������� ����� � �������

public:
    Box(double volume) : availableVolume(volume) {}

    // ����� ��� ���������� ������ � �������
    bool add(Shape* shape) {
        double shapeVolume = shape->getVolume();

        if (shapeVolume <= availableVolume) {
            shapes.push_back(shape);
            availableVolume -= shapeVolume;
            return true;
        } else {
            return false; // ������������ ����� ��� ���������� ����� ������
        }
    }

    // ����� ��� ������ ���������� � ������� � �������
    void displayContents() const {
        std::cout << "Box contents:" << std::endl;
        for (const auto& shape : shapes) {
            std::cout << "- Shape volume: " << shape->getVolume() << std::endl;
        }
    }
};

int main() {
    // ������ �������������
    Box box(100.0); // ������� ������� � ������� 100.0

    // ������� ������
    Cube cube(5.0);
    Sphere sphere(4.0);
    Cylinder cylinder(3.0, 6.0);

    // ��������� ������ � �������
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

    // ������� ���������� �������
    box.displayContents();

    return 0;
}

NUM 4
#include <iostream>
#include <vector>

// ����������� ������� ����� ��� ���������� �����
class Shape {
public:
    virtual double getVolume() const = 0; // ����� ����������� ������� ��� ��������� ������
    virtual void displayInfo() const = 0; // ����� ����������� ������� ��� ������ ����������
    virtual ~Shape() {} // ����������� ����������
};

// ����������� ����� ��� ������������� ����
class Cube : public Shape {
protected:
    double side; // ����� ������� ����

public:
    Cube(double side) : side(side) {}

    double getVolume() const override {
        return side * side * side;
    }

    void displayInfo() const override {
        std::cout << "Cube volume: " << getVolume() << std::endl;
    }
};

// ����������� ����� ��� ������������� �����
class Sphere : public Shape {
protected:
    double radius; // ������ �����

public:
    Sphere(double radius) : radius(radius) {}

    double getVolume() const override {
        return (4.0 / 3.0) * 3.141592653589793 * radius * radius * radius;
    }

    void displayInfo() const override {
        std::cout << "Sphere volume: " << getVolume() << std::endl;
    }
};

// ����������� ����� ��� ������������� ��������
class Cylinder : public Shape {
protected:
    double radius; // ������ ��������
    double height; // ������ ��������

public:
    Cylinder(double radius, double height) : radius(radius), height(height) {}

    double getVolume() const override {
        return 3.141592653589793 * radius * radius * height;
    }

    void displayInfo() const override {
        std::cout << "Cylinder volume: " << getVolume() << std::endl;
    }
};

// ����� Box, ��������� ��� ���������� �����
class Box {
private:
    double availableVolume; // ��������� ����� � �������
    std::vector<Shape*> shapes; // ������ ��� �������� ����� � �������

public:
    Box(double volume) : availableVolume(volume) {}

    // ����� ��� ���������� ������ � �������
    bool add(Shape* shape) {
        double shapeVolume = shape->getVolume();

        if (shapeVolume <= availableVolume) {
            shapes.push_back(shape);
            availableVolume -= shapeVolume;
            return true;
        } else {
            return false; // ������������ ����� ��� ���������� ����� ������
        }
    }

    // ����� ��� ������ ���������� � ������� � �������
    void displayContents() const {
        std::cout << "Box contents:" << std::endl;
        for (const auto& shape : shapes) {
            shape->displayInfo();
        }
    }

    // ���������� ��� ������������ ������ �� �����
    ~Box() {
        for (const auto& shape : shapes) {
            delete shape;
        }
    }
};

int main() {
    // ������ �������������
    Box box(100.0); // ������� ������� � ������� 100.0

    // ������� ������
    Cube cube(5.0);
    Sphere sphere(4.0);
    Cylinder cylinder(3.0, 6.0);

    // ��������� ������ � �������
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

    // ������� ���������� �������
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
    // �����������, ����������� ��� �������: ������ �������� � ������ ����� ��������
    WeightedRandomPicker(const std::vector<int>& inputValues, const std::vector<int>& inputWeights)
        : values(inputValues), weights(inputWeights), generator(std::time(0)) {}

    // ����� ��� �������� �������� �� ������� ������� ��������� �������, � ������ ��� ����
    int pickRandomValue() const {
        if (values.empty() || weights.empty() || values.size() != weights.size()) {
            throw std::invalid_argument("Invalid input arrays.");
        }

        std::discrete_distribution<int> distribution(weights.begin(), weights.end());
        return values[ distribution(generator) ];
    }
};

int main() {
    // ������ �������������
    std::vector<int> arrayValues = {1, 2, 3};
    std::vector<int> arrayWeights = {1, 2, 10};

    WeightedRandomPicker picker(arrayValues, arrayWeights);

    // �������� ��������� �������� � ������ �����
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
    // ���� � �������� ��������
    std::string brand;
    double size_h;
    double size_w;
    double price;

    // ����� ��� ��������� ������
    void getData() const {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Size (Height x Width): " << size_h << " x " << size_w << std::endl;
        std::cout << "Price: " << price << std::endl;
    }
};

int main() {
    // ������� ������� ������ Tiles
    Tiles tile1, tile2;

    // �������� ������ � ���� ��������
    tile1.brand = "ExampleBrand1";
    tile1.size_h = 10.0;
    tile1.size_w = 5.0;
    tile1.price = 20.0;

    tile2.brand = "ExampleBrand2";
    tile2.size_h = 8.0;
    tile2.size_w = 6.0;
    tile2.price = 25.0;

    // ������� ������, ������� ����� getData()
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
    // ����� ��� ����� ������
    void inputData() {
        std::cout << "Enter first name: ";
        std::cin >> firstName;

        std::cout << "Enter last name: ";
        std::cin >> lastName;

        std::cout << "Enter age: ";
        std::cin >> age;
    }

    // ����� ��� ����������� ������ �� �����
    void displayData() const {
        std::cout << "Name: " << firstName << " " << lastName << std::endl;
        std::cout << "Age: " << age << std::endl;
    }
};

int main() {
    // ������� ������� ������ Children
    Children child1, child2;

    // �������� ������ � ���� ��������
    std::cout << "Enter data for child 1:" << std::endl;
    child1.inputData();

    std::cout << std::endl;

    std::cout << "Enter data for child 2:" << std::endl;
    child2.inputData();

    // ������� ������, ������� ����� displayData()
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
    // ����� ��� ���������� ������� ����������
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

    // ����� ��� ������ �������� ����� �� �������� ��������
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

    // ����� ��� ����������� �������
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
    // ������ �������������
    ArrayConverter arrayConverter;

    // ���������� ������� ����������
    arrayConverter.fillArray();

    // ����������� ��������� �������
    std::cout << "Original array:" << std::endl;
    arrayConverter.displayArray();

    // ������������ ������ �������� ����� �� �������� ��������
    arrayConverter.convertRowsToColumns();

    // ����������� ������� ����� ������
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

    // ����������� ����� ��� ������� �������������� ��������
    virtual double calculateMonthlySalary() const = 0;

    // ������ ��� ��������� �������������� ���������
    int getId() const {
        return id;
    }

    // ������ ��� ��������� ����� ���������
    const std::string& getName() const {
        return name;
    }

    // ����������� ����������
    virtual ~Worker() {}
};

class HourlyWorker : public Worker {
private:
    double hourlyRate;

public:
    HourlyWorker(int id, const std::string& name, double hourlyRate)
        : Worker(id, name), hourlyRate(hourlyRate) {}

    // ���������� ������ ��� ������� �������������� ��������
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

    // ���������� ������ ��� ������� �������������� ��������
    double calculateMonthlySalary() const override {
        return fixedSalary;
    }
};

// ������� ��� �������������� ������ ����������
bool compareWorkers(const Worker* a, const Worker* b) {
    if (a->calculateMonthlySalary() == b->calculateMonthlySalary()) {
        return a->getName() < b->getName();
    }
    return a->calculateMonthlySalary() > b->calculateMonthlySalary();
}

// ������� ��� ������ ���������� � ����������
void displayWorkers(const std::vector<Worker*>& workers) {
    std::cout << std::setw(15) << "ID" << std::setw(15) << "Name" << std::setw(25) << "Monthly Salary" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    for (const auto& worker : workers) {
        std::cout << std::setw(15) << worker->getId() << std::setw(15) << worker->getName()
                  << std::setw(25) << worker->calculateMonthlySalary() << std::endl;
    }
}

int main() {
    // ������� ������� ����������
    HourlyWorker worker1(1, "John", 15.0);
    FixedWorker worker2(2, "Alice", 2000.0);
    HourlyWorker worker3(3, "Bob", 20.0);

    // ��������� ������ ����������� �� ������� ����������
    std::vector<Worker*> workers = {&worker1, &worker2, &worker3};

    // ��������� ������ ����������
    std::sort(workers.begin(), workers.end(), compareWorkers);

    // a) ������� ���������� � ����������
    std::cout << "a) Ordered list of workers by monthly salary:" << std::endl;
    displayWorkers(workers);

    // b) ������� ������ 5 ���� ����������
    std::cout << "\nb) First 5 names of workers:" << std::endl;
    for (int i = 0; i < 5 && i < workers.size(); ++i) {
        std::cout << workers[i]->getName() << std::endl;
    }

    // c) ������� ��������� 3 �������������� ����������
    std::cout << "\nc) Last 3 IDs of workers:" << std::endl;
    for (int i = workers.size() - 3; i < workers.size(); ++i) {
        if (i >= 0) {
            std::cout << workers[i]->getId() << std::endl;
        }
    }

    // d) ���������� ��������� � ����
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

    // e) ������ ��������� �� �����
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

        // ������� ���������� � ��������� ����������
        std::cout << "\ne) List of workers read from 'workers.txt':" << std::endl;
        displayWorkers(readWorkers);

        // ����������� ������, ���������� ��� ��������� ����������
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

// ��������� ��� ������������� ���������� ��������� ������
struct TerminalStatistics {
    int trips;
    int singleRideTickets;
    double revenue;

    TerminalStatistics() : trips(0), singleRideTickets(0), revenue(0.0) {}
};

// ������� ����� ������������ �����
class TransportCard {
protected:
    double balance;

public:
    TransportCard() : balance(0.0) {}

    double getBalance() const {
        return balance;
    }

    // ����� ��� ���������� ����� ����� ��������
    virtual void rechargeAtATM(double amount) {
        balance += amount;
    }

    // ����� ��� ���������� ����� ����� ��������� ����������
    virtual void rechargeViaMobileApp(double amount) {
        balance += amount;
    }

    // ����� ��� ������ �������
    virtual void payForRide() = 0;

    virtual ~TransportCard() {}
};

// ����� ��� ������������ ����� � ������������� ������� � �����
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

    // ���������� ������ ������ �������
    void payForRide() override {
        if (balance >= monthlyFee) {
            balance -= monthlyFee;
            std::cout << "Ride successfully paid with a monthly subscription card." << std::endl;
        } else {
            std::cout << "Insufficient funds. Please recharge your card." << std::endl;
        }
    }
};

// ����� ��� ������������ ����� � ������� �������
class SingleRideCard : public TransportCard {
private:
    int singleRideTickets;

public:
    SingleRideCard() : singleRideTickets(0) {}

    // ���������� ������ ������ �������
    void payForRide() override {
        if (singleRideTickets > 0) {
            --singleRideTickets;
            std::cout << "Ride successfully paid with a single ride ticket." << std::endl;
        } else if (balance >= 2.0) {
            balance -= 2.0; // ��������� ������� �������
            std::cout << "Ride successfully paid with balance." << std::endl;
        } else {
            std::cout << "Insufficient funds. Please recharge your card." << std::endl;
        }
    }

    // ����� ��� ���������� ����� ����� ��������
    void rechargeAtATM(double amount) override {
        balance += amount;
    }

    // ����� ��� ���������� ����� ����� ��������� ����������
    void rechargeViaMobileApp(double amount) override {
        balance += amount;
    }

    // ����� ��� ������� ��������� �������
    void buySingleRideTickets(int count) {
        singleRideTickets += count;
    }
};

// ����� ���������
class ATM {
public:
    // ����� ��� ���������� ����� ����� ��������
    void rechargeCardAtATM(TransportCard& card, double amount) {
        card.rechargeAtATM(amount);
    }
};

// ����� ���������� ����������
class MobileApp {
public:
    // ����� ��� ���������� ����� ����� ��������� ����������
    void rechargeCardViaMobileApp(TransportCard& card, double amount) {
        card.rechargeViaMobileApp(amount);
    }
};

// ����� ��������� ������
class PaymentTerminal {
private:
    TerminalStatistics statistics;

public:
    // ����� ��� �������� ������ �������
    void checkRidePayment(TransportCard& card) {
        card.payForRide();
        ++statistics.trips;
    }

    // ����� ��� ������ ���������� ��������� ������
    void displayStatistics() const {
        std::cout << "Terminal Statistics:" << std::endl;
        std::cout << "Trips: " << statistics.trips << std::endl;
        std::cout << "Single Ride Tickets Used: " << statistics.singleRideTickets << std::endl;
        std::cout << "Total Revenue: " << statistics.revenue << std::endl;
    }
};

int main() {
    // ������ �������������
    MonthlySubscriptionCard studentCard("Student", 30.0);
    SingleRideCard singleRideCard;

    ATM atm;
    MobileApp mobileApp;
    PaymentTerminal paymentTerminal;

    // ���������� ���� ����� �������� � ��������� ����������
    atm.rechargeCardAtATM(studentCard, 50.0);
    mobileApp.rechargeCardViaMobileApp(singleRideCard, 20.0);

    // ������� ��������� �������
    singleRideCard.buySingleRideTickets(5);

    // �������� ������ ������� ����� ��������
    paymentTerminal.checkRidePayment(studentCard);
    paymentTerminal.checkRidePayment(singleRideCard);
    paymentTerminal.checkRidePayment(singleRideCard);

    // ����� ���������� ��������� ������
    paymentTerminal.displayStatistics();
