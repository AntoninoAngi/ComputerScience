
sem_prior; sem_norm;

wait(){

  if (try_wait(sem_prior) == 0){
    printf("Waiting on priority semaphore, not blocking");
  }else{
    printf("Waiting on normal semaphore, blocking");
    wait(sem_norm);
  }

}


int wait(semaphore_t sem){
  lock(sem.lock);
  if (sem.cnt <= 0){
    printf("Too many threads already waiting, this is a non blocking wait\n");
    return -1; //could also return EAGAIN error
  }else{
    printf("Waiting succeded\n");
    sem.cnt--;
    //insert thread to sem.queue
    //block thread
  }
  unlock(sem.lock);
  return 0;
}


void signal(semaphore_t sem){
  lock (sem.lock);
  sem.cnt++;
  if (sem.cnt <= 0){
    //remove thread from S.queue
    //wake up thread
  }
  unlock(sem.lock);
}
