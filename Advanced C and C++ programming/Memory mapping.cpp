

VOID SearchFunction (DWORD start, DWORD size, TCHAR *string){
  LARGE_INTEGER fileSize;
  LARGE_INTEGER Position;
  DWORD Found = 0;

  Position.QuadPart = 0;

  GetFileSizeEx(hFile, &fileSize);
  hMap = CreateFileMapping (hFile, NULL, PAGE_READONLY, fileSize.HighPart, fileSize.LowPart, NULL);

  Position.QuadPart += start;

  while ((pFile = MapViewOfFile(hMap, FILE_MAP_READ, Position.HighPart, Position.LowPart, size)){

    if (_tcscmp(_T(pFile), _T(string) == 0){
      _tprintf(_T("String found\n"));
      Found = 1;
    }

    Position.QuadPart += size;

  };

  if (Found != 1){
    _tprintf(_T("String not found\n"));
  }

  UnMapViewOfFile(pFile);

}
