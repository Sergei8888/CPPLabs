/*
    Вашей задачей будет создать шаблонный класс для реализации стека.

    В нем нужно предусмотреть следующее:
    Конструктор с указанием размера стека.
    Метод size – возвращающий текущее кол-во элементов.
    Метод maxsize – возвращающий максимальное кол-во элементов.
    Метод empty – возвращает TRUE, если стек пуст, и FALSE, если
    есть хотя бы один элемент.
    Метод push, чтобы положить в элемент в стек
    Метод pop, чтобы извлечь элемент из стека
    Метод top, чтобы посмотреть верхний элемент стека, но не
    извлекать его.
    Метод Info, для компактного получения информации о состоянии
    стека (см. подробности ниже)

    Добавьте обработку некорректных ситуаций через исключения (блок
    try/catch):
    Невозможно выделить необходимый участок памяти под стек
    (std::bad_alloc).
    Невозможно добавить новый элемент в стек (например,
    std::overflow_error)
    Невозможно извлечь элемент из стека, так как стек пустой
    (например, std::out_of_range)
    Невозможно посмотреть элемент на вершине стека, так как стек
    пустой (например, std::logic_error).
 */

#include <iostream>
#include "../lab_25/HandMadeLogger.h"

class Stack {
private:
    int size;
    int maxSize;
    int *stack;

    Logger *logger = new Logger(
            LoggerSettings{
                    std::vector<LogLevelClass::LogLevel>{LogLevelClass::LogLevel::INFO,
                                                         LogLevelClass::LogLevel::WARNING,
                                                         LogLevelClass::LogLevel::ERROR},
                    std::vector<LoggerTransport>{
                            {&std::cout, LoggerTransport::LoggerTransportTypes::CONSOLE}}},
            LogMessageSettings{LogLevelClass::LogLevel::INFO, true, true});;
public:
    Stack(int size) {
        if (size < 0) {
            throw std::bad_alloc();
        }

        this->size = 0;
        this->maxSize = size;
        this->stack = new int[size];
    }

    int getSize() {
        return this->size;
    }

    int getMaxsize() {
        return this->maxSize;
    }

    bool isEmpty() const {
        return this->size == 0;
    }

    void push(int value) {
        try {
            if (this->size == this->maxSize) {
                throw std::overflow_error("Stack overflow");
            }
        } catch (std::overflow_error &e) {
            this->logger->error(e.what());
            return;
        }


        this->stack[this->size] = value;
        this->size++;
    }

    int pop() {
        try {
            if (this->size == 0) {
                throw std::out_of_range("Stack is empty");
            }
        } catch (std::out_of_range &e) {
            this->logger->error(e.what());
            return -1;
        }

        this->size--;
        return this->stack[this->size];
    }

    int top() {
        try {
            if (this->size == 0) {
                throw std::logic_error("Stack is empty");
            }
        } catch (std::logic_error &e) {
            this->logger->error(e.what());
            return -1;
        }


        return this->stack[this->size - 1];
    }

    void info() {
        std::cout << "Stack info:" << std::endl;
        std::cout << "Size: " << this->size << std::endl;
        std::cout << "Max size: " << this->maxSize << std::endl;
        std::cout << "Empty: " << this->isEmpty() << std::endl;
        std::cout << "Top: " << this->top() << std::endl;
    }
};

int main() {
    Stack stack = Stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(5);
    stack.push(2);
    stack.push(6);

    stack.push(7);

    stack.info();

    return 0;
}