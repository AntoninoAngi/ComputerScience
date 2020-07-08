
OVERLAPPED ov;
DWORD Done, count;


BOOL writeIntegers(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfIntegers) {
  LARGE_INTEGER FilePos;
  ov = {0,0,0,0,NULL};

  FilePos.QuadPart = 0;
  ov.Offset = FilePos.LowPart;
  ov.OffsetHigh = FilePos.HighPart;



  ReadFileEx (hFile, lpBuffer, sizeof(INT), &ov,WDone);

  if (!Done){
    SleepEx(0, TRUE);
  }
  return TRUE;
}

VOID WINAPI WDone (DWORD Code, DWORD bytes, LPOVERLAPPED ov){
  LARGE_INTEGER FilePos;
  FilePos.LowPart = ov->Offset;
  FilePos.HighPart = ov->OffsetHigh;

  if (count >= nNumberOfIntegers){
    Done = 1;
    return;
  }
  count++;
  FilePos.QuadPart += sizeof(INT);
  ov->Offset = FilePos.LowPart;
  ov->OffsetHigh = FilePos.HighPart;

  WriteFileEx(hFile, lpBuffer, sizeof(INT), &ov,WDone);
  SleepEx(0, TRUE);
}
