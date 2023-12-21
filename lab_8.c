Реализуйте очередь с нисходящим приоритетом.

#include <iostream>
#include <queue>
#include <vector>

template <typename T, typename Priority>
class PriorityQueue {
private:
    struct QueueNode {
        T item;
        Priority priority;

        // Переопределение оператора '<' для сравнения приоритетов
        bool operator<(const QueueNode& other) const {
            return priority < other.priority;
        }
    };

    std::priority_queue<QueueNode> queue;

public:
    void push(const T& item, const Priority& priority) {
        QueueNode node = {item, priority};
        queue.push(node);
    }

    T pop() {
        T item = queue.top().item;
        queue.pop();
        return item;
    }

    bool isEmpty() const {
        return queue.empty();
    }
};

int main() {
    PriorityQueue<std::string, int> priorityQueue;

    priorityQueue.push("Task 1", 3);
    priorityQueue.push("Task 2", 1);
    priorityQueue.push("Task 3", 2);

    std::cout << priorityQueue.pop() << std::endl;  // Выведет "Task 1"
    std::cout << priorityQueue.pop() << std::endl;  // Выведет "Task 3"
    std::cout << priorityQueue.pop() << std::endl;  // Выведет "Task 2"

    return 0;
}


Реализуйте ADT с круговой очередью, используя Arrays
#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Максимальный размер круговой очереди

template <typename T>
class CircularQueue {
private:
    T queue[MAX_SIZE];
    int front, rear;

public:
    CircularQueue() : front(-1), rear(-1) {}

    // Функция для проверки, пуста ли очередь
    bool isEmpty() const {
        return front == -1 && rear == -1;
    }

    // Функция для проверки, полна ли очередь
    bool isFull() const {
        return (rear + 1) % MAX_SIZE == front;
    }

    // Функция для добавления элемента в очередь
    void enqueue(const T& item) {
        if (isFull()) {
            cout << "Очередь переполнена. Невозможно добавить элемент." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        queue[rear] = item;
        cout << "Элемент " << item << " добавлен в очередь." << endl;
    }

    // Функция для удаления элемента из очереди
    T dequeue() {
        if (isEmpty()) {
            cout << "Очередь пуста. Невозможно удалить элемент." << endl;
            return T(); // Возвращаем значение по умолчанию для типа T
        }

        T removedItem = queue[front];

        if (front == rear) {
            front = rear = -1; // Если удаляем последний элемент, сбрасываем front и rear
        } else {
            front = (front + 1) % MAX_SIZE;
        }

        cout << "Элемент " << removedItem << " удален из очереди." << endl;
        return removedItem;
    }

    // Функция для отображения элементов в очереди
    void display() {
        if (isEmpty()) {
            cout << "Очередь пуста." << endl;
            return;
        }

        cout << "Элементы в очереди: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue<int> cq;

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.display();

    cq.dequeue();
    cq.display();

    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6); // Переполнение
    cq.display();

    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.display();

    return 0;
}
