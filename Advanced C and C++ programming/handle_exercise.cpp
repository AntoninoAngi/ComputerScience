//utilizzo un HANDLE per ognuno dei produttori

typedef struct{
  HANDLE mProd[2]; //A or B
  HANDLE mCons;
}struttura;



while(1){
  prod_done = WaitForMultipleObjects(2, &mProd, FALSE, INFINITE);
  id = prod_done - WAIT_OBJECT_0;

  __try{
    WaitForSingleObject(mCons, INFINITE);
    ComputeData(pConData, pDataA, pDataB);
  }__finally{ReleaseMutex(mProd[id]); ReleaseMutex(mCons);}


}
