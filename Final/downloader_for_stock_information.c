#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <curl/curl.h>

// Using curl to download the webpage

void main()
{
    // DECLARATION OF VARIABLES
    CURL *curl;
    FILE *fp;
    int result;
    char url[2048] = "https://merolagani.com/LatestMarket.aspx";
    char filename[100] = "hello.txt";

    // OPENTING FILES AND LIBRARIES
    // OPENING THE FILE IN BINARY SINCE IT IS IN HTML FORMAT
    fp = fopen(filename, "wb");
    // INITIALIZING CURL LIBRARY
    curl = curl_easy_init();

    // SAYING THE URL TO THE PROGRAM
    curl_easy_setopt(curl, CURLOPT_URL, url);
    // SAYING THE FILE TO THE PROGRAM
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    // ERROR HANDLING
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

    // To see if the program opened sucessfully
    result = curl_easy_perform(curl);

    // Closing files and curl
    fclose(fp);
    curl_easy_cleanup(curl);
}
