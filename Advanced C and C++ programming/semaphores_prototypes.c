//sem_init, sem_wait and sem_post using counter and conditional variables


typedef struct{
pthrad_mutex_t *lock;
pthread_cond_t *cond;
int count;
}sema_cond;


void sema_init(sema_cond *sem, int value){
  sem->lock = (pthread_mutex_t) malloc (sizeof(pthrad_mutex_t));
  pthread_mutex_init(sem->lock, NULL);

  pthread_mutex_lock(sem->lock);
  sem->cond = (pthread_cond_t) malloc (sizeof(pthrad_cond_t));
  sem->count = value;
  pthread_cond_init(sem->cond, NULL);
  pthread_mutex_unlock(sem->lock);
}

void sema_wait(sema_cond *sem){
  pthread_mutex_lock(sem->lock);

  sem->count--;
  while (sem->count < 0){
    pthread_cond_wait(sem->cond, s->lock);
  }

  pthread_mutex_unlock(sem->lock);
}

void sema_post(sema_cond *sem){
  pthread_mutex_lock(sem->lock);
  sem->count++;
  if (sem->count >= 0){
    pthread_cond_signal(sem->cond);
  }

  pthread_mutex_unlock(sem->lock);
}
