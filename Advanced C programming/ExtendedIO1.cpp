
LONGLONG nRecord=0, Done=0;
struct record Rec;
OVERLAPPED OverLap;
DWORD Code;

int _tmain (int argc, LPTSTR argv []){

OverLap = {0,0,0,0, NULL};
LARGE_INTEGER pos;
pos.QuadPart = 0;
OverLap.Offset = pos.LowPart;
OverLap.OffsetHigh = pos.HighPart;

hInputFile = CreateFile (argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
ReadFileEx (hInputFile, &Rec, sizeof (struct record), &OverLap, ReadDone);

CloseHandle (hInputFile);
 while (!Done)
   SleepEx (0, TRUE);
 _tprintf (_T ("NUM of Records: %d\n"), nRecord);
}


static VOID WINAPI ReadDone (DWORD Code, DWORD nBytes, LPOVERLAPPED pOv){
  LARGE_INTEGER pos;
  pos.LowPart = pOv->Offset;
  pos.HighPart = pOv->OffsetHigh;

  if (Code == ERROR_HANDLE_EOF){
    Done = 1;
    return;
  }

  nRecord++;
  pos.QuadPart += sizeof(struct record);
  pOv->Offset = pos.LowPart;
  pOv->OffsetHigh = pos.HighPart;

  ReadFileEx (hInputFile, &Rec, sizeof (struct record), &ov, ReadDone);
  SleepEx(0, TRUE);
  return;
}
