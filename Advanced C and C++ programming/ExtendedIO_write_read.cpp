
OVERLAPPED ov;
DWORD Done, count, written;


DWORD StoreDataToFile(HANDLE hFile, RECORD *r, DWORD nR){

  LARGE_INTEGER FilePos;
  ov = {0,0,0,0, NULL};

  FilePos.QuadPart = 0;
  ov.OffsetHigh = FilePos.HighPart;
  ov.Offset = FilePos.LowPart;

  WriteFileEx(hFile, r, sizeof(RECORD), &ov, writeRecord);

  if (!Done){
    SleepEx(0, TRUE);
  }

  return 0;

}

VOID WINAPI writeRecord(DWORD Code, DWORD nBytes, LPOVERLAPPED pOv) {
  LARGE_INTEGER FilePos;
  FilePos.HighPart = pOv->OffsetHigh;
  FilePos.LowPart = pOv->Offset;

  if (written >= nR){
    Done = 1;
    return;
  }

  written++;
  FilePos.QuadPart += sizeof(RECORD);
  pOv->OffsetHigh = FilePos.HighPart;
  pOv->Offset = FilePos.LowPart;

  WriteFileEx(hFile, r, sizeof(RECORD), pOv, writeDone);
  SleepEx(0, TRUE);
}


VOID WINAPI writeDone(DWORD Code, DWORD nBytes, LPOVERLAPPED pOv) {
  LARGE_INTEGER FilePos;
  FilePos.HighPart = pOv->OffsetHigh;
  FilePos.LowPart = pOv->Offset;

  if (Code == ERROR_HANDLE_EOF){
    Done = 1;
    return;
  }

  count++;
  FilePos.QuadPart += sizeof(RECORD);
  pOv->OffsetHigh = FilePos.HighPart;
  pOv->Offset = FilePos.LowPart;

  WriteFileEx(hFile, r, sizeof(RECORD), pOv, writeDone);
  SleepEx(0, TRUE);
}
