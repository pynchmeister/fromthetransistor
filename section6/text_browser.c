#include <stdio.h>
#include <curl/curl.h>

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp) {
    return fwrite(buffer, size, nmemb, (FILE *)userp);
}

int main(void) {
   CURL *curl;
   CURLcode res;
   curl = curl_easy_init();
   if(curl) {
      curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

      /* Perform the request, res will get the return code */
      res = curl_easy_perform(curl);
      /* Check for errors */
      if(res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_stderror(res));

     /* always cleanup */
     curl_easy_cleanup(curl)
   }
  return 0;
}
