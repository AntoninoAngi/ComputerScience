DWORD Done;
DWORD first_value;
record struttura;

DWORD countCircularList(HANDLE hFile, DWORD start){
  LARGE_INTEGER filePos;
  OVERLAPPED ov = {0,0,0,0, NULL};

  filePos.QuadPart = start*sizeof(record);
  ov.OffsetHigh = filePos.HighPart;
  ov.Offset = filePos.LowPart;

  ReadFileEx(hFile, &struttura, sizeof(record), &ov, readDone);
  if (!Done){
    SleepEx(True, NULL);
  }
  return count_global;
}

VOID WINAPI readDone(DWORD Code, DWORD nBytes, LPOVERLAPPED pOv){
  LARGE_INTEGER filePos;

  count_global++;

  if (struttura.next == first_value){
    Done = 1;
    return;
  }

  filePos.QuadPart = struttura.next * sizeof(record);

  pOv->OffsetHigh = filePos.HighPart;
  pOv->Offset = filePos.LowPart;


  ReadFileEx(hFile, &struttura, sizeof(record), pOv, readDone);

  return;


}
