// AI chatbot using curl library C++
#include <iostream>
#include <string>
#include <curl/curl.h>
using namespace std;

string callOpenAI(const string& prompt) {
    CURL* curl;
    CURLcode res;
    string response;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "API key here ");

        string data = "{\"model\": \"text-davinci-003\", \"prompt\": \"" + prompt + "\", \"max_tokens\": 150}";

        curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/completions");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

        auto writeCallback = [](void* contents, size_t size, size_t nmemb, void* userp) -> size_t {
            ((string*)userp)->append((char*)contents, size * nmemb);
            return size * nmemb;
        };

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return response;
}

int main() {
    string input;
    cout << "You: ";
    getline(cin, input);

    string response = callOpenAI(input);
    cout << "Bot: " << response << endl;

    return 0;
}
