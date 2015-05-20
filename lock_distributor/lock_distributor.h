#ifndef LOCK_DISTRIBUTOR_H
#define LOCK_DISTRIBUTOR_H

#include<pthread.h>

class lock_distributor{
    public:
        lock_distributor();
        void getLock();
        void freeLock();
};
#endif
