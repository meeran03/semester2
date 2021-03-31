# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
using namespace std;

class Car {
    private:
        string name;
        string engine;
        string color;
        string brand;
    public:
        //Constructor Function
        Car(string n,string e,string c,string b) {
            name = n;
            engine = e;
            color = c;
            brand = b;
        }

        void displayInfo();
};

class Tesla :  Car {
    public :
        void checkerFun() {
            cout << "Good Till Here\n";
        }
        int model = 2001;
};



int main() {
    srand(time(0));
    Car coure = Car("COURE","2000CC","WHITE","DAIHATSU");
    coure.displayInfo();
    Tesla car1;
    cout << car1.model << endl;
    return 0;
}

void Car :: displayInfo() {
    cout << "Name : " << name << endl;
    cout << "Rating : " << rand() % 5+1 << endl;
    cout << "Color : " << color << endl;
    cout << "Engine : " << engine << endl;
    cout << "Brand : " << brand << endl;
}