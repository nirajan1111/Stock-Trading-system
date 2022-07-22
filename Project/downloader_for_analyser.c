#include <stdio.h>
#include <conio.h>
#include "C:\msys64\mingw64\include\curl\curl.h"

// Using curl to download the webpage

int downloader_for_analyser(char stock_code[])
{
    // DECLARATION OF VARIABLES
    CURL *curl;
    FILE *fp;
    int result;
    char url[2048] = strcat("https://merolagani.com/CompanyDetail.aspx?symbol=", stock_code);
    char filename[100] = stock_code;

    // OPENTING FILES AND LIBRARIES
    // OPENING THE FILE IN BINARY SINCE IT IS IN HTML FORMAT
    fp = fopen(filename, "wb");
    // INITIALIZING CURL LIBRARY
    curl = curl_easy_init();

    // SAYING THE URL TO THE PROGRAM
    curl_easy_setopt(curl, CURLOPT_URL, url);
    // SAYING THE FILE TO THE PROGRAM
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    // 
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

    // To see if the program opened sucessfully
    result = curl_easy_perform(curl);
    if (result == CURLE_OK)
    {
        printf("Download sucessful!\n");
    }
    else
    {
        printf("ERROR: %s\n", curl_easy_strerror(result));
    }
    // Here CURDLE_OK means the download is sucessful
    // We can substitute CURDLE_OK by 1

    //Closing files and curl
    fclose(fp);
    curl_easy_cleanup(curl);

    return 0;
}
