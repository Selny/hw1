#include <iostream>

using namespace std;

#define MAX 10

template<typename T>
class Stack {
private:
    T items[MAX];
    int top; //  current index
public:
    Stack() { top = -1; }

    bool push(T item) {
        if (top >= (MAX - 1)) {
            cout << "Stack overflow!";
            return false;
        }
        else {
            items[++top] = item;
            return true;
        }
    }
    T peek() {
        if (top < 0) {
            cout << "Stack is Empty!" << endl;
            return 0;
        }
        else {
            return items[top];
        }
    }
    T pop() {
        if (top < 0) {
            cout << "Stack is underflow!" << endl;
            return items[top];
        }
        else {
            return items[top--];
        }
    }
    
    Stack<T>& operator=(Stack<T> other) {
        Stack<T> temp;
        
        while(!other.isEmpty()) {
            temp.push(other.pop());
        }
        while(!temp.isEmpty()) {
            push(temp.pop());
        }
        return *this;
    }

    bool isEmpty() const { return top < 0; }
    bool isFull() const { return top == (MAX - 1); }
};

class Engine {
public:
    int engine_no;
    string company;
    int volume;
    
    Engine() = default;
    
    Engine(const int engine_no, const string company, const int volume) {
        this->engine_no = engine_no;
        this->company = company;
        this->volume = volume;
    }
    
    void show() {
        cout << "Engine: " << engine_no << endl;
        cout << "Company: " << company << endl;
        cout << "Volume: " << volume << endl;
    }
    
};

class Vehicle {
public:
    int id;
    string model;
    string vendor;
    Engine engine;
    
    Vehicle() = default;
    Vehicle(const int id, const string model, const string vendor, const Engine& engine) {
        this->id = id;
        this->model = model;
        this->vendor = vendor;
        this->engine = engine;
    }
    
    virtual void show() = 0;
};

class Car : public Vehicle {
public:
    bool hasSpoiler;
    
    Car() = default;
    Car(const int id, const string model, const string vendor, const Engine& engine, const bool hasSpoiler) : Vehicle(id, model, vendor, engine){
        this->hasSpoiler = hasSpoiler;
    }
    
    void show() {
        cout << "Car\nId: " << id << endl;
        cout << "Model: " << model << endl;
        cout << "Vendor: " << vendor << endl;
        cout << "Has spoiler : " << hasSpoiler << endl;
        engine.show();
    }
};

class Ship : public Vehicle {
public:
    bool hasSail;
    
    Ship() = default;
    Ship(const int id, const string model, const string vendor, const Engine& engine, const bool hasSail) : Vehicle(id, model, vendor, engine){
        this->hasSail = hasSail;
    }
    
    void show() {
        cout << "Ship\nId: " << id << endl;
        cout << "Model: " << model << endl;
        cout << "Vendor: " << vendor << endl;
        cout << "Has sail : " << hasSail << endl;
        engine.show();
    }
};

class Airplane : public Vehicle {
public:
    int engineCount;
    int passengersCapacity;
    
    Airplane() = default;
    Airplane(const int id, const string model, const string vendor, const Engine& engine, const int engineCount, const int passengersCapacity) : Vehicle(id, model, vendor, engine){
        this->engineCount = engineCount;
        this->passengersCapacity = passengersCapacity;
    }
    
    void show() {
        cout << "Airplane\nId: " << id << endl;
        cout << "Model: " << model << endl;
        cout << "Vendor: " << vendor << endl;
        cout << "Engine count : " << engineCount << endl;
        engine.show();
    }
};

class VehicleDepo {
public:
    Stack<Car> cars;
    Stack<Ship> ships;
    Stack<Airplane> airplanes;
    
    VehicleDepo() = default;
    VehicleDepo(const Stack<Car> cars, const Stack<Ship> ships, const Stack<Airplane> airplanes) {
        this->cars = cars;
        this->ships = ships;
        this->airplanes = airplanes;
    }
    template <typename T>
    void info(Stack<T> other) {
        cout << "\n";
        while(!other.isEmpty()){
            other.pop().show();
        }
    }
    
    void ShowAll(){
        info<Car>(cars);
        info<Ship>(ships);
        info<Airplane>(airplanes);
    }
    
};

int main() {
    
    Engine e1(1, "BMW Engine", 4);
    Engine e2(2, "Ferrari Engine", 6);
    Engine e3(3, "Ship Engine", 2);
    Engine e4(4, "Airplane Engine", 25);
    
    Car c1(1, "BMW", "Kamaz Online", e1, false);
    Car c2(2, "Ferrari", "eBay", e2, true);
    
    Stack<Car> cars;
    cars.push(c1);
    cars.push(c2);
    
    Ship s1(1, "Lotka", "Nenemin Lotkasi MMC", e3, false);
    
    Stack<Ship> ships;
    ships.push(s1);
    
    Airplane a1(1, "White Plane", "Turkish Airlines", e4, 4, 120);
    
    Stack<Airplane> airplanes;
    airplanes.push(a1);
    
    VehicleDepo v1(cars, ships, airplanes);
    v1.ShowAll();
    
    
    return 0;
}
