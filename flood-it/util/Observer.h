#ifndef OBSERVER_H
#define OBSERVER_H


    class Observer {
        public:
        /**
         * @brief Destructor
         */
        virtual ~Observer() = default;

        /**
         * @brief Update the observer
         */
        virtual void update() = 0;
    };


#endif // OBSERVER_H
