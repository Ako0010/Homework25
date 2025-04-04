#pragma once

class Worker {
public:
    static size_t nextId;
    size_t id;
    string name;
    string surname;
    size_t age;
    size_t pageCount;

    Worker() : id(0), name(""), surname(""), age(0), pageCount(0) {}

    Worker(string name, string surname, size_t age, size_t pageCount)
        : name(name), surname(surname), age(age), pageCount(pageCount) {
        id = ++nextId; 
    }

    void printWorker() const {
        cout << "----------------------------------------\n";
        cout << left << setw(10) << "Worker ID" << ": " << id << endl;
        cout << left << setw(10) << "Name" << ": " << name << " " << surname << endl;
        cout << left << setw(10) << "Age" << ": " << age << endl;
        cout << left << setw(10) << "Pages" << ": " << pageCount << endl;
        cout << "----------------------------------------\n";
    }
};

size_t Worker::nextId = 0;

template<typename T, int MAX = 10>
class SimpleQueue
{
    T _container[MAX]{};
    int _front = -1;
    int _rear = -1;

public:
    SimpleQueue() = default;

    void enQueue(T element)
    {
        if (isFull())
            throw "Queue overflow";

        if (isEmpty())
            _front = 0;

        _container[++_rear] = element;
    }

    void deQueue()
    {
        if (isEmpty())
            throw "Queue underflow";

        _front++;

        if (_front > _rear)
            _front = _rear = -1;
    }

    T peek() const
    {
        if (isEmpty())
            throw "Queue is Empty";

        return _container[_front];
    }

    int size() const
    {
        if (_front == -1)
            return 0;

        return _rear - _front + 1;
    }

    bool isEmpty() const { return size() == 0; }
    bool isFull() const { return size() == MAX; }

    const T* getContainer() const
    {
        return _container;
    }
};

class Printer {
private:
    SimpleQueue<Worker> workerQueue;

public:
    void request(const Worker& worker) {
        workerQueue.enQueue(worker);
        cout << "Worker " << worker.name << " " << worker.surname << " added to the queue.\n";
    }

    void start() {
        cout << "\nStarting the printing process...\n\n";
        while (!workerQueue.isEmpty()) {
            Worker currentWorker = workerQueue.peek();
            workerQueue.deQueue();

            currentWorker.printWorker();
            cout << "Printing " << currentWorker.pageCount << " pages...\n";
            cout << "Printing finished for " << currentWorker.name << " " << currentWorker.surname << "\n";
            cout << "----------------------------------------\n";
        }

        cout << "\nQueue is empty. All printing is completed.\n";
    }
};
