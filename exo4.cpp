#include <iostream>
#include <Windows.h>
#include <WinInet.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    HINTERNET hSession, hURL;
    char* Buffer = new char[1024];
    DWORD BufferLen, BytesWritten;
    HANDLE FileHandle;

    hSession = InternetOpenA(NULL, 0, NULL, NULL, 0);
    hURL = InternetOpenUrlA(hSession, "https://www.sap.com/belgique/index.html", NULL, 0, 0, 0);

    FileHandle = CreateFileA("C:\\Users\\Knacki\\Downloads\\test.txt", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 0);
    BytesWritten = 0;
    do
    {
        InternetReadFile(hURL, Buffer, 1024, &BufferLen);
        WriteFile(FileHandle, Buffer, BufferLen, &BytesWritten, NULL);
    } while (BufferLen != 0);
    CloseHandle(FileHandle);

    InternetCloseHandle(hURL);
    InternetCloseHandle(hSession);

    ShellExecuteA(0, "open", "C:\\Users\\Knacki\\Downloads\\test.txt", NULL, NULL, 1);

    cout << "Operation complete!";
    system("PAUSE");
   
    ifstream fichier("C:\\Users\\Knacki\\Downloads\\test.txt");
    fstream fileEdited("C:\\Users\\Knacki\\Downloads\\final.txt");
    string result = "";

    if (fichier && fileEdited)
    {
        //L'ouverture s'est bien passée, on peut donc lire

        string ligne; //Une variable pour stocker les lignes lues

        while (getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            while (ligne.find("SAP") != string::npos)
            ligne.replace(ligne.find("SAP"), 3, "Odoo");

            
            fileEdited << ligne << endl;
        }
    }
      return 0;
}