typedef{

DWORD cnt_curr, cnt_max;
process_t *queue;
char lock;

} USER_SEMAPHORE, *LPUSER_SEMAPHORE;

LPUSER_SEMAPHORE initSemaphore(int init_cnt, int maxCnt){
  USER_SEMAPHORE sem;

  lock(sem.lock);
  sem.queue = NULL;
  sem.cnt_curr = init_cnt;
  sem.cnt_max = maxCnt;
  unlock(sem.lock);

  return *sem;
}

BOOL ReleaseSem(LPUSER_SEMAPHORE sem){
  lock(sem->lock);
  lock->cnt_curr++;
  if (lock->cnt_curr > lock->cnt_max){
    _tprintf(_T("Error\n"));
    unlock(sem->lock);
    return FALSE;
  }else{
    //remove thread from queue
    unlock(sem->lock);
    return TRUE;
  }
}

BOOL WaitSem(LPUSER_SEMAPHORE sem){
  lock(sem->lock);
  lock->cnt_curr--;
  //insert thread to queue
  unlock(sem->lock);
  return TRUE;
}
