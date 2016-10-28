#include <vector>
#include <string>
#include <cstdio>

#ifdef __WIN32
	#include <windows.h>
#else
	#include <dirent.h>
	#include <cstring>
	#include <cstdlib>
#endif

/* Example on how listDir could be called */
//std::vector<std::string> fileNamesVector;
//listDir(opts.file2, fileNamesVector);	/* opts.file2 holds the directory name */
//std::cout << "Number of file names found in search directory: " << fileNamesVector.size << "\n\n";

void listDir(const char* dirName, std::vector<std::string>& fnVec)
{
#ifdef __WIN32
	size_t origsize = strlen(dirName) + 1;
    size_t convertedChars = 0;
	wchar_t wdirName[MAX_PATH];

    mbstowcs_s(&convertedChars, wdirName, origsize, dirName, _TRUNCATE);
    wcscat_s(wdirName, L"\\*.*");

	WIN32_FIND_DATA fd;
	HANDLE h = FindFirstFile(wdirName, &fd);
	fnVec.clear();	

	// Convert to a char*
	origsize = wcslen(fd.cFileName) + 1;    
    convertedChars = 0;
	char nstring[MAX_PATH];
	wcstombs_s(&convertedChars, nstring, origsize, fd.cFileName, _TRUNCATE);
       	
	fnVec.push_back(nstring);
	
	while (FindNextFile(h, &fd))
	{
		// Convert to a char*
		size_t origsize = wcslen(fd.cFileName) + 1;    
		size_t convertedChars = 0;
		char nstring[MAX_PATH];
		wcstombs_s(&convertedChars, nstring, origsize, fd.cFileName, _TRUNCATE);
		char filedirstring[MAX_PATH];
		strcpy(filedirstring, dirName);
		strcat(filedirstring, "\\");
		strcat(filedirstring, nstring);
		fnVec.push_back(filedirstring);		
	}	

	fnVec.erase(fnVec.begin(),fnVec.begin()+2);
#else
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(dirName)) != NULL) {
		while((ent = readdir(dir)) != NULL) {
			fnVec.push_back(std::string(ent->d_name));
		}
		closedir(dir);
	}
	{
		fprintf(stderr,"Could not open the directory %s\n", dirName);
		exit(-1);
	}
#endif
}


