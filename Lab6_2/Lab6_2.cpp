#include <iostream>
using namespace std;

// Абстрактный базовый класс Обувь
class Shoes {
public:
    virtual string description() = 0;
};

// Конкретный класс Кроссовки
class Sneakers : public Shoes {
public:
    string description() override {
        return "Кроссовки";
    }
};

// Класс Туфли
class DressShoes : public Shoes {
public:
    string description() override {
        return "Туфли";
    }
};

// Абстрактный класс Одежда
class Clothing {
public:
    virtual string description() = 0;
};

// Класс Спортивный костюм
class Sportswear : public Clothing {
public:
    string description() override {
        return "Спортивный костюм";
    }
};

// Класс Смокинг
class Tuxedo : public Clothing {
public:
    string description() override {
        return "Смокинг";
    }
};

// Абстрактная класс Одежда
class ClothingFactory {
public:
    virtual Shoes* createShoes() = 0;
    virtual Clothing* createClothing() = 0;
};

// Конкретный класс Спортивный костюм
class SportswearFactory : public ClothingFactory {
public:
    Shoes* createShoes() override {
        return new Sneakers();
    }

    Clothing* createClothing() override {
        return new Sportswear();
    }
};

// Конкретный класс Вечерний наряд
class EveningwearFactory : public ClothingFactory {
public:
    Shoes* createShoes() override {
        return new DressShoes();
    }

    Clothing* createClothing() override {
        return new Tuxedo();
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    ClothingFactory* sportswearFactory = new SportswearFactory();
    Shoes* sneakers = sportswearFactory->createShoes();
    Clothing* sportswear = sportswearFactory->createClothing();

    ClothingFactory* eveningwearFactory = new EveningwearFactory();
    Shoes* dressShoes = eveningwearFactory->createShoes();
    Clothing* tuxedo = eveningwearFactory->createClothing();

    cout << sneakers->description() << endl;    
    cout << sportswear->description() << endl;  

    cout << dressShoes->description() << endl; 
    cout << tuxedo->description() << endl;

    delete sneakers;
    delete sportswear;
    delete dressShoes;
    delete tuxedo;
    delete sportswearFactory;
    delete eveningwearFactory;

    return 0;
}
