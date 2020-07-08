
#define SEC 10

int nR = 0;
init (meR, 1);
init (meW, 1);
init (W, 1);
init (R, 1);
int ret = -1;



//READER
wait(meR);
wait(R);
ret = -1;
nR++;
if (nR == 1)
    wait(W);
signal (meR);

//lettura

wait(meR);
signal(R);
nR--;
if (nR == 0)
  signal(W);
signal (meR);


//WRITER
wait(meW);
wait(W);

//scrive

if (ret == 0)
    signal(R);
signal (W);
signal (meW);

clock_gettime (CLOCK_REALTIME, &ts);
ts.tv_sec += SEC;
ret = sem_timedwait(R, &ts);
