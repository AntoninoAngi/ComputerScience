
for (i = 0; i < N; i++){
  indexes[i] = i;
}


for (i = 0; i < N; i++){
  id = WaitForMultipleObjects(N, tHandles, TRUE, INFINITE) - WAIT_OBJECT_0;

  iThread = indexes[id];
  indexes[id] = indexes[--N];
  tHandles[id] = tHandles[N];
  ProcessThreadResult(tHandles[iThread]);

}
