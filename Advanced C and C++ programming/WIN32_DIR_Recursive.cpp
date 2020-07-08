

HANDLE se;
static void TraverseAndSaveList(LPTSTR fullPath, LPTSTR dirName, HANDLE fileHandle){

  WIN32_FIND_DATA findFile;
  TCHAR searchPath[200], newPath[200];
  HANDLE searchHandle;
  DWORD typefile;

  _stprintf(searchPath, _T("%s\\%s\\*"), fullPath, dirName);

  searchHandle = FindFirstFile(searchPath, &findFile);

  do {
    _stprintf(newPath, _T("%s\\%s"), fullPath, dirName);
    typefile = Filetype(&findFile);
    if (typefile == TYPE_FILE){
      WaitForSingleObject(se, INFINITE);
      WriteFile(fileHandle, findFile.cFileName, sizeof(TCHAR), NULL, NULL);
      ReleaseSemaphore(se, 1, NULL);

    }else if (typefile == TYPE_DIR){
      TraverseAndSaveList(newPath, findFile.cFileName, fileHandle);
    }

  } while(FindNextFile(searchHandle, &findFile));

}


DWORD Filetype(LPWIN32_FIND_DATA datatype){
  DWORD type = TYPE_FILE;
  BOOL IsDir = (datatype->dwFileAttribute & FILE_ATTRIBUTE_DIRECTORY) != 0;

  if(IsDIr){
    if (lstrcmp(datatype->cFileName, _T(".")) == 0 || lstrcmp(datatype->cFileName, _T(".."))){
      type = TYPE_DOT;
    }
    else{
      type = TYPE_DIR;
    }
  }



  return type;
}
