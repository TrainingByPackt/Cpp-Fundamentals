#include <iostream>

class Department {
public:

    Department(int expectedEarning, int effectiveEarning)
    : d_expectedEarning(expectedEarning), d_effectiveEarning(effectiveEarning)
    {}

    bool hasReachedTarget() const {return d_effectiveEarning >= d_expectedEarning;}
    int expectedEarning() const {return d_expectedEarning;}
    int effectiveEarning() const {return d_effectiveEarning;}
private:
    int d_expectedEarning;
    int d_effectiveEarning;
};


class Employee {
public:
    // This method is virtual: when called on a reference or pointer
    // to Employee the method of the run-time type will be called if
    // if overrides it.
    virtual int getBaseSalary() const { return 100; }

    virtual int getBonus(const Department& dep) const {
        if (dep.hasReachedTarget()) {
            return int(0.1 * getBaseSalary());
        }
        return 0;
    }

    // This method is not virtual, so calling it from an Employee type
    // will always call this methid
    int getTotalComp(const Department& dep) {
            // The method is calling two virtual methods, these
            // will instead be resolved like virtual methods,
            // and call the run-time type's method.
            return getBaseSalary() + getBonus(dep);
    }
};


class Manager : public Employee {
public:
    // Override the method for the manager.
    // When 'getTotalComp' is going to be called on the manager,
    // this method will be called
    virtual int getBaseSalary() const override { return 150; }

    virtual int getBonus(const Department& dep) const override {
        if (dep.hasReachedTarget()) {
            int additionalDeparmentEarnings = dep.effectiveEarning() - dep.expectedEarning();
            return int(0.2 * getBaseSalary() + 0.01 * additionalDeparmentEarnings);
        }
        return 0;
    }
};


int main()
{
    Department dep(1000, 1100);
    Employee employee;
    Manager manager;
    std::cout << "Employee: " << employee.getTotalComp(dep) << ". Manager: " << manager.getTotalComp(dep) << std::endl;
}
