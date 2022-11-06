#include <stdatomic.h>
#include <stddef.h>
#include <threads.h>

/**
 * 
 * CON40-C Do not destroy a mutex while it is locked
 * 
 * Los Mutex son usados para protenger las estructuras de datos compartidas.
 * 
 * Si se destruye el mutex, lo subprocesos asociados a este quedarian bloqueados y
 * las secciones criticas y los datos compartidos quedarian desprotegidos.
*/


    //Todo codigo comentado no se deberia usar



mtx_t lock;
atomic_int completed = ATOMIC_VAR_INIT(0);
enum { max_threads = 5 };

int do_work(void *arg) {
/*
  int *i = (int *)arg;
 
    if (*i == 0) { 
        // Creation thread 
        if (thrd_success != mtx_init(&lock, mtx_plain)) {
        //Handle error 
        }
        
        atomic_store(&completed, 1);
    } else if (*i < max_threads - 1) { 
        // Worker thread 
    */
        if (thrd_success != mtx_lock(&lock)) {
            // Handle error 
        }
        // Access data protected by the lock 
        atomic_fetch_add(&completed, 1);
        if (thrd_success != mtx_unlock(&lock)) {
            // Handle error 
        }
    /*} else { 
        // Destruction thread 
        mtx_destroy(&lock);
    }
    */
    return 0;
}
  
int main(void) {
    thrd_t threads[max_threads];
    if (thrd_success != mtx_init(&lock, mtx_plain)){
            /* Handle error */        
    }
    for (size_t i = 0; i < max_threads; i++) {
        if (thrd_success != thrd_create(&threads[i], do_work, &i)) {
            /* Handle error */
        }
    }
    for (size_t i = 0; i < max_threads; i++) {
        if (thrd_success != thrd_join(threads[i], 0)) {
            /* Handle error */
        }
    }
        mtx_destroy(&lock);
  return 0;
}