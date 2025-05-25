#include "Observable.h"

void Observable::registerObserver(Observer* observer) {
    _observers.insert(observer);
}

void Observable::unregisterObserver(Observer* observer) {
    _observers.erase(observer);
}

void Observable::notifyObservers() {
    for (Observer* observer : _observers) {
        if (observer) {
            observer->update();
        }
    }
}
