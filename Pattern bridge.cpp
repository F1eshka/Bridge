#include <iostream>
#include <memory>  // Для использования std::shared_ptr

using namespace std;

// Интерфейс IWallCreator
class IWallCreator {
public:
    virtual void BuildWallWithDoor() = 0;
    virtual void BuildWall() = 0;
    virtual void BuildWallWithWindow() = 0;
    virtual ~IWallCreator() {}
};

// Реализация IWallCreator для кирпичных стен
class BrickWallCreator : public IWallCreator {
public:
    void BuildWallWithDoor() override {
        cout << "Brick wall with door built." << "\n";
    }

    void BuildWall() override {
        cout << "Brick wall built." << "\n";
    }

    void BuildWallWithWindow() override {
        cout << "Brick wall with window built." << "\n";
    }
};

// Реализация IWallCreator для бетонных плит
class ConcreteSlabWallCreator : public IWallCreator {
public:
    void BuildWallWithDoor() override {
        cout << "Concrete slab wall with door built." << "\n";
    }

    void BuildWall() override {
        cout << "Concrete slab wall built." << "\n";
    }

    void BuildWallWithWindow() override {
        cout << "Concrete slab wall with window built." << "\n";
    }
};

// Интерфейс IBuldingCompany
class IBuldingCompany {
public:
    virtual void BuildFoundation() = 0;
    virtual void BuildRoom() = 0;
    virtual void BuildRoof() = 0;
    virtual void SetWallCreator(shared_ptr<IWallCreator> creator) = 0;
    virtual ~IBuldingCompany() {}
};

// Реализация IBuldingCompany
class BuldingCompany : public IBuldingCompany {
private:
    shared_ptr<IWallCreator> WallCreator;
public:
    void BuildFoundation() override {
        cout << "Foundation is built." << "\n";
    }

    void BuildRoom() override {
        if (WallCreator) {
            WallCreator->BuildWallWithDoor();
            WallCreator->BuildWall();
            WallCreator->BuildWallWithWindow();
            WallCreator->BuildWall();
            cout << "Room finished." << "\n";
        }
    }

    void BuildRoof() override {
        cout << "Roof is done." << "\n";
    }

    void SetWallCreator(shared_ptr<IWallCreator> creator) override {
        WallCreator = creator;
    }
};

int main() {
    auto brickWallCreator = make_shared<BrickWallCreator>();
    auto concreteSlabWallCreator = make_shared<ConcreteSlabWallCreator>();
    auto buildingCompany = make_shared<BuldingCompany>();

    buildingCompany->BuildFoundation();
    buildingCompany->SetWallCreator(concreteSlabWallCreator);
    buildingCompany->BuildRoom();

    buildingCompany->SetWallCreator(brickWallCreator);
    buildingCompany->BuildRoom();
    buildingCompany->BuildRoom();
    buildingCompany->BuildRoof();

    return 0;
}
