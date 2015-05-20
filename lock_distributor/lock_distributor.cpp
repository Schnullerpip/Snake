#include "lock_distributor.h"

static pthread_mutex_t  lock;

lock_distributor::lock_distributor(){
    pthread_mutex_init(&lock, NULL);
}

void lock_distributor::getLock(){
    pthread_mutex_lock(&lock);
}

void lock_distributor::freeLock(){
    pthread_mutex_unlock(&lock);
}
