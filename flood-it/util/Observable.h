#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <set>
#include "Observer.h"

/**
 * @brief Interface for observable objects
 */
class Observable {
protected:
    std::set<Observer*> _observers;

public:
    virtual ~Observable() = default;

    /**
     * @brief Register an observer
     * @param observer A pointer to the observer
     */
    void registerObserver(Observer* observer);

    /**
     * @brief Unregister an observer
     * @param observer A pointer to the observer
     */
    void unregisterObserver(Observer* observer);

    /**
     * @brief Notify all observers
     */
    void notifyObservers();
};

#endif // OBSERVABLE_H
